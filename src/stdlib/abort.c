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

/* abort( void ) */

#include <stdlib.h>
#include <signal.h>

#ifndef REGTEST

void abort( void )
{
    raise( SIGABRT );
    exit( EXIT_FAILURE );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <stdio.h>

static void aborthandler( int sig )
{
    exit( 0 );
}

int main( void )
{
    int UNEXPECTED_RETURN_FROM_ABORT = 0;
    TESTCASE( signal( SIGABRT, &aborthandler ) != SIG_ERR );
    abort();
    TESTCASE( UNEXPECTED_RETURN_FROM_ABORT );
    return TEST_RESULTS;
}

#endif
