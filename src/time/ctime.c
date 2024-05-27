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

#include <time.h>

#ifndef REGTEST

char * ctime( const time_t * timer )
{
    /* Section 4.12.3.2 of X3.159-1989 requires that
        The ctime function converts the calendar time pointed to by timer
        to local time in the form of a string. It is equivalent to
            asctime(localtime(timer))
    */
    struct tm * tmp = localtime( timer );
    return tmp ? asctime( tmp ) : NULL;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <stdio.h>

int main( void )
{
    /* TODO: System Clock DST */
    time_t t;

    t = -2147483648l;
    TESTCASE( strcmp( ctime( &t ), "Fri Dec 13 21:45:52 1901\n" ) == 0 );

    t = 2147483647l;
    TESTCASE( strcmp( ctime( &t ), "Tue Jan 19 04:14:07 2038\n" ) == 0 );

    return TEST_RESULTS;
}

#endif
