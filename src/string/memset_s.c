/* This file is part of the Polyglot C Library. It originates from the Public
   Domain C Library (PDCLib).

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

#define __STDC_WANT_LIB_EXT1__ 1

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <param.h>
#include <stdint.h>


errno_t memset_s(void *s, rsize_t smax, int c, rsize_t n)
{
    if (s == NULL)
        return EINVAL;
    if (smax > RSIZE_MAX)
        return E2BIG;

    for (rsize_t i = 0; i < MIN(rsize_t, smax, n); ++i) {
        ((unsigned char *)s)[i] = (unsigned char)c;
    }

    if (n > RSIZE_MAX)
        return E2BIG;
    if (n > smax)
        return EOVERFLOW;

    return 0;
}


