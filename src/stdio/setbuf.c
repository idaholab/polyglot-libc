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

/* setbuf( FILE *, char * ) */

#include <stdio.h>

#ifndef REGTEST

void setbuf( struct _PDCLIB_file_t * _PDCLIB_restrict stream, char * _PDCLIB_restrict buf )
{
    if ( buf == NULL )
    {
        setvbuf( stream, buf, _IONBF, BUFSIZ );
    }
    else
    {
        setvbuf( stream, buf, _IOFBF, BUFSIZ );
    }
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <stdlib.h>

int main( void )
{
    /* TODO: Extend testing once setvbuf() is finished. */
#ifndef REGTEST
    char buffer[ BUFSIZ + 1 ];
    FILE * fh;
    /* full buffered */
    TESTCASE( ( fh = tmpfile() ) != NULL );
    setbuf( fh, buffer );
    TESTCASE( fh->buffer == buffer );
    TESTCASE( fh->bufsize == BUFSIZ );
    TESTCASE( ( fh->status & ( _IOFBF | _IONBF | _IOLBF ) ) == _IOFBF );
    TESTCASE( fclose( fh ) == 0 );
    /* not buffered */
    TESTCASE( ( fh = tmpfile() ) != NULL );
    setbuf( fh, NULL );
    TESTCASE( ( fh->status & ( _IOFBF | _IONBF | _IOLBF ) ) == _IONBF );
    TESTCASE( fclose( fh ) == 0 );
#else
    puts( " NOTEST setbuf() test driver is PDCLib-specific." );
#endif
    return TEST_RESULTS;
}

#endif
