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

#ifndef _LINUX_SEM_H
#define _LINUX_SEM_H _LINUX_SEM_H

#define __NEED_SEMOP_FLAGS 1
#define __NEED_SEMCTL_COMMANDS 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(sem.h))
#include __target_os_arch_header(sem.h)
#endif

#ifdef __NEED_SEMOP_FLAGS
#define SEM_UNDO    0x1000
#endif

#ifdef __NEED_SEMCTL_COMMANDS
#define GETNCNT     0x0e
#define GETPID      0x0b
#define GETVAL      0x0c
#define GETALL      0x0d
#define GETZCNT     0x0f
#define SETVAL      0x10
#define SETALL      0x11
#endif

int __semctl(int, int, int, long);

#undef __NEED_SEMOP_FLAGS
#undef __NEED_SEMCTL_COMMANDS

#endif // _LINUX_SEM_H
