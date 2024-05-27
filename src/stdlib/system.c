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

/* system( const char * ) */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* This is an example implementation of system() fit for use with POSIX kernels.
*/

int system(const char * string)
{
    int result;
    const char * argv[] = { "sh", "-c", NULL, NULL };
    argv[2] = string;

    if (string != NULL) {
        int pid = fork();

        if (pid == 0) {
            execve( "/bin/sh", ( char ** const )argv, NULL );
        } else if (pid > 0) {
            if (waitpid(pid, &result, 0) == -1) {
                return -1;
            }
            if (WIFEXITED(result)) {
                return WEXITSTATUS(result);
            } else if (WIFSIGNALED(result)) {
                return -WTERMSIG(result);
            } else {
                /* FIXME: what should we return here? */
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return (system("echo") == 0 ? 1 : 0);
    }
}

#ifdef TEST

#include "_PDCLIB_test.h"

#define SHELLCOMMAND "echo 'SUCCESS testing system()'"

int main( void )
{
    FILE * fh;
    char buffer[25];
    buffer[24] = 'x';
    TESTCASE( ( fh = freopen( testfile, "wb+", stdout ) ) != NULL );
    TESTCASE( system( SHELLCOMMAND ) );
    rewind( fh );
    TESTCASE( fread( buffer, 1, 24, fh ) == 24 );
    TESTCASE( memcmp( buffer, "SUCCESS testing system()", 24 ) == 0 );
    TESTCASE( buffer[24] == 'x' );
    TESTCASE( fclose( fh ) == 0 );
    TESTCASE( remove( testfile ) == 0 );
    return TEST_RESULTS;
}

#endif
