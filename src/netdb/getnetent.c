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


#if defined(__NETDB_NET_PATH)
struct netent *__getnetent_file()
{
    char *line, *p;

read_line:
    // Try to read a line; return NULL if we hit EOF
    if (!fgets(__netdb_net_buf, sizeof(__netdb_net_buf), __netdb_net_fd))
        return NULL;

    line = __netdb_net_buf;

    // Strip comments and/or whitespace
    __db_strip_comment(line);
    __db_strip_whitespace(&line);

    // Skip lines that are entirely comments or whitespace
    if (!strlen(line))
        goto read_line;

    // Initialize the structure
    bzero(&__netdb_net_ent, sizeof(struct netent));

    // Store the pointer to the name, then walk the line for another token
    __netdb_net_ent.n_name = line;
    __db_find_next_token(&line, " \t", " \t");

    // Network address type is always AF_INET, never AF_INET6
    __netdb_net_ent.n_addrtype = AF_INET;

    // Find the next token, then use our saved position as a null-terminated
    // network address to attempt to parse
    p = line;
    __db_find_next_token(&line, " \t", " \t");
    if (inet_aton(p, (struct in_addr *)&__netdb_net_ent.n_net) != 1)
        goto read_line;
    __netdb_net_ent.n_net = ntohl(__netdb_net_ent.n_net);

    // Walk through as many aliases as we can find on the line
    for (int i = 0; line && (i < __NETDB_NET_ALIAS_COUNT); ++i) {
        __netdb_net_ent.n_aliases[i] = line;
        __db_find_next_token(&line, " \t", " \t");
    }

    return &__netdb_net_ent;
}
#endif


struct netent *__getnetent_list()
{
    if (__netdb_net_list_ptr->n_name) {
        memcpy(
            &__netdb_net_ent,
            __netdb_net_list_ptr,
            sizeof(struct netent)
        );
        ++__netdb_net_list_ptr;
        return &__netdb_net_ent;
    } else {
        return NULL;
    }
}


struct netent *getnetent()
{
    __netdb_net_openfile();

#if defined(__NETDB_NET_PATH)
    if (__netdb_net_file_exists) {
        return __getnetent_file();
    } else {
        return __getnetent_list();
    }
#else
    return __getnetent_list();
#endif
}


