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


#define DNS_PORT 53


struct dns_ctx *__netdb_dns_ctx = NULL;
char __netdb_dns_ns[__NETDB_DNS_NS_COUNT][__NETDB_DNS_NS_BUF_SIZE];


static int __netdb_dns_get_nameservers()
{
    char *p, *n;
    int idx = 0;

    // Clear out our list first thing
    bzero(__netdb_dns_ns, sizeof(__netdb_dns_ns));

    // Try to use an environment variable if it was specified
    if (((p = n = getenv("POLYGLOT_NAMESERVERS")) != NULL) && (*p)) {
        do {
            if ((n = strchr(p, ';')))
                *(n++) = 0;
            strncpy(__netdb_dns_ns[idx++], p, __NETDB_DNS_NS_BUF_SIZE);
            p = n;
        } while(n && (idx < __NETDB_DNS_NS_COUNT));
    }
#if defined(__NETDB_RESOLV_PATH)
    else {
        FILE *fd;
        char buf[__NETDB_DNS_NS_BUF_SIZE + 16];
        char *line = buf;

        if ((fd = fopen(__NETDB_RESOLV_PATH, "r")) == NULL)
            goto finish;

        // Try to read a line; break if we hit EOF
        while ((idx < __NETDB_DNS_NS_COUNT) && fgets(buf, sizeof(buf), fd)) {
            line = buf;

            // Strip comments and/or whitespace
            __db_strip_comment(line);
            __db_strip_whitespace(&line);

            // Skip lines that are entirely comments or whitespace
            if (!strlen(line))
                continue;

            // Make sure we only grab nameserver lines
            if (strncmp(line, "nameserver", 10))
                continue;

            // Extract the nameserver from the line
            __db_find_next_token(&line, " \t", " \t");
            strncpy(__netdb_dns_ns[idx++], line, __NETDB_DNS_NS_BUF_SIZE);
        }

        fclose(fd);
    }
#endif

finish:
    return 0;
}


// XXX: this is static because it should only be called via atexit
static void __netdb_dns_finish()
{
    if (__netdb_dns_ctx) {
        dns_close(__netdb_dns_ctx);
        dns_free(__netdb_dns_ctx);
        __netdb_dns_ctx = NULL;
    }
}


int __netdb_dns_init()
{
    int count = 0;

    if (__netdb_dns_ctx == NULL) {
        // Get our set of nameservers before we start the context
        if (__netdb_dns_get_nameservers())
            goto failure;

        // Register an exit handler so we can teardown our DNS properly
        atexit(__netdb_dns_finish);

        // Init the global context (must happen first)
        if (dns_init(NULL, 0) < 0)
            goto failure;
        // Try to create a new DNS context for us to use
        __netdb_dns_ctx = dns_new(NULL);
        if (__netdb_dns_ctx == NULL)
            goto failure;
        // Init our new context
        if (dns_init(__netdb_dns_ctx, 0) < 0)
            goto failure;

        // Try to add all the nameservers we discovered above
        for (int i = 0; i < __NETDB_DNS_NS_COUNT; ++i) {
            if (!__netdb_dns_ns[i][0])
                continue;
            if (dns_add_serv(__netdb_dns_ctx, __netdb_dns_ns[i]) >= 0)
                ++count;
        }
        // Make sure we added at least one nameserver
        if (count == 0)
            goto failure;

        // Try to actually open the DNS context now that it's prepped
        if (dns_open(__netdb_dns_ctx) < 0) {
            // FIXME: make consistent formatting with other errors... add global logging function instead?
            fprintf(stderr, "** failed to open DNS context (%s)\n", dns_strerror(dns_status(__netdb_dns_ctx)));
            goto failure;
        }
    }

    return 0;

failure:
    if (__netdb_dns_ctx) {
        dns_free(__netdb_dns_ctx);
        __netdb_dns_ctx = NULL;
    }
    return 1;
}


