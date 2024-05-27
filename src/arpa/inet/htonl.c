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

#include <inttypes.h>

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

uint32_t htonl(uint32_t n)
{
    return ((n & 0xff) << 24)
           | (((n >> 8) & 0xff) << 16)
           | (((n >> 16) & 0xff) << 8)
           | (n >> 24);
}

uint32_t ntohl(uint32_t n)
{
    return htonl(n);
}

#else

uint32_t htonl(uint32_t n)
{
    return n;
}

uint32_t ntohl(uint32_t n)
{
    return n;
}

#endif

