#ifndef _NETDEV_H_
#define _NETDEV_H_
#include <rte_mbuf.h>

int neteth_rcv(struct rte_mbuf *pkt); 
#endif
