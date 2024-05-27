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

/* memcpy_s( void *, rsize_t, const void *, rsize_t ) */

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef REGTEST

errno_t memcpy_s( void * _PDCLIB_restrict s1, rsize_t s1max, const void * _PDCLIB_restrict s2, rsize_t n )
{
    char * dest = ( char * ) s1;
    const char * src = ( const char * ) s2;

    if ( s1 != NULL && s2 != NULL && s1max <= RSIZE_MAX && n <= RSIZE_MAX && n <= s1max )
    {
        while ( n-- )
        {
            if ( dest == s2 || src == s1 )
            {
                goto runtime_constraint_violation;
            }

            *dest++ = *src++;
        }

        return 0;
    }

runtime_constraint_violation:

    if ( s1 != NULL && s1max <= RSIZE_MAX )
    {
        memset( s1, 0, s1max );
    }

    _PDCLIB_constraint_handler( _PDCLIB_CONSTRAINT_VIOLATION( _PDCLIB_EINVAL ) );
    return _PDCLIB_EINVAL;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#if ! defined( REGTEST ) || defined( __STDC_LIB_EXT1__ )

static int HANDLER_CALLS = 0;

static void test_handler( const char * _PDCLIB_restrict msg, void * _PDCLIB_restrict ptr, errno_t error )
{
    ++HANDLER_CALLS;
}

#endif

int main( void )
{
#if ! defined( REGTEST ) || defined( __STDC_LIB_EXT1__ )
    char s[] = "xxxxxxxxxxx";
    set_constraint_handler_s( test_handler );

    TESTCASE( memcpy_s( s, 11, abcde, 6 ) == 0 );
    TESTCASE( s[4] == 'e' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( memcpy_s( s + 5, 6, abcde, 5 ) == 0 );
    TESTCASE( s[9] == 'e' );
    TESTCASE( s[10] == 'x' );

    s[5] = 'x';

    TESTCASE( memcpy_s( s, 5, abcde, 6 ) != 0 );
    TESTCASE( memcmp( s, "\0\0\0\0\0x", 6 ) == 0 );

    TESTCASE( memcpy_s( s, 3, s + 2, 3 ) != 0 );
    TESTCASE( memcpy_s( s + 2, 3, s, 3 ) != 0 );

    /* Overlapping */
    TESTCASE( memcpy_s( s, 4, s + 3, 4 ) != 0 );
    TESTCASE( memcpy_s( s + 3, 4, s, 4 ) != 0 );

    TESTCASE( HANDLER_CALLS == 5 );
#endif
    return TEST_RESULTS;
}

#endif
