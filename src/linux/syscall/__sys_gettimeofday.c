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
#include <sys/time.h>

#ifdef __NR_gettimeofday

int __sys_gettimeofday(struct timeval *tp, void *tzp)
{
    struct __kernel_old_timeval k_tp;

    if (syscall(__NR_gettimeofday, &k_tp, tzp) == -1)
        return -1;
    tp->tv_sec = k_tp.tv_sec;
    tp->tv_usec = k_tp.tv_usec;
    return 0;
}

#endif
