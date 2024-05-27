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

/* strrchr( const char *, int ) */

#include <string.h>

#ifndef REGTEST

char * strrchr( const char * s, int c )
{
    size_t i = 0;

    while ( s[i++] )
    {
        /* EMPTY */
    }

    do
    {
        if ( s[--i] == ( char ) c )
        {
            return ( char * ) s + i;
        }
    } while ( i );

    return NULL;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    char abccd[] = "abccd";
    TESTCASE( strrchr( abcde, '\0' ) == &abcde[5] );
    TESTCASE( strrchr( abcde, 'e' ) == &abcde[4] );
    TESTCASE( strrchr( abcde, 'a' ) == &abcde[0] );
    TESTCASE( strrchr( abccd, 'c' ) == &abccd[3] );
    return TEST_RESULTS;
}

#endif
