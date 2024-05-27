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

/* strncat( char *, const char *, size_t ) */

#include <string.h>

#ifndef REGTEST

char * strncat( char * _PDCLIB_restrict s1, const char * _PDCLIB_restrict s2, size_t n )
{
    char * rc = s1;

    while ( *s1 )
    {
        ++s1;
    }

    while ( n && ( *s1++ = *s2++ ) )
    {
        --n;
    }

    if ( n == 0 )
    {
        *s1 = '\0';
    }

    return rc;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    char s[] = "xx\0xxxxxx";
    TESTCASE( strncat( s, abcde, 10 ) == s );
    TESTCASE( s[2] == 'a' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( s[7] == '\0' );
    TESTCASE( s[8] == 'x' );
    s[0] = '\0';
    TESTCASE( strncat( s, abcdx, 10 ) == s );
    TESTCASE( s[4] == 'x' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strncat( s, "\0", 10 ) == s );
    TESTCASE( s[5] == '\0' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( strncat( s, abcde, 0 ) == s );
    TESTCASE( s[5] == '\0' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( strncat( s, abcde, 3 ) == s );
    TESTCASE( s[5] == 'a' );
    TESTCASE( s[7] == 'c' );
    TESTCASE( s[8] == '\0' );
    return TEST_RESULTS;
}

#endif
