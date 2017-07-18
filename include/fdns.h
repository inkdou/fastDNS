#ifndef _FDNS_H_
#define _FDNS_H_
#include "query.h"
#include "nsd.h"
#include "util.h"

int fdns_prepare(struct nsd *nsd);
int fdns_init(void);
int fdns_slave(unsigned lcore_id);
query_type* fdns_process(struct rte_mbuf *pkt , int offset, int received); 
#endif
