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

/* vsnprintf( char *, size_t, const char *, va_list ) */

#include <stdio.h>
#include <stdarg.h>

#ifndef REGTEST

int vsnprintf( char * _PDCLIB_restrict s, size_t n, const char * _PDCLIB_restrict format, _PDCLIB_va_list arg )
{
    /* TODO: This function should interpret format as multibyte characters.  */
    struct _PDCLIB_status_t status;
    status.base = 0;
    status.flags = 0;
    status.n = n;
    status.i = 0;
    status.current = 0;
    status.s = s;
    status.width = 0;
    status.prec = EOF;
    status.stream = NULL;
    va_copy( status.arg, arg );

    while ( *format != '\0' )
    {
        const char * rc;

        if ( ( *format != '%' ) || ( ( rc = _PDCLIB_print( format, &status ) ) == format ) )
        {
            /* No conversion specifier, print verbatim */
            if ( status.i < n )
            {
                s[ status.i ] = *format;
            }

            status.i++;
            format++;
        }
        else
        {
            /* Continue parsing after conversion specifier */
            format = rc;
        }
    }

    if ( status.i  < n )
    {
        s[ status.i ] = '\0';
    }

    va_end( status.arg );
    return status.i;
}

#endif

#ifdef TEST
#define _PDCLIB_FILEID "stdio/vsnprintf.c"
#define _PDCLIB_STRINGIO
#include <stdint.h>
#include <stddef.h>
#include "_PDCLIB_test.h"

static int testprintf( char * s, const char * format, ... )
{
    int i;
    va_list arg;
    va_start( arg, format );
    i = vsnprintf( s, 100, format, arg );
    va_end( arg );
    return i;
}

int main( void )
{
    char target[100];
#include "printf_testcases.h"
    return TEST_RESULTS;
}

#endif
