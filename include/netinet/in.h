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

#if !defined(_NETINET_IN_H)
#define _NETINET_IN_H 1

/* INCLUDES *******************************************************************/

#include <inttypes.h>
#include <sys/socket.h>
#include <target/in.h>

/* MACRO DEFINITIONS **********************************************************/

#define INADDR_NONE ((unsigned long int)0xffffffff)
#define INADDR_LOOPBACK ((unsigned long int)0x7f000001)

#define IN6ADDR_ANY_INIT \
    { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } }
#define IN6ADDR_LOOPBACK_INIT \
    { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } }

#define IN6_IS_ADDR_UNSPECIFIED(a) \
    ( \
        (((const uint32_t*)(a))[0] == 0) && \
        (((const uint32_t*)(a))[1] == 0) && \
        (((const uint32_t*)(a))[2] == 0) && \
        (((const uint32_t*)(a))[3] == 0) \
    )
#define IN6_ARE_ADDR_EQUAL(a, b) \
    ( \
        (((const uint32_t*)(a))[0] == ((const uint32_t*)(b))[0]) && \
        (((const uint32_t*)(a))[1] == ((const uint32_t*)(b))[1]) && \
        (((const uint32_t*)(a))[2] == ((const uint32_t*)(b))[2]) && \
        (((const uint32_t*)(a))[3] == ((const uint32_t*)(b))[3]) \
    )
#define IN6_IS_ADDR_MULTICAST(a) \
    ( \
        ((const uint8_t *)(a))[0] == 0xff \
    )

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

#define IN6_IS_ADDR_LOOPBACK(a) \
    ( \
        (((const uint32_t*)(a))[0] == 0) && \
        (((const uint32_t*)(a))[1] == 0) && \
        (((const uint32_t*)(a))[2] == 0) && \
        (((const uint32_t*)(a))[3] == 0x01000000u) \
    )
#define IN6_IS_ADDR_LINKLOCAL(a) \
    ( \
        (((const uint32_t*)(a))[0] & 0x0000c0ffu) == 0x000080feu \
    )
#define IN6_IS_ADDR_SITELOCAL(a) \
    ( \
        (((const uint32_t*)(a))[0] & 0x0000c0ffu) == 0x0000c0feu \
    )
#define IN6_IS_ADDR_V4MAPPED(a) \
    ( \
        (((const uint32_t*)(a))[0] == 0) && \
        (((const uint32_t*)(a))[1] == 0) && \
        (((const uint32_t*)(a))[2] == 0xffff0000u) \
    )
#define IN6_IS_ADDR_V4COMPAT(a) \
    ( \
        (((const uint32_t*)(a))[0] == 0) && \
        (((const uint32_t*)(a))[1] == 0) && \
        (((const uint32_t*)(a))[2] == 0) && \
        (((const uint32_t*)(a))[3] != 0x00000000u) && \
        (((const uint32_t*)(a))[3] != 0x01000000u) \
    )

#else // __ORDER_LITTLE_ENDIAN__

#define IN6_IS_ADDR_LOOPBACK(a) \
    ( \
        (((const uint32_t*)(a))[0] == 0) && \
        (((const uint32_t*)(a))[1] == 0) && \
        (((const uint32_t*)(a))[2] == 0) && \
        (((const uint32_t*)(a))[3] == 0x00000001u) \
    )
#define IN6_IS_ADDR_LINKLOCAL(a) \
    ( \
        (((const uint32_t*)(a))[0] & 0xffc00000u) == 0xfe800000u \
    )
#define IN6_IS_ADDR_SITELOCAL(a) \
    ( \
        (((const uint32_t*)(a))[0] & 0xffc00000u) == 0xfec00000u \
    )
#define IN6_IS_ADDR_V4MAPPED(a) \
    ( \
        (((const uint32_t*)(a))[0] == 0) && \
        (((const uint32_t*)(a))[1] == 0) && \
        (((const uint32_t*)(a))[2] == 0x0000ffffu) \
    )
#define IN6_IS_ADDR_V4COMPAT(a) \
    ( \
        (((const uint32_t*)(a))[0] == 0) && \
        (((const uint32_t*)(a))[1] == 0) && \
        (((const uint32_t*)(a))[2] == 0) && \
        (((const uint32_t*)(a))[3] != 0x00000000u) && \
        (((const uint32_t*)(a))[3] != 0x00000001u) \
    )

#endif // __ORDER_LITTLE_ENDIAN__

/* VARIABLE DEFINITIONS *******************************************************/

extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;

/* ADDITIONAL INCLUDES ********************************************************/

#include <arpa/inet.h>

/******************************************************************************/

#endif // _NETINET_IN_H
