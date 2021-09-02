#ifndef UIP_NEWIP_H
#define UIP_NEWIP_H

#include "net/ip/uipopt.h"
#include "net/ipv4/uip.h"

#include <string.h>

#define UIP_NEWIP_MAX_LEVEL 4
#define UIP_NEWIP_BUFSIZE 1500

typedef struct uip_nipaddr_level {
    uint8_t current_level;
    union   top_addr{
        uint8_t u8[2];
        uint16_t u16;
    } current_addr;
};
typedef struct uip_nipaddr_t {
    uint8_t level;
    //TODO(zhaotinghai): 变长数组
    uip_nipaddr_level v[UIP_NEWIP_MAX_LEVEL];
};

#include "net/ip/tcpip.h"

#define uip_newip_sethostaddr(addr) uip_newipaddr_copy(&uip_nip_hostaddr, (addr))

#define uip_newip_gethostaddr(addr) uip_newipaddr_copy((addr), &uip_nip_hostaddr)

void uip_newip_init(void);

#define uip_newip_input()  uip_newip_process(UIP_NEWIP_DATA)

#define uip_newip_udp_periodic(conn) do {   uip_newip_udp_conn = &uip_newip_udp_conns[conn]; \   
    uip_newip_process(UIP_NEWIP_UDP_TIMER);} while(0)

#define uip_newip_udp_periodic(conn) do { uip_newip_udp_conn = conn;    \
    uip_newip_process(UIP_NEWIP_UDP_TIMER); } while(0)

typedef union {
    uint8_t u8[UIP_NEWIP_BUFSIZE];
} uip_newip_buf_t;

void uip_newip_unlisten(uint16_t port);

void uip_newip_listen(uint16_t port);

struct uip_newip_conn *uip_newip_connect(const uip_nipaddr_t *ripaddr, uint16_t port);

void uip_newip_send(const void *data, int len);




