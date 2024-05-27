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

/* fclose( FILE * ) */

#include <stdio.h>
#include <stdlib.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
extern mtx_t _PDCLIB_filelist_mtx;
#endif

extern struct _PDCLIB_file_t * _PDCLIB_filelist;

int fclose( struct _PDCLIB_file_t * stream )
{
    _PDCLIB_LOCK( _PDCLIB_filelist_mtx );
    _PDCLIB_LOCK( stream->mtx );

    /* Flush buffer */
    if ( stream->status & _PDCLIB_FWRITE )
    {
        if ( _PDCLIB_flushbuffer( stream ) == EOF )
        {
            /* Flush failed, errno already set */
            _PDCLIB_UNLOCK( stream->mtx );
            _PDCLIB_UNLOCK( _PDCLIB_filelist_mtx );
            return EOF;
        }
    }

    /* Close handle */
    _PDCLIB_close( stream->handle );

    /* Remove stream from list */
    if ( _PDCLIB_getstream( stream ) )
    {
        _PDCLIB_UNLOCK( stream->mtx );
        _PDCLIB_UNLOCK( _PDCLIB_filelist_mtx );
        return EOF;
    }

    /* Delete tmpfile() */
    if ( stream->status & _PDCLIB_DELONCLOSE )
    {
        _PDCLIB_remove( stream->filename );
    }

    /* Free buffer */
    if ( stream->status & _PDCLIB_FREEBUFFER )
    {
        free( stream->buffer );
    }

    /* Free filename (standard streams do not have one, but free( NULL )
       is a valid no-op)
    */
    free( stream->filename );

    _PDCLIB_UNLOCK( stream->mtx );

#ifndef __STDC_NO_THREADS__
    mtx_destroy( &stream->mtx );
#endif

    /* Free stream */
    if ( stream != stdin && stream != stdout && stream != stderr )
    {
        free( stream );
    }

    _PDCLIB_UNLOCK( _PDCLIB_filelist_mtx );

    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
#ifndef REGTEST
    struct _PDCLIB_file_t * file1;
    struct _PDCLIB_file_t * file2;
    remove( testfile1 );
    remove( testfile2 );
    TESTCASE( _PDCLIB_filelist == stdin );
    TESTCASE( ( file1 = fopen( testfile1, "w" ) ) != NULL );
    TESTCASE( _PDCLIB_filelist == file1 );
    TESTCASE( ( file2 = fopen( testfile2, "w" ) ) != NULL );
    TESTCASE( _PDCLIB_filelist == file2 );
    TESTCASE( fclose( file2 ) == 0 );
    TESTCASE( _PDCLIB_filelist == file1 );
    TESTCASE( ( file2 = fopen( testfile2, "w" ) ) != NULL );
    TESTCASE( _PDCLIB_filelist == file2 );
    TESTCASE( fclose( file1 ) == 0 );
    TESTCASE( _PDCLIB_filelist == file2 );
    TESTCASE( fclose( file2 ) == 0 );
    TESTCASE( _PDCLIB_filelist == stdin );
    TESTCASE( remove( testfile1 ) == 0 );
    TESTCASE( remove( testfile2 ) == 0 );
#else
    puts( " NOTEST fclose() test driver is PDCLib-specific." );
#endif
    return TEST_RESULTS;
}

#endif
