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


#if defined(__NETDB_HOST_PATH)
struct hostent *__gethostent_file()
{
    char *line, *p;

read_line:
    // Try to read a line; return NULL if we hit EOF
    if (!fgets(__netdb_host_buf, sizeof(__netdb_host_buf), __netdb_host_fd))
        return NULL;

    line = __netdb_host_buf;

    // Strip comments and/or whitespace
    __db_strip_comment(line);
    __db_strip_whitespace(&line);

    // Skip lines that are entirely comments or whitespace
    if (!strlen(line))
        goto read_line;

    // Initialize the structure
    bzero(&__netdb_host_ent, sizeof(__netdb_host_ent));
    bzero(&__netdb_host_addrs, sizeof(__netdb_host_addrs));

    // Store the pointer to the start of the line, and find the next token;
    // we do it this way to null-terminate the IP address.
    p = line;
    __db_find_next_token(&line, " \t", " \t");

    // Attempt to parse IPv4/IPv6 addresses at our pointer.
    if (inet_pton(AF_INET, p, __netdb_host_addrs[0]) == 1) {
        __netdb_host_ent.h_addrtype = AF_INET;
        __netdb_host_ent.h_length = 4;
        __netdb_host_ent.h_addr_list[0] = __netdb_host_addrs[0];
    } else if (inet_pton(AF_INET6, p, __netdb_host_addrs[0]) == 1) {
        __netdb_host_ent.h_addrtype = AF_INET6;
        __netdb_host_ent.h_length = 16;
        __netdb_host_ent.h_addr_list[0] = __netdb_host_addrs[0];
    } else {
        // The line was invalid, we just continue with the next line.
        goto read_line;
    }

    // Store the pointer to the name, then walk the line for another token
    __netdb_host_ent.h_name = line;
    __db_find_next_token(&line, " \t", " \t");

    // Walk through as many aliases as we can find on the line
    for (int i = 0; line && (i < __NETDB_PROTO_ALIAS_COUNT); ++i) {
        __netdb_host_ent.h_aliases[i] = line;
        __db_find_next_token(&line, " \t", " \t");
    }

    return &__netdb_host_ent;
}
#endif


struct hostent *__gethostent_list()
{
    if (!__netdb_host_list_ptr)
        return NULL;

    if (__netdb_host_list_ptr->h_name) {
        memcpy(
            &__netdb_host_ent,
            __netdb_host_list_ptr,
            sizeof(struct hostent)
        );
        ++__netdb_host_list_ptr;
        return &__netdb_host_ent;
    } else {
        return NULL;
    }
}


struct hostent *gethostent()
{
    __netdb_host_openfile();

#if defined(__NETDB_HOST_PATH)
    if (__netdb_host_file_exists) {
        return __gethostent_file();
    } else {
        return __gethostent_list();
    }
#else
    return __gethostent_list();
#endif
}


