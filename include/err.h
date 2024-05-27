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

#ifndef _ERR_H
#define _ERR_H _ERR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

__attribute__((noreturn)) void err(int eval, const char *fmt, ...);
__attribute__((noreturn)) void errx(int eval, const char *fmt, ...);
__attribute__((noreturn)) void verr(int eval, const char *fmt, va_list args);
__attribute__((noreturn)) void verrx(int eval, const char *fmt, va_list args);
void vwarn(const char *fmt, va_list args);
void vwarnx(const char *fmt, va_list args);
void warn(const char *fmt, ...);
void warnx(const char *fmt, ...);

void __err_print(int append_err, const char *fmt, va_list args);

#ifdef __cplusplus
} // extern C
#endif

#endif // _ERR_H
