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

/* memchr( const void *, int, size_t ) */

#include <string.h>

#ifndef REGTEST

void * memchr( const void * s, int c, size_t n )
{
    const unsigned char * p = ( const unsigned char * ) s;

    while ( n-- )
    {
        if ( *p == ( unsigned char ) c )
        {
            return ( void * ) p;
        }

        ++p;
    }

    return NULL;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( memchr( abcde, 'c', 5 ) == &abcde[2] );
    TESTCASE( memchr( abcde, 'a', 1 ) == &abcde[0] );
    TESTCASE( memchr( abcde, 'a', 0 ) == NULL );
    TESTCASE( memchr( abcde, '\0', 5 ) == NULL );
    TESTCASE( memchr( abcde, '\0', 6 ) == &abcde[5] );
    return TEST_RESULTS;
}

#endif
