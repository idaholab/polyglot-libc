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

#ifndef _LINUX_SIGNAL_H
#define _LINUX_SIGNAL_H _LINUX_SIGNAL_H

#include <_platform.h>
#if __has_include(__target_os_arch_header(signal.h))
#include __target_os_arch_header(signal.h)
#else
#error "No architecture-specific <bits/linux/signal.h> header available"
#endif

#endif // _LINUX_SIGNAL_H
