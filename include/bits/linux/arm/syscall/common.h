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

#ifndef _LINUX_ARM_SYSCALL_COMMON_H
#define _LINUX_ARM_SYSCALL_COMMON_H 1

#if !defined(__NR_SYSCALL_BASE)
#error "Specific ARM ABI syscall header must be included first"
#endif

/* These syscalls are ARM private. */
#define __ARM_NR_BASE                       (__NR_SYSCALL_BASE + 0x0f0000)
#define __ARM_NR_breakpoint                 (__ARM_NR_BASE + 1)
#define __ARM_NR_cacheflush                 (__ARM_NR_BASE + 2)
#define __ARM_NR_usr26                      (__ARM_NR_BASE + 3)
#define __ARM_NR_usr32                      (__ARM_NR_BASE + 4)
#define __ARM_NR_set_tls                    (__ARM_NR_BASE + 5)
#define __ARM_NR_get_tls                    (__ARM_NR_BASE + 6)

#endif // _LINUX_ARM_SYSCALL_COMMON_H
