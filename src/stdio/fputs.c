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

/* fputs( const char *, FILE * ) */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

int fputs( const char * _PDCLIB_restrict s, struct _PDCLIB_file_t * _PDCLIB_restrict stream )
{
    _PDCLIB_LOCK( stream->mtx );

    if ( _PDCLIB_prepwrite( stream ) == EOF )
    {
        _PDCLIB_UNLOCK( stream->mtx );
        return EOF;
    }

    while ( *s != '\0' )
    {
        /* Unbuffered and line buffered streams get flushed when fputs() does
           write the terminating end-of-line. All streams get flushed if the
           buffer runs full.
        */
        stream->buffer[ stream->bufidx++ ] = *s;

        if ( ( stream->bufidx == stream->bufsize ) ||
             ( ( stream->status & _IOLBF ) && *s == '\n' )
           )
        {
            if ( _PDCLIB_flushbuffer( stream ) == EOF )
            {
                _PDCLIB_UNLOCK( stream->mtx );
                return EOF;
            }
        }

        ++s;
    }

    if ( stream->status & _IONBF )
    {
        if ( _PDCLIB_flushbuffer( stream ) == EOF )
        {
            _PDCLIB_UNLOCK( stream->mtx );
            return EOF;
        }
    }

    _PDCLIB_UNLOCK( stream->mtx );

    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    const char * const message = "SUCCESS testing fputs()";
    FILE * fh;
    size_t i;
    TESTCASE( ( fh = tmpfile() ) != NULL );
    TESTCASE( fputs( message, fh ) >= 0 );
    rewind( fh );

    for ( i = 0; i < 23; ++i )
    {
        TESTCASE( fgetc( fh ) == message[i] );
    }

    TESTCASE( fclose( fh ) == 0 );
    return TEST_RESULTS;
}

#endif
