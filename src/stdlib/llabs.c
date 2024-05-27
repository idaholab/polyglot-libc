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

/* llabs( long int ) */

#include <stdlib.h>

#ifndef REGTEST

long long int llabs( long long int j )
{
    return ( j >= 0 ) ? j : -j;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <limits.h>

int main( void )
{
    TESTCASE( llabs( 0ll ) == 0 );
    TESTCASE( llabs( LLONG_MAX ) == LLONG_MAX );
    TESTCASE( llabs( LLONG_MIN + 1 ) == -( LLONG_MIN + 1 ) );
    return TEST_RESULTS;
}

#endif
