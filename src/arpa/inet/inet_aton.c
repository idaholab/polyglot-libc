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

#include <stdlib.h>
#include <arpa/inet.h>


int inet_aton(const char *cp, struct in_addr *pin)
{
    const char *p = cp;
    char *n;
    uint32_t v, addr = 0;

    v = strtol(p, &n, 0);
    if (*n == '.') {
        addr |= ((v & 0xff) << 24);
        p = n + 1;
    } else if (*n == 0) {
        addr |= (v & 0xffffffff);
        goto parsed;
    } else {
        return 0;
    }

    v = strtol(p, &n, 0);
    if (*n == '.') {
        addr |= ((v & 0xff) << 16);
        p = n + 1;
    } else if (*n == 0) {
        addr |= (v & 0xffffff);
        goto parsed;
    } else {
        return 0;
    }

    v = strtol(p, &n, 0);
    if (*n == '.') {
        addr |= ((v & 0xff) << 8);
        p = n + 1;
    } else if (*n == 0) {
        addr |= (v & 0xffff);
        goto parsed;
    } else {
        return 0;
    }

    v = strtol(p, &n, 0);
    if (*n == 0) {
        addr |= (v & 0xff);
        goto parsed;
    } else {
        return 0;
    }

parsed:
    pin->s_addr = htonl(addr);
    return 1;
}


in_addr_t inet_addr(const char *cp)
{
    struct in_addr addr;

    if (inet_aton(cp, &addr) == 1) {
        return addr.s_addr;
    } else {
        return -1;
    }
}


