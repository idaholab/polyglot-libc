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

/* localtime( const time_t * ) */

#include <time.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_tzcode.h"

struct tm * localtime( const time_t * timer )
{
    return _PDCLIB_localtime_tzset( timer, &_PDCLIB_tm, true );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* TODO: System Clock DST */

    time_t t;
    struct tm * time;

    t = -2147483648l;
    time = localtime( &t );
    TESTCASE( time->tm_sec == 52 );
    TESTCASE( time->tm_min == 45 );
    TESTCASE( time->tm_hour == 21 );
    TESTCASE( time->tm_mday == 13 );
    TESTCASE( time->tm_mon == 11 );
    TESTCASE( time->tm_year == 1 );
    TESTCASE( time->tm_wday == 5 );
    TESTCASE( time->tm_yday == 346 );

    t = 2147483647l;
    time = localtime( &t );
    TESTCASE( time->tm_sec == 7 );
    TESTCASE( time->tm_min == 14 );
    TESTCASE( time->tm_hour == 4 );
    TESTCASE( time->tm_mday == 19 );
    TESTCASE( time->tm_mon == 0 );
    TESTCASE( time->tm_year == 138 );
    TESTCASE( time->tm_wday == 2 );
    TESTCASE( time->tm_yday == 18 );

    return TEST_RESULTS;
}

#endif
