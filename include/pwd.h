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

#ifndef _PWD_H
#define _PWD_H _PWD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

struct passwd
{
    char *pw_name;
    char *pw_passwd;
    uid_t pw_uid;
    gid_t pw_gid;
    char *pw_gecos;
    char *pw_dir;
    char *pw_shell;
};

struct passwd *getpwnam(const char *);
struct passwd *getpwent(void);
struct passwd *getpwuid(uid_t);
void endpwent(void);
void setpwent(void);

/* FIXME: the following functions are currently not implemented:
 *
 *   - int getpwuid_r(uid_t, struct passwd *, char *, size_t, struct passwd **);
 *   - int getpwnam_r(const char *, struct passwd *, char *, size_t,
 *          struct passwd **);
 */

#include <target/paths.h>
#include <stdio.h>

#define __PASSWD_BUF_LEN 256

extern char __passwd_buf[__PASSWD_BUF_LEN];
extern struct passwd __passwd_ent;
extern const struct passwd __passwd_list[];
extern const struct passwd *__passwd_list_ptr;
#if defined(__PASSWD_PATH)
extern int __passwd_file_exists;
extern FILE *__passwd_fd;
#endif

void __passwd_openfile();

#ifdef __cplusplus
} // extern C
#endif

#endif // _PWD_H
