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

#ifndef _LINUX_SPARC_IOCTL_H
#define _LINUX_SPARC_IOCTL_H 1

#undef __NEED_IOC_ARCH_BITS
#undef __NEED_IOC_DIRECTION_BITS
#undef __NEED_IOCTLS

#include <bits/linux/termios.h>

#define _IOC_SIZEBITS   13
#define _IOC_DIRBITS    3

#define _IOC_NONE       1U
#define _IOC_READ       2U
#define _IOC_WRITE      4U

#define FIONREAD        _IOR('f', 127, int)
#define TCFLSH          _IO('T', 7)
#define TCGETA          _IOR('T', 1, struct termio)
#define TCGETS          _IOR('T', 8, struct termios)
#define TCSBRK          _IO('T', 5)
#define TCSETA          _IOW('T', 2, struct termio)
#define TCSETAF         _IOW('T', 4, struct termio)
#define TCSETAW         _IOW('T', 3, struct termio)
#define TCSETS          _IOW('T', 9, struct termios)
#define TCSETSF         _IOW('T', 11, struct termios)
#define TCSETSW         _IOW('T', 10, struct termios)
#define TCXONC          _IO('T', 6)
#define TIOCCBRK        _IO('t', 122)
#define TIOCCONS        _IO('t', 36)
#define TIOCEXCL        _IO('t', 13)
#define TIOCGETD        _IOR('t', 0, int)
#define TIOCGPGRP       _IOR('t', 131, int)
#define TIOCGPTN        _IOR('t', 134, unsigned int)
#define TIOCGSID        _IOR('t', 133, int)
#define TIOCGSOFTCAR    _IOR('t', 100, int)
#define TIOCGWINSZ      _IOR('t', 104, struct winsize)
#define TIOCMBIC        _IOW('t', 107, int)
#define TIOCMBIS        _IOW('t', 108, int)
#define TIOCMGET        _IOR('t', 106, int)
#define TIOCMSET        _IOW('t', 109, int)
#define TIOCNOTTY       _IO('t', 113)
#define TIOCNXCL        _IO('t', 14)
#define TIOCOUTQ        _IOR('t', 115, int)
#define TIOCSBRK        _IO('t', 123)
#define TIOCSCTTY       _IO('t', 132)
#define TIOCSETD        _IOW('t', 1, int)
#define TIOCSPGRP       _IOW('t', 130, int)
#define TIOCSPTLCK      _IOW('t', 135, int)
#define TIOCSSOFTCAR    _IOW('t', 101, int)
#define TIOCSTI         _IOW('t', 114, char)
#define TIOCSWINSZ      _IOW('t', 103, struct winsize)

#endif // _LINUX_SPARC_IOCTL_H
