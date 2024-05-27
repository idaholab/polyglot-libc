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

#ifndef _PLATFORM_H
#define _PLATFORM_H _PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef linux
#undef linux
#define linux linux
#endif

#ifdef i386
#undef i386
#define i386 i386
#endif

#ifdef mips
#undef mips
#define mips mips
#endif

#ifdef sparc
#undef sparc
#define sparc sparc
#endif

#define __target_arch_header(name)      <bits/__target_arch/name>
#define __target_os_header(name)        <bits/__target_os/name>
#define __target_os_arch_header(name)   <bits/__target_os/__target_arch/name>
#define __target_abi_syscall_header     <bits/__target_os/__target_arch/syscall/__target_abi.h>

#define __polyglot_warning(msg)         __attribute__((warning(msg)))
#define __polyglot_deprecated(msg)      __attribute__((deprecated(msg)))
#define __polyglot_unavailable(msg)     __attribute__((unavailable(msg)))

#ifdef __cplusplus
#define EXTERN_C_START  extern "C" {
#define EXTERN_C_END    } // extern C
#else
#define EXTERN_C_START
#define EXTERN_C_END
#endif

#ifdef __cplusplus
} // extern C
#endif

#endif // _PLATFORM_H
