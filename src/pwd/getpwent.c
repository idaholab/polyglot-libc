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
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#if defined(__PASSWD_PATH)
struct passwd *__getpwent_file()
{
    char *line, *p;

read_line:
    // Try to read a line; return NULL if we hit EOF
    if (!fgets(__passwd_buf, sizeof(__passwd_buf), __passwd_fd))
        return NULL;

    line = __passwd_buf;

    // Strip comments and/or whitespace
    __db_strip_comment(line);
    __db_strip_whitespace(&line);

    // Skip lines that are entirely comments or whitespace
    if (!strlen(line))
        goto read_line;

    // Initialize the structure
    bzero(&__passwd_ent, sizeof(__passwd_ent));

    // Get the name field
    __passwd_ent.pw_name = line;
    __db_find_next_token(&line, ":", "");

    // Get the encrypted password field
    __passwd_ent.pw_passwd = line;
    __db_find_next_token(&line, ":", "");

    // Parse the user ID field
    __passwd_ent.pw_uid = strtoll(line, NULL, 10);
    __db_find_next_token(&line, ":", "");

    // Parse the group ID field
    __passwd_ent.pw_gid = strtoll(line, NULL, 10);
    __db_find_next_token(&line, ":", "");

    // Get the full name field
    __passwd_ent.pw_gecos = line;
    __db_find_next_token(&line, ":", "");

    // Get the home dir field
    __passwd_ent.pw_dir = line;
    __db_find_next_token(&line, ":", "");

    // Get the shell field
    __passwd_ent.pw_shell = line;
    __db_find_next_token(&line, ":", "");

    return &__passwd_ent;
}
#endif


struct passwd *__getpwent_list()
{
    if (!__passwd_list_ptr)
        return NULL;

    if (__passwd_list_ptr->pw_name) {
        memcpy(
            &__passwd_ent,
            __passwd_list_ptr,
            sizeof(struct passwd)
        );
        ++__passwd_list_ptr;
        return &__passwd_ent;
    } else {
        return NULL;
    }
}


struct passwd *getpwent()
{
    __passwd_openfile();

#if defined(__PASSWD_PATH)
    if (__passwd_file_exists) {
        return __getpwent_file();
    } else {
        return __getpwent_list();
    }
#else
    return __getpwent_list();
#endif
}


