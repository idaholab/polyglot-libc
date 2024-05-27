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

/* fgetpos( FILE * , fpos_t * ) */

#include <stdio.h>

#ifndef REGTEST

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

int fgetpos( struct _PDCLIB_file_t * _PDCLIB_restrict stream, struct _PDCLIB_fpos_t * _PDCLIB_restrict pos )
{
    _PDCLIB_LOCK( stream->mtx );
    pos->offset = stream->pos.offset + stream->bufidx - stream->ungetidx;
    pos->status = stream->pos.status;
    /* TODO: Add mbstate. */
    _PDCLIB_UNLOCK( stream->mtx );
    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <string.h>

int main( void )
{
    FILE * fh;
    fpos_t pos1, pos2;
    TESTCASE( ( fh = tmpfile() ) != NULL );
    TESTCASE( fgetpos( fh, &pos1 ) == 0 );
    TESTCASE( fwrite( teststring, 1, strlen( teststring ), fh ) == strlen( teststring ) );
    TESTCASE( fgetpos( fh, &pos2 ) == 0 );
    TESTCASE( fsetpos( fh, &pos1 ) == 0 );
    TESTCASE( ftell( fh ) == 0 );
    TESTCASE( fsetpos( fh, &pos2 ) == 0 );
    TESTCASE( ( size_t )ftell( fh ) == strlen( teststring ) );
    TESTCASE( fclose( fh ) == 0 );
    return TEST_RESULTS;
}

#endif
