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
#include <sys/select.h>

#ifdef __NR_select

int __sys_select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *efds,
        struct timeval *tv)
{
    struct __kernel_old_timeval k_tv;

    if (tv) {
        k_tv.tv_sec = tv->tv_sec;
        k_tv.tv_usec = tv->tv_usec;
    }

    return syscall(__NR_select, nfds, rfds, wfds, efds, tv ? &k_tv : NULL);
}

#endif
