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

#include <polyglot/file_at.h>
#include <fcntl.h>
#include <unistd.h>


/* prep for doing an action relative to a file descriptor (fstatat, fopenat,
 * etc.); should always be followed up with __file_at_pop if it succeeds */
int __file_at_push(int *cur_fd, int dest_fd)
{
    if (dest_fd == AT_FDCWD) {
        *cur_fd = -1;
    } else {
        /* XXX: this won't cause recursion (i.e. from an openat shim), because
         * it will go through the previous if-branch */
        if ((*cur_fd = open(".", O_RDONLY | O_DIRECTORY)) == -1)
            return -1;
        // FIXME: what about platforms that don't have fchdir...
        if (fchdir(dest_fd) == -1) {
            close(*cur_fd);
            return -1;
        }
    }
    return 0;
}

/* cleanup what __file_at_push sets up */
int __file_at_pop(int cur_fd)
{
    int result = 0;
    if (cur_fd != -1) {
        result = fchdir(cur_fd);
        close(cur_fd);
    }
    return result;
}

