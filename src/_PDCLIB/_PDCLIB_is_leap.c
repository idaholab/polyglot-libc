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
_PDCLIB_is_leap( int )
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_int.h"

int _PDCLIB_is_leap( int year_offset )
{
    /* year given as offset from 1900, matching tm.tm_year in <time.h> */
    long long year = year_offset + 1900ll;
    return ( ( year % 4 ) == 0 && ( ( year % 25 ) != 0 || ( year % 400 ) == 0 ) );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    /* 1901 not leap */
    TESTCASE( ! _PDCLIB_is_leap( 1 ) );
    /* 1904 leap */
    TESTCASE( _PDCLIB_is_leap( 4 ) );
    /* 1900 not leap */
    TESTCASE( ! _PDCLIB_is_leap( 0 ) );
    /* 2000 leap */
    TESTCASE( _PDCLIB_is_leap( 100 ) );
#endif
    return TEST_RESULTS;
}

#endif
