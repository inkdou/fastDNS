#ifndef _NSD_H_
#define _NSD_H_

#include "namedb.h"
#include "edns.h"
#include "options.h"

#define EXTRA_DOMAIN_NUMBERS 1024
struct nsd {
    struct namedb *db;
    const char      *chrootdir;
    uint16_t        nsid_len;
    const char      *identity;
    const char      *version;
    unsigned char   *nsid;
    const char *dbfile;
    edns_data_type edns_ipv4;
    size_t ipv4_edns_size;
    struct nsd_options *options;
};

typedef struct nsd nsd_type;
#endif
