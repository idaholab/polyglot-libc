/* This file is part of the Polyglot C Library.

   Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED

   The Polyglot C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the License,
   or (at your option) any later version.

   The Polyglot C library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
   for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library; if not, see <https://www.gnu.org/licenses/>. */

#ifndef _LINUX_IN_H
#define _LINUX_IN_H _LINUX_IN_H

#define __NEED_IPPROTOS 1
#define __NEED_IN_ADDR 1
#define __NEED_SOCKADDR_IN 1
#define __NEED_IPV6_OPTIONS 1
#define __NEED_IN6_ADDR 1
#define __NEED_SOCKADDR_IN6 1
#define __NEED_IPV6_MREQ 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(in.h))
#include __target_os_arch_header(in.h)
#endif

#include <sys/socket.h>

// pretty much by definition, these types are correct
typedef unsigned short      in_port_t;
typedef unsigned            in_addr_t;

// these should be these constants 100% of the time
#define INADDR_ANY          0x00000000
#define INADDR_BROADCAST    0xffffffff

#ifdef __NEED_IPPROTOS
#define IPPROTO_IP          0
#define IPPROTO_ICMP        1
#define IPPROTO_TCP         6
#define IPPROTO_UDP         17
#define IPPROTO_RAW         255
#define IPPROTO_IPV6        41
#endif

#ifdef __NEED_IN_ADDR
struct in_addr {
    in_addr_t               s_addr;
};
#endif

#ifdef __NEED_SOCKADDR_IN
struct sockaddr_in {
    union {
        struct {
            sa_family_t     sin_family;
            in_port_t       sin_port;
            struct in_addr  sin_addr;
        };
        char                __pad[16];
    };
};
#endif

#ifdef __NEED_IPV6_OPTIONS
#define IPV6_JOIN_GROUP     20
#define IPV6_LEAVE_GROUP    21
#define IPV6_MULTICAST_HOPS 18
#define IPV6_MULTICAST_IF   17
#define IPV6_MULTICAST_LOOP 19
#define IPV6_UNICAST_HOPS   16
#define IPV6_V6ONLY         26
#endif

#ifdef __NEED_IN6_ADDR
struct in6_addr {
    unsigned char           s6_addr[16];
};
#endif

#ifdef __NEED_SOCKADDR_IN6
struct sockaddr_in6 {
    sa_family_t             sin6_family;
    in_port_t               sin6_port;
    unsigned                sin6_flowinfo;
    struct in6_addr         sin6_addr;
    unsigned                sin6_scope_id;
};
#endif

#ifdef __NEED_IPV6_MREQ
struct ipv6_mreq {
    struct in6_addr         ipv6mr_multiaddr;
    unsigned                ipv6mr_interface;
};
#endif

#undef __NEED_IPPROTOS
#undef __NEED_IN_ADDR
#undef __NEED_SOCKADDR_IN
#undef __NEED_IPV6_OPTIONS
#undef __NEED_IN6_ADDR
#undef __NEED_SOCKADDR_IN6
#undef __NEED_IPV6_MREQ

#endif // _LINUX_IN_H
