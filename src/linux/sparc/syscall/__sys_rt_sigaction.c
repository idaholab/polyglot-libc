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

#ifdef __NR_rt_sigaction

#ifndef __NR_sigreturn
#error "SPARC rt_sigaction needs sigreturn, but __NR_sigreturn undefined!"
#endif

/* XXX: older SPARC Linux kernels with rt_sigaction don't correctly handle a
 * NULL restorer parameter (2.6.18 Debian does, at least, but our test NAS with
 * 2.6.17 does not), which results in "illegal instruction" on return from the
 * handler. This can be fixed by either: a) not using rt_sigaction, and only
 * using sigaction instead, or b) passing in a restorer function. We use option
 * (b), since it's the 'better' solution. */

int __sys_rt_sigaction(int sig, const struct sigaction *act,
        struct sigaction *oact)
{
    struct __kernel_rt_sigaction k_act;
    struct __kernel_rt_sigaction k_oact;

    if (act != NULL) {
        k_act.sa_handler = act->sa_handler;
        k_act.sa_flags = act->sa_flags;
        __sigcopyset(
            (__sigset_int_t *)&k_act.sa_mask,
            __KERNEL_RT_SIGSET_NWORDS,
            (__sigset_int_t *)&act->sa_mask,
            __SIGSET_NWORDS
        );
    }

    if (syscall(   
        __NR_rt_sigaction, sig,
        (act  == NULL ? NULL: &k_act ),
        (oact == NULL ? NULL: &k_oact),
        __sys_sigreturn,
        __KERNEL_RT_SIGSET_BYTES
    ) == -1)
        return -1;

    if (oact != NULL) {
        oact->sa_handler = k_oact.sa_handler;
        oact->sa_flags = k_oact.sa_flags;
        __sigcopyset(
            (__sigset_int_t *)&act->sa_mask,
            __SIGSET_NWORDS,
            (__sigset_int_t *)&k_act.sa_mask,
            __KERNEL_RT_SIGSET_NWORDS
        );
    }

    return 0;
}

#endif
