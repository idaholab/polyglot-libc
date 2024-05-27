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

#ifndef _LINUX_SHM_H
#define _LINUX_SHM_H _LINUX_SHM_H

#define __NEED_SHM_FLAGS 1
#define __NEED_SHMLBA 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(shm.h))
#include __target_os_arch_header(shm.h)
#endif

#ifdef __NEED_SHM_FLAGS
#define SHM_RDONLY  0x1000
#define SHM_RND     0x2000
#endif

/* FIXME: this needs to have architecture-specific versions */
#ifdef __NEED_SHMLBA
#define SHMLBA      (getpagesize())
#endif

#undef __NEED_SHM_FLAGS
#undef __NEED_SHMLBA

#endif // _LINUX_SHM_H
