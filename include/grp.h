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

#ifndef _GRP_H
#define _GRP_H _GRP_H 

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#define __GROUP_MEMBER_COUNT 8

struct group
{
    char *gr_name;
    char *gr_passwd;
    gid_t gr_gid;
    char *gr_mem[__GROUP_MEMBER_COUNT+1];
};

struct group *getgrgid(gid_t);
struct group *getgrnam(const char *);
struct group *getgrent(void);
void endgrent(void);
void setgrent(void);

/* FIXME: the following functions are currently not implemented:
 *
 *   - int getgrgid_r(gid_t, struct group *, char *, size_t, struct group **);
 *   - int getgrnam_r(const char *, struct group *, char *, size_t,
 *          struct group **);
 */

#include <target/paths.h>
#include <stdio.h>

#define __GROUP_BUF_LEN 256

extern char __group_buf[__GROUP_BUF_LEN];
extern struct group __group_ent;
extern const struct group __group_list[];
extern const struct group *__group_list_ptr;
#if defined(__GROUP_PATH)
extern int __group_file_exists;
extern FILE *__group_fd;
#endif

void __group_openfile();

#ifdef __cplusplus
} // extern C
#endif

#endif // _GRP_H
