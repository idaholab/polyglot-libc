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

#ifndef _LINUX_IPC_H
#define _LINUX_IPC_H _LINUX_IPC_H

#define __NEED_IPC_FLAGS 1
#define __NEED_IPC_PRIVATE 1
#define __NEED_IPC_COMMANDS 1
#define __NEED_IPC_OPS 1
#define __NEED_IPC_VERSIONS 1
#define __NEED_IPC_PERM 1
#define __NEED_IPC64_PERM 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(ipc.h))
#include __target_os_arch_header(ipc.h)
#endif

#ifdef __NEED_IPC_FLAGS
#define IPC_CREAT       01000
#define IPC_EXCL        02000
#define IPC_NOWAIT      04000
#endif

#ifdef __NEED_IPC_PRIVATE
#define IPC_PRIVATE     0
#endif

#ifdef __NEED_IPC_COMMANDS
#define IPC_RMID        0
#define IPC_SET         1
#define IPC_STAT        2
#define IPC_INFO        3
#endif

#include <bits/linux/types.h>

#ifdef __NEED_IPC_OPS
#define IPC_SEMOP       1
#define IPC_SEMGET      2
#define IPC_SEMCTL      3
#define IPC_SEMTIMEDOP  4
#define IPC_MSGSND      11
#define IPC_MSGRCV      12
#define IPC_MSGGET      13
#define IPC_MSGCTL      14
#define IPC_SHMAT       21
#define IPC_SHMDT       22
#define IPC_SHMGET      23
#define IPC_SHMCTL      24
#endif

#ifdef __NEED_IPC_VERSIONS
#define IPC_OLD         0
#define IPC_64          0x100
#endif

#ifdef __NEED_IPC_PERM
struct __kernel_ipc_perm
{
    __kernel_key_t      key;
    __kernel_uid_t      uid;
    __kernel_gid_t      gid;
    __kernel_uid_t      cuid;
    __kernel_gid_t      cgid;
    __kernel_mode_t     mode;
    unsigned short      seq;
};
#endif

#ifdef __NEED_IPC64_PERM
struct __kernel_ipc64_perm
{
    __kernel_key_t      key;
    __kernel_uid32_t    uid;
    __kernel_gid32_t    gid;
    __kernel_uid32_t    cuid;
    __kernel_gid32_t    cgid;
    __kernel_mode_t     mode;
    unsigned char       __pad1[4 - sizeof(__kernel_mode_t)];
    unsigned short      seq;
    unsigned short      __pad2;
    __kernel_ulong_t    __unused1;
    __kernel_ulong_t    __unused2;
};
#endif

#define IPCCALL(v,o)    (((v) << 16) | (o))

/* generic IPC multicall, libc maps IPC calls to this */
long __ipc_generic(long, long, long, long, long);

/* macro to handle calling IPC correctly (i.e. with longs) */
#define __ipc(cmd, a, b, c, d) \
    __ipc_generic( \
        (cmd), \
        (long)(a), \
        (long)(b), \
        (long)(c), \
        (long)(d) \
    )

#define __NEED_IPC_FLAGS 1
#define __NEED_IPC_PRIVATE 1
#define __NEED_IPC_COMMANDS 1
#define __NEED_IPC_OPS 1
#define __NEED_IPC_VERSIONS 1
#define __NEED_IPC_PERM 1
#define __NEED_IPC64_PERM 1

#endif // _LINUX_IPC_H
