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

/* vsscanf( const char *, const char *, va_list ) */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#ifndef REGTEST

int vsscanf( const char * _PDCLIB_restrict s, const char * _PDCLIB_restrict format, va_list arg )
{
    /* TODO: This function should interpret format as multibyte characters.  */
    struct _PDCLIB_status_t status;
    status.base = 0;
    status.flags = 0;
    status.n = 0;
    status.i = 0;
    status.current = 0;
    status.s = ( char * ) s;
    status.width = 0;
    status.prec = EOF;
    status.stream = NULL;
    va_copy( status.arg, arg );

    while ( *format != '\0' )
    {
        const char * rc;

        if ( ( *format != '%' ) || ( ( rc = _PDCLIB_scan( format, &status ) ) == format ) )
        {
            /* No conversion specifier, match verbatim */
            if ( isspace( *format ) )
            {
                /* Whitespace char in format string: Skip all whitespaces */
                /* No whitespaces in input do not result in matching error */
                while ( isspace( *status.s ) )
                {
                    ++status.s;
                    ++status.i;
                }
            }
            else
            {
                /* Non-whitespace char in format string: Match verbatim */
                if ( *status.s != *format )
                {
                    if ( *status.s == '\0' && status.n == 0 )
                    {
                        /* Early input error */
                        return EOF;
                    }

                    /* Matching error */
                    return status.n;
                }
                else
                {
                    ++status.s;
                    ++status.i;
                }
            }

            ++format;
        }
        else
        {
            /* NULL return code indicates error */
            if ( rc == NULL )
            {
                if ( ( *status.s == '\n' ) && ( status.n == 0 ) )
                {
                    status.n = EOF;
                }

                break;
            }

            /* Continue parsing after conversion specifier */
            format = rc;
        }
    }

    va_end( status.arg );
    return status.n;
}

#endif

#ifdef TEST
#define _PDCLIB_FILEID "stdio/vsscanf.c"
#define _PDCLIB_STRINGIO

#include "_PDCLIB_test.h"

static int testscanf( const char * stream, const char * format, ... )
{
    va_list ap;
    int result;
    va_start( ap, format );
    result = vsscanf( stream, format, ap );
    va_end( ap );
    return result;
}

int main( void )
{
    char source[100];
#include "scanf_testcases.h"
    return TEST_RESULTS;
}

#endif
