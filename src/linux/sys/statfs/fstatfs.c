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
#include <sys/types.h>

syscall_choice(
    /* syscall   */ fstatfs,
    /* return    */ int,
    /* args      */ (
                        int, fd,
                        struct statfs*, statbuf
                    ),
    /* failure   */ -1,
#ifdef __NR_fstatfs64
    /* option    */ FSTATFS64, __sys_fstatfs64,
#endif
#ifdef __NR_fstatfs
    /* option    */ FSTATFS, __sys_fstatfs,
#endif
)

int fstatfs64(int, struct statfs*)
__attribute__((alias("fstatfs")));

