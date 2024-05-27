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

#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <netdb.h>
#include <udns.h>


static struct addrinfo *newaddrinfo()
{
    struct addrinfo *addr;

    addr = (struct addrinfo *)malloc(sizeof(struct addrinfo));
    bzero(addr, sizeof(struct addrinfo));

    return addr;
}

static struct sockaddr *newsockaddr4(struct in_addr addr, in_port_t port)
{
    struct sockaddr_in *sa4;

    sa4 = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    bzero(sa4, sizeof(struct sockaddr_in));
    sa4->sin_family = AF_INET;
    sa4->sin_addr = addr;
    sa4->sin_port = htons(port);

    return (struct sockaddr *)sa4;
}

static struct sockaddr *newsockaddr6(struct in6_addr addr, in_port_t port)
{
    struct sockaddr_in6 *sa6;

    sa6 = (struct sockaddr_in6 *)malloc(sizeof(struct sockaddr_in6));
    bzero(sa6, sizeof(struct sockaddr_in6));
    sa6->sin6_family = AF_INET6;
    sa6->sin6_addr = addr;
    sa6->sin6_port = htons(port);

    return (struct sockaddr *)sa6;
}


#define ERROR(n) \
    { \
        e = (n); \
        goto error; \
    }


int getaddrinfo(const char *restrict hostname, const char *restrict servname,
        const struct addrinfo *restrict hints, struct addrinfo **restrict res)
{
    int e = 0;
    char *p;
    int family;
    struct addrinfo *head = NULL, *ptr = NULL;
    struct in_addr in4;
    struct in6_addr in6;
    in_port_t port;
    int proto;
    struct hostent *he = NULL;
    struct servent *se = NULL;

    if (!hostname && !servname)
        ERROR(EAI_NONAME);

    head = newaddrinfo();

    if (hints) {
        family = hints->ai_family;
        head->ai_socktype = hints->ai_socktype;
        head->ai_protocol = hints->ai_protocol;
        head->ai_flags = hints->ai_flags;
    } else {
        family = AF_UNSPEC;
        head->ai_socktype = 0;
        head->ai_protocol = 0;
        head->ai_flags = 0;
    }

do_service:
    port = (in_port_t)strtol(servname, &p, 10);
    if (servname != p)
        goto do_protocol;
    else if (head->ai_flags & AI_NUMERICSERV)
        ERROR(EAI_NONAME);

    switch (head->ai_protocol)
    {
    case 0:
        p = NULL;
        break;
    case IPPROTO_TCP:
        p = "tcp";
        break;
    case IPPROTO_UDP:
        p = "udp";
        break;
    default:
        ERROR(EAI_SERVICE);
    }

    if ((se = getservbyname(servname, p)) == NULL)
        ERROR(EAI_SERVICE);

    port = se->s_port;

do_protocol:
    if (!head->ai_protocol) {
        // XXX: other platforms seem to default to UDP if service isn't known
        if (!se) {
            head->ai_protocol = IPPROTO_UDP;
        } else if (!memcmp(se->s_proto, "tcp\0", 4)) {
            head->ai_protocol = IPPROTO_TCP;
        } else if (!memcmp(se->s_proto, "udp\0", 4)) {
            head->ai_protocol = IPPROTO_UDP;
        } else {
            ERROR(EAI_SERVICE);
        }
    }
    if (!head->ai_socktype) {
        switch (head->ai_protocol)
        {
        case IPPROTO_TCP:
            head->ai_socktype = SOCK_STREAM;
            break;
        case IPPROTO_UDP:
            head->ai_socktype = SOCK_DGRAM;
            break;
        default:
            ERROR(EAI_SERVICE);
        }
    }

do_numerichost4:
    if ((family == AF_INET) || (family == AF_UNSPEC)) {
        if (inet_pton(AF_INET, hostname, &in4) != 1)
            goto do_numerichost6;

        head->ai_family = AF_INET;
        head->ai_addrlen = sizeof(struct sockaddr_in);
        head->ai_addr = newsockaddr4(in4, port);

        goto finish;
    }

do_numerichost6:
    if ((family == AF_INET6) || (family == AF_UNSPEC)) {
        if (inet_pton(AF_INET6, hostname, &in6) != 1)
            goto do_hosts;

        head->ai_family = AF_INET6;
        head->ai_addrlen = sizeof(struct sockaddr_in6);
        head->ai_addr = newsockaddr6(in6, port);

        goto finish;
    }

do_hosts:
    // Open and/or rewind the file
    sethostent(__netdb_host_stayopen);

    // Iterate through records, seeing if they match
    while ((he = gethostent())) {
        // Filter out other types of addresses
        if ((family != AF_UNSPEC) && (he->h_addrtype != family))
            continue;
        // Match a name/alias
        if (!strcmp(he->h_name, hostname))
            goto entry_matched;
        for (char **alias = he->h_aliases; *alias; ++alias)
            if (!strcmp(*alias, hostname))
                goto entry_matched;

        continue;

entry_matched:
        for (char **addr = he->h_addr_list; *addr; ++addr) {
            if (!ptr) {
                ptr = head;
            } else {
                ptr->ai_next = newaddrinfo();
                ptr = ptr->ai_next;
                ptr->ai_socktype = head->ai_socktype;
                ptr->ai_protocol = head->ai_protocol;
                ptr->ai_flags = head->ai_flags;
            }

            ptr->ai_family = he->h_addrtype;
            switch (ptr->ai_family)
            {
            case AF_INET:
                ptr->ai_addrlen = sizeof(struct sockaddr_in);
                ptr->ai_addr = newsockaddr4(*((struct in_addr *)*addr), port);
                break;
            case AF_INET6:
                ptr->ai_addrlen = sizeof(struct sockaddr_in6);
                ptr->ai_addr = newsockaddr6(*((struct in6_addr *)*addr), port);
                break;
            default:
                ERROR(EAI_FAIL);
            }
        }

        if ((hints->ai_flags & AI_CANONNAME) && !head->ai_canonname) {
            head->ai_canonname = strdup(he->h_name);
        }
    }

    // This is the authoritative source if we found something
    if (head->ai_addr)
        goto finish;

do_lookup_ipv4:
    if (head->ai_flags & AI_NUMERICHOST)
        ERROR(EAI_NONAME);

    // We weren't able to find the name locally, so now we check DNS
    if (__netdb_dns_init())
        ERROR(EAI_FAIL);

    if ((family == AF_UNSPEC) || (family == AF_INET)) {
        struct dns_rr_a4 *r4;

        if ((r4 = dns_resolve_a4(__netdb_dns_ctx, hostname, 0)) == NULL)
            goto do_lookup_ipv6;

        for (int i = 0; i < r4->dnsa4_nrr; ++i) {
            if (!ptr) {
                ptr = head;
            } else {
                ptr->ai_next = newaddrinfo();
                ptr = ptr->ai_next;
                ptr->ai_socktype = head->ai_socktype;
                ptr->ai_protocol = head->ai_protocol;
                ptr->ai_flags = head->ai_flags;
            }

            ptr->ai_family = AF_INET;
            ptr->ai_addrlen = sizeof(struct sockaddr_in);
            ptr->ai_addr = newsockaddr4(r4->dnsa4_addr[i], port);

        }

        if ((hints->ai_flags & AI_CANONNAME) && !head->ai_canonname) {
            head->ai_canonname = strdup(r4->dnsa4_cname);
        }

        free(r4);
    }

do_lookup_ipv6:
    if ((family == AF_UNSPEC) || (family == AF_INET6)) {
        struct dns_rr_a6 *r6;

        if ((r6 = dns_resolve_a6(__netdb_dns_ctx, hostname, 0)) == NULL)
            goto finish;

        for (int i = 0; i < r6->dnsa6_nrr; ++i) {
            if (!ptr) {
                ptr = head;
            } else {
                ptr->ai_next = newaddrinfo();
                ptr = ptr->ai_next;
                ptr->ai_socktype = head->ai_socktype;
                ptr->ai_protocol = head->ai_protocol;
                ptr->ai_flags = head->ai_flags;
            }

            ptr->ai_family = AF_INET6;
            ptr->ai_addrlen = sizeof(struct sockaddr_in6);
            ptr->ai_addr = newsockaddr6(r6->dnsa6_addr[i], port);
        }

        if ((hints->ai_flags & AI_CANONNAME) && !head->ai_canonname) {
            head->ai_canonname = strdup(r6->dnsa6_cname);
        }

        free(r6);
    }

finish:
    if (!head->ai_addr)
        ERROR(EAI_NONAME);
    *res = head;
    return 0;

error:
    if (head)
        freeaddrinfo(head);
    return e;
}


