/*
 * Copyright (c) 2005, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef CONTIKI_NET_H_
#define CONTIKI_NET_H_

#include "contiki.h"                    //contiki系统相关

#include "net/ip/tcpip.h"               //tcpip相关
#include "net/ip/uip.h"                 //uip相关
#include "net/ipv4/uip-fw.h"            //fw相关
#include "net/ipv4/uip-fw-drv.h"        //drv相关    
#include "net/ipv4/uip_arp.h"           //arp相关
#include "net/ip/uiplib.h"              //uiplib库
#include "net/ip/uip-udp-packet.h"      //uip数据包
#include "net/ip/simple-udp.h"          //udp相关
#include "net/ip/uip-nameserver.h"      //域名服务器
//IPV6网络协议栈配置
#if NETSTACK_CONF_WITH_IPV6
#include "net/ipv6/uip-icmp6.h"         //icmp6
#include "net/ipv6/uip-ds6.h"           //ds6
#endif /* NETSTACK_CONF_WITH_IPV6 */

#include "net/ip/resolv.h"              //resolv

#include "net/ip/psock.h"               //psock

#include "net/ip/udp-socket.h"          //udp通信相关库
#include "net/ip/tcp-socket.h"          //tcp通信相关库

#include "net/rime/rime.h"              //rime协议

#include "net/netstack.h"               //网络堆栈

#endif /* CONTIKI_NET_H_ */
