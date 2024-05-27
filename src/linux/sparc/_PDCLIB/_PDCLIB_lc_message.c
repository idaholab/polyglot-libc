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

#include <stddef.h>
#include <pdclib/_PDCLIB_int.h>

struct _PDCLIB_lc_messages_t *_PDCLIB_lc_messages = NULL;

#define ERRNO_CASE(e) case e: return (char*)#e;

char *_PDCLIB_lc_message(int err)
{
    if (_PDCLIB_lc_messages != NULL)
        return _PDCLIB_lc_messages->errno_texts[err];
    switch (err)
    {
    ERRNO_CASE(EPERM)
    ERRNO_CASE(ENOENT)
    ERRNO_CASE(ESRCH)
    ERRNO_CASE(EINTR)
    ERRNO_CASE(EIO)
    ERRNO_CASE(ENXIO)
    ERRNO_CASE(E2BIG)
    ERRNO_CASE(ENOEXEC)
    ERRNO_CASE(EBADF)
    ERRNO_CASE(ECHILD)
    ERRNO_CASE(EAGAIN)
    ERRNO_CASE(ENOMEM)
    ERRNO_CASE(EACCES)
    ERRNO_CASE(EFAULT)
    ERRNO_CASE(ENOTBLK)
    ERRNO_CASE(EBUSY)
    ERRNO_CASE(EEXIST)
    ERRNO_CASE(EXDEV)
    ERRNO_CASE(ENODEV)
    ERRNO_CASE(ENOTDIR)
    ERRNO_CASE(EISDIR)
    ERRNO_CASE(EINVAL)
    ERRNO_CASE(ENFILE)
    ERRNO_CASE(EMFILE)
    ERRNO_CASE(ENOTTY)
    ERRNO_CASE(ETXTBSY)
    ERRNO_CASE(EFBIG)
    ERRNO_CASE(ENOSPC)
    ERRNO_CASE(ESPIPE)
    ERRNO_CASE(EROFS)
    ERRNO_CASE(EMLINK)
    ERRNO_CASE(EPIPE)
    ERRNO_CASE(EDOM)
    ERRNO_CASE(ERANGE)
    ERRNO_CASE(EINPROGRESS)
    ERRNO_CASE(EALREADY)
    ERRNO_CASE(ENOTSOCK)
    ERRNO_CASE(EDESTADDRREQ)
    ERRNO_CASE(EMSGSIZE)
    ERRNO_CASE(EPROTOTYPE)
    ERRNO_CASE(ENOPROTOOPT)
    ERRNO_CASE(EPROTONOSUPPORT)
    ERRNO_CASE(ESOCKTNOSUPPORT)
    ERRNO_CASE(EOPNOTSUPP)
    ERRNO_CASE(EPFNOSUPPORT)
    ERRNO_CASE(EAFNOSUPPORT)
    ERRNO_CASE(EADDRINUSE)
    ERRNO_CASE(EADDRNOTAVAIL)
    ERRNO_CASE(ENETDOWN)
    ERRNO_CASE(ENETUNREACH)
    ERRNO_CASE(ENETRESET)
    ERRNO_CASE(ECONNABORTED)
    ERRNO_CASE(ECONNRESET)
    ERRNO_CASE(ENOBUFS)
    ERRNO_CASE(EISCONN)
    ERRNO_CASE(ENOTCONN)
    ERRNO_CASE(ESHUTDOWN)
    ERRNO_CASE(ETOOMANYREFS)
    ERRNO_CASE(ETIMEDOUT)
    ERRNO_CASE(ECONNREFUSED)
    ERRNO_CASE(ELOOP)
    ERRNO_CASE(ENAMETOOLONG)
    ERRNO_CASE(EHOSTDOWN)
    ERRNO_CASE(EHOSTUNREACH)
    ERRNO_CASE(ENOTEMPTY)
    ERRNO_CASE(EPROCLIM)
    ERRNO_CASE(EUSERS)
    ERRNO_CASE(EDQUOT)
    ERRNO_CASE(ESTALE)
    ERRNO_CASE(EREMOTE)
    ERRNO_CASE(ENOSTR)
    ERRNO_CASE(ETIME)
    ERRNO_CASE(ENOSR)
    ERRNO_CASE(ENOMSG)
    ERRNO_CASE(EBADMSG)
    ERRNO_CASE(EIDRM)
    ERRNO_CASE(EDEADLK)
    ERRNO_CASE(ENOLCK)
    ERRNO_CASE(ENONET)
    ERRNO_CASE(ERREMOTE)
    ERRNO_CASE(ENOLINK)
    ERRNO_CASE(EADV)
    ERRNO_CASE(ESRMNT)
    ERRNO_CASE(ECOMM)
    ERRNO_CASE(EPROTO)
    ERRNO_CASE(EMULTIHOP)
    ERRNO_CASE(EDOTDOT)
    ERRNO_CASE(EREMCHG)
    ERRNO_CASE(ENOSYS)
    ERRNO_CASE(ESTRPIPE)
    ERRNO_CASE(EOVERFLOW)
    ERRNO_CASE(EBADFD)
    ERRNO_CASE(ECHRNG)
    ERRNO_CASE(EL2NSYNC)
    ERRNO_CASE(EL3HLT)
    ERRNO_CASE(EL3RST)
    ERRNO_CASE(ELNRNG)
    ERRNO_CASE(EUNATCH)
    ERRNO_CASE(ENOCSI)
    ERRNO_CASE(EL2HLT)
    ERRNO_CASE(EBADE)
    ERRNO_CASE(EBADR)
    ERRNO_CASE(EXFULL)
    ERRNO_CASE(ENOANO)
    ERRNO_CASE(EBADRQC)
    ERRNO_CASE(EBADSLT)
    ERRNO_CASE(EDEADLOCK)
    ERRNO_CASE(EBFONT)
    ERRNO_CASE(ELIBEXEC)
    ERRNO_CASE(ENODATA)
    ERRNO_CASE(ELIBBAD)
    ERRNO_CASE(ENOPKG)
    ERRNO_CASE(ELIBACC)
    ERRNO_CASE(ENOTUNIQ)
    ERRNO_CASE(ERESTART)
    ERRNO_CASE(EUCLEAN)
    ERRNO_CASE(ENOTNAM)
    ERRNO_CASE(ENAVAIL)
    ERRNO_CASE(EISNAM)
    ERRNO_CASE(EREMOTEIO)
    ERRNO_CASE(EILSEQ)
    ERRNO_CASE(ELIBMAX)
    ERRNO_CASE(ELIBSCN)
    ERRNO_CASE(ENOMEDIUM)
    ERRNO_CASE(EMEDIUMTYPE)
    ERRNO_CASE(ECANCELED)
    ERRNO_CASE(ENOKEY)
    ERRNO_CASE(EKEYEXPIRED)
    ERRNO_CASE(EKEYREVOKED)
    ERRNO_CASE(EKEYREJECTED)
    ERRNO_CASE(EOWNERDEAD)
    ERRNO_CASE(ENOTRECOVERABLE)
    default:
        return (char*)"(unknown error)";
    }
}

