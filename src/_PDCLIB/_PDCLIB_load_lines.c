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

/*
_PDCLIB_load_lines( FILE *, size_t )
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef REGTEST

char * _PDCLIB_load_lines( FILE * fh, size_t lines )
{
    size_t required = 0;
    long pos = ftell( fh );
    char * rc = NULL;
    int c;

    /* Count the number of characters */
    while ( lines && ( c = fgetc( fh ) ) != EOF )
    {
        if ( c == '\n' )
        {
            --lines;
        }

        ++required;
    }

    if ( ! feof( fh ) )
    {
        if ( ( rc = (char *)malloc( required ) ) != NULL )
        {
            size_t i;

            fseek( fh, pos, SEEK_SET );
            fread( rc, 1, required, fh );

            for ( i = 0; i < required; ++i )
            {
                if ( rc[ i ] == '\n' )
                {
                    rc[ i ] = '\0';
                }
            }
        }
    }

    return rc;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    FILE * fh = fopen( "test_lines.txt", "w+" );
    char * rc;

    TESTCASE( fh != NULL );
    TESTCASE( fputs( "Foo\n\nBar\n", fh ) != EOF );

    rewind( fh );
    rc = _PDCLIB_load_lines( fh, 3 );
    fclose( fh );
    remove( "test_lines.txt" );

    TESTCASE( rc != NULL );
    TESTCASE( strcmp( rc, "Foo" ) == 0 );
    TESTCASE( strcmp( rc + 4, "" ) == 0 );
    TESTCASE( strcmp( rc + 5, "Bar" ) == 0 );

#endif
    return TEST_RESULTS;
}

#endif
