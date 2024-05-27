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
#include <bits/linux/signal.h>
#include <signal.h>
#include <errno.h>

#ifdef __NR_rt_sigprocmask

int __sys_rt_sigprocmask(int how, const sigset_t *set, sigset_t *oset)
{
    __kernel_rt_sigset_t k_set;
    __kernel_rt_sigset_t k_oset;

    if (set != NULL) {
        __sigemptyset(
            (__sigset_int_t *)&k_set,
            __KERNEL_RT_SIGSET_NWORDS
        );
        __sigcopyset(
            (__sigset_int_t *)&k_set,
            __KERNEL_RT_SIGSET_NWORDS,
            (__sigset_int_t *)set,
            __SIGSET_NWORDS
        );
    }
    if (oset != NULL) {
        __sigemptyset(
            (__sigset_int_t *)&k_oset,
            __KERNEL_RT_SIGSET_NWORDS
        );
    }

    if (syscall(   
        __NR_rt_sigprocmask, how,
        (set == NULL ? NULL: &k_set),
        (oset == NULL ? NULL: &k_oset),
        __KERNEL_RT_SIGSET_BYTES
    ) == -1)
        return -1;

    if (oset != NULL) {
        __sigemptyset(
            (__sigset_int_t *)oset,
            __SIGSET_NWORDS
        );
        __sigcopyset(
            (__sigset_int_t *)oset,
            __SIGSET_NWORDS,
            (__sigset_int_t *)&k_oset,
            __KERNEL_RT_SIGSET_NWORDS
        );
    }

    return 0;
}

#endif
