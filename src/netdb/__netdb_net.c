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


char __netdb_net_buf[__NETDB_NET_BUF_LEN];
struct netent __netdb_net_ent;
int __netdb_net_stayopen = 0;

#if defined(__NETDB_NET_PATH)
int __netdb_net_file_exists = 1;
FILE *__netdb_net_fd = NULL;
#endif


const struct netent __netdb_net_list[] = {
    { "loopback", { NULL }, AF_INET, 0x7f000000 },
    { NULL, { NULL }, 0, 0 },
};
const struct netent *__netdb_net_list_ptr = NULL;


void __netdb_net_openfile()
{
#if defined(__NETDB_NET_PATH)
    if (!__netdb_net_fd && !__netdb_net_list_ptr) {
        if (__netdb_net_file_exists) {
            __netdb_net_fd = fopen(__NETDB_NET_PATH, "r");
            __netdb_net_file_exists = (__netdb_net_fd != NULL);
        }
        if (__netdb_net_file_exists) {
            rewind(__netdb_net_fd);
        } else {
            __netdb_net_list_ptr = __netdb_net_list;
        }
    }
#else
    if (!__netdb_net_list_ptr) {
        __netdb_net_list_ptr = __netdb_net_list;
    }
#endif
}


