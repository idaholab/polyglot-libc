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

#include <sys/statfs.h>
#include <target/statfs.h>

#define __copy_to_statfs_generic(funcname, kernel_type) \
void funcname(const kernel_type* src, struct statfs* dest) \
{ \
    dest->f_type    = src->f_type; \
    dest->f_bsize   = src->f_bsize; \
    dest->f_blocks  = src->f_blocks; \
    dest->f_bfree   = src->f_bfree; \
    dest->f_bavail  = src->f_bavail; \
    dest->f_files   = src->f_files; \
    dest->f_ffree   = src->f_ffree; \
    dest->f_fsid    = src->f_fsid.val[0]; \
    dest->f_namelen = src->f_namelen; \
    dest->f_frsize  = src->f_frsize; \
    dest->f_flags   = src->f_flags; \
}

#ifdef __HAS_KERNEL_STATFS
__copy_to_statfs_generic(
    __copy_kernel_statfs_to_statfs,
    struct __kernel_statfs
)
#endif

#ifdef __HAS_KERNEL_STATFS64
__copy_to_statfs_generic(
    __copy_kernel_statfs64_to_statfs,
    struct __kernel_statfs64
)
#endif

#ifdef __HAS_KERNEL_COMPAT_STATFS64
__copy_to_statfs_generic(
    __copy_kernel_compat_statfs64_to_statfs,
    struct __kernel_compat_statfs64
)
#endif

#undef __copy_to_statfs_generic

