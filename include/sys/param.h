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

#if !defined(_SYS_PARAM_H)
#define _SYS_PARAM_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* This is a non-POSIX header, so what's expected in here is a little bit less
 * well-defined. So... we're adding definitions as we figure out we need them,
 * which probably _isn't_ the best approach, but... */

#define BIG_ENDIAN __ORDER_BIG_ENDIAN__
#define LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
#define BYTE_ORDER __BYTE_ORDER__

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_PARAM_H
