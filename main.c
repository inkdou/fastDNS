#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/queue.h>
#include <unistd.h>

#include <rte_cycles.h>
#include <rte_memory.h>
#include <rte_memzone.h>
#include <rte_launch.h>
#include <rte_eal.h>
#include <rte_per_lcore.h>
#include <rte_lcore.h>
#include <rte_debug.h>
#include <rte_ring.h>
#include <rte_log.h>
#include <rte_mempool.h>
#include <rte_mbuf.h>
#include <rte_ethdev.h>
#include <rte_kni.h>

#include "netdev.h"
#include "fdns.h"

static const char *_SEC_2_PRI = "SEC_2_PRI";
struct rte_ring *recv_ring;
const unsigned string_size = 15;
struct rte_kni *kni;
static struct rte_kni_ops kni_ops = {
    .change_mtu = NULL,
    .config_network_if = NULL,
};

#define PACKET_READ_SIZE 32
struct rte_mempool *pktmbuf_pool;
static const struct rte_eth_conf port_conf_default = {
    .rxmode = { .max_rx_pkt_len = ETHER_MAX_LEN }
};
#define MBUF_CACHE_SIZES 250
#define NUM_MBUFS 8191
#define MAX_PKT_BURST 512
#define RX_RING_SIZE 1024
#define TX_RING_SIZE 512
#define BUFLEN 100

static void 
slave_process_packet(__attribute__((unused)) unsigned lcore_id, struct rte_mbuf *pkt) {
    int ret = -1;
    ret = neteth_rcv(pkt);
    (void)ret;
}

static int
lcore_slave(__attribute__((unused)) void *arg) {
    unsigned lcore_id = rte_lcore_id();
    volatile int quit = 0;

    printf("Starting core %u\n", lcore_id);

    while (!quit){
        void *msg;
        if (rte_ring_dequeue(recv_ring, &msg) < 0){
            continue;
        }
        slave_process_packet(lcore_id, msg);
    }
    return 0;
}

static void 
master_process_packets(uint32_t port_num __rte_unused,
    struct rte_mbuf *pkts[], uint16_t rx_count) 
{
    uint16_t i;
    int ret;
    for (i = 0; i < rx_count; i++) {
        if ( (ret = rte_ring_enqueue(recv_ring, pkts[i])) < 0) {
            printf("Failed to enqueue %d\n", ret);
        }
    }
    /* if (unlikely(rte_ring_sp_enqueue_bulk(recv_ring, (void**)pkts, rx_count, NULL) != 0)) { 
       printf("failed\n");
       for(i = 0; i < rx_count; i++) {
       rte_pktmbuf_free(pkts[i]);
       }
       } */
}

static void
kni_burst_free_mbufs(struct rte_mbuf **pkts, unsigned num)
{
    unsigned i;

    if (pkts == NULL)
        return;

    for (i = 0; i < num; i++) {
        rte_pktmbuf_free(pkts[i]);
        pkts[i] = NULL;
    }
}

static int
lcore_master(__attribute__((unused)) void *arg) {
    int quit = 0;
    struct rte_mbuf *pkts_kni[1024];
    int num = 0;
    int nb_tx = 0;

    while(!quit) {
        struct rte_mbuf *buf[PACKET_READ_SIZE];
        uint16_t rx_count;

        rx_count = rte_eth_rx_burst(0, 0, buf, PACKET_READ_SIZE);
        if(likely(rx_count > 0)) 
            master_process_packets(0, buf, rx_count);
        else {
            rte_kni_tx_burst(kni,NULL , 0); 
            rte_kni_handle_request(kni); 
        }

        num = rte_kni_rx_burst(kni, pkts_kni, 1024);
        if(num > 0) {
            nb_tx = rte_eth_tx_burst(0, 0, pkts_kni, (uint16_t)num);
            if(nb_tx < num)
                kni_burst_free_mbufs(&pkts_kni[nb_tx], num - nb_tx);
        }
    }
    return 0;
}

#define RTE_MP_RX_DESC_DEFAULT 512
#define RTE_MP_TX_DESC_DEFAULT 512

static inline int  
port_init(uint8_t port, struct rte_mempool *mbuf_pool)  
{  
    struct rte_eth_conf port_conf = port_conf_default;  
    const uint16_t rx_rings = 1, tx_rings = 1;  
    struct ether_addr addr;
    int retval;  
    uint16_t q;  

    if (port >= rte_eth_dev_count())  
        return -1;  

    /* Configure the Ethernet device. */  
    retval = rte_eth_dev_configure(port, rx_rings, tx_rings, &port_conf);  
    if (retval != 0)  
        return retval;  

    /* Allocate and set up 1 RX queue per Ethernet port. */  
    for (q = 0; q < rx_rings; q++) {  
        retval = rte_eth_rx_queue_setup(port, q, RX_RING_SIZE,  
            rte_eth_dev_socket_id(port), NULL, mbuf_pool);  
        if (retval < 0)  
            return retval;  
    }  

    /* Allocate and set up 1 TX queue per Ethernet port. */  
    for (q = 0; q < tx_rings; q++) {  
        retval = rte_eth_tx_queue_setup(port, q, TX_RING_SIZE,  
            rte_eth_dev_socket_id(port), NULL);  
        if (retval < 0)  
            return retval;  
    }  

    /* Start the Ethernet port. */  
    retval = rte_eth_dev_start(port);  
    if (retval < 0)  
        return retval;  

    /* Display the port MAC address. */  
    rte_eth_macaddr_get(port, &addr);  
    printf("Port %u MAC: %02" PRIx8 " %02" PRIx8 " %02" PRIx8  
        " %02" PRIx8 " %02" PRIx8 " %02" PRIx8 "\n",  
        (unsigned)port,  
        addr.addr_bytes[0], addr.addr_bytes[1],  
        addr.addr_bytes[2], addr.addr_bytes[3],  
        addr.addr_bytes[4], addr.addr_bytes[5]);  

    /* Enable RX in promiscuous mode for the Ethernet device. */  
    rte_eth_promiscuous_enable(port);  

    return 0;  
}  

int
main(int argc, char **argv)
{
    int ret;
    unsigned lcore_id;
    const unsigned flags = RING_F_SP_ENQ;
    struct rte_kni_conf conf;
    struct rte_eth_dev_info info;
    struct rte_kni_ops ops;

    ret = rte_eal_init(argc, argv);
    if (ret < 0)
        rte_panic("Cannot init EAL\n");

    pktmbuf_pool = rte_pktmbuf_pool_create("POOL_BUFF", 40960,
        250, 0,
        RTE_MBUF_DEFAULT_BUF_SIZE, rte_socket_id());

    if(port_init(0,  pktmbuf_pool) < 0)
        rte_exit(EXIT_FAILURE, "Error:port init\n");

    if(fdns_init() < 0)
        rte_exit(EXIT_FAILURE, "Error:fdns_init\n");


    rte_kni_init(1);
    memset(&conf, 0, sizeof(conf));
    memset(&info, 0, sizeof(info));
    memset(&ops, 0, sizeof(ops));

    rte_eth_dev_info_get(0, &info);
    conf.addr = info.pci_dev->addr;
    conf.id = info.pci_dev->id;
    snprintf(conf.name, sizeof(conf.name), "kni");

    /* core id 1 configured for kernel thread */
    conf.core_id = 0;
    conf.force_bind = 1;
    conf.mbuf_size = 512;
    conf.group_id = (uint16_t)0;

    ops = kni_ops;
    ops.port_id = 0;

    /* basic test of kni processing */
    kni = rte_kni_alloc(pktmbuf_pool, &conf, &ops);
    if (!kni) {
        printf("fail to create kni\n");
        return -1;
    }

    rte_delay_ms(1000);
    if(system("ifconfig" " kni" " mtu" " 1450") == -1) {
        printf("error mtu\n"); 
    }

    recv_ring = rte_ring_create(_SEC_2_PRI, RX_RING_SIZE, rte_socket_id(), flags);

    /* call lcore_hello() on every slave lcore */
    RTE_LCORE_FOREACH_SLAVE(lcore_id) {
        fdns_slave(lcore_id);
        rte_eal_remote_launch(lcore_slave, NULL, lcore_id);
    }

    /* call it on master lcore too */
    if (system("ifconfig" " kni" " up") == -1)
        printf("up error\n");
    lcore_master(NULL);

    rte_eal_mp_wait_lcore();
    return 0;
}
