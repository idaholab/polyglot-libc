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
int_least64_t _PDCLIB_seek( FILE *, int_least64_t, int )

This is an example implementation of _PDCLIB_seek() fit for use with POSIX
kernels.
 */

#ifndef REGTEST

#include <stdio.h>
#include <stdint.h>

#include "pdclib/_PDCLIB_glue.h"

extern int64_t lseek64( int fd, _PDCLIB_int_least64_t offset, int whence );
extern long lseek( int fd, long offset, int whence );

_PDCLIB_int_least64_t _PDCLIB_seek( struct _PDCLIB_file_t * stream, _PDCLIB_int_least64_t offset, int whence )
{
    _PDCLIB_int_least64_t rc;

    switch ( whence )
    {
        case SEEK_SET:
        case SEEK_CUR:
        case SEEK_END:
            /* EMPTY - OK */
            break;

        default:
            *_PDCLIB_errno_func() = _PDCLIB_EINVAL;
            return EOF;
            break;
    }

#ifdef __CYGWIN__
    rc = lseek( stream->handle, offset, whence );
#else
    rc = lseek64( stream->handle, offset, whence );
#endif

    if ( rc != EOF )
    {
        stream->ungetidx = 0;
        stream->bufidx = 0;
        stream->bufend = 0;
        stream->pos.offset = rc;
        return rc;
    }

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
