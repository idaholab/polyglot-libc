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
_PDCLIB_update_tzname_etc( struct state const *, struct ttinfo const * )
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_tzcode.h"

void _PDCLIB_update_tzname_etc( struct state const * sp, struct ttinfo const * ttisp )
{
#if HAVE_TZNAME
    tzname[ ttisp->tt_isdst ] = (char *) &sp->chars[ ttisp->tt_desigidx ];
#endif
#if USG_COMPAT
    if ( ! ttisp->tt_isdst )
    {
        timezone = - ttisp->tt_utoff;
    }
#endif
#if ALTZONE
    if ( ttisp->tt_isdst )
    {
        altzone = - ttisp->tt_utoff;
    }
#endif
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
