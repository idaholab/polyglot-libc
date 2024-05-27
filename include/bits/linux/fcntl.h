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

#ifndef _LINUX_FCNTL_H
#define _LINUX_FCNTL_H _LINUX_FCNTL_H 

#define __NEED_FCNTL_COMMANDS 1
#define __NEED_FCNTL_FD_FLAGS 1
#define __NEED_FCNTL_FLAGS 1
#define __NEED_FILE_CONSTANTS 1
#define __NEED_AT_CONSTANTS 1
#define __NEED_FADVISE_CONSTANTS 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(fcntl.h))
#include __target_os_arch_header(fcntl.h)
#endif

// FIXME: move... where did this come from?
#define F_OK 0

/* Command argument to fcntl(). */
#ifdef __NEED_FCNTL_COMMANDS
#define F_DUPFD                 0
#define F_GETFD                 1
#define F_SETFD                 2
#define F_GETFL                 3
#define F_SETFL                 4
#define F_GETLK                 5
#define F_SETLK                 6
#define F_SETLKW                7
#define F_SETOWN                8
#define F_GETOWN                9
#define F_DUPFD_CLOEXEC         1030
#endif

/* File descriptor flags to fcntl(). */
#ifdef __NEED_FCNTL_FD_FLAGS
#define FD_CLOEXEC  1
#endif

/* Record locking flags to fcntl(). */
#ifdef __NEED_FCNTL_FLAGS
#define F_RDLCK                 0
#define F_WRLCK                 1
#define F_UNLCK                 2
#endif

/* File flag constants. */
#ifdef __NEED_FILE_CONSTANTS
#define O_APPEND                0x400
#define O_CLOEXEC               0x80000
#define O_CREAT                 0x40
#define O_DIRECTORY             0x10000
#define O_DSYNC                 0x1000
#define O_EXCL                  0x80
#define O_EXEC                  __builtin_error("O_EXEC")
#define O_NOCTTY                0x100
#define O_NOFOLLOW              0x20000
#define O_NONBLOCK              0x800
#define O_RDONLY                0x0
#define O_RDWR                  0x2
#define O_RSYNC                 __builtin_error("O_RSYNC")
#define O_SEARCH                __builtin_error("O_SEARCH")
#define O_SYNC                  0x101000
#define O_TRUNC                 0x200
#define O_TTY_INIT              __builtin_error("O_TTY_INIT")
#define O_WRONLY                0x1
#endif

/* Constants for *at() functions. */
#ifdef __NEED_AT_CONSTANTS
#define AT_FDCWD                (-100)
#define AT_EACCESS              0x200
#define AT_SYMLINK_NOFOLLOW     0x100
#define AT_SYMLINK_FOLLOW       0x400
#define AT_REMOVEDIR            0x200
#endif

/* Constants for posix_fadvise(). */
#ifdef __NEED_FADVISE_CONSTANTS
#define POSIX_FADV_DONTNEED     4
#define POSIX_FADV_NOREUSE      5
#define POSIX_FADV_NORMAL       0
#define POSIX_FADV_RANDOM       1
#define POSIX_FADV_SEQUENTIAL   2
#define POSIX_FADV_WILLNEED     3
#endif

#undef __NEED_FCNTL_COMMANDS
#undef __NEED_FCNTL_FD_FLAGS
#undef __NEED_FCNTL_FLAGS
#undef __NEED_FILE_CONSTANTS
#undef __NEED_AT_CONSTANTS
#undef __NEED_FADVISE_CONSTANTS


#endif // _LINUX_FCNTL_H
