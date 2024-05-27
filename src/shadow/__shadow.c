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

#include <shadow.h>


char __shadow_buf[__SHADOW_BUF_LEN];
struct spwd __shadow_ent;

#if defined(__SHADOW_PATH)
int __shadow_file_exists = 1;
FILE *__shadow_fd = NULL;
#endif

const struct spwd __shadow_list[] = {
    { "root", "jm21kNvMWaWyI", 1, -1, -1, -1, -1, -1, 0 },
    { NULL, NULL, 0, 0, 0, 0, 0, 0, 0 },
};
const struct spwd *__shadow_list_ptr = NULL;


void __shadow_openfile()
{
#if defined(__SHADOW_PATH)
    if (!__shadow_fd && !__shadow_list_ptr) {
        if (__shadow_file_exists) {
            __shadow_fd = fopen(__SHADOW_PATH, "r");
            __shadow_file_exists = (__shadow_fd != NULL);
        }
        if (__shadow_file_exists) {
            rewind(__shadow_fd);
        } else {
            __shadow_list_ptr = __shadow_list;
        }
    }
#else
    if (!__shadow_list_ptr) {
        __shadow_list_ptr = __shadow_list;
    }
#endif
}


