#include <rte_ether.h>
#include <rte_kni.h>
#include <rte_mbuf.h>
#include <arpa/inet.h>
#include "netdev.h"
#include "ipv4.h"

extern struct rte_kni *kni;
int neteth_rcv(struct rte_mbuf *pkt) { 
    struct ether_hdr *eth_hdr = NULL;
    eth_hdr = rte_pktmbuf_mtod(pkt, struct ether_hdr *); 

    switch(ntohs(eth_hdr->ether_type)) {
    case ETHER_TYPE_ARP:
        rte_kni_tx_burst(kni, &pkt, 1); 
        rte_kni_handle_request(kni);
        rte_pktmbuf_free(pkt);
        break;
    case ETHER_TYPE_IPv4:
        ipv4_rcv(pkt, sizeof(struct ether_hdr));
        break;
    case ETHER_TYPE_IPv6:
    default:
        break;
    }
    return 0;

}
