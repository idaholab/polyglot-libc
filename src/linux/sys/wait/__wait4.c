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
#include <sys/types.h>

/* XXX: technically, wait4() is a SVR4 thing, but isn't POSIX, so we are
 * marking it as being internal rather than making it external (that way we
 * don't have to use the other calls to provide it) */

syscall_choice(
    /* syscall   */ __wait4,
    /* return    */ pid_t,
    /* args      */ (
                        pid_t, pid,
                        int*, wstatus,
                        int, options,
                        struct rusage*, rusage
                    ),
    /* failure   */ -1,
#ifdef __NR_wait4
    /* option    */ WAIT4, __sys_wait4,
#endif
)

