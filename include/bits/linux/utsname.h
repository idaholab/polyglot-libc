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

#ifndef _LINUX_UTSNAME_H
#define _LINUX_UTSNAME_H _LINUX_UTSNAME_H

#define __NEED_KERNEL_UTSNAME_OLDOLD_SIZE 1
#define __NEED_KERNEL_UTSNAME_OLD_SIZE 1
#define __NEED_KERNEL_UTSNAME_SIZE 1
#define __NEED_KERNEL_UTSNAME_OLDOLD 1
#define __NEED_KERNEL_UTSNAME_OLD 1
#define __NEED_KERNEL_UTSNAME 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(utsname.h))
#include __target_os_arch_header(utsname.h)
#endif

#ifdef __NEED_KERNEL_UTSNAME_OLDOLD_SIZE
#undef __NEED_KERNEL_UTSNAME_OLDOLD_SIZE
#define __KERNEL_UTSNAME_OLDOLD_SIZE 9
#endif

#ifdef __NEED_KERNEL_UTSNAME_OLD_SIZE
#undef __NEED_KERNEL_UTSNAME_OLD_SIZE
#define __KERNEL_UTSNAME_OLD_SIZE 65
#endif

#ifdef __NEED_KERNEL_UTSNAME_SIZE
#undef __NEED_KERNEL_UTSNAME_SIZE
#define __KERNEL_UTSNAME_SIZE 65
#endif

#ifdef __NEED_KERNEL_UTSNAME_OLDOLD
#undef __NEED_KERNEL_UTSNAME_OLDOLD
struct kernel_utsname_oldold
{
    char sysname    [__KERNEL_UTSNAME_OLDOLD_SIZE];
    char nodename   [__KERNEL_UTSNAME_OLDOLD_SIZE];
    char release    [__KERNEL_UTSNAME_OLDOLD_SIZE];
    char version    [__KERNEL_UTSNAME_OLDOLD_SIZE];
    char machine    [__KERNEL_UTSNAME_OLDOLD_SIZE];
};
#endif

#ifdef __NEED_KERNEL_UTSNAME_OLD
#undef __NEED_KERNEL_UTSNAME_OLD
struct kernel_utsname_old
{
    char sysname    [__KERNEL_UTSNAME_OLD_SIZE];
    char nodename   [__KERNEL_UTSNAME_OLD_SIZE];
    char release    [__KERNEL_UTSNAME_OLD_SIZE];
    char version    [__KERNEL_UTSNAME_OLD_SIZE];
    char machine    [__KERNEL_UTSNAME_OLD_SIZE];
};
#endif

#ifdef __NEED_KERNEL_UTSNAME
#undef __NEED_KERNEL_UTSNAME
struct kernel_utsname
{
    char sysname    [__KERNEL_UTSNAME_SIZE];
    char nodename   [__KERNEL_UTSNAME_SIZE];
    char release    [__KERNEL_UTSNAME_SIZE];
    char version    [__KERNEL_UTSNAME_SIZE];
    char machine    [__KERNEL_UTSNAME_SIZE];
    char domainname [__KERNEL_UTSNAME_SIZE];
};
#endif

#endif // _LINUX_UTSNAME_H
