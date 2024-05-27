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

/* strspn( const char *, const char * ) */

#include <string.h>

#ifndef REGTEST

size_t strspn( const char * s1, const char * s2 )
{
    size_t len = 0;
    const char * p;

    while ( s1[ len ] )
    {
        p = s2;

        while ( *p )
        {
            if ( s1[len] == *p )
            {
                break;
            }

            ++p;
        }

        if ( ! *p )
        {
            return len;
        }

        ++len;
    }

    return len;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( strspn( abcde, "abc" ) == 3 );
    TESTCASE( strspn( abcde, "b" ) == 0 );
    TESTCASE( strspn( abcde, abcde ) == 5 );
    return TEST_RESULTS;
}

#endif
