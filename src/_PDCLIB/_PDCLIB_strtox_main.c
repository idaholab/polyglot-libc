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
_PDCLIB_strtox_main( const char **, int, _PDCLIB_uintmax_t, _PDCLIB_uintmax_t, int )
*/

#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

#ifndef REGTEST

_PDCLIB_uintmax_t _PDCLIB_strtox_main( const char ** p, unsigned int base, uintmax_t error, uintmax_t limval, int limdigit, char * sign )
{
    _PDCLIB_uintmax_t rc = 0;
    int digit = -1;
    const char * x;

    while ( ( x = (const char *)memchr( _PDCLIB_digits, tolower( **p ), base ) ) != NULL )
    {
        digit = x - _PDCLIB_digits;

        if ( ( rc < limval ) || ( ( rc == limval ) && ( digit <= limdigit ) ) )
        {
            rc = rc * base + ( unsigned )digit;
            ++( *p );
        }
        else
        {
            errno = ERANGE;

            /* TODO: Only if endptr != NULL - but do we really want *another* parameter? */
            /* TODO: Earlier version was missing tolower() here but was not caught by tests */
            while ( memchr( _PDCLIB_digits, tolower( **p ), base ) != NULL )
            {
                ++( *p );
            }

            /* TODO: This is ugly, but keeps caller from negating the error value */
            *sign = '+';
            return error;
        }
    }

    if ( digit == -1 )
    {
        *p = NULL;
        return 0;
    }

    return rc;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <errno.h>

int main( void )
{
#ifndef REGTEST
    const char * p;
    char test[] = "123_";
    char fail[] = "xxx";
    char sign = '-';
    /* basic functionality */
    p = test;
    errno = 0;
    TESTCASE( _PDCLIB_strtox_main( &p, 10u, ( uintmax_t )999, ( uintmax_t )12, 3, &sign ) == 123 );
    TESTCASE( errno == 0 );
    TESTCASE( p == &test[3] );
    /* proper functioning to smaller base */
    p = test;
    TESTCASE( _PDCLIB_strtox_main( &p, 8u, ( uintmax_t )999, ( uintmax_t )12, 3, &sign ) == 0123 );
    TESTCASE( errno == 0 );
    TESTCASE( p == &test[3] );
    /* overflowing subject sequence must still return proper endptr */
    p = test;
    TESTCASE( _PDCLIB_strtox_main( &p, 4u, ( uintmax_t )999, ( uintmax_t )1, 2, &sign ) == 999 );
    TESTCASE( errno == ERANGE );
    TESTCASE( p == &test[3] );
    TESTCASE( sign == '+' );
    /* testing conversion failure */
    errno = 0;
    p = fail;
    sign = '-';
    TESTCASE( _PDCLIB_strtox_main( &p, 10u, ( uintmax_t )999, ( uintmax_t )99, 8, &sign ) == 0 );
    TESTCASE( p == NULL );
#endif
    return TEST_RESULTS;
}

#endif
