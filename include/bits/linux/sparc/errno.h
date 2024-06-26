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

#ifndef _LINUX_SPARC_ERRNO_H
#define _LINUX_SPARC_ERRNO_H 1

#undef __NEED_UNIVERSAL_ERRNO

/* XXX: 35 seems to not be defined; these follow Solaris' scheme, so it could
 * be that the initial set is a little different, or 35 on Solaris is something
 * Linux just simply doesn't have... not sure */
//#define <unknown>         35
#define EINPROGRESS         36
#define EALREADY            37
#define ENOTSOCK            38
#define EDESTADDRREQ        39
#define EMSGSIZE            40
#define EPROTOTYPE          41
#define ENOPROTOOPT         42
#define EPROTONOSUPPORT     43
#define ESOCKTNOSUPPORT     44
#define EOPNOTSUPP          45
#define EPFNOSUPPORT        46
#define EAFNOSUPPORT        47
#define EADDRINUSE          48
#define EADDRNOTAVAIL       49
#define ENETDOWN            50
#define ENETUNREACH         51
#define ENETRESET           52
#define ECONNABORTED        53
#define ECONNRESET          54
#define ENOBUFS             55
#define EISCONN             56
#define ENOTCONN            57
#define ESHUTDOWN           58
#define ETOOMANYREFS        59
#define ETIMEDOUT           60
#define ECONNREFUSED        61
#define ELOOP               62
#define ENAMETOOLONG        63
#define EHOSTDOWN           64
#define EHOSTUNREACH        65
#define ENOTEMPTY           66
#define EPROCLIM            67
#define EUSERS              68
#define EDQUOT              69
#define ESTALE              70
#define EREMOTE             71
#define ENOSTR              72
#define ETIME               73
#define ENOSR               74
#define ENOMSG              75
#define EBADMSG             76
#define EIDRM               77
#define EDEADLK             78
#define ENOLCK              79
#define ENONET              80
#define ERREMOTE            81
#define ENOLINK             82
#define EADV                83
#define ESRMNT              84
#define ECOMM               85
#define EPROTO              86
#define EMULTIHOP           87
#define EDOTDOT             88
#define EREMCHG             89
#define ENOSYS              90
#define ESTRPIPE            91
#define EOVERFLOW           92
#define EBADFD              93
#define ECHRNG              94
#define EL2NSYNC            95
#define EL3HLT              96
#define EL3RST              97
#define ELNRNG              98
#define EUNATCH             99
#define ENOCSI              100
#define EL2HLT              101
#define EBADE               102
#define EBADR               103
#define EXFULL              104
#define ENOANO              105
#define EBADRQC             106
#define EBADSLT             107
#define EDEADLOCK           108
#define EBFONT              109
#define ELIBEXEC            110
#define ENODATA             111
#define ELIBBAD             112
#define ENOPKG              113
#define ELIBACC             114
#define ENOTUNIQ            115
#define ERESTART            116
#define EUCLEAN             117
#define ENOTNAM             118
#define ENAVAIL             119
#define EISNAM              120 
#define EREMOTEIO           121
#define EILSEQ              122
#define ELIBMAX             123
#define ELIBSCN             124
#define ENOMEDIUM           125
#define EMEDIUMTYPE         126
#define ECANCELED           127
#define ENOKEY              128
#define EKEYEXPIRED         129
#define EKEYREVOKED         130
#define EKEYREJECTED        131
#define EOWNERDEAD          132
#define ENOTRECOVERABLE     133

#endif // _LINUX_SPARC_ERRNO_H
