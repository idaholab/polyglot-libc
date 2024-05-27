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

/* Common definitions <stddef.h> */

#ifndef _PDCLIB_STDDEF_H
#define _PDCLIB_STDDEF_H _PDCLIB_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pdclib/_PDCLIB_lib_ext1.h"
#include "pdclib/_PDCLIB_int.h"

typedef _PDCLIB_ptrdiff_t ptrdiff_t;

#ifndef _PDCLIB_SIZE_T_DEFINED
#define _PDCLIB_SIZE_T_DEFINED _PDCLIB_SIZE_T_DEFINED
typedef _PDCLIB_size_t size_t;
#endif

#ifndef __cplusplus
typedef _PDCLIB_wchar_t   wchar_t;
#endif

#ifndef _PDCLIB_NULL_DEFINED
#define _PDCLIB_NULL_DEFINED _PDCLIB_NULL_DEFINED
#define NULL _PDCLIB_NULL
#endif

#define offsetof( type, member ) _PDCLIB_offsetof( type, member )

/* Annex K -- Bounds-checking interfaces */

#if ( __STDC_WANT_LIB_EXT1__ + 0 ) != 0
#ifndef _PDCLIB_RSIZE_T_DEFINED
#define _PDCLIB_RSIZE_T_DEFINED _PDCLIB_RSIZE_T_DEFINED
typedef size_t rsize_t;
#endif
#endif

/* Extension hook for downstream projects that want to have non-standard
   extensions to standard headers.
*/
#ifdef _PDCLIB_EXTEND_STDDEF_H
#include _PDCLIB_EXTEND_STDDEF_H
#endif

#ifdef __cplusplus
}
#endif

#endif
