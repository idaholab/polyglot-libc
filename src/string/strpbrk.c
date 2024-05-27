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

/* strpbrk( const char *, const char * ) */

#include <string.h>

#ifndef REGTEST

char * strpbrk( const char * s1, const char * s2 )
{
    const char * p1 = s1;
    const char * p2;

    while ( *p1 )
    {
        p2 = s2;

        while ( *p2 )
        {
            if ( *p1 == *p2++ )
            {
                return ( char * ) p1;
            }
        }

        ++p1;
    }

    return NULL;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( strpbrk( abcde, "x" ) == NULL );
    TESTCASE( strpbrk( abcde, "xyz" ) == NULL );
    TESTCASE( strpbrk( abcdx, "x" ) == &abcdx[4] );
    TESTCASE( strpbrk( abcdx, "xyz" ) == &abcdx[4] );
    TESTCASE( strpbrk( abcdx, "zyx" ) == &abcdx[4] );
    TESTCASE( strpbrk( abcde, "a" ) == &abcde[0] );
    TESTCASE( strpbrk( abcde, "abc" ) == &abcde[0] );
    TESTCASE( strpbrk( abcde, "cba" ) == &abcde[0] );
    return TEST_RESULTS;
}

#endif
