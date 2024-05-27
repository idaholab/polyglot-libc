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
_PDCLIB_gmtsub( struct state const *, time_t const *, int_fast32_t, struct tm * )
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_tzcode.h"

/* gmtsub is to gmtime as localsub is to localtime. */
struct tm * _PDCLIB_gmtsub( struct state const * sp, time_t const * timep, int_fast32_t offset, struct tm * tmp )
{
    struct tm * result;

    result = _PDCLIB_timesub( timep, offset, _PDCLIB_gmtptr, tmp );

#ifdef TM_ZONE
    /* Could get fancy here and deliver something such as
       "+xx" or "-xx" if offset is non-zero,
       but this is no time for a treasure hunt.
    */
    tmp->TM_ZONE = ( (char *)( offset ? wildabbr : _PDCLIB_gmtptr ? _PDCLIB_gmtptr->chars : gmt ) );
#endif

    return result;
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
