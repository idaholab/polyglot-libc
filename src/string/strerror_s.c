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

/* strerror_s( char *, rsize_t, errno_t ) */

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef REGTEST

#include <locale.h>

errno_t strerror_s( char * s, rsize_t maxsize, errno_t errnum )
{
    size_t len = strerrorlen_s( errnum );

    if ( s == NULL || maxsize > RSIZE_MAX || maxsize == 0 )
    {
        _PDCLIB_constraint_handler( _PDCLIB_CONSTRAINT_VIOLATION( _PDCLIB_EINVAL ) );
        return _PDCLIB_EINVAL;
    }

    if ( len < maxsize )
    {
        strcpy( s, strerror( errnum ) );
    }
    else
    {
        strncpy( s, strerror( errnum ), maxsize - 1 );

        if ( maxsize > 3 )
        {
            strcpy( &s[ maxsize - 4 ], "..." );
        }
        else
        {
            s[ maxsize - 1 ] = '\0';
        }
    }

    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <stdio.h>
#include <errno.h>

int main( void )
{
#if ! defined( REGTEST ) || defined( __STDC_LIB_EXT1__ )
    /* FIXME: reimplement to not use _PDCLIB_ERRNO_MAX */
    /*
    char s[14];
    TESTCASE( strerror_s( s, 14, _PDCLIB_ERRNO_MAX ) == 0 );
    TESTCASE( strcmp( s, "unknown error" ) == 0 );
    TESTCASE( strerror_s( s, 13, _PDCLIB_ERRNO_MAX ) == 0 );
    TESTCASE( strcmp( s, "unknown e..." ) == 0 );
    */
#endif
    return TEST_RESULTS;
}

#endif
