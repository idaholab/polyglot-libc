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
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


const char *__inet_ntop_ipv4(const void *restrict src, char *restrict dst,
                socklen_t size)
{
    const char *in = (const char *)src;

    if (size < INET_ADDRSTRLEN) {
        errno = ENOSPC;
        return NULL;
    }
    snprintf(
        dst, size,
        // FIXME: apparently hh* is broken, fix it.  See Polyglot issue
        // #22 - Arch: x86_64-linux-elf: 'h' format string
        //
        // "%hhu.%hhu.%hhu.%hhu",
        "%u.%u.%u.%u",
        (unsigned)in[0] & 0xff,
        (unsigned)in[1] & 0xff,
        (unsigned)in[2] & 0xff,
        (unsigned)in[3] & 0xff
    );
    return dst;
}


const char *__inet_ntop_ipv6(const void * restrict src, char * restrict dst,
                socklen_t size)
{
    int zidx = -1, zlen = -1, tlen;
    unsigned short *parts = (unsigned short *)src;
    char *ptr = dst;
    socklen_t remain = size;
    size_t c;

    if (size < INET6_ADDRSTRLEN) {
        errno = ENOSPC;
        return NULL;
    }

    // Find the longest string of zero segments in the address
    for (int i = 0; i < 8; ++i) {
        if (parts[i] == 0) {
            tlen = 1;
            for (int j = i + 1; j < 8; ++j) {
                if (parts[j] == 0) {
                    ++tlen;
                } else {
                    break;
                }
            }
            if ((tlen > 1) && (tlen > zlen)) {
                zidx = i;
                zlen = tlen;
            }
            i += tlen - 1;
        }
    }

    // Print the address into our buffer, skipping the zero chunk found above
    for (int i = 0; i < 8; ++i) {
        if (i == zidx) {
            c = snprintf(ptr, remain, ":");
            remain -= c;
            ptr += c;
            i += zlen;
        }
        if (i != 0) {
            c = snprintf(ptr, remain, ":");
            remain -= c;
            ptr += c;
        }
        if (i >= 8)
            break;

        c = snprintf(ptr, remain, "%hx", ntohs(parts[i]));
        remain -= c;
        ptr += c;
    }

    return dst;
}


const char *inet_ntop(int af, const void *restrict src, char *restrict dst,
                socklen_t size)
{
    switch (af)
    {
    case AF_INET:
        return __inet_ntop_ipv4(src, dst, size);
    case AF_INET6:
        return __inet_ntop_ipv6(src, dst, size);
    default:
        errno = EAFNOSUPPORT;
        return NULL;
    }
}


