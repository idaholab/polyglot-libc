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

#ifndef _POLYGLOT_FILE_AT_H
#define _POLYGLOT_FILE_AT_H _POLYGLOT_FILE_AT_H

#define __file_at_context(fd, ...) \
    { \
        int cur_fd; \
        if (__file_at_push(&cur_fd, fd) == -1) \
            return -1; \
        __VA_ARGS__ \
        if (__file_at_pop(cur_fd) == -1) \
            return -1; \
    }

int __file_at_push(int *cur_fd, int dest_fd);
int __file_at_pop(int cur_fd);

#endif // _POLYGLOT_FILE_AT_H
