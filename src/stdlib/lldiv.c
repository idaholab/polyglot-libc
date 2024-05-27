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

/* lldiv( long long int, long long int ) */

#include <stdlib.h>

#ifndef REGTEST

lldiv_t lldiv( long long int numer, long long int denom )
{
    lldiv_t rc;
    rc.quot = numer / denom;
    rc.rem  = numer % denom;
    /* TODO: pre-C99 compilers might require modulus corrections */
    return rc;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    lldiv_t result;
    result = lldiv( 5ll, 2ll );
    TESTCASE( result.quot == 2 && result.rem == 1 );
    result = lldiv( -5ll, 2ll );
    TESTCASE( result.quot == -2 && result.rem == -1 );
    result = lldiv( 5ll, -2ll );
    TESTCASE( result.quot == -2 && result.rem == 1 );
    TESTCASE( sizeof( result.quot ) == sizeof( long long ) );
    TESTCASE( sizeof( result.rem )  == sizeof( long long ) );
    return TEST_RESULTS;
}

#endif
