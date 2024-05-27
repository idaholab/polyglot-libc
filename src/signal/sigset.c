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

#include <param.h>
#include <sys/types.h>
#include <signal.h>


void __sigemptyset(__sigset_int_t *set, ssize_t len)
{
    while (--len >= 0) {
        set[len] = 0ul;
    }
}

void __sigfillset(__sigset_int_t *set, ssize_t len)
{
    while (--len >= 0) {
        set[len] = ~0ul;
    }
}

int __sigisemptyset(const __sigset_int_t *set, ssize_t len)
{
    while (--len >= 0) {
        if (set[len] != 0) {
            return 1;
        }
    }
    return 0;
}

void __sigcopyset(__sigset_int_t *dest, ssize_t dest_len, __sigset_int_t *src,
                  ssize_t src_len)
{
    ssize_t len = MIN(ssize_t, dest_len, src_len);

    __sigemptyset(dest, dest_len);
    while (--len >= 0) {
        dest[len] = src[len];
    }
}

void __sigandset(__sigset_int_t *dest, __sigset_int_t *left, __sigset_int_t *right,
                 ssize_t len)
{
    while (--len >= 0) {
        dest[len] = left[len] & right[len];
    }
}

void __sigorset(__sigset_int_t *dest, __sigset_int_t *left, __sigset_int_t *right,
                ssize_t len)
{
    while (--len >= 0) {
        dest[len] = left[len] | right[len];
    }
}

int __sigismember(const __sigset_int_t *set, ssize_t len, int sig)
{
    return (set[__sigword(sig)] & __sigmask(sig)) ? 1 : 0;
}

void __sigaddset(__sigset_int_t *set, ssize_t len, int sig)
{
    set[__sigword(sig)] |= __sigmask(sig);
}

void __sigdelset(__sigset_int_t *set, ssize_t len, int sig)
{
    set[__sigword(sig)] &= ~__sigmask(sig);
}

/******************************************************************************/

int sigemptyset(sigset_t *set)
{
    __sigemptyset((__sigset_int_t *)set, __SIGSET_NWORDS);
    return 0;
}

int sigfillset(sigset_t *set)
{
    __sigfillset((__sigset_int_t *)set, __SIGSET_NWORDS);
    return 0;
}

int sigismember(const sigset_t *set, int sig)
{
    return __sigismember((const __sigset_int_t *)set, __SIGSET_NWORDS, sig);
}

int sigaddset(sigset_t *set, int sig)
{
    __sigaddset((__sigset_int_t *)set, __SIGSET_NWORDS, sig);
    return 0;
}

int sigdelset(sigset_t *set, int sig)
{
    __sigdelset((__sigset_int_t *)set, __SIGSET_NWORDS, sig);
    return 0;
}


