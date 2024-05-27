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

/* fputc( int, FILE * ) */

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

int fputc( int c, struct _PDCLIB_file_t * stream )
{
    _PDCLIB_LOCK( stream->mtx );

    if ( _PDCLIB_prepwrite( stream ) == EOF )
    {
        _PDCLIB_UNLOCK( stream->mtx );
        return EOF;
    }

    stream->buffer[stream->bufidx++] = ( char )c;

    if ( ( stream->bufidx == stream->bufsize )                   /* _IOFBF */
           || ( ( stream->status & _IOLBF ) && ( ( char )c == '\n' ) ) /* _IOLBF */
           || ( stream->status & _IONBF )                        /* _IONBF */
       )
    {
        /* buffer filled, unbuffered stream, or end-of-line. */
        c = ( _PDCLIB_flushbuffer( stream ) == 0 ) ? c : EOF;
    }

    _PDCLIB_UNLOCK( stream->mtx );

    return c;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* Testing covered by ftell.c */
    return TEST_RESULTS;
}

#endif
