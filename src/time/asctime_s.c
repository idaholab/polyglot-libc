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

/* asctime_s( char *, rsize_t, const struct tm * ) */

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#ifndef REGTEST

#include <stdio.h>

errno_t asctime_s( char * s, rsize_t maxsize, const struct tm * timeptr )
{
    if ( s == NULL || timeptr == NULL || maxsize < 26 || maxsize > RSIZE_MAX || timeptr->tm_year < -1900 || timeptr->tm_year > 8099 /* TODO: || not normalized */ )
    {
        if ( s != NULL && maxsize > 0 && maxsize <= RSIZE_MAX )
        {
            s[0] = '\0';
        }

        _PDCLIB_constraint_handler( _PDCLIB_CONSTRAINT_VIOLATION( _PDCLIB_EINVAL ) );
        return _PDCLIB_EINVAL;
    }

    sprintf( s, "%s %s %2d %.2d:%.2d:%.2d %4d\n",
             _PDCLIB_lc_time_C.day_name_abbr[ timeptr->tm_wday ],
             _PDCLIB_lc_time_C.month_name_abbr[ timeptr->tm_mon ],
             timeptr->tm_mday,
             timeptr->tm_hour,
             timeptr->tm_min,
             timeptr->tm_sec,
             timeptr->tm_year + 1900 );

    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <string.h>

int main( void )
{
    /* TODO: Constraint handling */

    struct tm time;
    MKTIME( time, 52, 3, 1, 16, 8, 73, 0, 0 );
    TESTCASE( strcmp( asctime( &time ), "Sun Sep 16 01:03:52 1973\n" ) == 0 );
    MKTIME( time, 0, 0, 0, 1, 0, 0, 0, 0 );
    TESTCASE( strcmp( asctime( &time ), "Sun Jan  1 00:00:00 1900\n" ) == 0 );
    MKTIME( time, 60, 59, 23, 31, 11, 8099, 6, 0 );
    TESTCASE( strcmp( asctime( &time ), "Sat Dec 31 23:59:60 9999\n" ) == 0 );
    return TEST_RESULTS;
}

#endif