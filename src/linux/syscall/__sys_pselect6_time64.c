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
#include <sys/select.h>
#include <signal.h>

#ifdef __NR_pselect6_time64

// FIXME: we are fixing Linux types at some point... but not yet
struct __kernel_time64 {
    long long tv_sec;
    long long tv_nsec;
};

int __sys_pselect6_time64(int nfds, fd_set *rfds, fd_set *wfds, fd_set *efds,
        const struct timespec *ts, const sigset_t *sigmask)
{
    struct __kernel_time64 k_ts;
    struct __kernel_rt_sigset k_sig;
    struct {
        const struct __kernel_rt_sigset *ss;
        size_t ss_len;
    } k_arg;

    if (ts) {
        k_ts.tv_sec = ts->tv_sec;
        k_ts.tv_nsec = ts->tv_nsec;
    }
    if (sigmask) {
        __sigcopyset(
            (__sigset_int_t *)&k_sig,
            __KERNEL_RT_SIGSET_NWORDS,
            (__sigset_int_t *)sigmask,
            __SIGSET_NWORDS
        );
        k_arg.ss = &k_sig;
        k_arg.ss_len = __KERNEL_RT_SIGSET_NWORDS;
    } else {
        k_arg.ss = NULL;
        k_arg.ss_len = 0;
    }

    return syscall(
        __NR_pselect6_time64,
        nfds, rfds, wfds, efds,
        ts ? &k_ts : NULL,
        &k_arg
    );
}

#endif
