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
_PDCLIB_strtox_prelim( const char *, char *, int * )
*/

#include <ctype.h>
#include <stddef.h>
#include <string.h>

#ifndef REGTEST

const char * _PDCLIB_strtox_prelim( const char * p, char * sign, int * base )
{
    /* skipping leading whitespace */
    while ( isspace( *p ) )
    {
        ++p;
    }

    /* determining / skipping sign */
    if ( *p != '+' && *p != '-' )
    {
        *sign = '+';
    }
    else
    {
        *sign = *( p++ );
    }

    /* determining base */
    if ( *p == '0' )
    {
        ++p;

        if ( ( *base == 0 || *base == 16 ) && ( *p == 'x' || *p == 'X' ) )
        {
            *base = 16;
            ++p;

            /* catching a border case here: "0x" followed by a non-digit should
               be parsed as the unprefixed zero.
               We have to "rewind" the parsing; having the base set to 16 if it
               was zero previously does not hurt, as the result is zero anyway.
            */
            if ( memchr( _PDCLIB_digits, tolower( *p ), *base ) == NULL )
            {
                p -= 2;
            }
        }
        else if ( *base == 0 )
        {
            *base = 8;
            /* back up one digit, so that a plain zero is decoded correctly
               (and endptr is set correctly as well).
               (2019-01-15, Giovanni Mascellani)
            */
            --p;
        }
        else
        {
            --p;
        }
    }
    else if ( ! *base )
    {
        *base = 10;
    }

    return ( ( *base >= 2 ) && ( *base <= 36 ) ) ? p : NULL;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    int base = 0;
    char sign = '\0';
    char test1[] = "  123";
    char test2[] = "\t+0123";
    char test3[] = "\v-0x123";
    TESTCASE( _PDCLIB_strtox_prelim( test1, &sign, &base ) == &test1[2] );
    TESTCASE( sign == '+' );
    TESTCASE( base == 10 );
    base = 0;
    sign = '\0';
    TESTCASE( _PDCLIB_strtox_prelim( test2, &sign, &base ) == &test2[2] );
    TESTCASE( sign == '+' );
    TESTCASE( base == 8 );
    base = 0;
    sign = '\0';
    TESTCASE( _PDCLIB_strtox_prelim( test3, &sign, &base ) == &test3[4] );
    TESTCASE( sign == '-' );
    TESTCASE( base == 16 );
    base = 10;
    sign = '\0';
    TESTCASE( _PDCLIB_strtox_prelim( test3, &sign, &base ) == &test3[2] );
    TESTCASE( sign == '-' );
    TESTCASE( base == 10 );
    base = 1;
    TESTCASE( _PDCLIB_strtox_prelim( test3, &sign, &base ) == NULL );
    base = 37;
    TESTCASE( _PDCLIB_strtox_prelim( test3, &sign, &base ) == NULL );
#endif
    return TEST_RESULTS;
}

#endif
