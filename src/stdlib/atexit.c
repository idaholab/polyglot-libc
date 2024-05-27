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

/* atexit( void (*)( void ) ) */

#include <stdlib.h>

#ifndef REGTEST

extern void ( *_PDCLIB_exitstack[] )( void );
extern size_t _PDCLIB_exitptr;

int atexit( void ( *func )( void ) )
{
    if ( _PDCLIB_exitptr == _PDCLIB_ATEXIT_SLOTS )
    {
        return -1;
    }
    else
    {
        _PDCLIB_exitstack[ _PDCLIB_exitptr++ ] = func;
        return 0;
    }
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <assert.h>

static int flags[ 32 ];

static void counthandler( void )
{
    static int count = 0;
    flags[ count ] = count;
    ++count;
}

static void checkhandler( void )
{
    int i;

    for ( i = 0; i < 32; ++i )
    {
        assert( flags[ i ] == i );
    }
}

int main( void )
{
    int i;
    TESTCASE( atexit( &checkhandler ) == 0 );

    for ( i = 0; i < 32; ++i )
    {
        TESTCASE( atexit( &counthandler ) == 0 );
    }

    return TEST_RESULTS;
}

#endif
