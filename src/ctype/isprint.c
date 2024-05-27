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

/* isprint( int ) */

#include <ctype.h>

#ifndef REGTEST

#include <locale.h>

int isprint( int c )
{
    /* FIXME: Space as of current locale charset, not source charset. */
    return ( _PDCLIB_lc_ctype->entry[c].flags & _PDCLIB_CTYPE_GRAPH ) || ( c == ' ' );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( isprint( 'a' ) );
    TESTCASE( isprint( 'z' ) );
    TESTCASE( isprint( 'A' ) );
    TESTCASE( isprint( 'Z' ) );
    TESTCASE( isprint( '@' ) );
    TESTCASE( ! isprint( '\t' ) );
    TESTCASE( ! isprint( '\0' ) );
    TESTCASE( isprint( ' ' ) );
    return TEST_RESULTS;
}

#endif
