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

#include <pwd.h>


char __passwd_buf[__PASSWD_BUF_LEN];
struct passwd __passwd_ent;

#if defined(__PASSWD_PATH)
int __passwd_file_exists = 1;
FILE *__passwd_fd = NULL;
#endif


const struct passwd __passwd_list[] = {
    { "root", "", 0, 0, "root", "/", "/bin/sh" },
    { NULL, NULL, 0, 0, NULL, NULL, NULL },
};
const struct passwd *__passwd_list_ptr = NULL;


void __passwd_openfile()
{
#if defined(__PASSWD_PATH)
    if (!__passwd_fd && !__passwd_list_ptr) {
        if (__passwd_file_exists) {
            __passwd_fd = fopen(__PASSWD_PATH, "r");
            __passwd_file_exists = (__passwd_fd != NULL);
        }
        if (__passwd_file_exists) {
            rewind(__passwd_fd);
        } else {
            __passwd_list_ptr = __passwd_list;
        }
    }
#else
    if (!__passwd_list_ptr) {
        __passwd_list_ptr = __passwd_list;
    }
#endif
}


