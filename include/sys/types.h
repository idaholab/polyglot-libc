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

#if !defined(_SYS_TYPES_H)
#define _SYS_TYPES_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* ASSERTIONS *****************************************************************/

/* The following assertion is in place because on all the platforms we are
 * currently targeting, it is correct, but could need to be adjusted in the
 * future if we add a platform that doesn't match. */

#if __SIZEOF_SIZE_T__ != __SIZEOF_LONG__
#error "sizeof(size_t) != sizeof(long)"
#endif

/******************************************************************************/

/* The types defined in this file don't match the kernel-internal types; this is
 * to provide the widest possible field for each type so that we can coalesce
 * different syscalls (i.e. stat/stat64) into a single resulting field based on
 * what is available on a given platform at runtime.
 *
 * We intentionally don't define any of the following. This is not in compliance
 * with the POSIX.1-2008 standard, but these represent features that are not
 * implemented in this particular C library (but could be at a later date).
 *
 *   - pthread_attr_t
 *   - pthread_barrier_t
 *   - pthread_barrierattr_t
 *   - pthread_cond_t
 *   - pthread_condattr_t
 *   - pthread_key_t
 *   - pthread_mutex_t
 *   - pthread_mutexattr_t
 *   - pthread_once_t
 *   - pthread_rwlock_t
 *   - pthread_rwlockattr_t
 *   - pthread_spinlock_t
 *   - pthread_t
 *   - trace_attr_t         [OB, TRC]
 *   - trace_event_id_t     [OB, TRC]
 *   - trace_event_set_t    [OB, TRC]
 *   - trace_id_t           [OB, TRC]
 */

/* POSIX TYPES ****************************************************************/

typedef long long           blkcnt_t;
typedef long long           blksize_t;
typedef long long           clock_t;
typedef int                 clockid_t;
typedef unsigned long long  dev_t;
typedef unsigned long long  fsblkcnt_t;
typedef unsigned long long  fsfilcnt_t;
typedef unsigned int        gid_t;
typedef int                 id_t;
typedef unsigned long long  ino_t;
typedef int                 key_t;
typedef unsigned int        mode_t;
typedef unsigned long long  nlink_t;
typedef long long           off_t;
typedef int                 pid_t;
typedef __SIZE_TYPE__       size_t;
typedef long                ssize_t;
typedef long long           suseconds_t;
typedef long long           time_t;
typedef long long           timer_t;
typedef unsigned int        uid_t;
typedef unsigned long long  useconds_t;

/* NON-POSIX TYPES ************************************************************/

typedef unsigned char       u_int8_t;
typedef unsigned short      u_int16_t;
typedef unsigned            u_int32_t;
typedef char               *caddr_t;
typedef unsigned char       u_char;
typedef unsigned short      u_short, ushort;
typedef unsigned            u_int, uint;
typedef unsigned long       u_long, ulong;
typedef long long           quad_t;
typedef unsigned long long  u_quad_t;
typedef unsigned int        fsid_t;

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_TYPES_H
