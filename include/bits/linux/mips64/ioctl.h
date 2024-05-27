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

#ifndef _LINUX_MIPS64_IOCTL_H
#define _LINUX_MIPS64_IOCTL_H _LINUX_MIPS64_IOCTL_H

#undef __NEED_IOC_ARCH_BITS
#undef __NEED_IOC_DIRECTION_BITS
#undef __NEED_IOCTLS

#include <bits/linux/termios.h>

#define _IOC_SIZEBITS   13
#define _IOC_DIRBITS    3

#define _IOC_NONE       1U
#define _IOC_READ       2U
#define _IOC_WRITE      4U

#define FIONREAD        0x467f
#define TCFLSH          0x5407
#define TCGETA          0x5401
#define TCGETS          0x540d
#define TCSBRK          0x5405
#define TCSETA          0x5402
#define TCSETAF         0x5404
#define TCSETAW         0x5403
#define TCSETS          0x540e
#define TCSETSF         0x5410
#define TCSETSW         0x540f
#define TCXONC          0x5406
#define TIOCCBRK        0x5428
#define TIOCCONS        _IOW('t', 120, int)
#define TIOCEXCL        0x740d
#define TIOCGETD        0x7400
#define TIOCGPGRP       _IOR('t', 119, int)
#define TIOCGPTN        _IOR('T', 48, unsigned int)
#define TIOCGSID        0x7416
#define TIOCGSOFTCAR    0x5481
#define TIOCGWINSZ      _IOR('t', 104, struct winsize)
#define TIOCMBIC        0x741c
#define TIOCMBIS        0x741b
#define TIOCMGET        0x741d
#define TIOCMSET        0x741a
#define TIOCNOTTY       0x5471
#define TIOCNXCL        0x740e
#define TIOCOUTQ        0x7472
#define TIOCSBRK        0x5427
#define TIOCSCTTY       0x5480
#define TIOCSETD        0x7401
#define TIOCSPGRP       _IOW('t', 118, int)
#define TIOCSPTLCK      _IOW('T', 49, int)
#define TIOCSSOFTCAR    0x5482
#define TIOCSTI         0x5472
#define TIOCSWINSZ      _IOW('t', 103, struct winsize)

#endif // _LINUX_MIPS64_IOCTL_H
