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

/* int fileno( FILE * ) */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifndef __STDC_NO_THREADS__
#include <threads.h>
#endif

int fileno( struct _PDCLIB_file_t *rc )
{
    int handle;

    if (rc == NULL) {
        errno = EBADF;
        handle = -1;
    } else {
#ifndef __STDC_NO_THREADS__
    _PDCLIB_LOCK( &rc->mtx );
#endif
        handle = rc->handle;
#ifndef __STDC_NO_THREADS__
    _PDCLIB_UNLOCK( &rc->mtx );
#endif
    }

    return handle;
}

#endif

