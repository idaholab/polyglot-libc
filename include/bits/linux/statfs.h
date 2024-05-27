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

#ifndef _LINUX_STATFS_H
#define _LINUX_STATFS_H _LINUX_STATFS_H

#include <sys/statfs.h>
#include <bits/linux/types.h>
#include <stdint.h>

#define __NEED_KERNEL_STATFS 1
#define __NEED_KERNEL_STATFS64 1
#define __NEED_KERNEL_COMPAT_STATFS64 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(statfs.h))
#include __target_os_arch_header(statfs.h)
#endif

#if (defined(__NEED_STATFS) || defined(__NEED_STATFS64)) \
    && !defined(__kernel_statfs_word)
#error "Arch doesn't define __kernel_statfs_word!"
#endif

#ifdef __NEED_KERNEL_STATFS
#ifndef __PACK_KERNEL_STATFS
#define __PACK_KERNEL_STATFS
#endif
struct __kernel_statfs {
    __kernel_statfs_word f_type;
    __kernel_statfs_word f_bsize;
    __kernel_statfs_word f_blocks;
    __kernel_statfs_word f_bfree;
    __kernel_statfs_word f_bavail;
    __kernel_statfs_word f_files;
    __kernel_statfs_word f_ffree;
    __kernel_fsid_t f_fsid;
    __kernel_statfs_word f_namelen;
    __kernel_statfs_word f_frsize;
    __kernel_statfs_word f_flags;
    __kernel_statfs_word f_spare[4];
} __PACK_KERNEL_STATFS;
#undef __PACK_KERNEL_STATFS
#define __HAS_KERNEL_STATFS 1
#endif // __NEED_KERNEL_STATFS

#ifdef __NEED_KERNEL_STATFS64
#ifndef __PACK_KERNEL_STATFS64
#define __PACK_KERNEL_STATFS64
#endif
struct __kernel_statfs64 {
    __kernel_statfs_word f_type;
    __kernel_statfs_word f_bsize;
    uint64_t f_blocks;
    uint64_t f_bfree;
    uint64_t f_bavail;
    uint64_t f_files;
    uint64_t f_ffree;
    __kernel_fsid_t f_fsid;
    __kernel_statfs_word f_namelen;
    __kernel_statfs_word f_frsize;
    __kernel_statfs_word f_flags;
    __kernel_statfs_word f_spare[4];
} __PACK_KERNEL_STATFS64;
#undef __PACK_KERNEL_STATFS64
#define __HAS_KERNEL_STATFS64 1
#endif // __NEED_KERNEL_STATFS64

#ifdef __NEED_KERNEL_COMPAT_STATFS64
#ifndef __PACK_KERNEL_COMPAT_STATFS64
#define __PACK_KERNEL_COMPAT_STATFS64
#endif
struct __kernel_compat_statfs64 {
    uint32_t f_type;
    uint32_t f_bsize;
    uint64_t f_blocks;
    uint64_t f_bfree;
    uint64_t f_bavail;
    uint64_t f_files;
    uint64_t f_ffree;
    __kernel_fsid_t f_fsid;
    uint32_t f_namelen;
    uint32_t f_frsize;
    uint32_t f_flags;
    uint32_t f_spare[4];
} __PACK_KERNEL_COMPAT_STATFS64;
#undef __PACK_KERNEL_COMPAT_STATFS64
#define __HAS_KERNEL_COMPAT_STATFS64 1
#endif // __NEED_KERNEL_COMPAT_STATFS64

#undef __kernel_statfs_word
#undef __NEED_KERNEL_STATFS
#undef __NEED_KERNEL_STATFS64
#undef __NEED_KERNEL_COMPAT_STATFS64

#ifdef __HAS_KERNEL_STATFS
void __copy_kernel_statfs_to_statfs(const struct __kernel_statfs*, struct statfs*);
#endif
#ifdef __HAS_KERNEL_STATFS64
void __copy_kernel_statfs64_to_statfs(const struct __kernel_statfs64*, struct statfs*);
#endif
#ifdef __HAS_KERNEL_COMPAT_STATFS64
void __copy_kernel_compat_statfs64_to_statfs(const struct __kernel_compat_statfs64*, struct statfs*);
#endif

#endif // _LINUX_STATFS_H
