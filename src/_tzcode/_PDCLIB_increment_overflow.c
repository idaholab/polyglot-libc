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
_PDCLIB_increment_overflow( int *, int )
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_tzcode.h"

/* Normalize logic courtesy Paul Eggert. */

bool _PDCLIB_increment_overflow( int * ip, int j )
{
    int const i = *ip;

    /* If i >= 0 there can only be overflow if i + j > INT_MAX
       or if j > INT_MAX - i; given i >= 0, INT_MAX - i cannot overflow.
       If i < 0 there can only be overflow if i + j < INT_MIN
       or if j < INT_MIN - i; given i < 0, INT_MIN - i cannot overflow.
    */
    if ( ( i >= 0 ) ? ( j > _PDCLIB_INT_MAX - i ) : ( j < _PDCLIB_INT_MIN - i ) )
    {
        return true;
    }

    *ip += j;
    return false;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
#endif

    return TEST_RESULTS;
}

#endif
