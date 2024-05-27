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

#if defined(__kernel_sa_rt_restorer) && !defined(SA_RESTORER)
#error "__kernel_sa_rt_restorer is defined, but SA_RESTORER is not"
#endif

int __sys_rt_sigaction(int sig, const struct sigaction *act,
        struct sigaction *oact)
{
    struct __kernel_rt_sigaction k_act;
    struct __kernel_rt_sigaction k_oact;

    if (act != NULL) {
        k_act.sa_handler = act->sa_handler;
        k_act.sa_flags = act->sa_flags;
#if defined(__kernel_sa_rt_restorer)
        k_act.sa_flags |= SA_RESTORER;
        k_act.sa_restorer = __kernel_sa_rt_restorer;
#endif
        __sigcopyset(
            (__sigset_int_t *)&k_act.sa_mask,
            __KERNEL_RT_SIGSET_NWORDS,
            (__sigset_int_t *)&act->sa_mask,
            __SIGSET_NWORDS
        );
    }

    if (syscall(   
        __NR_rt_sigaction, sig,
        (act == NULL ? NULL: &k_act),
        (oact == NULL ? NULL: &k_oact),
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
