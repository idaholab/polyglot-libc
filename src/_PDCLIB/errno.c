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
_PDCLIB_errno
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_int.h"

#if (__STDC_NO_THREADS__ != 1) && (__STDC_VERSION__ >= 201112L)
_Thread_local int _PDCLIB_errno = 0;
#else
static int _PDCLIB_errno = 0;
#endif

int * _PDCLIB_errno_func()
{
    return &_PDCLIB_errno;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <errno.h>

#if (__STDC_NO_THREADS__ != 1) && (__STDC_VERSION__ >= 201112L)

#include <threads.h>

static int thread_func( void * arg )
{
    TESTCASE( errno == 0 );
    *_PDCLIB_errno_func() = 1;
    TESTCASE( errno == 1 );
    thrd_exit( 0 );
}

#endif

int main( void )
{
    errno = 0;
    TESTCASE( errno == 0 );
    errno = EDOM;
    TESTCASE( errno == EDOM );
    errno = ERANGE;
    TESTCASE( errno == ERANGE );

#if (__STDC_NO_THREADS__ != 1) && (__STDC_VERSION__ >= 201112L)
    {
        thrd_t t;
        struct timespec spec = { 1, 0 };
        int rc;

        TESTCASE( thrd_create( &t, thread_func, NULL ) == thrd_success );

        TESTCASE( thrd_sleep( &spec, NULL ) == 0 );
        TESTCASE( errno == ERANGE );
        TESTCASE( thrd_join( t, &rc ) == thrd_success );
        TESTCASE( rc == 0 );
    }
#endif

    return TEST_RESULTS;
}

#endif
