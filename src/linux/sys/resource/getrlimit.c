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
#include <sys/resource.h>

/* XXX: there are three options for getting this info from the kernel:
 *   - prlimit64(): always 64-bit fields; on true 32-bit (i.e. 32-bit binary on
 *     a 32-bit host), the value is still limited to 32-bits (although
 *     RLIM_INFINITY is 64-bit -1), but on a 64-bit host (regardless of 32- or
 *     64-bit binary), the full 64-bit field is available
 *   - ugetrlimit(): pointer-sized fields; for 32-bit binaries, these values
 *     are capped at 32-bit, but for 64-bit binaries, it's full 64-bit width
 *   - getrlimit(): always 32-bit values, regardless of field size
 */

syscall_choice(
    /* syscall   */ getrlimit,
    /* return    */ int,
    /* args      */ (
                        int, resource,
                        struct rlimit*, rlim
                    ),
    /* failure   */ -1,
#ifdef HAS_NATIVE_prlimit64
    /* option    */ PRLIMIT64, __getrlimit_via_prlimit64,
#endif
#ifdef __NR_ugetrlimit
    /* option    */ UGETRLIMIT, __sys_ugetrlimit,
#endif
#ifdef __NR_getrlimit
    /* option    */ GETRLIMIT, __sys_getrlimit,
#endif
)

