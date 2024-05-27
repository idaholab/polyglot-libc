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

#ifndef _LINUX_I386_TYPES_H
#define _LINUX_I386_TYPES_H _LINUX_I386_TYPES_H

typedef long                __kernel_long_t;
typedef unsigned long       __kernel_ulong_t;

/*
#if __LONG_WIDTH__ != 64
typedef unsigned int        __kernel_size_t;
typedef int                 __kernel_ssize_t;
typedef int                 __kernel_ptrdiff_t;
#else
typedef __kernel_ulong_t    __kernel_size_t;
typedef __kernel_long_t     __kernel_ssize_t;
typedef __kernel_long_t     __kernel_ptrdiff_t;
#endif
*/
/* XXX: this used to be the above definition, but long should be the right
 * width regardless of where we are; revert if this ever becomes a problem */
typedef __kernel_ulong_t    __kernel_size_t;
typedef __kernel_long_t     __kernel_ssize_t;
typedef __kernel_long_t     __kernel_ptrdiff_t;

typedef char *              __kernel_caddr_t;
typedef __kernel_long_t     __kernel_clock_t;
typedef int                 __kernel_clockid_t;
typedef int                 __kernel_daddr_t;
typedef unsigned short      __kernel_gid_t;
typedef unsigned short      __kernel_gid16_t;
typedef unsigned int        __kernel_gid32_t;
typedef __kernel_ulong_t    __kernel_ino_t;
typedef unsigned short      __kernel_ipc_pid_t;
typedef int                 __kernel_key_t;
typedef long long           __kernel_loff_t;
typedef unsigned short      __kernel_mode_t;
typedef int                 __kernel_mqd_t;
typedef __kernel_long_t     __kernel_off_t;
typedef unsigned short      __kernel_old_dev_t;
typedef unsigned short      __kernel_old_gid_t;
typedef __kernel_long_t     __kernel_old_time_t;
typedef unsigned short      __kernel_old_uid_t;
typedef int                 __kernel_pid_t;
typedef void              (*__kernel_sighandler_t)(int);
typedef __kernel_long_t     __kernel_suseconds_t;
typedef __kernel_long_t     __kernel_time_t;
typedef long long           __kernel_time64_t;
typedef int                 __kernel_timer_t;
typedef unsigned short      __kernel_uid_t;
typedef unsigned short      __kernel_uid16_t;
typedef unsigned int        __kernel_uid32_t;

typedef struct {
    int val[2];
} __kernel_fsid_t;

#endif // _LINUX_I386_TYPES_H
