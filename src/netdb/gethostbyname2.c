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

#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>


#define ROUND(p, n) (((p) + (n) - 1) & -(n))


struct hostent *gethostbyname2(const char *name, int af)
{
    struct hostent *ent;

    // If we are allowed IPv4, check if we were given a bare IPv4 address
    if ((af == AF_INET) || (af == AF_ANY)) {
        if (inet_pton(AF_INET, name, __netdb_host_addrs[0]) == 1) {
            // Clear our structure
            bzero(&__netdb_host_ent, sizeof(__netdb_host_ent));
            // Write the name we were given to our buffer
            snprintf(__netdb_host_buf, sizeof(__netdb_host_buf), "%s", name);
            // Fill our our entry
            __netdb_host_ent = (struct hostent){
                .h_name         = __netdb_host_buf,
                .h_aliases[0]   = __netdb_host_buf,
                .h_addrtype     = AF_INET,
                .h_length       = 4,
                .h_addr_list[0] = __netdb_host_addrs[0],
            };

            ent = &__netdb_host_ent;
            goto finish;
        }
    }

    // If we are allowed IPv6, check if we were given a bare IPv6 address
    if ((af == AF_INET6) || (af == AF_ANY)) {
        if (inet_pton(AF_INET6, name, __netdb_host_addrs[0]) == 1) {
            // Clear our structure
            bzero(&__netdb_host_ent, sizeof(__netdb_host_ent));
            // Write the name we were given to our buffer
            snprintf(__netdb_host_buf, sizeof(__netdb_host_buf), "%s", name);
            // Fill our our entry
            __netdb_host_ent = (struct hostent){
                .h_name         = __netdb_host_buf,
                .h_aliases[0]   = __netdb_host_buf,
                .h_addrtype     = AF_INET6,
                .h_length       = 16,
                .h_addr_list[0] = __netdb_host_addrs[0],
            };

            ent = &__netdb_host_ent;
            goto finish;
        }
    }

    // Open and/or rewind the file
    sethostent(__netdb_host_stayopen);

    // Iterate through records, seeing if they match
    while ((ent = gethostent())) {
        // Filter out other types of addresses
        if ((af != AF_ANY) && (ent->h_addrtype != af))
            continue;
        // Match a name/alias
        if (!strcmp(ent->h_name, name))
            goto finish;
        for (char **alias = ent->h_aliases; *alias; ++alias)
            if (!strcmp(*alias, name))
                goto finish;
    }

// #if defined(__HAVE_DNS)

    struct dns_rr_a4 *r4;
    struct dns_rr_a6 *r6;
    size_t c;

    // We weren't able to find the name locally, so now we check DNS
    if (__netdb_dns_init())
        goto failure;

    // XXX: if we were told to find any type of address, we look up IPv4
    switch (af)
    {
    case AF_ANY:
    case AF_INET:
        if ((r4 = dns_resolve_a4(__netdb_dns_ctx, name, 0)) == NULL)
            break;

        bzero(__netdb_host_buf, sizeof(__netdb_host_buf));

        c = 1 + snprintf(
            __netdb_host_buf, sizeof(__netdb_host_buf),
            "%s", r4->dnsa4_qname
        );
        snprintf(
            __netdb_host_buf + c, sizeof(__netdb_host_buf) - c,
            "%s", r4->dnsa4_cname
        );

        bzero(&__netdb_host_ent, sizeof(__netdb_host_ent));

        __netdb_host_ent.h_name = __netdb_host_buf;
        __netdb_host_ent.h_aliases[0] = __netdb_host_buf + c;
        __netdb_host_ent.h_addrtype = AF_INET;
        __netdb_host_ent.h_length = 4;

        for (int i = 0; i < r4->dnsa4_nrr; ++i) {
            memcpy(
                __netdb_host_addrs[i],
                &r4->dnsa4_addr[i],
                sizeof(struct in_addr)
            );
            __netdb_host_ent.h_addr_list[i] = __netdb_host_addrs[i];
        }

        free(r4);
        ent = &__netdb_host_ent;
        goto finish;

    case AF_INET6:
        if ((r6 = dns_resolve_a6(__netdb_dns_ctx, name, 0)) == NULL)
            break;

        bzero(__netdb_host_buf, sizeof(__netdb_host_buf));

        c = 1 + snprintf(
            __netdb_host_buf, sizeof(__netdb_host_buf),
            "%s", r6->dnsa6_qname
        );
        c = ROUND(c, 8);
        snprintf(
            __netdb_host_buf + c, sizeof(__netdb_host_buf) - c,
            "%s", r6->dnsa6_cname
        );

        bzero(&__netdb_host_ent, sizeof(__netdb_host_ent));

        __netdb_host_ent.h_name = __netdb_host_buf;
        __netdb_host_ent.h_aliases[0] = __netdb_host_buf + c;
        __netdb_host_ent.h_addrtype = AF_INET6;
        __netdb_host_ent.h_length = 16;

        for (int i = 0; i < r6->dnsa6_nrr; ++i) {
            memcpy(
                __netdb_host_addrs[i],
                &r6->dnsa6_addr[i],
                sizeof(struct in6_addr)
            );
            __netdb_host_ent.h_addr_list[i] = __netdb_host_addrs[i];
        }

        free(r6);
        ent = &__netdb_host_ent;
        goto finish;

    default:
        break;
    }

// #endif // __HAVE_DNS

failure:
    // We found nothing, so we return NULL
    ent = NULL;

finish:
    if (!__netdb_host_stayopen)
        endhostent();
    return ent;
}


