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

/* isxdigit( int ) */

#include <ctype.h>

#ifndef REGTEST

#include <locale.h>

int isxdigit( int c )
{
    return ( isdigit( c ) ||
             ( c >= _PDCLIB_lc_ctype->Xdigits_low && c <= _PDCLIB_lc_ctype->Xdigits_high ) ||
             ( c >= _PDCLIB_lc_ctype->xdigits_low && c <= _PDCLIB_lc_ctype->xdigits_high )
           );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( isxdigit( '0' ) );
    TESTCASE( isxdigit( '9' ) );
    TESTCASE( isxdigit( 'a' ) );
    TESTCASE( isxdigit( 'f' ) );
    TESTCASE( ! isxdigit( 'g' ) );
    TESTCASE( isxdigit( 'A' ) );
    TESTCASE( isxdigit( 'F' ) );
    TESTCASE( ! isxdigit( 'G' ) );
    TESTCASE( ! isxdigit( '@' ) );
    TESTCASE( ! isxdigit( ' ' ) );
    return TEST_RESULTS;
}

#endif
