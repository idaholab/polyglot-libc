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
_PDCLIB_fillbuffer( struct _PDCLIB_file_t * )

This is an example implementation of _PDCLIB_fillbuffer() fit for use with POSIX
kernels.
*/

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

typedef long ssize_t;
extern ssize_t read( int fd, void * buf, size_t count );

int _PDCLIB_fillbuffer( struct _PDCLIB_file_t * stream )
{
    /* No need to handle buffers > INT_MAX, as PDCLib doesn't allow them */
    ssize_t rc = read( stream->handle, stream->buffer, stream->bufsize );

    if ( rc > 0 )
    {
        /* Reading successful. */
        if ( !( stream->status & _PDCLIB_FBIN ) )
        {
            /* TODO: Text stream conversion here */
        }

        stream->pos.offset += rc;
        stream->bufend = rc;
        stream->bufidx = 0;
        return 0;
    }

    if ( rc < 0 )
    {
        /* Flag the stream */
        stream->status |= _PDCLIB_ERRORFLAG;
        return EOF;
    }

    /* End-of-File */
    stream->status |= _PDCLIB_EOFFLAG;
    return EOF;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* Testing covered by ftell.c */
    return TEST_RESULTS;
}

#endif
