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

#include <netdb.h>


char __netdb_proto_buf[__NETDB_PROTO_BUF_LEN];
struct protoent __netdb_proto_ent;
int __netdb_proto_stayopen = 0;

#if defined(__NETDB_PROTO_PATH)
int __netdb_proto_file_exists = 1;
FILE *__netdb_proto_fd = NULL;
#endif


const struct protoent __netdb_proto_list[] = {
    { "ip",     { "IP",     NULL }, IPPROTO_IP      },
    { "icmp",   { "ICMP",   NULL }, IPPROTO_ICMP    },
    { "tcp",    { "TCP",    NULL }, IPPROTO_TCP     },
    { "udp",    { "UDP",    NULL }, IPPROTO_UDP     },
    { "ipv6",   { "IPv6",   NULL }, IPPROTO_IPV6    },
    { NULL,     { NULL           }, -1              },
};
const struct protoent *__netdb_proto_list_ptr = NULL;


void __netdb_proto_openfile()
{
#if defined(__NETDB_PROTO_PATH)
    if (!__netdb_proto_fd && !__netdb_proto_list_ptr) {
        if (__netdb_proto_file_exists) {
            __netdb_proto_fd = fopen(__NETDB_PROTO_PATH, "r");
            __netdb_proto_file_exists = (__netdb_proto_fd != NULL);
        }
        if (__netdb_proto_file_exists) {
            rewind(__netdb_proto_fd);
        } else {
            __netdb_proto_list_ptr = __netdb_proto_list;
        }
    }
#else
    if (!__netdb_proto_list_ptr) {
        __netdb_proto_list_ptr = __netdb_proto_list;
    }
#endif
}


