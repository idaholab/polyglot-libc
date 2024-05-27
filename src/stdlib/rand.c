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

/* rand( void ) */

#include <stdlib.h>

#ifndef REGTEST

int rand( void )
{
    _PDCLIB_seed = _PDCLIB_seed * 1103515245 + 12345;
    return ( int )( _PDCLIB_seed / 65536 ) % 32768;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    int rnd1, rnd2;
    TESTCASE( ( rnd1 = rand() ) < RAND_MAX );
    TESTCASE( ( rnd2 = rand() ) < RAND_MAX );
    srand( 1 );
    TESTCASE( rand() == rnd1 );
    TESTCASE( rand() == rnd2 );
    return TEST_RESULTS;
}

#endif
