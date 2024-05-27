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

/* fwrite( void *, size_t, size_t, FILE * ) */

#include <stdio.h>
#include <string.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

size_t fread( void * _PDCLIB_restrict ptr, size_t size, size_t nmemb, struct _PDCLIB_file_t * _PDCLIB_restrict stream )
{
    char * dest = ( char * )ptr;
    size_t nmemb_i;

    _PDCLIB_LOCK( stream->mtx );

    if ( _PDCLIB_prepread( stream ) == EOF )
    {
        _PDCLIB_UNLOCK( stream->mtx );
        return 0;
    }

    for ( nmemb_i = 0; nmemb_i < nmemb; ++nmemb_i )
    {
        size_t size_i;

        for ( size_i = 0; size_i < size; ++size_i )
        {
            if ( stream->bufidx == stream->bufend )
            {
                if ( _PDCLIB_fillbuffer( stream ) == EOF )
                {
                    /* Could not read requested data */
                    _PDCLIB_UNLOCK( stream->mtx );
                    return nmemb_i;
                }
            }

            dest[ nmemb_i * size + size_i ] = stream->buffer[ stream->bufidx++ ];
        }
    }

    _PDCLIB_UNLOCK( stream->mtx );

    return nmemb_i;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    FILE * fh;
    const char * message = "Testing fwrite()...\n";
    char buffer[21];
    buffer[20] = 'x';
    TESTCASE( ( fh = tmpfile() ) != NULL );
    /* fwrite() / readback */
    TESTCASE( fwrite( message, 1, 20, fh ) == 20 );
    rewind( fh );
    TESTCASE( fread( buffer, 1, 20, fh ) == 20 );
    TESTCASE( memcmp( buffer, message, 20 ) == 0 );
    TESTCASE( buffer[20] == 'x' );
    /* same, different nmemb / size settings */
    rewind( fh );
    TESTCASE( memset( buffer, '\0', 20 ) == buffer );
    TESTCASE( fwrite( message, 5, 4, fh ) == 4 );
    rewind( fh );
    TESTCASE( fread( buffer, 5, 4, fh ) == 4 );
    TESTCASE( memcmp( buffer, message, 20 ) == 0 );
    TESTCASE( buffer[20] == 'x' );
    /* same... */
    rewind( fh );
    TESTCASE( memset( buffer, '\0', 20 ) == buffer );
    TESTCASE( fwrite( message, 20, 1, fh ) == 1 );
    rewind( fh );
    TESTCASE( fread( buffer, 20, 1, fh ) == 1 );
    TESTCASE( memcmp( buffer, message, 20 ) == 0 );
    TESTCASE( buffer[20] == 'x' );
    /* Done. */
    TESTCASE( fclose( fh ) == 0 );
    return TEST_RESULTS;
}

#endif
