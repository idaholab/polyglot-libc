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

#ifndef _LINUX_WAIT_H
#define _LINUX_WAIT_H _LINUX_WAIT_H

/******************************************************************************/

#include <_platform.h>
#if __has_include(__target_os_arch_header(wait.h))
#include __target_os_arch_header(wait.h)
#else
#error "No architecture-specific <bits/linux/wait.h> header available"
#endif

/******************************************************************************/

pid_t __wait4(pid_t, int*, int, struct rusage*);

/******************************************************************************/

#endif // _LINUX_WAIT_H