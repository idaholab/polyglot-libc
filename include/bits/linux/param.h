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

#ifndef _LINUX_PARAM_H
#define _LINUX_PARAM_H _LINUX_PARAM_H

#define __NEED_HZ 1
#define __NEED_EXEC_PAGESIZE 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(param.h))
#include __target_os_arch_header(param.h)
#endif

/* these don't vary */
#define NOGROUP         (-1)
#define MAXHOSTNAMELEN  64

#ifdef __NEED_HZ
#define HZ              100
#endif

#ifdef __NEED_EXEC_PAGESIZE
#define EXEC_PAGESIZE   4096
#endif

#undef __NEED_HZ
#undef __NEED_EXEC_PAGESIZE

#endif // _LINUX_PARAM_H
