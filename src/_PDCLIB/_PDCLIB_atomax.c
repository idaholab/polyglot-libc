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
_PDCLIB_atomax( const char * )
*/

#include <string.h>
#include <ctype.h>

#ifndef REGTEST

_PDCLIB_intmax_t _PDCLIB_atomax( const char * s )
{
    _PDCLIB_intmax_t rc = 0;
    char sign = '+';
    const char * x;

    /* TODO: In other than "C" locale, additional patterns may be defined     */
    while ( isspace( *s ) )
    {
        ++s;
    }

    if ( *s == '+' )
    {
        ++s;
    }
    else if ( *s == '-' )
    {
        sign = *( s++ );
    }

    /* TODO: Earlier version was missing tolower() but was not caught by tests */
    while ( ( x = (const char *)memchr( _PDCLIB_digits, tolower( *( s++ ) ), 10 ) ) != NULL )
    {
        rc = rc * 10 + ( x - _PDCLIB_digits );
    }

    return ( sign == '+' ) ? rc : -rc;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    /* basic functionality */
    TESTCASE( _PDCLIB_atomax( "123" ) == 123 );
    /* testing skipping of leading whitespace and trailing garbage */
    TESTCASE( _PDCLIB_atomax( " \n\v\t\f123xyz" ) == 123 );
#endif
    return TEST_RESULTS;
}

#endif
