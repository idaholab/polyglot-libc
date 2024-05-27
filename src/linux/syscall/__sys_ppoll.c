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
#include <bits/linux/types.h>
#include <bits/linux/signal.h>
#include <signal.h>
#include <poll.h>

/* XXX: it seems like ppoll only exists on platforms with rt_sig* stuff? */

#ifdef __NR_ppoll

int __sys_ppoll(struct pollfd fds[], nfds_t nfds, const struct timespec *ts,
        const sigset_t *sigmask)
{
    struct __kernel_timespec kts;
    struct __kernel_rt_sigset ksig;

    if (ts) {
        kts.tv_sec = ts->tv_sec;
        kts.tv_nsec = ts->tv_nsec;
    }
    if (sigmask) {
        __sigcopyset(
            (__sigset_int_t *)&ksig,
            __KERNEL_RT_SIGSET_NWORDS,
            (__sigset_int_t *)sigmask,
            __SIGSET_NWORDS
        );
    }

    return syscall(
        __NR_ppoll,
        fds, nfds,
        (ts ? &kts : NULL),
        (sigmask ? &ksig : NULL),
        __KERNEL_RT_SIGSET_BYTES
    );
}

#endif
