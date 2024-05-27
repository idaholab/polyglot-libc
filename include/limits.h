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

/* Sizes of integer types <limits.h> */

#ifndef _PDCLIB_LIMITS_H
#define _PDCLIB_LIMITS_H _PDCLIB_LIMITS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pdclib/_PDCLIB_int.h"

/* TODO: Defined to 1 as multibyte characters are not supported yet. */
#define MB_LEN_MAX 1

#define LLONG_MIN  _PDCLIB_LLONG_MIN
#define LLONG_MAX  _PDCLIB_LLONG_MAX
#define ULLONG_MAX _PDCLIB_ULLONG_MAX

#define CHAR_BIT   _PDCLIB_CHAR_BIT
#define CHAR_MAX   _PDCLIB_CHAR_MAX
#define CHAR_MIN   _PDCLIB_CHAR_MIN
#define SCHAR_MAX  _PDCLIB_SCHAR_MAX
#define SCHAR_MIN  _PDCLIB_SCHAR_MIN
#define UCHAR_MAX  _PDCLIB_UCHAR_MAX
#define SHRT_MAX   _PDCLIB_SHRT_MAX
#define SHRT_MIN   _PDCLIB_SHRT_MIN
#define INT_MAX    _PDCLIB_INT_MAX
#define INT_MIN    _PDCLIB_INT_MIN
#define LONG_MAX   _PDCLIB_LONG_MAX
#define LONG_MIN   _PDCLIB_LONG_MIN
#define USHRT_MAX  _PDCLIB_USHRT_MAX
#define UINT_MAX   _PDCLIB_UINT_MAX
#define ULONG_MAX  _PDCLIB_ULONG_MAX

/* Extension hook for downstream projects that want to have non-standard
   extensions to standard headers.
*/
#ifdef _PDCLIB_EXTEND_LIMITS_H
#include _PDCLIB_EXTEND_LIMITS_H
#endif

#ifdef __cplusplus
}
#endif

#endif
