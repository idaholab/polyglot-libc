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

/* memcmp( const void *, const void *, size_t ) */

#include <string.h>

#ifndef REGTEST

int memcmp( const void * s1, const void * s2, size_t n )
{
    const unsigned char * p1 = ( const unsigned char * ) s1;
    const unsigned char * p2 = ( const unsigned char * ) s2;

    while ( n-- )
    {
        if ( *p1 != *p2 )
        {
            return *p1 - *p2;
        }

        ++p1;
        ++p2;
    }

    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    const char xxxxx[] = "xxxxx";
    TESTCASE( memcmp( abcde, abcdx, 5 ) < 0 );
    TESTCASE( memcmp( abcde, abcdx, 4 ) == 0 );
    TESTCASE( memcmp( abcde, xxxxx, 0 ) == 0 );
    TESTCASE( memcmp( xxxxx, abcde, 1 ) > 0 );
    return 0;
}

#endif
