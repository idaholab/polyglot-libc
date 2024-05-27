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

#ifndef _LINUX_POLL_H
#define _LINUX_POLL_H _LINUX_POLL_H

#define __NEED_POLL_STANDARD 1
#define __NEED_POLL_NONSTANDARD 1
#define __NEED_POLLFD 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(poll.h))
#include __target_os_arch_header(poll.h)
#endif

/* these are standardized per iBCS2 */
#ifdef __NEED_POLL_STANDARD
#define POLLIN      0x0001
#define POLLPRI     0x0002
#define POLLOUT     0x0004
#define POLLERR     0x0008
#define POLLHUP     0x0010
#define POLLNVAL    0x0020
#endif

/* these are nonstandard */
#ifdef __NEED_POLL_NONSTANDARD
#define POLLRDNORM  0x0040
#define POLLRDBAND  0x0080
#define POLLWRNORM  0x0100
#define POLLWRBAND  0x0200
#define POLLMSG     0x0400
#define POLLREMOVE  0x1000
#define POLLRDHUP   0x2000
#endif

#ifdef __NEED_POLLFD
struct __kernel_pollfd {
    int     fd;
    short   events;
    short   revents;
};
#endif

#undef __NEED_POLL_STANDARD
#undef __NEED_POLL_NONSTANDARD
#undef __NEED_POLLFD

#endif // _LINUX_POLL_H
