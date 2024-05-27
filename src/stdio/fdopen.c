/* This file is part of the Polyglot C Library.

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

/* fdopen( int, const char * ) */

#include <stdio.h>
#include <stdlib.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <string.h>

#ifndef __STDC_NO_THREADS__
#include <threads.h>
extern mtx_t _PDCLIB_filelist_mtx;
#endif

extern struct _PDCLIB_file_t * _PDCLIB_filelist;

struct _PDCLIB_file_t * fdopen( int fd, const char * _PDCLIB_restrict mode )
{
    struct _PDCLIB_file_t * rc;
    unsigned int filemode = _PDCLIB_filemode( mode );

    if ( filemode == 0 )
    {
        /* mode invalid */
        return NULL;
    }

    /* See tmpfile(), which does much of the same. */

    if ( ( rc = _PDCLIB_init_file_t( NULL ) ) == NULL )
    {
        /* initializing FILE structure failed */
        return NULL;
    }

    /* Setting buffer to _IOLBF because "when opened, a stream is fully
       buffered if and only if it can be determined not to refer to an
       interactive device."
    */
    rc->status |= filemode | _IOLBF;

    if ( ( rc->handle = fd ) == _PDCLIB_NOHANDLE )
    {
        /* We were given an invalid descriptor */
#ifndef __STDC_NO_THREADS__
        mtx_destroy( &rc->mtx );
#endif
        free( rc->buffer );
        free( rc );
        return NULL;
    }

    /* Set our filename to NULL */
    rc->filename = NULL;

    /* Adding to list of open files */
    _PDCLIB_LOCK( _PDCLIB_filelist_mtx );
    rc->next = _PDCLIB_filelist;
    _PDCLIB_filelist = rc;
    _PDCLIB_UNLOCK( _PDCLIB_filelist_mtx );
    return rc;
}

#endif

