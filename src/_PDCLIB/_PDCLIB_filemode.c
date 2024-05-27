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
_PDCLIB_filemode( const char * )

Helper function that parses the C-style mode string passed to fopen() into the
PDCLib flags FREAD, FWRITE, FAPPEND, FRW (read-write) and FBIN (binary mode).
*/

#include <stdio.h>

#ifndef REGTEST

unsigned int _PDCLIB_filemode( const char * const mode )
{
    unsigned rc = 0;
    size_t i;

    if ( mode == NULL )
    {
        return 0;
    }

    switch ( mode[0] )
    {
        case 'r':
            rc |= _PDCLIB_FREAD;
            break;

        case 'w':
            rc |= _PDCLIB_FWRITE;
            break;

        case 'a':
            rc |= _PDCLIB_FAPPEND | _PDCLIB_FWRITE;
            break;

        default:
            /* Other than read, write, or append - invalid */
            return 0;
    }

    for ( i = 1; i < 4; ++i )
    {
        switch ( mode[i] )
        {
            case '+':
                if ( rc & _PDCLIB_FRW )
                {
                    /* Duplicates are invalid */
                    return 0;
                }

                rc |= _PDCLIB_FRW;
                break;

            case 'b':
                if ( rc & _PDCLIB_FBIN )
                {
                    /* Duplicates are invalid */
                    return 0;
                }

                rc |= _PDCLIB_FBIN;
                break;

            case '\0':
                /* End of mode */
                return rc;

            default:
                /* Other than read/write or binary - invalid. */
                return 0;
        }
    }

    /* Longer than three chars - invalid. */
    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    TESTCASE( _PDCLIB_filemode( "r" ) == _PDCLIB_FREAD );
    TESTCASE( _PDCLIB_filemode( "w" ) == _PDCLIB_FWRITE );
    TESTCASE( _PDCLIB_filemode( "a" ) == ( _PDCLIB_FAPPEND | _PDCLIB_FWRITE ) );
    TESTCASE( _PDCLIB_filemode( "r+" ) == ( _PDCLIB_FREAD | _PDCLIB_FRW ) );
    TESTCASE( _PDCLIB_filemode( "w+" ) == ( _PDCLIB_FWRITE | _PDCLIB_FRW ) );
    TESTCASE( _PDCLIB_filemode( "a+" ) == ( _PDCLIB_FAPPEND | _PDCLIB_FWRITE | _PDCLIB_FRW ) );
    TESTCASE( _PDCLIB_filemode( "rb" ) == ( _PDCLIB_FREAD | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "wb" ) == ( _PDCLIB_FWRITE | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "ab" ) == ( _PDCLIB_FAPPEND | _PDCLIB_FWRITE | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "r+b" ) == ( _PDCLIB_FREAD | _PDCLIB_FRW | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "w+b" ) == ( _PDCLIB_FWRITE | _PDCLIB_FRW | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "a+b" ) == ( _PDCLIB_FAPPEND | _PDCLIB_FWRITE | _PDCLIB_FRW | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "rb+" ) == ( _PDCLIB_FREAD | _PDCLIB_FRW | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "wb+" ) == ( _PDCLIB_FWRITE | _PDCLIB_FRW | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "ab+" ) == ( _PDCLIB_FAPPEND | _PDCLIB_FWRITE | _PDCLIB_FRW | _PDCLIB_FBIN ) );
    TESTCASE( _PDCLIB_filemode( "x" ) == 0 );
    TESTCASE( _PDCLIB_filemode( "r++" ) == 0 );
    TESTCASE( _PDCLIB_filemode( "wbb" ) == 0 );
    TESTCASE( _PDCLIB_filemode( "a+bx" ) == 0 );
#endif
    return TEST_RESULTS;
}

#endif
