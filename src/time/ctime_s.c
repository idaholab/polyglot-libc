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

/* ctime( const time_t * ) */

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#ifndef REGTEST

errno_t ctime_s( char * s, rsize_t maxsize, const time_t * timer )
{
    struct tm tm;

    if ( s == NULL || timer == NULL || maxsize < 26 || maxsize > RSIZE_MAX )
    {
        if ( s != NULL && maxsize > 0 && maxsize <= RSIZE_MAX )
        {
            s[0] = '\0';
        }

        _PDCLIB_constraint_handler( _PDCLIB_CONSTRAINT_VIOLATION( _PDCLIB_EINVAL ) );
        return _PDCLIB_EINVAL;
    }

    return asctime_s( s, maxsize, localtime_s( timer, &tm ) );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <stdio.h>

int main( void )
{
#ifndef REGTEST
    /* TODO: System Clock DST */
    time_t t;
    char s[27];

    /* TODO: Constraint handling */

    t = -2147483648l;
    TESTCASE( ctime_s( s, 27, &t ) == 0 );
    TESTCASE( strcmp( s, "Fri Dec 13 21:45:52 1901\n" ) == 0 );

    t = 2147483647l;
    TESTCASE( ctime_s( s, 27, &t ) == 0 );
    TESTCASE( strcmp( s, "Tue Jan 19 04:14:07 2038\n" ) == 0 );
#endif

    return TEST_RESULTS;
}

#endif
