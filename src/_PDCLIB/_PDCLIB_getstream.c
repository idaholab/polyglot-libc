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
_PDCLIB_getstream( FILE * )
*/

#include <stdio.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_int.h"

extern struct _PDCLIB_file_t * _PDCLIB_filelist;

int _PDCLIB_getstream( struct _PDCLIB_file_t * stream )
{
    struct _PDCLIB_file_t * previous;

    if ( ! _PDCLIB_isstream( stream, &previous ) )
    {
        *_PDCLIB_errno_func() = _PDCLIB_EBADF;
        return EOF;
    }

    if ( previous != NULL )
    {
        previous->next = stream->next;
    }
    else
    {
        _PDCLIB_filelist = stream->next;
    }

    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* No testdriver */
    return TEST_RESULTS;
}

#endif
