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

/* strncmp( const char *, const char *, size_t ) */

#include <string.h>

#ifndef REGTEST

int strncmp( const char * s1, const char * s2, size_t n )
{
    while ( n && *s1 && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
        --n;
    }

    if ( n == 0 )
    {
        return 0;
    }
    else
    {
        return ( *( unsigned char * )s1 - * ( unsigned char * )s2 );
    }
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    char cmpabcde[] = "abcde\0f";
    char cmpabcd_[] = "abcde\xfc";
    char empty[] = "";
    char x[] = "x";
    TESTCASE( strncmp( abcde, cmpabcde, 5 ) == 0 );
    TESTCASE( strncmp( abcde, cmpabcde, 10 ) == 0 );
    TESTCASE( strncmp( abcde, abcdx, 5 ) < 0 );
    TESTCASE( strncmp( abcdx, abcde, 5 ) > 0 );
    TESTCASE( strncmp( empty, abcde, 5 ) < 0 );
    TESTCASE( strncmp( abcde, empty, 5 ) > 0 );
    TESTCASE( strncmp( abcde, abcdx, 4 ) == 0 );
    TESTCASE( strncmp( abcde, x, 0 ) == 0 );
    TESTCASE( strncmp( abcde, x, 1 ) < 0 );
    TESTCASE( strncmp( abcde, cmpabcd_, 10 ) < 0 );
    return TEST_RESULTS;
}

#endif
