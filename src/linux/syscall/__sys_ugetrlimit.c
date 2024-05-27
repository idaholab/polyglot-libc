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
#include <sys/resource.h>
#include <bits/linux/resource.h>

#ifdef __NR_ugetrlimit

int __sys_ugetrlimit(int resource, struct rlimit *rlim)
{
    struct __kernel_rlimit k_rlim;

    if (syscall(__NR_ugetrlimit, resource, &k_rlim) == -1)
        return -1;

    rlim->rlim_cur = (k_rlim.rlim_cur == __KERNEL_RLIM_INFINITY
                        ? RLIM_INFINITY : k_rlim.rlim_cur);
    rlim->rlim_max = (k_rlim.rlim_max == __KERNEL_RLIM_INFINITY
                        ? RLIM_INFINITY : k_rlim.rlim_max);
    return 0;
}

#endif
