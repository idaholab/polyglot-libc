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

#ifndef _LINUX_SPARC_IPC_H
#define _LINUX_SPARC_IPC_H _LINUX_SPARC_IPC_H

#undef __NEED_IPC_FLAGS
#undef __NEED_IPC64_PERM

#define IPC_CREAT   0x1000
#define IPC_EXCL    0x2000
#define IPC_NOWAIT  0x4000

#include <bits/linux/types.h>

struct __kernel_ipc64_perm {
    __kernel_key_t      key;
    __kernel_uid32_t    uid;
    __kernel_gid32_t    gid;
    __kernel_uid32_t    cuid;
    __kernel_gid32_t    cgid;
#ifndef __arch64__
    unsigned short      __pad0;
#endif
    __kernel_mode_t     mode;
    unsigned short      __pad1;
    unsigned short      seq;
    unsigned long long  __unused1;
    unsigned long long  __unused2;
};

#endif // _LINUX_SPARC_IPC_H
