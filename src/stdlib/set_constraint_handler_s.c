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

/* set_constraint_handler_s( constraint_handler_t ) */

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdlib.h>

#ifndef REGTEST

constraint_handler_t _PDCLIB_constraint_handler = abort_handler_s;

constraint_handler_t set_constraint_handler_s( constraint_handler_t handler )
{
    constraint_handler_t previous = _PDCLIB_constraint_handler;

    if ( handler == NULL )
    {
        _PDCLIB_constraint_handler = abort_handler_s;
    }
    else
    {
        _PDCLIB_constraint_handler = handler;
    }

    return previous;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    TESTCASE( _PDCLIB_constraint_handler == abort_handler_s );
    TESTCASE( set_constraint_handler_s( ignore_handler_s ) == abort_handler_s );
    TESTCASE( _PDCLIB_constraint_handler == ignore_handler_s );
    TESTCASE( set_constraint_handler_s( NULL ) == ignore_handler_s );
    TESTCASE( _PDCLIB_constraint_handler == abort_handler_s );
#endif
    return TEST_RESULTS;
}

#endif
