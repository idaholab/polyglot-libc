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

/* So it turns out that this header file isn't part of the POSIX standard at
 * all; although ioctl() is defined in <stropts.h> with an equivalent signature,
 * it is intended for use with the XSI STREAMS interface. Thus, we are defining
 * the constants/functions as used for normal ioctl() use here. */

#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H _SYS_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif

/* MACRO/TYPE DEFINITIONS *****************************************************/

#include <target/ioctl.h>

#define TIOCINQ FIONREAD

/* FUNCTION PROTOTYPES ********************************************************/

int ioctl(int, unsigned long, ...);

/******************************************************************************/

#include <stdarg.h>

int __ioctl_v(int, unsigned long, va_list);

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_IOCTL_H
