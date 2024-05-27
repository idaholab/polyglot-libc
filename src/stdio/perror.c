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

/* perror( const char * ) */

#include <stdio.h>
#include <errno.h>
#include <locale.h>

#ifndef REGTEST

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

void perror( const char * s )
{
    _PDCLIB_LOCK( stderr->mtx );

    if ( ( s != NULL ) && ( s[0] != '\n' ) )
    {
        fprintf( stderr, "%s: ", s );
    }
    fprintf( stderr, "%s\n", _PDCLIB_lc_message( errno ) );

    _PDCLIB_UNLOCK( stderr->mtx );
    return;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main( void )
{
    FILE * fh;
    unsigned long long max = ULLONG_MAX;
    char buffer[100];
    sprintf( buffer, "%llu", max );
    TESTCASE( ( fh = freopen( testfile, "wb+", stderr ) ) != NULL );
    TESTCASE( strtol( buffer, NULL, 10 ) == LONG_MAX );
    perror( "Test" );
    rewind( fh );
    TESTCASE( fread( buffer, 1, 7, fh ) == 7 );
    TESTCASE( memcmp( buffer, "Test: ", 6 ) == 0 );
    TESTCASE( fclose( fh ) == 0 );
    TESTCASE( remove( testfile ) == 0 );
    return TEST_RESULTS;
}

#endif
