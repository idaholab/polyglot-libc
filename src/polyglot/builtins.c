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

/* XXX: This is the base set of builtins needed by the core CRT functionality,
 * so we don't pull in more than we need ideally. */

//#include <polyglot/syscall_choice.h>
#include <polyglot/environ.h>
#include <stddef.h>

int __argc = 0;
char **__argv = NULL;

char **__start_environ;
struct environ_impl __environ_impl;
extern char **__environ __attribute__((alias("__environ_impl")));
extern char **environ __attribute__((alias("__environ_impl")));

void (*__debug_init)() = NULL;

void *__heap_begin = NULL;
void *__heap_end = NULL;

