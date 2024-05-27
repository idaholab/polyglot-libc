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

#include <polyglot/db.h>
#include <grp.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#if defined(__GROUP_PATH)
struct group *__getgrent_file()
{
    char *line, *p;

read_line:
    // Try to read a line; return NULL if we hit EOF
    if (!fgets(__group_buf, sizeof(__group_buf), __group_fd))
        return NULL;

    line = __group_buf;

    // Strip comments and/or whitespace
    __db_strip_comment(line);
    __db_strip_whitespace(&line);

    // Skip lines that are entirely comments or whitespace
    if (!strlen(line))
        goto read_line;

    // Initialize the structure
    bzero(&__group_ent, sizeof(__group_ent));

    // Get the name field
    __group_ent.gr_name = line;
    __db_find_next_token(&line, ":", "");

    // Get the encrypted password field
    __group_ent.gr_passwd = line;
    __db_find_next_token(&line, ":", "");

    // Parse the group ID field
    __group_ent.gr_gid = strtoll(line, NULL, 10);
    __db_find_next_token(&line, ":", "");

    // Walk through as many members as we can find on the line
    for (int i = 0; line && *line && (i < __GROUP_MEMBER_COUNT); ++i) {
        __group_ent.gr_mem[i] = line;
        __db_find_next_token(&line, ",", "");
    }

    return &__group_ent;
}
#endif


struct group *__getgrent_list()
{
    if (!__group_list_ptr)
        return NULL;

    if (__group_list_ptr->gr_name) {
        memcpy(
            &__group_ent,
            __group_list_ptr,
            sizeof(struct group)
        );
        ++__group_list_ptr;
        return &__group_ent;
    } else {
        return NULL;
    }
}


struct group *getgrent()
{
    __group_openfile();

#if defined(__GROUP_PATH)
    if (__group_file_exists) {
        return __getgrent_file();
    } else {
        return __getgrent_list();
    }
#else
    return __getgrent_list();
#endif
}


