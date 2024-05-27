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

#ifndef _LINUX_PTY_H
#define _LINUX_PTY_H _LINUX_PTY_H

#define __NEED_PTY_OLD 1
#define __NEED_PTY_NEW 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(pty.h))
#include __target_os_arch_header(pty.h)
#endif

/* Used for old-style PTYs */
#ifdef __NEED_PTY_OLD
#define XRANGE          "pqrstuvwxyzabcde"
#define YRANGE          "0123456789abcdef"
#define PTMX_DEV        "/dev/ptmx"
#define PTS_PREFIX      "/dev/pts"
#define PTS_PREFIX_LEN  (sizeof(PTS_PREFIX) - 1)
#endif

/* Used for new-style PTYs */
#ifdef __NEED_PTY_NEW
#define PTYM_PREFIX     "/dev/pty"
#define PTYS_PREFIX     "/dev/tty"
#define PTY_PREFIX_LEN  (sizeof(PTYM_PREFIX) - 1)
#endif

#undef __NEED_PTY_OLD
#undef __NEED_PTY_NEW

#endif // _LINUX_PTY_H
