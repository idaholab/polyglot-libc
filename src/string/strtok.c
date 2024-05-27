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

/* strtok( char *, const char * ) */

#ifndef REGTEST
#define __STDC_WANT_LIB_EXT1__ 1
#endif

#include <string.h>

#ifndef REGTEST

char * strtok( char * _PDCLIB_restrict s1, const char * _PDCLIB_restrict s2 )
{
    static char * tmp = NULL;
    static rsize_t max;

    if ( s1 != NULL )
    {
        /* new string */
        tmp = s1;
        max = strlen( tmp );
    }

    return _PDCLIB_strtok( s1, &max, s2, &tmp );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    char s[] = "_a_bc__d_";
    TESTCASE( strtok( s, "_" ) == &s[1] );
    TESTCASE( s[1] == 'a' );
    TESTCASE( s[2] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == &s[3] );
    TESTCASE( s[3] == 'b' );
    TESTCASE( s[4] == 'c' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == &s[7] );
    TESTCASE( s[6] == '_' );
    TESTCASE( s[7] == 'd' );
    TESTCASE( s[8] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == NULL );
    strcpy( s, "ab_cd" );
    TESTCASE( strtok( s, "_" ) == &s[0] );
    TESTCASE( s[0] == 'a' );
    TESTCASE( s[1] == 'b' );
    TESTCASE( s[2] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == &s[3] );
    TESTCASE( s[3] == 'c' );
    TESTCASE( s[4] == 'd' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == NULL );
    return TEST_RESULTS;
}

#endif
