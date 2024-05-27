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

#ifndef _LINUX_SPARC_RESOURCE_H
#define _LINUX_SPARC_RESOURCE_H _LINUX_SPARC_RESOURCE_H

#undef __NEED_RLIMIT_CONSTS
#define RLIMIT_AS       9
#define RLIMIT_CORE     4
#define RLIMIT_CPU      0
#define RLIMIT_DATA     2
#define RLIMIT_FSIZE    1
#define RLIMIT_NOFILE   6
#define RLIMIT_STACK    3

#ifndef __arch64__
#undef __NEED_RLIM_INFINITY
#define __KERNEL_RLIM_INFINITY 0x7fffffff
#endif

#endif // _LINUX_SPARC_RESOURCE_H
