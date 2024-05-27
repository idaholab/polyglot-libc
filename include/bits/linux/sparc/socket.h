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

#if !defined(_LINUX_SPARC_SOCKET_H)
#define _LINUX_SPARC_SOCKET_H 1

#define SCM_RIGHTS i    0x01

#define SOCK_STREAM     1
#define SOCK_DGRAM      2
#define SOCK_RAW        3
#define SOCK_SEQPACKET  5

#define SOL_SOCKET      0xffff

#define SO_DEBUG        0x0001
#define SO_PASSCRED     0x0002
#define SO_REUSEADDR    0x0004
#define SO_KEEPALIVE    0x0008
#define SO_DONTROUTE    0x0010
#define SO_BROADCAST    0x0020
#define SO_PEERCRED     0x0040
#define SO_LINGER       0x0080
#define SO_OOBINLINE    0x0100
#define SO_REUSEPORT    0x0200
#define SO_BSDCOMPAT    0x0400
#define SO_RCVLOWAT     0x0800
#define SO_SNDLOWAT     0x1000
#define SO_RCVTIMEO     0x2000
#define SO_SNDTIMEO     0x4000
#define SO_ACCEPTCONN   0x8000

#define SO_SNDBUF       0x1001
#define SO_RCVBUF       0x1002
#define SO_SNDBUFFORCE  0x100a
#define SO_RCVBUFFORCE  0x100b
#define SO_ERROR        0x1007
#define SO_TYPE         0x1008

#define SOMAXCONN       128 /* FIXME: this is low? */

#define MSG_OOB         0x0001
#define MSG_PEEK        0x0002
#define MSG_DONTROUTE   0x0004
#define MSG_TRYHARD     0x0004
#define MSG_CTRUNC      0x0008
#define MSG_PROBE       0x0010
#define MSG_TRUNC       0x0020
#define MSG_DONTWAIT    0x0040
#define MSG_EOR         0x0080
#define MSG_WAITALL     0x0100
#define MSG_FIN         0x0200
#define MSG_SYN         0x0400
#define MSG_CONFIRM     0x0800
#define MSG_RST         0x1000
#define MSG_ERRQUEUE    0x2000
#define MSG_NOSIGNAL    0x4000
#define MSG_MORE        0x8000
#define MSG_EOF         MSG_FIN

#define AF_UNIX         1
#define AF_INET         2
#define AF_INET6        10
#define AF_MAX          45

#define PF_INET         AF_INET
#define PF_INET6        AF_INET6
#define PF_UNIX         AF_UNIX
#define PF_MAX          AF_MAX

#define SHUT_RD         0
#define SHUT_WR         1
#define SHUT_RDWR       2

#define INET_ADDRSTRLEN     (16)
#define INET6_ADDRSTRLEN    (48)

typedef unsigned short sa_family_t;

struct sockaddr {
    sa_family_t sa_family;
    char sa_data[];
};

struct sockaddr_storage {
    sa_family_t ss_family;
    char ss_data[128 - sizeof(sa_family_t)];
};

#endif // _LINUX_SPARC_SOCKET_H
