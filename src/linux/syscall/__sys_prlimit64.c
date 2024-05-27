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

#ifdef __NR_prlimit64

int __sys_prlimit64(pid_t pid, int resource, const struct rlimit *new_rlim,
        struct rlimit *old_rlim)
{
    struct __kernel_rlimit64 k_new_rlim, k_old_rlim;

    /* XXX: under all the Linux architectures we're aware of, struct rlimit is
     * the same as struct __kernel_rlimit64, but this doesn't preclude the
     * possibility that there could be architectures with padding/ordering
     * differences, so we're copying the fields here */

    if (new_rlim) {
        k_new_rlim.rlim_cur = (new_rlim->rlim_cur == RLIM_INFINITY
                                ? __KERNEL_RLIM64_INFINITY
                                : new_rlim->rlim_cur);
        k_new_rlim.rlim_max = (new_rlim->rlim_max == RLIM_INFINITY
                                ? __KERNEL_RLIM64_INFINITY
                                : new_rlim->rlim_max);
    }

    if (syscall(__NR_prlimit64, pid, resource, new_rlim, old_rlim) == -1)
        return -1;

    if (old_rlim) {
        old_rlim->rlim_cur = (k_old_rlim.rlim_cur == __KERNEL_RLIM64_INFINITY
                                ? RLIM_INFINITY
                                : k_old_rlim.rlim_cur);
        old_rlim->rlim_max = (k_old_rlim.rlim_max == __KERNEL_RLIM64_INFINITY
                                ? RLIM_INFINITY
                                : k_old_rlim.rlim_max);
    }

    return 0;
}

#endif
