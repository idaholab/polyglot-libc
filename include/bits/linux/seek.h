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

#ifndef _LINUX_SEEK_H
#define _LINUX_SEEK_H _LINUX_SEEK_H

#define __NEED_SEEK_CONSTS

#include <_platform.h>
#if __has_include(__target_os_arch_header(seek.h))
#include __target_os_arch_header(seek.h)
#endif

#ifdef __NEED_SEEK_CONSTS
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif

#undef __NEED_SEEK_CONSTS

#endif // _LINUX_SEEK_H
