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
_PDCLIB_init_ttinfo( struct ttinfo *, int_fast32_t, bool, int )
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_tzcode.h"

/* Initialize *S to a value based on UTOFF, ISDST, and DESIGIDX.  */
void _PDCLIB_init_ttinfo( struct ttinfo * s, int_fast32_t utoff, bool isdst, int desigidx )
{
    s->tt_utoff = utoff;
    s->tt_isdst = isdst;
    s->tt_desigidx = desigidx;
    s->tt_ttisstd = false;
    s->tt_ttisut = false;
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
