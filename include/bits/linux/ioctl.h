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

#ifndef _LINUX_IOCTL_H
#define _LINUX_IOCTL_H _LINUX_IOCTL_H

#define __NEED_IOC_STANDARD_BITS 1
#define __NEED_IOC_ARCH_BITS 1
#define __NEED_IOC_DIRECTION_BITS 1
#define __NEED_IOC_MASKS 1
#define __NEED_IOC_SHIFTS 1
#define __NEED_IOC_COMBINE_MACRO 1
#define __NEED_IO_MACROS 1
#define __NEED_IOCTLS 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(ioctl.h))
#include __target_os_arch_header(ioctl.h)
#endif

#ifdef __NEED_IOC_STANDARD_BITS
#define _IOC_NRBITS     8
#define _IOC_TYPEBITS   8
#endif

#ifdef __NEED_IOC_ARCH_BITS
#define _IOC_SIZEBITS   14
#define _IOC_DIRBITS    2
#endif

#ifdef __NEED_IOC_DIRECTION_BITS
#define _IOC_NONE       0U
#define _IOC_READ       2U
#define _IOC_WRITE      1U
#endif

#ifdef __NEED_IOC_MASKS
#define _IOC_NRMASK     ((1 << (_IOC_NRBITS      )) - 1)
#define _IOC_TYPEMASK   ((1 << (_IOC_TYPEBITS    )) - 1)
#define _IOC_SIZEMASK   ((1 << (_IOC_SIZEBITS    )) - 1)
#define _IOC_DIRMASK    ((1 << (_IOC_DIRBITS     )) - 1)
#endif

#ifdef __NEED_IOC_SHIFTS
#define _IOC_NRSHIFT    0
#define _IOC_TYPESHIFT  (_IOC_NRSHIFT   + _IOC_NRBITS  )
#define _IOC_SIZESHIFT  (_IOC_TYPESHIFT + _IOC_TYPEBITS)
#define _IOC_DIRSHIFT   (_IOC_SIZESHIFT + _IOC_SIZEBITS)
#endif

#ifdef __NEED_IOC_COMBINE_MACRO
#define _IOC(dir, type, nr, size) \
    ( (unsigned int) \
    ( ((dir)  << _IOC_DIRSHIFT) \
    | ((type) << _IOC_TYPESHIFT) \
    | ((nr)   << _IOC_NRSHIFT) \
    | ((size) << _IOC_SIZESHIFT) ))
#endif

#ifdef __NEED_IO_MACROS
#define _IO(t,n)        _IOC(_IOC_NONE,           (t),(n),0        )
#define _IOR(t,n,s)     _IOC(_IOC_READ,           (t),(n),sizeof(s))
#define _IOW(t,n,s)     _IOC(_IOC_WRITE,          (t),(n),sizeof(s))
#define _IOWR(t,n,s)    _IOC(_IOC_READ|_IOC_WRITE,(t),(n),sizeof(s))
#endif

#ifdef __NEED_IOCTLS
#define FIONREAD        0x541b
#define TCFLSH          0x540b
#define TCGETA          0x5405
#define TCGETS          0x5401
#define TCSBRK          0x5409
#define TCSETA          0x5406
#define TCSETAF         0x5408
#define TCSETAW         0x5407
#define TCSETS          0x5402
#define TCSETSF         0x5404
#define TCSETSW         0x5403
#define TCXONC          0x540a
#define TIOCCBRK        0x5428
#define TIOCCONS        0x541d
#define TIOCEXCL        0x540c
#define TIOCGETD        0x5424
#define TIOCGPGRP       0x540f
#define TIOCGPTN        _IOR('T', 48, unsigned int)
#define TIOCGSID        0x5429
#define TIOCGSOFTCAR    0x5419
#define TIOCGWINSZ      0x5413
#define TIOCMBIC        0x5417
#define TIOCMBIS        0x5416
#define TIOCMGET        0x5415
#define TIOCMSET        0x5418
#define TIOCNOTTY       0x5422
#define TIOCNXCL        0x540d
#define TIOCOUTQ        0x5411
#define TIOCSBRK        0x5427
#define TIOCSCTTY       0x540e
#define TIOCSETD        0x5423
#define TIOCSPGRP       0x5410
#define TIOCSPTLCK      _IOW('T', 49, int)
#define TIOCSSOFTCAR    0x541a
#define TIOCSTI         0x5412
#define TIOCSWINSZ      0x5414
#endif

#undef __NEED_IOC_STANDARD_BITS
#undef __NEED_IOC_ARCH_BITS
#undef __NEED_IOC_DIRECTION_BITS
#undef __NEED_IOC_MASKS
#undef __NEED_IOC_SHIFTS
#undef __NEED_IOC_COMBINE_MACRO
#undef __NEED_IO_MACROS
#undef __NEED_IOCTLS

#endif // _LINUX_IOCTL_H
