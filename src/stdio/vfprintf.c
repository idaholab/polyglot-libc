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

/* vfprintf( FILE *, const char *, va_list ) */

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

int vfprintf( struct _PDCLIB_file_t * _PDCLIB_restrict stream, const char * _PDCLIB_restrict format, va_list arg )
{
    /* TODO: This function should interpret format as multibyte characters.  */
    struct _PDCLIB_status_t status;
    status.base = 0;
    status.flags = 0;
    status.n = SIZE_MAX;
    status.i = 0;
    status.current = 0;
    status.s = NULL;
    status.width = 0;
    status.prec = EOF;
    status.stream = stream;

    _PDCLIB_LOCK( stream->mtx );

    if ( _PDCLIB_prepwrite( stream ) == EOF )
    {
        _PDCLIB_UNLOCK( stream->mtx );
        return EOF;
    }

    va_copy( status.arg, arg );

    while ( *format != '\0' )
    {
        const char * rc;

        if ( ( *format != '%' ) || ( ( rc = _PDCLIB_print( format, &status ) ) == format ) )
        {
            /* No conversion specifier, print verbatim */
            stream->buffer[ stream->bufidx++ ] = *format;

            if ( ( stream->bufidx == stream->bufsize )
                 || ( ( stream->status & _IOLBF ) && ( *format == '\n' ) )
                 || ( stream->status & _IONBF )
               )
            {
                if ( _PDCLIB_flushbuffer( stream ) != 0 )
                {
                    _PDCLIB_UNLOCK( stream->mtx );
                    return EOF;
                }
            }

            ++format;
            status.i++;
        }
        else
        {
            /* Continue parsing after conversion specifier */
            format = rc;
        }
    }

    va_end( status.arg );
    _PDCLIB_UNLOCK( stream->mtx );
    return status.i;
}

#endif

#ifdef TEST
#define _PDCLIB_FILEID "stdio/vfprintf.c"
#define _PDCLIB_FILEIO
#include <stddef.h>
#include "_PDCLIB_test.h"

static int testprintf( FILE * stream, const char * format, ... )
{
    int i;
    va_list arg;
    va_start( arg, format );
    i = vfprintf( stream, format, arg );
    va_end( arg );
    return i;
}

int main( void )
{
    FILE * target;
    TESTCASE( ( target = tmpfile() ) != NULL );
#include "printf_testcases.h"
    TESTCASE( fclose( target ) == 0 );
    return TEST_RESULTS;
}

#endif
