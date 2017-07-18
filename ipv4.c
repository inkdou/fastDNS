#include <rte_mbuf.h>
#include <rte_ether.h> 
#include <rte_ip.h>
#include <rte_malloc.h>
#include <rte_udp.h>
#include <arpa/inet.h>
#include <rte_byteorder.h>
#include <rte_ethdev.h>
#include <rte_kni.h>

#include "ipv4.h"
#include "fdns.h"
#include "query.h"
#include "buffer.h"

#define NUDP_PORT 0x3500 
#define IP_DEFTTL  64   /* from RFC 1340. */
#define IP_VERSION 0x40
#define IP_HDRLEN  0x05 /* default IP header length == five 32-bits words. */
#define IP_VHL_DEF (IP_VERSION | IP_HDRLEN)
extern struct rte_mempool *pktmbuf_pool;
extern struct rte_kni *kni;

static void
copy_buf_to_pkt_segs(void *buf, unsigned len, struct rte_mbuf *pkt,
    unsigned offset)
{
    struct rte_mbuf *seg;
    void *seg_buf;
    unsigned copy_len;

    seg = pkt;
    while (offset >= seg->data_len) {
        offset -= seg->data_len;
        seg = seg->next;
    }
    copy_len = seg->data_len - offset;
    seg_buf = rte_pktmbuf_mtod_offset(seg, char *, offset);
    while (len > copy_len) {
        rte_memcpy(seg_buf, buf, (size_t) copy_len);
        len -= copy_len;
        buf = ((char *) buf + copy_len);
        seg = seg->next;
        seg_buf = rte_pktmbuf_mtod(seg, void *);
    }
    rte_memcpy(seg_buf, buf, (size_t) len);
}

static inline void
copy_buf_to_pkt(void *buf, unsigned len, struct rte_mbuf *pkt, unsigned offset)
{
    if (offset + len <= pkt->data_len) {
        rte_memcpy(rte_pktmbuf_mtod_offset(pkt, char *, offset), buf,
            (size_t) len);
        return;
    }
    copy_buf_to_pkt_segs(buf, len, pkt, offset);
}

void
init_eth_header(struct ether_hdr *eth_hdr, struct ether_addr *src_mac, \
    struct ether_addr *dst_mac, uint16_t ether_type)
{
    ether_addr_copy(dst_mac, &eth_hdr->d_addr);
    ether_addr_copy(src_mac, &eth_hdr->s_addr);

    eth_hdr->ether_type = rte_cpu_to_be_16(ether_type);
}

uint16_t
init_ipv4_header(struct ipv4_hdr *ip_hdr, uint32_t src_addr,
    uint32_t dst_addr, uint16_t pkt_data_len)
{
    uint16_t pkt_len;
    unaligned_uint16_t *ptr16;
    uint32_t ip_cksum;

    pkt_len = (uint16_t) (pkt_data_len + sizeof(struct ipv4_hdr));

    ip_hdr->version_ihl   = IP_VHL_DEF;
    ip_hdr->type_of_service   = 0;
    ip_hdr->fragment_offset = 0;
    ip_hdr->time_to_live   = IP_DEFTTL;
    ip_hdr->next_proto_id = IPPROTO_UDP;
    ip_hdr->packet_id = 0;
    ip_hdr->total_length   = rte_cpu_to_be_16(pkt_len);
    ip_hdr->src_addr = src_addr;
    ip_hdr->dst_addr = dst_addr;

    ptr16 = (unaligned_uint16_t *)ip_hdr;
    ip_cksum = 0;
    ip_cksum += ptr16[0]; ip_cksum += ptr16[1];
    ip_cksum += ptr16[2]; ip_cksum += ptr16[3];
    ip_cksum += ptr16[4];
    ip_cksum += ptr16[6]; ip_cksum += ptr16[7];
    ip_cksum += ptr16[8]; ip_cksum += ptr16[9];


    ip_cksum = ((ip_cksum & 0xFFFF0000) >> 16) +
        (ip_cksum & 0x0000FFFF);
    ip_cksum %= 65536;
    ip_cksum = (~ip_cksum) & 0x0000FFFF;
    if (ip_cksum == 0)
        ip_cksum = 0xFFFF;
    ip_hdr->hdr_checksum = (uint16_t) ip_cksum;

    return pkt_len;
}


uint16_t
init_udp_header(struct udp_hdr *udp_hdr, uint16_t src_port,
    uint16_t dst_port, uint16_t pkt_data_len)
{
    uint16_t pkt_len;

    pkt_len = (uint16_t) (pkt_data_len + sizeof(struct udp_hdr));

    udp_hdr->src_port = src_port;
    udp_hdr->dst_port = dst_port;
    udp_hdr->dgram_len = rte_cpu_to_be_16(pkt_len);
    udp_hdr->dgram_cksum = 0; 

    return pkt_len;
}

int
generate_packet_burst(struct rte_mempool *mp, struct rte_mbuf **pkts_burst,
    struct ether_hdr *eth_hdr, uint8_t vlan_enabled, void *ip_hdr,
    uint8_t ipv4, struct udp_hdr *udp_hdr, int nb_pkt_per_burst,
    uint8_t pkt_len, uint8_t nb_pkt_segs)
{
    int i, nb_pkt = 0;
    size_t eth_hdr_size;

    struct rte_mbuf *pkt_seg;
    struct rte_mbuf *pkt;

    for (nb_pkt = 0; nb_pkt < nb_pkt_per_burst; nb_pkt++) {
        pkt = rte_pktmbuf_alloc(mp);
        if (pkt == NULL) {
nomore_mbuf:
            if (nb_pkt == 0)
                return -1;
            break;
        }

        pkt->data_len = pkt_len;
        pkt_seg = pkt;
        for (i = 1; i < nb_pkt_segs; i++) {
            pkt_seg->next = rte_pktmbuf_alloc(mp);
            if (pkt_seg->next == NULL) {
                pkt->nb_segs = i;
                rte_pktmbuf_free(pkt);
                goto nomore_mbuf;
            }
            pkt_seg = pkt_seg->next;
            pkt_seg->data_len = pkt_len;
        }
        pkt_seg->next = NULL; /* Last segment of packet. */

        if (vlan_enabled)
            eth_hdr_size = sizeof(struct ether_hdr) + sizeof(struct vlan_hdr);
        else
            eth_hdr_size = sizeof(struct ether_hdr);

        copy_buf_to_pkt(eth_hdr, eth_hdr_size, pkt, 0);

        if (ipv4) {
            copy_buf_to_pkt(ip_hdr, sizeof(struct ipv4_hdr), pkt, eth_hdr_size);
            copy_buf_to_pkt(udp_hdr, sizeof(*udp_hdr), pkt, eth_hdr_size +
                sizeof(struct ipv4_hdr));
        } else {
            copy_buf_to_pkt(ip_hdr, sizeof(struct ipv6_hdr), pkt, eth_hdr_size);
            copy_buf_to_pkt(udp_hdr, sizeof(*udp_hdr), pkt, eth_hdr_size +
                sizeof(struct ipv6_hdr));
        }

        pkt->nb_segs = nb_pkt_segs;
        pkt->pkt_len = pkt_len;
        pkt->l2_len = eth_hdr_size;

        if (ipv4) {
            pkt->vlan_tci  = ETHER_TYPE_IPv4;
            pkt->l3_len = sizeof(struct ipv4_hdr);
        } else {
            pkt->vlan_tci  = ETHER_TYPE_IPv6;
            pkt->l3_len = sizeof(struct ipv6_hdr);
        }

        pkts_burst[nb_pkt] = pkt;
    }
    return nb_pkt;
}

int ipv4_rcv(struct rte_mbuf *pkt, uint16_t offset) {
    struct ether_hdr *eth_hdr = NULL;
    struct ipv4_hdr *ip4_hdr = NULL;
    struct udp_hdr *udp_hdr = NULL; 

    int hlen = 0;
    int len = 0;
    struct rte_mbuf **mtable;
    query_type *query;

    int received = 0;
    int slen = 0;

    struct ether_addr *src_mac, *dst_mac;
    uint32_t src_addr, dst_addr;
    uint16_t src_port, dst_port;

    struct ether_hdr pkt_eth_hdr;
    struct ipv4_hdr pkt_ipv4_hdr;
    struct udp_hdr pkt_udp_hdr;

    ip4_hdr = rte_pktmbuf_mtod_offset(pkt, struct ipv4_hdr *, offset);
    if( (ip4_hdr->version_ihl & 0xF0) != IP_VERSION) {
        printf("version\n");
        goto cleanup; 
    }

    hlen = (ip4_hdr->version_ihl & ~IP_VERSION ) << 2;
    len = rte_be_to_cpu_16(ip4_hdr->total_length);
    if(len < hlen) {
        printf("len=%d,hlen=%d\n", len,hlen);
        goto cleanup; 
    }

    if(pkt->pkt_len < len + offset)
    {
        printf("pkt_len < len+offset, %d,%d\n", pkt->pkt_len, len+offset);
        goto cleanup;
    }

    switch(ip4_hdr->next_proto_id) {
    case IPPROTO_UDP:
        eth_hdr = rte_pktmbuf_mtod(pkt, struct ether_hdr*);
        udp_hdr = rte_pktmbuf_mtod_offset(pkt, struct udp_hdr*, offset + hlen);
        if(len != hlen + ntohs(udp_hdr->dgram_len)) {
            goto cleanup; 
        }
        if(udp_hdr->dst_port && NUDP_PORT) {
            //printf("DNS request\n");
            received = rte_be_to_cpu_16(udp_hdr->dgram_len) - sizeof(struct udp_hdr);
            offset = offset + sizeof(struct ipv4_hdr) + sizeof(struct udp_hdr);
            src_mac = &(eth_hdr->d_addr);
            dst_mac = &(eth_hdr->s_addr);

            src_addr = ip4_hdr->dst_addr;
            dst_addr = ip4_hdr->src_addr;

            src_port = udp_hdr->dst_port;
            dst_port = udp_hdr->src_port;
            //printf("%s\n",inet_ntoa(*(struct in_addr*)&(src_addr)));
            if((uint32_t)inet_addr("192.168.100.228") == src_addr) {
                query = fdns_process(pkt, offset, received);

                slen = buffer_remaining(query->packet);
                if(query != NULL && slen > 0) {
                    init_eth_header(&pkt_eth_hdr, src_mac, dst_mac, ETHER_TYPE_IPv4);
                    init_ipv4_header(&pkt_ipv4_hdr, src_addr, dst_addr, 8 + slen);
                    init_udp_header(&pkt_udp_hdr, src_port, dst_port, slen);

                    mtable = (struct rte_mbuf **)rte_calloc("tx_buff", 20, sizeof(void*), RTE_CACHE_LINE_SIZE);

                    generate_packet_burst(pktmbuf_pool, mtable, &pkt_eth_hdr, 0, &pkt_ipv4_hdr, 1,
                        &pkt_udp_hdr, 1, 42+slen, 1);

                    copy_buf_to_pkt(buffer_begin(query->packet), slen, mtable[0], sizeof(struct ether_hdr) + sizeof(struct ipv4_hdr) + sizeof(struct udp_hdr));
                    rte_eth_tx_burst(0, 0, mtable, 1);

                }
                query_reset(query, UDP_MAX_MESSAGE_LEN, 0);
            }
        }
        break;
    case IPPROTO_ICMP:
        rte_kni_tx_burst(kni, &pkt, 1); 
        rte_kni_handle_request(kni);
        return 0;
    default:
        //printf("Unsupported proto\n");
        break;
    }
cleanup:
    rte_pktmbuf_free(pkt);
    return 0;
}
