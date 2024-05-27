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

#include <inttypes.h>

#ifndef REGTEST

imaxdiv_t imaxdiv( intmax_t numer, intmax_t denom )
{
    imaxdiv_t rc;
    rc.quot = numer / denom;
    rc.rem  = numer % denom;
    return rc;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    imaxdiv_t result;
    result = imaxdiv( ( intmax_t )5, ( intmax_t )2 );
    TESTCASE( result.quot == 2 && result.rem == 1 );
    result = imaxdiv( ( intmax_t )-5, ( intmax_t )2 );
    TESTCASE( result.quot == -2 && result.rem == -1 );
    result = imaxdiv( ( intmax_t )5, ( intmax_t )-2 );
    TESTCASE( result.quot == -2 && result.rem == 1 );
    TESTCASE( sizeof( result.quot ) == sizeof( intmax_t ) );
    TESTCASE( sizeof( result.rem )  == sizeof( intmax_t ) );
    return TEST_RESULTS;
}

#endif
