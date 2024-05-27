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

#include <bits/linux/syscall.h>
#include <bits/linux/time.h>
#include <time.h>

#ifdef __NR_clock_gettime32

int __sys_clock_gettime32(clockid_t clock_id, struct timespec *tp)
{
    struct __kernel_old_timespec32 k_ts32;

    if (syscall(__NR_clock_gettime32, clock_id, &k_ts32) == -1)
        return -1;
    tp->tv_sec = k_ts32.tv_sec;
    tp->tv_nsec = k_ts32.tv_nsec;
    return 0;
}

#endif
