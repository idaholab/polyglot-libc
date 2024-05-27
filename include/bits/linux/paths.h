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

#ifndef _LINUX_PATHS_H
#define _LINUX_PATHS_H _LINUX_PATHS_H

#define __NEED_PATHS 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(paths.h))
#include __target_os_arch_header(paths.h)
#endif

#ifdef __NEED_PATHS
#define __GROUP_PATH        "/etc/group"
#define __NETDB_HOST_PATH   "/etc/hosts"
#define __NETDB_NET_PATH    "/etc/networks"
#define __NETDB_PROTO_PATH  "/etc/protocols"
#define __NETDB_SERV_PATH   "/etc/services"
#define __NETDB_RESOLV_PATH "/etc/resolv.conf"
#define __PASSWD_PATH       "/etc/passwd"
#define __SHADOW_PATH       "/etc/shadow"
#endif

#undef __NEED_PATHS

#endif // _LINUX_PATHS_H
