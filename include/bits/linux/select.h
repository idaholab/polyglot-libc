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

#ifndef _LINUX_SELECT_H
#define _LINUX_SELECT_H _LINUX_SELECT_H

#define __NEED_FD_SETSIZE 1
#define __NEED_FD_SET 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(select.h))
#include __target_os_arch_header(select.h)
#endif

#ifdef __NEED_FD_SETSIZE
#define FD_SETSIZE  1024
#endif

#ifdef __NEED_FD_SET
#define FD_NWORDS   (FD_SETSIZE / (8 * sizeof(__fd_mask)))
typedef unsigned long __fd_mask;
struct __fd_set {
    __fd_mask fds_bits[FD_NWORDS];
};
#endif

#undef __NEED_FD_SETSIZE
#undef __NEED_FD_SET

#endif // _LINUX_SELECT_H
