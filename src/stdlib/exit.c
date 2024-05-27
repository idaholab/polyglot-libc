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

/* exit( int ) */

#include <stdlib.h>

#ifndef REGTEST

/* TODO - "...except that a function is called after any previously registered
   functions that had already been called at the time it was registered."
*/

void ( *_PDCLIB_exitstack[ _PDCLIB_ATEXIT_SLOTS ] )( void );
size_t _PDCLIB_exitptr = 0;

void exit( int status )
{
    while ( _PDCLIB_exitptr != 0 )
    {
        _PDCLIB_exitstack[ --_PDCLIB_exitptr ]();
    }

    _Exit( status );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* Unwinding of regstack tested in atexit(). */
    return TEST_RESULTS;
}

#endif
