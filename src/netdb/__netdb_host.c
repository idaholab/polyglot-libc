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


char __netdb_host_buf[__NETDB_HOST_BUF_LEN];
char __netdb_host_addrs[__NETDB_HOST_ADDR_COUNT][sizeof(struct in6_addr)];
struct hostent __netdb_host_ent;
int __netdb_host_stayopen = 0;

#if defined(__NETDB_HOST_PATH)
int __netdb_host_file_exists = 1;
FILE *__netdb_host_fd = NULL;
#endif


const struct hostent __netdb_host_list[] = {
    { "localhost", { NULL }, AF_INET, 4, { "\x7f\x00\x00\x01", NULL } },
    { NULL, { NULL }, 0, 0, { NULL } },
};
const struct hostent *__netdb_host_list_ptr = NULL;


void __netdb_host_openfile()
{
#if defined(__NETDB_HOST_PATH)
    if (!__netdb_host_fd && !__netdb_host_list_ptr) {
        if (__netdb_host_file_exists) {
            __netdb_host_fd = fopen(__NETDB_HOST_PATH, "r");
            __netdb_host_file_exists = (__netdb_host_fd != NULL);
        }
        if (__netdb_host_file_exists) {
            rewind(__netdb_host_fd);
        } else {
            __netdb_host_list_ptr = __netdb_host_list;
        }
    }
#else
    if (!__netdb_host_list_ptr) {
        __netdb_host_list_ptr = __netdb_host_list;
    }
#endif
}


