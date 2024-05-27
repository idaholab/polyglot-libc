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


char __netdb_serv_buf[__NETDB_SERV_BUF_LEN];
struct servent __netdb_serv_ent;
int __netdb_serv_stayopen = 0;

#if defined(__NETDB_SERV_PATH)
int __netdb_serv_file_exists = 1;
FILE *__netdb_serv_fd = NULL;
#endif


const struct servent __netdb_serv_list[] = {
    { "tcpmux",         { NULL          },  1,      "tcp"   },
    { "tcpmux",         { NULL          },  1,      "udp"   },
    { "echo",           { NULL          },  7,      "tcp"   },
    { "echo",           { NULL          },  7,      "udp"   },
    { "discard",        { NULL          },  9,      "tcp"   },
    { "discard",        { NULL          },  9,      "udp"   },
    { "ftp-data",       { NULL          },  20,     "tcp"   },
    { "ftp-data",       { NULL          },  20,     "udp"   },
    { "ftp",            { NULL          },  21,     "tcp"   },
    { "ftp",            { NULL          },  21,     "udp"   },
    { "ssh",            { NULL          },  22,     "tcp"   },
    { "ssh",            { NULL          },  22,     "udp"   },
    { "telnet",         { NULL          },  23,     "tcp"   },
    { "telnet",         { NULL          },  23,     "udp"   },
    { "domain",         { NULL          },  53,     "tcp"   },
    { "domain",         { NULL          },  53,     "udp"   },
    { "bootps",         { NULL          },  67,     "tcp"   },
    { "bootps",         { NULL          },  67,     "udp"   },
    { "bootpc",         { NULL          },  68,     "tcp"   },
    { "bootpc",         { NULL          },  68,     "udp"   },
    { "tftp",           { NULL          },  69,     "tcp"   },
    { "tftp",           { NULL          },  69,     "udp"   },
    { "http",           { NULL          },  80,     "tcp"   },
    { "http",           { NULL          },  80,     "udp"   },
    { "sftp",           { NULL          },  115,    "tcp"   },
    { "sftp",           { NULL          },  115,    "udp"   },
    { "ntp",            { NULL          },  123,    "tcp"   },
    { "ntp",            { NULL          },  123,    "udp"   },
    { "https",          { NULL          },  443,    "tcp"   },
    { "https",          { NULL          },  443,    "udp"   },
    { "dhcpv6-client",  { NULL          },  546,    "tcp"   },
    { "dhcpv6-client",  { NULL          },  546,    "udp"   },
    { "dhcpv6-server",  { NULL          },  547,    "tcp"   },
    { "dhcpv6-server",  { NULL          },  547,    "udp"   },
    { NULL,             { NULL          },  -1,     NULL    },
};
const struct servent *__netdb_serv_list_ptr = NULL;


void __netdb_serv_openfile()
{
#if defined(__NETDB_SERV_PATH)
    if (!__netdb_serv_fd && !__netdb_serv_list_ptr) {
        if (__netdb_serv_file_exists) {
            __netdb_serv_fd = fopen(__NETDB_SERV_PATH, "r");
            __netdb_serv_file_exists = (__netdb_serv_fd != NULL);
        }
        if (__netdb_serv_file_exists) {
            rewind(__netdb_serv_fd);
        } else {
            __netdb_serv_list_ptr = __netdb_serv_list;
        }
    }
#else
    if (!__netdb_serv_list_ptr) {
        __netdb_serv_list_ptr = __netdb_serv_list;
    }
#endif
}


