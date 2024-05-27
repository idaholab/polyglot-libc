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

#ifndef _POLYGLOT_ENVIRON_H
#define _POLYGLOT_ENVIRON_H _POLYGLOT_ENVIRON_H

struct environ_impl
{
    char **buffer;
    unsigned count;
    unsigned total;

    char **owned;
};

extern char **__start_environ;
extern struct environ_impl __environ_impl;
extern char **__environ;

int __env_clear(struct environ_impl *env);
void __env_dump(struct environ_impl *env);
int __env_ensure_writable(struct environ_impl *env);
char *__env_get(struct environ_impl *env, const char *name);
int __env_get_idx(struct environ_impl *env, const char *name);
int __env_put(struct environ_impl *env, char *string, int owned);
int __env_set(struct environ_impl *env, const char *name, const char *value, int overwrite);
int __env_unset(struct environ_impl *env, const char *name);
int __env_verify(struct environ_impl *env);

#endif // _POLYGLOT_ENVIRON_H
