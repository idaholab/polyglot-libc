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

#ifndef _LINUX_ERRNO_H
#define _LINUX_ERRNO_H _LINUX_ERRNO_H

#define __NEED_GENERIC_ERRNO 1
#define __NEED_UNIVERSAL_ERRNO 1

#include <_platform.h>
#if __has_include(__target_os_arch_header(errno.h))
#include __target_os_arch_header(errno.h)
#endif

/* these are universal errno values; we provide a macro to prevent them being
 * defined (see above), but this shouldn't need to be used... */
#ifdef __NEED_GENERIC_ERRNO
#define EPERM               1
#define ENOENT              2
#define ESRCH               3
#define EINTR               4
#define EIO                 5
#define ENXIO               6
#define E2BIG               7
#define ENOEXEC             8
#define EBADF               9
#define ECHILD              10
#define EAGAIN              11
#define EWOULDBLOCK         11
#define ENOMEM              12
#define EACCES              13
#define EFAULT              14
#define ENOTBLK             15
#define EBUSY               16
#define EEXIST              17
#define EXDEV               18
#define ENODEV              19
#define ENOTDIR             20
#define EISDIR              21
#define EINVAL              22
#define ENFILE              23
#define EMFILE              24
#define ENOTTY              25
#define ETXTBSY             26
#define EFBIG               27
#define ENOSPC              28
#define ESPIPE              29
#define EROFS               30
#define EMLINK              31
#define EPIPE               32
#define EDOM                33
#define ERANGE              34
#endif

/* this is the Linux universal set of errno values; it is used across a number of
 * different architectures... in general, if Linux is either the main OS for the
 * platform, or support was added recently, this is the set that's used; the main
 * counterexamples are architectures that have other sets for historical reasons
 * (MIPS, SPARC, etc.); fundamentally, it's based on the i386 set */
#ifdef __NEED_UNIVERSAL_ERRNO
#define EDEADLK             35
#define ENAMETOOLONG        36
#define ENOLCK              37
#define ENOSYS              38
#define ENOTEMPTY           39
#define ELOOP               40
#define ENOMSG              42
#define EIDRM               43
#define ECHRNG              44
#define EL2NSYNC            45
#define EL3HLT              46
#define EL3RST              47
#define ELNRNG              48
#define EUNATCH             49
#define ENOCSI              50
#define EL2HLT              51
#define EBADE               52
#define EBADR               53
#define EXFULL              54
#define ENOANO              55
#define EBADRQC             56
#define EBADSLT             57
#define EDEADLOCK           58
#define EBFONT              59
#define ENOSTR              60
#define ENODATA             61
#define ETIME               62
#define ENOSR               63
#define ENONET              64
#define ENOPKG              65
#define EREMOTE             66
#define ENOLINK             67
#define EADV                68
#define ESRMNT              69
#define ECOMM               70
#define EPROTO              71
#define EMULTIHOP           72
#define EDOTDOT             73
#define EBADMSG             74
#define EOVERFLOW           75
#define ENOTUNIQ            76
#define EBADFD              77
#define EREMCHG             78
#define ELIBACC             79
#define ELIBBAD             80
#define ELIBSCN             81
#define ELIBMAX             82
#define ELIBEXEC            83
#define EILSEQ              84
#define ERESTART            85
#define ESTRPIPE            86
#define EUSERS              87
#define ENOTSOCK            88
#define EDESTADDRREQ        89
#define EMSGSIZE            90
#define EPROTOTYPE          91
#define ENOPROTOOPT         92
#define EPROTONOSUPPORT     93
#define ESOCKTNOSUPPORT     94
#define EOPNOTSUPP          95
#define EPFNOSUPPORT        96
#define EAFNOSUPPORT        97
#define EADDRINUSE          98
#define EADDRNOTAVAIL       99
#define ENETDOWN            100
#define ENETUNREACH         101
#define ENETRESET           102
#define ECONNABORTED        103
#define ECONNRESET          104
#define ENOBUFS             105
#define EISCONN             106
#define ENOTCONN            107
#define ESHUTDOWN           108
#define ETOOMANYREFS        109
#define ETIMEDOUT           110
#define ECONNREFUSED        111
#define EHOSTDOWN           112
#define EHOSTUNREACH        113
#define EALREADY            114
#define EINPROGRESS         115
#define ESTALE              116
#define EUCLEAN             117
#define ENOTNAM             118
#define ENAVAIL             119
#define EISNAM              120
#define EREMOTEIO           121
#define EDQUOT              122
#define ENOMEDIUM           123
#define EMEDIUMTYPE         124
#define ECANCELED           125
#define ENOKEY              126
#define EKEYEXPIRED         127
#define EKEYREVOKED         128
#define EKEYREJECTED        129
#define EOWNERDEAD          130
#define ENOTRECOVERABLE     131
#define ERFKILL             132
#define EHWPOISON           133
#endif

#undef __NEED_GENERIC_ERRNO
#undef __NEED_UNIVERSAL_ERRNO

#endif // _LINUX_ERRNO_H
