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

/* strcat_s( char *, rsize_t, const char * ) */

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef REGTEST

errno_t strcat_s( char * _PDCLIB_restrict s1, rsize_t s1max, const char * _PDCLIB_restrict s2 )
{
    char * dest = s1;
    const char * src = s2;

    if ( s1 != NULL && s2 != NULL && s1max <= RSIZE_MAX && s1max != 0 )
    {
        while ( *dest )
        {
            if ( s1max-- == 0 || dest++ == s2 )
            {
                goto runtime_constraint_violation;
            }
        }

        do
        {
            if ( s1max-- == 0 || dest == s2 || src == s1 )
            {
                goto runtime_constraint_violation;
            }
        } while ( ( *dest++ = *src++ ) );

        return 0;
    }

runtime_constraint_violation:

    if ( s1 != NULL && s1max > 0 && s1max <= RSIZE_MAX )
    {
        s1[0] = '\0';
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
    char s[] = "xx\0xxxxxx";
    set_constraint_handler_s( test_handler );

    TESTCASE( strcat_s( s, 10, abcde ) == 0 );
    TESTCASE( s[2] == 'a' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( s[7] == '\0' );
    TESTCASE( s[8] == 'x' );
    s[0] = '\0';
    TESTCASE( strcat_s( s, 10, abcdx ) == 0 );
    TESTCASE( s[4] == 'x' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strcat_s( s, 10, "\0" ) == 0 );
    TESTCASE( s[5] == '\0' );
    TESTCASE( s[6] == 'e' );

    TESTCASE( strcat_s( s, 6, "" ) == 0 );
    TESTCASE( strcat_s( s, 5, "" ) != 0 );
    TESTCASE( strcat_s( s, 7, "x" ) == 0 );
    TESTCASE( s[5] == 'x' );
    TESTCASE( s[6] == '\0' );

    /* Overlapping */
    TESTCASE( strcat_s( s, 7, s + 6 ) != 0 );
    s[3] = '\0';
    TESTCASE( strcat_s( s + 3, 4, s ) != 0 );

    TESTCASE( HANDLER_CALLS == 3 );
#endif
    return TEST_RESULTS;
}

#endif
