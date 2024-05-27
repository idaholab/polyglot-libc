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

#ifndef _LINUX_SPARC_FCNTL_H
#define _LINUX_SPARC_FCNTL_H 1

#undef __NEED_FCNTL_COMMANDS
#undef __NEED_FCNTL_FLAGS
#undef __NEED_FILE_CONSTANTS

/* Command argument to fcntl(). */
#define F_DUPFD         0
#define F_GETFD         1
#define F_SETFD         2
#define F_GETFL         3
#define F_SETFL         4
#define F_GETOWN        5
#define F_SETOWN        6
#define F_GETLK         7
#define F_SETLK         8
#define F_SETLKW        9
#define F_SETSIG        10
#define F_GETSIG        11
#define F_GETLK64       12
#define F_SETLK64       13
#define F_SETLKW64      14
#define F_SETLEASE      1024
#define F_GETLEASE      1025
#define F_NOTIFY        1026

/* Record locking flags to fcntl(). */
#define F_RDLCK         1
#define F_WRLCK         2
#define F_UNLCK         3

/* File flag constants. */
#define O_ACCMODE       0x3
#define O_APPEND        0x8
#define O_ASYNC         0x40
#define O_CREAT         0x200
#define O_DIRECT        0x100000
#define O_DIRECTORY     0x10000
#define O_EXCL          0x800
#define O_EXEC          __builtin_error("O_EXEC")
#define O_NDELAY        (0x0004 | O_NONBLOCK)
#define O_NOATIME       0x200000
#define O_NOCTTY        0x8000
#define O_NOFOLLOW      0x20000
#define O_NONBLOCK      0x4000
#define O_RDONLY        0x0
#define O_RDWR          0x2
#define O_RSYNC         __builtin_error("O_RSYNC")
#define O_SEARCH        __builtin_error("O_SEARCH")
#define O_SYNC          0x2000
#define O_TRUNC         0x400
#define O_TTY_INIT      __builtin_error("O_TTY_INIT")
#define O_WRONLY        0x1

#endif // _LINUX_SPARC_FCNTL_H
