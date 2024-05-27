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

#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>


int __inet_pton_ipv4(const char *restrict src, void *restrict dst)
{
    const char *p = src;
    char *n;
    uint32_t v, addr = 0;

    v = strtol(p, &n, 0);
    if (*n == '.') {
        addr |= ((v & 0xff) << 24);
        p = n + 1;
    } else {
        return 0;
    }

    v = strtol(p, &n, 0);
    if (*n == '.') {
        addr |= ((v & 0xff) << 16);
        p = n + 1;
    } else {
        return 0;
    }

    v = strtol(p, &n, 0);
    if (*n == '.') {
        addr |= ((v & 0xff) << 8);
        p = n + 1;
    } else {
        return 0;
    }

    v = strtol(p, &n, 0);
    addr |= (v & 0xff);

    *((uint32_t *)dst) = htonl(addr);
    return 1;
}


#define NO_EXPAND 42

int __inet_pton_ipv6(const char * restrict src, void * restrict dst)
{
    char expand = NO_EXPAND, count = 0;
    unsigned short *parts = (unsigned short *)dst;
    const char *p = src, *e;

    // Handle leading '::' specially
    if ((p[0] == ':') && (p[1] == ':')) {
        expand = -1;
        p += 2;
    }

    for (int i = 0; i < 8; ++i) {
        if (!*p) {
            if (expand == NO_EXPAND) {
                return 0;
            } else {
                break;
            }
        }

        errno = 0;
        parts[i] = (unsigned short)strtol(p, (char **)&e, 16);
        if ((parts[i] == 0) && errno)
            return -1;
        parts[i] = htons(parts[i]);

        ++count;
        p = e;
        switch (p[0])
        {
        case ':':
            if (p[1] == ':') {
                expand = i;
                p += 2;
            } else {
                p += 1;
            }
        case 0:
            continue;
        default:
            return 0;
        }
    }

    // Decompress zeros
    if (expand != NO_EXPAND) {
        for (int i = 7, j = 7 - (8 - count); i > expand; --i, --j) {
            if (j > expand) {
                parts[i] = parts[j];
            } else {
                parts[i] = 0;
            }
        }
    }

    return 1;
}


int inet_pton(int af, const char *restrict src, void *restrict dst)
{
    switch (af)
    {
    case AF_INET:
        return __inet_pton_ipv4(src, dst);
    case AF_INET6:
        return __inet_pton_ipv6(src, dst);
    default:
        errno = EAFNOSUPPORT;
        return -1;
    }
}


