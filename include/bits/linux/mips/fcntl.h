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

#ifndef _LINUX_MIPS_FCNTL_H
#define _LINUX_MIPS_FCNTL_H _LINUX_MIPS_FCNTL_H

#undef __NEED_FILE_CONSTANTS

/* File flag constants. */
#define O_APPEND        0x8
#define O_CLOEXEC       0x80000
#define O_CREAT         0x100
#define O_DIRECTORY     0x10000
#define O_DSYNC         0x10
#define O_EXCL          0x400
#define O_EXEC          __builtin_error("O_EXEC")
#define O_NOCTTY        0x800
#define O_NOFOLLOW      0x20000
#define O_NONBLOCK      0x80
#define O_RDONLY        0x0
#define O_RDWR          0x2
#define O_RSYNC         __builtin_error("O_RSYNC")
#define O_SEARCH        __builtin_error("O_SEARCH")
#define O_SYNC          0x4010
#define O_TRUNC         0x200
#define O_TTY_INIT      __builtin_error("O_TTY_INIT")
#define O_WRONLY        0x1

#endif // _LINUX_MIPS_FCNTL_H
