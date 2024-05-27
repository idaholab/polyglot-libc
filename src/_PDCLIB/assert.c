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
_PDCLIB_assert( const char * )
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef REGTEST

void _PDCLIB_assert99( const char * const message1, const char * const function, const char * const message2 )
{
    fputs( message1, stderr );
    fputs( function, stderr );
    fputs( message2, stderr );
    abort();
}

void _PDCLIB_assert89( const char * const message )
{
    fputs( message, stderr );
    abort();
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <signal.h>

static int EXPECTED_ABORT = 0;
static int UNEXPECTED_ABORT = 1;

static void aborthandler( int sig )
{
    TESTCASE( ! EXPECTED_ABORT );
    exit( ( signed int )TEST_RESULTS );
}

#define NDEBUG

#include <assert.h>

static int disabled_test( void )
{
    int i = 0;
    assert( i == 0 ); /* NDEBUG set, condition met */
    assert( i == 1 ); /* NDEBUG set, condition fails */
    return i;
}

#undef NDEBUG

#include <assert.h>

int main( void )
{
    TESTCASE( signal( SIGABRT, &aborthandler ) != SIG_ERR );
    TESTCASE( disabled_test() == 0 );
    assert( UNEXPECTED_ABORT ); /* NDEBUG not set, condition met */
    assert( EXPECTED_ABORT ); /* NDEBUG not set, condition fails - should abort */
    return TEST_RESULTS;
}

#endif
