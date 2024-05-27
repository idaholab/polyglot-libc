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

#ifndef _FCNTL_H
#define _FCNTL_H _FCNTL_H

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <target/fcntl.h>
#include <target/seek.h>

/* Mask for file access modes based on previous macros. */

#define O_ACCMODE (O_RDONLY|O_WRONLY|O_RDWR)

/* TYPE DEFINITIONS ***********************************************************/

struct flock
{
    short l_type;
    short l_whence;
    off_t l_start;
    off_t l_len;
    pid_t l_pid;
};

/* FUNCTION PROTOTYPES ********************************************************/

int fcntl(int, int, ...);
int open(const char *, int, ...);
int openat(int, const char *, int, ...);
int posix_fadvise(int, off_t, off_t, int);

/* FIXME: the following functions are currently not implemented:
 *
 *   - int creat(const char *, mode_t);
 *   - int posix_fallocate(int, off_t, off_t);
 */

/******************************************************************************/

#include <stdarg.h>

int __fcntl_v(int, int, va_list);
int __open_v(const char *, int, va_list);
int __openat_v(int, const char *, int, va_list);

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _FCNTL_H
