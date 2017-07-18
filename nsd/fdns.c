#include <rte_ethdev.h>
#include <rte_mbuf.h>

#include "fdns.h"
#include "nsd.h"
#include "util.h"
#include "query.h"

struct nsd nsd;
#define MAX_CORES 5
#define CONFIGFILE1 "/opt/nsd/nsd.conf"
static struct query *queries[MAX_CORES];
extern struct rte_mempool *pktmbuf_pool;

static uint16_t *compressed_dname_offsets = 0;
static uint32_t compression_table_capacity = 0;
static uint32_t compression_table_size = 0;


static void
cleanup_dname_compression_tables(void *ptr)
{
    free(ptr);
    compressed_dname_offsets = NULL;
    compression_table_capacity = 0;
}

static void
initialize_dname_compression_tables(struct nsd *nsd)
{
    size_t needed = domain_table_count(nsd->db->domains) + 1;
    needed += EXTRA_DOMAIN_NUMBERS;
    if(compression_table_capacity < needed) {
        if(compressed_dname_offsets) {
            region_remove_cleanup(nsd->db->region,
                cleanup_dname_compression_tables,
                compressed_dname_offsets);
            free(compressed_dname_offsets);
        }
        compressed_dname_offsets = (uint16_t *) xalloc(
            needed * sizeof(uint16_t));
        region_add_cleanup(nsd->db->region, cleanup_dname_compression_tables,
            compressed_dname_offsets);
        compression_table_capacity = needed;
        compression_table_size=domain_table_count(nsd->db->domains)+1;
    }
    memset(compressed_dname_offsets, 0, needed * sizeof(uint16_t));
    compressed_dname_offsets[0] = QHEADERSZ; /* The original query name */
}

int fdns_prepare(struct nsd *nsd) {
    if ((nsd->db = namedb_open(nsd->dbfile, nsd->options)) == NULL) {
        printf("unable to open the database %s: %s",
            nsd->dbfile, strerror(errno));
        //xfrd_del_tempdir(nsd);
        return -1;
    } 

    if(nsd->options->zonefiles_check)
        namedb_check_zonefiles(nsd, nsd->options, NULL, NULL);

    compression_table_capacity = 0;
    initialize_dname_compression_tables(nsd);
    return 0;
}

int fdns_init() {
    log_myopen("/opt/nsd/log");
    memset(&nsd, 0, sizeof(struct nsd));
    nsd.options = nsd_options_create(region_create_custom(xalloc, free,
            DEFAULT_CHUNK_SIZE, DEFAULT_LARGE_OBJECT_SIZE,
            DEFAULT_INITIAL_CLEANUP_SIZE, 1));

    if(!parse_options_file(nsd.options, CONFIGFILE1, NULL, NULL)) {
        printf("could not read config: %s\n", CONFIGFILE1);
        return -1;
    }
    log_msg(LOG_INFO,"parse_option_file success\n");
    if(!nsd.dbfile)
    {
        if(nsd.options->database)
            nsd.dbfile = nsd.options->database;
    }
    if(!parse_zone_list_file(nsd.options)) {
        printf("could not read zonelist file %s\n",
            nsd.options->zonelistfile);
        return -1;
    }
    edns_init_data(&nsd.edns_ipv4, nsd.options->ipv4_edns_size);
    if (nsd.nsid_len == 0 && nsd.options->nsid) {
        if (strlen(nsd.options->nsid) % 2 != 0) {
            printf("the NSID must be a hex string of an even length.");
            return -1;
        }
        nsd.nsid = xalloc(strlen(nsd.options->nsid) / 2);
        nsd.nsid_len = strlen(nsd.options->nsid) / 2;
        if (hex_pton(nsd.options->nsid, nsd.nsid, nsd.nsid_len) == -1) {
            printf("hex string cannot be parsed '%s' in NSID.", nsd.options->nsid);
            return -1;
        }
    }

    edns_init_nsid(&nsd.edns_ipv4, nsd.nsid_len);
    //append_trailing_slash(&nsd.options->xfrdir, nsd.options->region);

    if (fdns_prepare(&nsd) != 0) {
        printf("server preparation failed,could "
            "not be started");
        return -1;
    }

    return 0;
}

int fdns_slave(unsigned lcore_id) {
    region_type *server_region = region_create(xalloc, free);
    queries[lcore_id] = query_create(server_region,
        compressed_dname_offsets, compression_table_size);
    printf("lcore=%d,queries=%p\n", lcore_id, queries[lcore_id]);
    return 1;
}

query_type * fdns_process(struct rte_mbuf *pkt , int offset, int received) {
    unsigned lcore_id = rte_lcore_id();
    char *rdata = NULL;

    query_type *query = queries[lcore_id];

    if(received < 0) {
        return NULL;
    }

    query_reset(query,  UDP_MAX_MESSAGE_LEN, 0);

    rdata = rte_pktmbuf_mtod_offset(pkt, char *, offset);
    buffer_write(query->packet, rdata, received);
    buffer_flip(query->packet);

    if(query_process(query, &nsd) != QUERY_DISCARDED) {
        query_add_optional(query, &nsd);  
        buffer_flip(query->packet);
    }else {
        query_reset(query, UDP_MAX_MESSAGE_LEN, 0);
    }

    return query;
}
