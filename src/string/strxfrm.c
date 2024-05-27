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

/* strxfrm( char *, const char *, size_t ) */

#include <string.h>

#ifndef REGTEST

#include <locale.h>

size_t strxfrm( char * _PDCLIB_restrict s1, const char * _PDCLIB_restrict s2, size_t n )
{
    size_t len = strlen( s2 );

    if ( len < n )
    {
        /* Cannot use strncpy() here as the filling of s1 with '\0' is not part
           of the spec.
        */
        /* FIXME: This should access _PDCLIB_lc_collate. */
        while ( n-- && ( *s1++ = ( unsigned char )*s2++ ) )
        {
            /* EMPTY */
        }
    }

    return len;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    char s[] = "xxxxxxxxxxx";
    TESTCASE( strxfrm( NULL, "123456789012", 0 ) == 12 );
    TESTCASE( strxfrm( s, "123456789012", 12 ) == 12 );
    /*
    The following test case is true in *this* implementation, but doesn't have to.
    TESTCASE( s[0] == 'x' );
    */
    TESTCASE( strxfrm( s, "1234567890", 11 ) == 10 );
    TESTCASE( s[0] == '1' );
    TESTCASE( s[9] == '0' );
    TESTCASE( s[10] == '\0' );
    return TEST_RESULTS;
}

#endif
