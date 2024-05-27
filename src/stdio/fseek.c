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

/* fseek( FILE *, long, int ) */

#include <stdio.h>
#include <sys/types.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

int fseek( struct _PDCLIB_file_t * stream, long offset, int whence )
{
    int rc;
    _PDCLIB_LOCK( stream->mtx );

    if ( stream->status & _PDCLIB_FWRITE )
    {
        if ( _PDCLIB_flushbuffer( stream ) == EOF )
        {
            _PDCLIB_UNLOCK( stream->mtx );
            return EOF;
        }
    }

    stream->status &= ~ _PDCLIB_EOFFLAG;

    if ( stream->status & _PDCLIB_FRW )
    {
        stream->status &= ~( _PDCLIB_FREAD | _PDCLIB_FWRITE );
    }

    if ( whence == SEEK_CUR )
    {
        offset -= ( ( ( int )stream->bufend - ( int )stream->bufidx ) + stream->ungetidx );
    }

    rc = ( _PDCLIB_seek( stream, offset, whence ) != EOF ) ? 0 : EOF;
    _PDCLIB_UNLOCK( stream->mtx );
    return rc;
}

int fseeko(struct _PDCLIB_file_t *stream, off_t offset, int whence)
{
    return fseek(stream, (long)offset, whence);
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <string.h>

int main( void )
{
    FILE * fh;
    TESTCASE( ( fh = tmpfile() ) != NULL );
    TESTCASE( fwrite( teststring, 1, strlen( teststring ), fh ) == strlen( teststring ) );
    /* General functionality */
    TESTCASE( fseek( fh, -1, SEEK_END ) == 0 );
    TESTCASE( ( size_t )ftell( fh ) == strlen( teststring ) - 1 );
    TESTCASE( fseek( fh, 0, SEEK_END ) == 0 );
    TESTCASE( ( size_t )ftell( fh ) == strlen( teststring ) );
    TESTCASE( fseek( fh, 0, SEEK_SET ) == 0 );
    TESTCASE( ftell( fh ) == 0 );
    TESTCASE( fseek( fh, 5, SEEK_CUR ) == 0 );
    TESTCASE( ftell( fh ) == 5 );
    TESTCASE( fseek( fh, -3, SEEK_CUR ) == 0 );
    TESTCASE( ftell( fh ) == 2 );
    /* Checking behaviour around EOF */
    TESTCASE( fseek( fh, 0, SEEK_END ) == 0 );
    TESTCASE( ! feof( fh ) );
    TESTCASE( fgetc( fh ) == EOF );
    TESTCASE( feof( fh ) );
    TESTCASE( fseek( fh, 0, SEEK_END ) == 0 );
    TESTCASE( ! feof( fh ) );
    /* Checking undo of ungetc() */
    TESTCASE( fseek( fh, 0, SEEK_SET ) == 0 );
    TESTCASE( fgetc( fh ) == teststring[0] );
    TESTCASE( fgetc( fh ) == teststring[1] );
    TESTCASE( fgetc( fh ) == teststring[2] );
    TESTCASE( ftell( fh ) == 3 );
    TESTCASE( ungetc( teststring[2], fh ) == teststring[2] );
    TESTCASE( ftell( fh ) == 2 );
    TESTCASE( fgetc( fh ) == teststring[2] );
    TESTCASE( ftell( fh ) == 3 );
    TESTCASE( ungetc( 'x', fh ) == 'x' );
    TESTCASE( ftell( fh ) == 2 );
    TESTCASE( fgetc( fh ) == 'x' );
    TESTCASE( ungetc( 'x', fh ) == 'x' );
    TESTCASE( ftell( fh ) == 2 );
    TESTCASE( fseek( fh, 2, SEEK_SET ) == 0 );
    TESTCASE( fgetc( fh ) == teststring[2] );
    /* Checking error handling */
    TESTCASE( fseek( fh, -5, SEEK_SET ) == -1 );
    TESTCASE( fseek( fh, 0, SEEK_END ) == 0 );
    TESTCASE( fclose( fh ) == 0 );
    return TEST_RESULTS;
}

#endif
