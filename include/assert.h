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

/* Diagnostics <assert.h> */

#ifdef __cplusplus
extern "C" {
#endif

#include "pdclib/_PDCLIB_config.h"

#ifndef _PDCLIB_ASSERT_H
#define _PDCLIB_ASSERT_H _PDCLIB_ASSERT_H
_PDCLIB_PUBLIC void _PDCLIB_assert99( const char * const, const char * const, const char * const );
_PDCLIB_PUBLIC void _PDCLIB_assert89( const char * const );
#endif

/* If NDEBUG is set, assert() is a null operation. */
#undef assert

/* XXX: Okay, so for whatever ... reason, this doesn't actually include
 * _PDCLIB_int.h, which is where the original of these macros are defined, but
 * then uses them?! So we copied them in here and renamed them a little... */
#define _PDCLIB_assert_symbol2string( x ) #x
#define _PDCLIB_assert_value2string( x ) _PDCLIB_assert_symbol2string( x )

#ifdef NDEBUG
#define assert( ignore ) ( (void) 0 )
#else
#if __STDC_VERSION__ >= 199901L
#define assert( expression ) ( ( expression ) ? (void) 0 \
        : _PDCLIB_assert99( "Assertion failed: " #expression \
                            ", function ", __func__, \
                            ", file " __FILE__ \
                            ", line " _PDCLIB_assert_value2string( __LINE__ ) \
                            "." _PDCLIB_endl ) )
#else
#define assert( expression ) ( ( expression ) ? (void) 0 \
        : _PDCLIB_assert89( "Assertion failed: " #expression \
                            ", file " __FILE__ \
                            ", line " _PDCLIB_assert_value2string( __LINE__ ) \
                            "." _PDCLIB_endl ) )
#endif
#endif

/* Extension hook for downstream projects that want to have non-standard
   extensions to standard headers.
*/
#ifdef _PDCLIB_EXTEND_ASSERT_H
#include _PDCLIB_EXTEND_ASSERT_H
#endif

#ifdef __cplusplus
}
#endif
