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

#ifndef _LINUX_I386_TIME_H
#define _LINUX_I386_TIME_H _LINUX_I386_TIME_H

#include <sys/types.h>

/* FIXME: CLOCKS_PER_SEC is defined in the PDClib headers too; merge? */
#define CLOCKS_PER_SEC ((clock_t)1000000)

#define CLOCK_REALTIME              0
#define CLOCK_MONOTONIC             1
#define CLOCK_PROCESS_CPUTIME_ID    2
#define CLOCK_THREAD_CPUTIME_ID     3

#include <bits/linux/types.h>

struct __kernel_timespec {
    __kernel_old_time_t tv_sec;
    long tv_nsec;
};

struct __kernel_timeval {
    __kernel_old_time_t tv_sec;
    __kernel_suseconds_t tv_usec;
};

struct __kernel_old_timeval {
    __kernel_long_t tv_sec;
    __kernel_long_t tv_usec;
};

struct __kernel_old_timespec32 {
    int tv_sec;
    int tv_nsec;
};

struct __kernel_old_timeval32 {
    int tv_sec;
    int tv_usec;
};

#endif // _LINUX_I386_TIME_H
