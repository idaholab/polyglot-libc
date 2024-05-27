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
_PDCLIB_gmtcheck( void )
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_tzcode.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
extern mtx_t _PDCLIB_time_mtx;
#endif

static void gmtload( struct state * sp )
{
    if ( _PDCLIB_tzload( gmt, sp, true ) != 0 )
    {
        _PDCLIB_tzparse( gmt, sp, true );
    }
}

void _PDCLIB_gmtcheck( void )
{
    static bool gmt_is_set;

    _PDCLIB_LOCK( _PDCLIB_time_mtx );

    if ( ! gmt_is_set )
    {
        gmtload( _PDCLIB_gmtptr );
        gmt_is_set = true;
    }

    _PDCLIB_UNLOCK( _PDCLIB_time_mtx );
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
