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
_PDCLIB_load_lc_messages( const char *, const char * )
*/

#ifndef REGTEST

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "pdclib/_PDCLIB_int.h"

struct _PDCLIB_lc_messages_t * _PDCLIB_load_lc_messages( const char * path, const char * locale )
{
    errno = EINVAL;
    return NULL;

    /* FIXME: implement this differently to not depend on _PDCLIB_ERRNO_MAX */
    /*
    struct _PDCLIB_lc_messages_t * rc = NULL;
    const char * extension = "_messages.dat";
    char * file = (char *)malloc( strlen( path ) + strlen( locale ) + strlen( extension ) + 1 );

    if ( file )
    {
        FILE * fh;

        strcpy( file, path );
        strcat( file, locale );
        strcat( file, extension );

        if ( ( fh = fopen( file, "rb" ) ) != NULL )
        {
            if ( ( rc = (struct _PDCLIB_lc_messages_t *)malloc( sizeof( struct _PDCLIB_lc_messages_t ) ) ) != NULL )
            {
                char * data = _PDCLIB_load_lines( fh, _PDCLIB_ERRNO_MAX );

                if ( data != NULL )
                {
                    size_t i;

                    for ( i = 0; i < _PDCLIB_ERRNO_MAX; ++i )
                    {
                        rc->errno_texts[ i ] = data;
                        data += strlen( data ) + 1;
                    }

                    rc->alloced = 1;
                }
                else
                {
                    free( rc );
                    rc = NULL;
                }
            }

            fclose( fh );
        }

        free( file );
    }

    return rc;
    */
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    FILE * fh = fopen( "test_numeric.dat", "wb" );
    struct _PDCLIB_lc_lconv_numeric_t * lc;
    TESTCASE( fh != NULL );
    TESTCASE( fputs( ",\n.\n\n", fh ) != EOF );
    fclose( fh );
    TESTCASE( ( lc = _PDCLIB_load_lc_numeric( "./", "test" ) ) );
    remove( "test_numeric.dat" );
    TESTCASE( strcmp( lc->decimal_point, "," ) == 0 );
    TESTCASE( strcmp( lc->thousands_sep, "." ) == 0 );
    TESTCASE( strcmp( lc->grouping, "" ) == 0 );
#endif

    return TEST_RESULTS;
}

#endif
