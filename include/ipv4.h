#ifndef _IP_H_
#define _IP_H_
#include <rte_mbuf.h>
#define IP_VERSION 0x40
int ipv4_rcv(struct rte_mbuf *pkt, uint16_t offset);
#endif
