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

#ifndef _LINUX_SOCKETCALL_H
#define _LINUX_SOCKETCALL_H _LINUX_SOCKETCALL_H

/* These are the first argument to socketcall(); it's essentially an older,
 * multiplexed syscall to handle all the socket things. */
#define SOCALL_SOCKET       1
#define SOCALL_BIND         2
#define SOCALL_CONNECT      3
#define SOCALL_LISTEN       4
#define SOCALL_ACCEPT       5
#define SOCALL_GETSOCKNAME  6
#define SOCALL_GETPEERNAME  7
#define SOCALL_SOCKETPAIR   8
#define SOCALL_SEND         9
#define SOCALL_RECV         10
#define SOCALL_SENDTO       11
#define SOCALL_RECVFROM     12
#define SOCALL_SHUTDOWN     13
#define SOCALL_SETSOCKOPT   14
#define SOCALL_GETSOCKOPT   15
#define SOCALL_SENDMSG      16
#define SOCALL_RECVMSG      17
#define SOCALL_ACCEPT4      18
#define SOCALL_RECVMMSG     19
#define SOCALL_SENDMMSG     20

int __socketcall_v(int, long**);

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/variadic/to_tuple.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

#define __socketcall(cmd, ...) \
    __socketcall_tup(cmd, BOOST_PP_VARIADIC_TO_TUPLE(__VA_ARGS__))
#define __socketcall_tup(cmd, tup) \
    ({ \
        long __socketcall_args[] = { \
            BOOST_PP_REPEAT(BOOST_PP_TUPLE_SIZE(tup), __socketcall_arg, tup) \
        }; \
        __socketcall_v(cmd, (long**)&__socketcall_args); \
    })
#define __socketcall_arg(z, n, tup) \
    (long)(BOOST_PP_TUPLE_ELEM(n, tup)),
    

#endif // _LINUX_SOCKETCALL_H
