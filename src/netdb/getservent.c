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
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#if defined(__NETDB_SERV_PATH)
struct servent *__getservent_file()
{
    char *line;

read_line:
    // Try to read a line; return NULL if we hit EOF
    if (!fgets(__netdb_serv_buf, sizeof(__netdb_serv_buf), __netdb_serv_fd))
        return NULL;

    line = __netdb_serv_buf;

    // Strip comments and/or whitespace
    __db_strip_comment(line);
    __db_strip_whitespace(&line);

    // Skip lines that are entirely comments or whitespace
    if (!strlen(line))
        goto read_line;

    // Initialize the structure
    bzero(&__netdb_serv_ent, sizeof(struct servent));

    __netdb_serv_ent.s_name = line;
    __db_find_next_token(&line, " \t", " \t");

    __netdb_serv_ent.s_port = atoi(line);
    __db_find_next_token(&line, "/", "");

    __netdb_serv_ent.s_proto = line;
    __db_find_next_token(&line, " \t", " \t");

    // Walk through as many aliases as we can find on the line
    for (int i = 0; line && (i < __NETDB_SERV_ALIAS_COUNT); ++i) {
        __netdb_serv_ent.s_aliases[i] = line;
        __db_find_next_token(&line, " \t", " \t");
    }

    return &__netdb_serv_ent;
}
#endif


struct servent *__getservent_list()
{
    if (__netdb_serv_list_ptr->s_name) {
        memcpy(
            &__netdb_serv_ent,
            __netdb_serv_list_ptr,
            sizeof(struct servent)
        );
        ++__netdb_serv_list_ptr;
        return &__netdb_serv_ent;
    } else {
        return NULL;
    }
}


struct servent *getservent()
{
    __netdb_serv_openfile();

#if defined(__NETDB_SERV_PATH)
    if (__netdb_serv_file_exists) {
        return __getservent_file();
    } else {
        return __getservent_list();
    }
#else
    return __getservent_list();
#endif
}


