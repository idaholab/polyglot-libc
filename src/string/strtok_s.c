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

/* strtok_s( char *, rsize_t *, const char *, char ** ) */

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>

#ifndef REGTEST

char * strtok_s( char * _PDCLIB_restrict s1, rsize_t * _PDCLIB_restrict s1max, const char * _PDCLIB_restrict s2, char ** _PDCLIB_restrict ptr )
{
    return _PDCLIB_strtok( s1, s1max, s2, ptr );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#if ! defined( REGTEST ) || defined( __STDC_LIB_EXT1__ )
    char s[] = "_a_bc__d_";
    char str1[] = "?a???b,,,#c";
    char str2[] = "\t \t";
    rsize_t max = sizeof( s );
    rsize_t max1 = sizeof( str1 );
    rsize_t max2 = sizeof( str2 );
    char * p;
    char * ptr1;
    char * ptr2;

    TESTCASE( _PDCLIB_strtok( s, &max, "_", &p ) == &s[1] );
    TESTCASE( s[1] == 'a' );
    TESTCASE( s[2] == '\0' );
    TESTCASE( _PDCLIB_strtok( NULL, &max, "_", &p ) == &s[3] );
    TESTCASE( s[3] == 'b' );
    TESTCASE( s[4] == 'c' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( _PDCLIB_strtok( NULL, &max, "_", &p ) == &s[7] );
    TESTCASE( s[6] == '_' );
    TESTCASE( s[7] == 'd' );
    TESTCASE( s[8] == '\0' );
    TESTCASE( _PDCLIB_strtok( NULL, &max, "_", &p ) == NULL );
    strcpy( s, "ab_cd" );
    max = strlen( s );
    TESTCASE( _PDCLIB_strtok( s, &max, "_", &p ) == &s[0] );
    TESTCASE( s[0] == 'a' );
    TESTCASE( s[1] == 'b' );
    TESTCASE( s[2] == '\0' );
    TESTCASE( _PDCLIB_strtok( NULL, &max, "_", &p ) == &s[3] );
    TESTCASE( s[3] == 'c' );
    TESTCASE( s[4] == 'd' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( _PDCLIB_strtok( NULL, &max, "_", &p ) == NULL );

    TESTCASE( _PDCLIB_strtok( str1, &max1, "?", &ptr1 ) == &str1[1] );
    TESTCASE( _PDCLIB_strtok( NULL, &max1, ",", &ptr1 ) == &str1[3] );
    TESTCASE( _PDCLIB_strtok( str2, &max2, " \t", &ptr2 ) == NULL );
    TESTCASE( _PDCLIB_strtok( NULL, &max1, "#,", &ptr1 ) == &str1[10] );
    TESTCASE( _PDCLIB_strtok( NULL, &max1, "?", &ptr1 ) == NULL );
#else
    /* Most libraries do not implement this function. */
    TESTCASE( NO_TESTDRIVER );
#endif
    return TEST_RESULTS;
}

#endif
