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

/* bsearch( const void *, const void *, size_t, size_t, int(*)( const void *, const void * ) ) */

#include <stdlib.h>

#ifndef REGTEST

void * bsearch( const void * key, const void * base, size_t nmemb, size_t size, int ( *compar )( const void *, const void * ) )
{
    const void * pivot;
    int rc;
    size_t corr;

    while ( nmemb )
    {
        /* algorithm needs -1 correction if remaining elements are an even number. */
        corr = nmemb % 2;
        nmemb /= 2;
        pivot = ( const char * )base + ( nmemb * size );
        rc = compar( key, pivot );

        if ( rc > 0 )
        {
            base = ( const char * )pivot + size;
            /* applying correction */
            nmemb -= ( 1 - corr );
        }
        else if ( rc == 0 )
        {
            return ( void * )pivot;
        }
    }

    return NULL;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

static int compare( const void * left, const void * right )
{
    return *( ( unsigned char * )left ) - *( ( unsigned char * )right );
}

int main( void )
{
    TESTCASE( bsearch( "e", abcde, 4, 1, compare ) == NULL );
    TESTCASE( bsearch( "e", abcde, 5, 1, compare ) == &abcde[4] );
    TESTCASE( bsearch( "a", abcde + 1, 4, 1, compare ) == NULL );
    TESTCASE( bsearch( "0", abcde, 1, 1, compare ) == NULL );
    TESTCASE( bsearch( "a", abcde, 1, 1, compare ) == &abcde[0] );
    TESTCASE( bsearch( "a", abcde, 0, 1, compare ) == NULL );
    TESTCASE( bsearch( "e", abcde, 3, 2, compare ) == &abcde[4] );
    TESTCASE( bsearch( "b", abcde, 3, 2, compare ) == NULL );
    return TEST_RESULTS;
}

#endif
