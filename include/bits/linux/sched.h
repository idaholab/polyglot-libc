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

#ifndef _LINUX_SCHED_H
#define _LINUX_SCHED_H _LINUX_SCHED_H

#define __NEED_CLONE_FLAGS 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(sched.h))
#include __target_os_arch_header(sched.h)
#endif

#ifdef __NEED_CLONE_FLAGS
#define CSIGNAL                 0x000000ff
#define CLONE_VM                0x00000100
#define CLONE_FS                0x00000200
#define CLONE_FILES             0x00000400
#define CLONE_SIGHAND           0x00000800
#define CLONE_PTRACE            0x00002000
#define CLONE_VFORK             0x00004000
#define CLONE_PARENT            0x00008000
#define CLONE_THREAD            0x00010000
#define CLONE_NEWNS             0x00020000
#define CLONE_SYSVSEM           0x00040000
#define CLONE_SETTLS            0x00080000
#define CLONE_PARENT_SETTID     0x00100000
#define CLONE_CHILD_CLEARTID    0x00200000
#define CLONE_DETACHED          0x00400000
#define CLONE_UNTRACED          0x00800000
#define CLONE_CHILD_SETTID      0x01000000
#define CLONE_NEWCGROUP         0x02000000
#define CLONE_NEWUTS            0x04000000
#define CLONE_NEWIPC            0x08000000
#define CLONE_NEWUSER           0x10000000
#define CLONE_NEWPID            0x20000000
#define CLONE_NEWNET            0x40000000
#define CLONE_IO                0x80000000
#endif

#include <sys/types.h>

pid_t __clone(unsigned long, void*, int, int*, int*, unsigned long);

#undef __NEED_CLONE_FLAGS

#endif // _LINUX_SCHED_H
