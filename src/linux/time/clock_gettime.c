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

/* XXX: we've taken the liberty of renaming the clock_gettime syscalls in the
 * Linux syscall definitions because they were inconsistent as to whether they
 * were 32- or 64-bit */

syscall_choice(
    /* syscall   */ clock_gettime,
    /* return    */ int,
    /* args      */ (
                        clockid_t, clock_id,
                        struct timespec*, tp
                    ),
    /* failure   */ -1,
#ifdef __NR_clock_gettime64
    /* option    */ CLOCK_GETTIME64, __sys_clock_gettime64,
#endif
#ifdef __NR_clock_gettime32
    /* option    */ CLOCK_GETTIME32, __sys_clock_gettime32,
#endif
)

