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
#include <shadow.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#if defined(__SHADOW_PATH)
struct spwd *__getspent_file()
{
    char *line, *p;

read_line:
    // Try to read a line; return NULL if we hit EOF
    if (!fgets(__shadow_buf, sizeof(__shadow_buf), __shadow_fd))
        return NULL;

    line = __shadow_buf;

    // Strip comments and/or whitespace
    __db_strip_comment(line);
    __db_strip_whitespace(&line);

    // Skip lines that are entirely comments or whitespace
    if (!strlen(line))
        goto read_line;

    // Initialize the structure
    bzero(&__shadow_ent, sizeof(__shadow_ent));

    // Get the name field
    __shadow_ent.sp_namp = line;
    __db_find_next_token(&line, ":", "");

    // Get the encrypted password field
    __shadow_ent.sp_pwdp = line;
    __db_find_next_token(&line, ":", "");

    // Parse the last change date
    __shadow_ent.sp_lstchg = strtoll(line, NULL, 10);
    __db_find_next_token(&line, ":", "");

    // Parse the min days to password change
    if (*line == ':') {
        __shadow_ent.sp_min = -1;
        ++line;
    } else {
        __shadow_ent.sp_min = strtoll(line, NULL, 10);
        __db_find_next_token(&line, ":", "");
    }

    // Parse the max days to password change
    if (*line == ':') {
        __shadow_ent.sp_max = -1;
        ++line;
    } else {
        __shadow_ent.sp_max = strtoll(line, NULL, 10);
        __db_find_next_token(&line, ":", "");
    }

    // Parse the warning period
    if (*line == ':') {
        __shadow_ent.sp_warn = -1;
        ++line;
    } else {
        __shadow_ent.sp_warn = strtoll(line, NULL, 10);
        __db_find_next_token(&line, ":", "");
    }

    // Parse the inactive day count
    if (*line == ':') {
        __shadow_ent.sp_inact = -1;
        ++line;
    } else {
        __shadow_ent.sp_inact = strtoll(line, NULL, 10);
        __db_find_next_token(&line, ":", "");
    }

    // Parse the expiry day count
    if (*line == ':') {
        __shadow_ent.sp_expire = -1;
        ++line;
    } else {
        __shadow_ent.sp_expire = strtoll(line, NULL, 10);
        __db_find_next_token(&line, ":", "");
    }

    // Parse the flags field
    if (*line == 0) {
        __shadow_ent.sp_flag = 0;
    } else {
        __shadow_ent.sp_flag = strtoll(line, NULL, 10);
        __db_find_next_token(&line, ":", "");
    }

    return &__shadow_ent;
}
#endif


struct spwd *__getspent_list()
{
    if (!__shadow_list_ptr)
        return NULL;

    if (__shadow_list_ptr->sp_namp) {
        memcpy(
            &__shadow_ent,
            __shadow_list_ptr,
            sizeof(struct spwd)
        );
        ++__shadow_list_ptr;
        return &__shadow_ent;
    } else {
        return NULL;
    }
}


struct spwd *getspent()
{
    __shadow_openfile();

#if defined(__SHADOW_PATH)
    if (__shadow_file_exists) {
        return __getspent_file();
    } else {
        return __getspent_list();
    }
#else
    return __getspent_list();
#endif
}


