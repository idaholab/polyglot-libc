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

#include <grp.h>


char __group_buf[__GROUP_BUF_LEN];
struct group __group_ent;

#if defined(__GROUP_PATH)
int __group_file_exists = 1;
FILE *__group_fd = NULL;
#endif


const struct group __group_list[] = {
    { "root", "", 0, { "root", NULL } },
    { NULL, NULL, 0, { NULL } },
};
const struct group *__group_list_ptr = NULL;


void __group_openfile()
{
#if defined(__GROUP_PATH)
    if (!__group_fd && !__group_list_ptr) {
        if (__group_file_exists) {
            __group_fd = fopen(__GROUP_PATH, "r");
            __group_file_exists = (__group_fd != NULL);
        }
        if (__group_file_exists) {
            rewind(__group_fd);
        } else {
            __group_list_ptr = __group_list;
        }
    }
#else
    if (!__group_list_ptr) {
        __group_list_ptr = __group_list;
    }
#endif
}


