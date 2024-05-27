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

/* ispunct( int ) */

#include <ctype.h>

#ifndef REGTEST

#include <locale.h>

int ispunct( int c )
{
    return ( _PDCLIB_lc_ctype->entry[c].flags & _PDCLIB_CTYPE_PUNCT );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( ! ispunct( 'a' ) );
    TESTCASE( ! ispunct( 'z' ) );
    TESTCASE( ! ispunct( 'A' ) );
    TESTCASE( ! ispunct( 'Z' ) );
    TESTCASE( ispunct( '@' ) );
    TESTCASE( ispunct( '.' ) );
    TESTCASE( ! ispunct( '\t' ) );
    TESTCASE( ! ispunct( '\0' ) );
    TESTCASE( ! ispunct( ' ' ) );
    return TEST_RESULTS;
}

#endif
