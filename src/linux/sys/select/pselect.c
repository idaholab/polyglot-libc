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

#include <polyglot/syscall_choice.h>
#include <bits/linux/syscall.h>
#include <bits/linux/features.h>
#include <bits/linux/shim.h>
#include <sys/select.h>

syscall_choice(
    /* syscall   */ pselect,
    /* return    */ int,
    /* args      */ (
                        int, nfds,
                        fd_set*, rfds,
                        fd_set*, wfds,
                        fd_set*, efds,
                        const struct timespec*, timeout,
                        const sigset_t*, sigmask
                    ),
    /* failure   */ -1,
#ifdef __NR_pselect6_time64
    /* option    */ PSELECT6_TIME64, __sys_pselect6_time64,
#endif
#ifdef __NR_pselect6
    /* option    */ PSELECT6, __sys_pselect6,
#endif
#ifdef HAS_NATIVE_select
    /* option    */ SELECT, __pselect_via_select,
#endif
)

