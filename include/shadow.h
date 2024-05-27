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

#ifndef _SHADOW_H
#define _SHADOW_H _SHADOW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

struct spwd
{
    char *sp_namp;
    char *sp_pwdp;
    long  sp_lstchg;
    long  sp_min;
    long  sp_max;
    long  sp_warn;
    long  sp_inact;
    long  sp_expire;
    unsigned long sp_flag;
};

struct spwd *getspnam(const char *);
struct spwd *getspent(void);
void endspent(void);
void setspent(void);

/* FIXME: the following functions are currently not implemented:
 *
 *   - int getspnam_r(const char *, struct spwd *, char *, size_t,
 *          struct spwd **);
 */

#include <target/paths.h>
#include <stdio.h>

#define __SHADOW_BUF_LEN 256

extern char __shadow_buf[__SHADOW_BUF_LEN];
extern struct spwd __shadow_ent;
extern const struct spwd __shadow_list[];
extern const struct spwd *__shadow_list_ptr;
#if defined(__SHADOW_PATH)
extern int __shadow_file_exists;
extern FILE *__shadow_fd;
#endif

void __shadow_openfile();

#ifdef __cplusplus
} // extern C
#endif

#endif // _SHADOW_H
