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

#if !defined(_STDINT_EXT_H)
#define _STDINT_EXT_H 1

#ifdef __cplusplus
extern "C" {
#endif

#if (__SIZEOF_SIZE_T__ == 4)
#define SSIZE_MAX __INT32_MAX__
#elif (__SIZEOF_SIZE_T__ == 8)
#define SSIZE_MAX __INT64_MAX__
#else
#error "Unhandled ssize_t size."
#endif

#ifdef __cplusplus
} // extern C
#endif

#endif // _STDINT_EXT_H
