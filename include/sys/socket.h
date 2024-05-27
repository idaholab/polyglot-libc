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

#if !defined(_SYS_SOCKET_H)
#define _SYS_SOCKET_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/uio.h>
#include <sys/types.h>

/* MACRO DEFINITIONS **********************************************************/

#define CMSG_DATA(cmsg)         __builtin_error("CMSG_DATA")
#define CMSG_NXTHDR(mhdr, cmsg) __builtin_error("CMSG_NXTHDR")
#define CMSG_FIRSTHDR(mhdr)     __builtin_error("CMSG_FIRSTHDR")

#define AF_ANY (-1)
#define AF_UNSPEC 0
#define PF_UNSPEC AF_UNSPEC

/* TYPE DEFINITIONS ***********************************************************/

typedef __UINT32_TYPE__ socklen_t;

struct msghdr
{
    void           *msg_name;
    socklen_t       msg_namelen;
    struct iovec   *msg_iov;
    int             msg_iovlen;
    void           *msg_control;
    socklen_t       msg_controllen;
    int             msg_flags;
};

struct cmsghdr
{
    socklen_t       cmsg_len;
    int             cmsg_level;
    int             cmsg_type;
};

struct linger
{
    int             l_onoff;
    int             l_linger;
};

/******************************************************************************/

#include <target/socket.h>

/* FUNCTION PROTOTYPES ********************************************************/

int accept(int, struct sockaddr*, socklen_t*);
int bind(int, const struct sockaddr *, socklen_t);
int connect(int, const struct sockaddr *, socklen_t);
int getpeername(int, struct sockaddr*, socklen_t*);
int getsockname(int, struct sockaddr*, socklen_t*);
int listen(int, int);
ssize_t recv(int, void*, size_t, int);
ssize_t recvfrom(int, void*, size_t, int, struct sockaddr*, socklen_t*);
ssize_t send(int, const void*, size_t, int);
ssize_t sendto(int, const void*, size_t, int, const struct sockaddr*, socklen_t);
int setsockopt(int, int, int, const void*, socklen_t);
int shutdown(int, int);
int socket(int, int, int);

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - int getsockopt(int, int, int, void *restrict, socklen_t *restrict);
 *   - ssize_t recvmsg(int, struct msghdr *, int);
 *   - ssize_t sendmsg(int, const struct msghdr *, int);
 *   - int sockatmark(int);
 *   - int socketpair(int, int, int, int [2]);
 */

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_SOCKET_H
