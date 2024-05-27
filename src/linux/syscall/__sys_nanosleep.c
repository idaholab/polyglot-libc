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

#ifdef __NR_nanosleep

int __sys_nanosleep(const struct timespec *req, struct timespec *rem)
{
    int r;
    struct __kernel_timespec k_req, k_rem;

    k_req.tv_sec = req->tv_sec;
    k_req.tv_nsec = req->tv_nsec;

    r = syscall(__NR_nanosleep, &k_req, &k_rem);

    if (rem) {
        rem->tv_sec = k_rem.tv_sec;
        rem->tv_nsec = k_rem.tv_nsec;
    }

    return r;
}

#endif
