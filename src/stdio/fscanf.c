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

/* fscanf( FILE *, const char *, ... ) */

#include <stdio.h>
#include <stdarg.h>

#ifndef REGTEST

int fscanf( FILE * _PDCLIB_restrict stream, const char * _PDCLIB_restrict format, ... )
{
    int rc;
    va_list ap;
    va_start( ap, format );
    rc = vfscanf( stream, format, ap );
    va_end( ap );
    return rc;
}

#endif

#ifdef TEST
#define _PDCLIB_FILEID "stdio/fscanf.c"
#define _PDCLIB_FILEIO

#include "_PDCLIB_test.h"

#define testscanf( stream, format, ... ) fscanf( stream, format, __VA_ARGS__ )

int main( void )
{
    FILE * source;
    TESTCASE( ( source = fopen( testfile, "wb+" ) ) != NULL );
#include "scanf_testcases.h"
    TESTCASE( fclose( source ) == 0 );
    return TEST_RESULTS;
}

#endif
