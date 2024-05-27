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

#ifndef _NETDB_H
#define _NETDB_H _NETDB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <netinet/in.h>
#include <sys/socket.h>
#include <inttypes.h>


#define __NETDB_HOST_ALIAS_COUNT 8
#define __NETDB_HOST_ADDR_COUNT 8

struct hostent
{
    char *h_name;
    char *h_aliases[__NETDB_HOST_ALIAS_COUNT+1];
    int h_addrtype;
    int h_length;
    char *h_addr_list[__NETDB_HOST_ADDR_COUNT+1];
};

#define __NETDB_NET_ALIAS_COUNT 4

struct netent
{
    char *n_name;
    char *n_aliases[__NETDB_NET_ALIAS_COUNT];
    int n_addrtype;
    uint32_t n_net;
};

#define __NETDB_PROTO_ALIAS_COUNT 4

struct protoent
{
    char *p_name;
    char *p_aliases[__NETDB_PROTO_ALIAS_COUNT+1];
    int p_proto;
};

#define __NETDB_SERV_ALIAS_COUNT 4

struct servent
{
    char *s_name;
    char *s_aliases[__NETDB_SERV_ALIAS_COUNT+1];
    int s_port;
    char *s_proto;
};

struct addrinfo
{
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    struct sockaddr *ai_addr;
    char *ai_canonname;
    struct addrinfo *ai_next;
};

extern int h_errno;

#define IPPORT_RESERVED     1024

#define HOST_NOT_FOUND      1
#define NO_DATA             2
#define NO_RECOVERY         3
#define TRY_AGAIN           4

#define AI_DEFAULT          0
#define AI_PASSIVE          0x0001
#define AI_CANONNAME        0x0002
#define AI_NUMERICHOST      0x0004
#define AI_NUMERICSERV      0x0008
#define AI_V4MAPPED         0x0010
#define AI_ALL              0x0020
#define AI_ADDRCONFIG       0x0040

#define NI_NOFQDN           0x0001
#define NI_NUMERICHOST      0x0002
#define NI_NAMEREQD         0x0004
#define NI_NUMERICSERV      0x0008
#define NI_NUMERICSCOPE     0x0010
#define NI_DGRAM            0x0020

#define EAI_AGAIN           -1
#define EAI_BADFLAGS        -2
#define EAI_FAIL            -3
#define EAI_FAMILY          -4
#define EAI_MEMORY          -5
#define EAI_NONAME          -6
#define EAI_SERVICE         -7
#define EAI_SOCKTYPE        -8
#define EAI_SYSTEM          -9
#define EAI_OVERFLOW        -10

void endhostent(void);
struct hostent *gethostbyaddr(const void *, socklen_t, int);
struct hostent *gethostbyname(const char *);
struct hostent *gethostbyname2(const char *, int);
struct hostent *gethostent(void);
void sethostent(int);

void endnetent(void);
struct netent *getnetbyaddr(uint32_t, int);
struct netent *getnetbyname(const char *);
struct netent *getnetent(void);
void setnetent(int);

void endprotoent(void);
struct protoent *getprotobyname(const char *);
struct protoent *getprotobynumber(int);
struct protoent *getprotoent(void);
void setprotoent(int);

void endservent(void);
struct servent *getservbyname(const char *, const char *);
struct servent *getservbyport(int, const char *);
struct servent *getservent(void);
void setservent(int);

void freeaddrinfo(struct addrinfo *);
const char *gai_strerror(int);
int getaddrinfo(const char *restrict, const char *restrict,
            const struct addrinfo *restrict, struct addrinfo **restrict);

/*
 * - int getnameinfo(const struct sockaddr *restrict, socklen_t,
 *           char *restrict, socklen_t, char *restrict, socklen_t, int);
 */

#include <target/paths.h>
#include <stdio.h>
#include <udns.h>

#define __NETDB_HOST_BUF_LEN 256

extern char __netdb_host_buf[__NETDB_HOST_BUF_LEN];
extern char __netdb_host_addrs[__NETDB_HOST_ADDR_COUNT]\
                              [sizeof(struct in6_addr)];
extern struct hostent __netdb_host_ent;
extern int __netdb_host_stayopen;
extern const struct hostent __netdb_host_list[];
extern const struct hostent *__netdb_host_list_ptr;
#if defined(__NETDB_HOST_PATH)
extern int __netdb_host_file_exists;
extern FILE *__netdb_host_fd;
#endif

#define __NETDB_NET_BUF_LEN 256

extern char __netdb_net_buf[__NETDB_NET_BUF_LEN];
extern struct netent __netdb_net_ent;
extern int __netdb_net_stayopen;
extern const struct netent __netdb_net_list[];
extern const struct netent *__netdb_net_list_ptr;
#if defined(__NETDB_NET_PATH)
extern int __netdb_net_file_exists;
extern FILE *__netdb_net_fd;
#endif

#define __NETDB_PROTO_BUF_LEN 256

extern char __netdb_proto_buf[__NETDB_PROTO_BUF_LEN];
extern struct protoent __netdb_proto_ent;
extern int __netdb_proto_stayopen;
extern const struct protoent __netdb_proto_list[];
extern const struct protoent *__netdb_proto_list_ptr;
#if defined(__NETDB_PROTO_PATH)
extern int __netdb_proto_file_exists;
extern FILE *__netdb_proto_fd;
#endif

#define __NETDB_SERV_BUF_LEN 256

extern char __netdb_serv_buf[__NETDB_SERV_BUF_LEN];
extern struct servent __netdb_serv_ent;
extern int __netdb_serv_stayopen;
extern const struct servent __netdb_serv_list[];
extern const struct servent *__netdb_serv_list_ptr;
#if defined(__NETDB_SERV_PATH)
extern int __netdb_serv_file_exists;
extern FILE *__netdb_serv_fd;
#endif

void __netdb_host_openfile();
void __netdb_net_openfile();
void __netdb_proto_openfile();
void __netdb_serv_openfile();

#define __NETDB_DNS_NS_COUNT 4
#define __NETDB_DNS_NS_BUF_SIZE 64

extern struct dns_ctx *__netdb_dns_ctx;
extern char __netdb_dns_ns[__NETDB_DNS_NS_COUNT][__NETDB_DNS_NS_BUF_SIZE];

int __netdb_dns_init();

#ifdef __cplusplus
} // extern C
#endif

#endif // _NETDB_H
