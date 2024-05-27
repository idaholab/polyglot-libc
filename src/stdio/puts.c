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

/* puts( const char * ) */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

extern char * _PDCLIB_eol;

int puts( const char * s )
{
    _PDCLIB_LOCK( stdout->mtx );

    if ( _PDCLIB_prepwrite( stdout ) == EOF )
    {
        _PDCLIB_UNLOCK( stdout->mtx );
        return EOF;
    }

    while ( *s != '\0' )
    {
        stdout->buffer[ stdout->bufidx++ ] = *s++;

        if ( stdout->bufidx == stdout->bufsize )
        {
            if ( _PDCLIB_flushbuffer( stdout ) == EOF )
            {
                _PDCLIB_UNLOCK( stdout->mtx );
                return EOF;
            }
        }
    }

    stdout->buffer[ stdout->bufidx++ ] = '\n';

    if ( ( stdout->bufidx == stdout->bufsize ) ||
         ( stdout->status & ( _IOLBF | _IONBF ) ) )
    {
        int rc = _PDCLIB_flushbuffer( stdout );
        _PDCLIB_UNLOCK( stdout->mtx );
        return rc;
    }
    else
    {
        _PDCLIB_UNLOCK( stdout->mtx );
        return 0;
    }
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    FILE * fh;
    const char * message = "SUCCESS testing puts()";
    char buffer[23];
    buffer[22] = 'x';
    TESTCASE( ( fh = freopen( testfile, "wb+", stdout ) ) != NULL );
    TESTCASE( puts( message ) >= 0 );
    rewind( fh );
    TESTCASE( fread( buffer, 1, 22, fh ) == 22 );
    TESTCASE( memcmp( buffer, message, 22 ) == 0 );
    TESTCASE( buffer[22] == 'x' );
    TESTCASE( fclose( fh ) == 0 );
    TESTCASE( remove( testfile ) == 0 );
    return TEST_RESULTS;
}

#endif
