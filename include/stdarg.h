/* This file is part of the Polyglot C Library. It originates from the Public
   Domain C Library (PDCLib).

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

/* Variable arguments <stdarg.h> */

#ifndef _PDCLIB_STDARG_H
#define _PDCLIB_STDARG_H _PDCLIB_STDARG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pdclib/_PDCLIB_config.h"

typedef _PDCLIB_va_list va_list;

#define va_arg( ap, type )    _PDCLIB_va_arg( ap, type )
#define va_copy( dest, src )  _PDCLIB_va_copy( dest, src )
#define va_end( ap )          _PDCLIB_va_end( ap )
#define va_start( ap, parmN ) _PDCLIB_va_start( ap, parmN )

/* Extension hook for downstream projects that want to have non-standard
   extensions to standard headers.
*/
#ifdef _PDCLIB_EXTEND_STDARG_H
#include _PDCLIB_EXTEND_STDARG_H
#endif

#ifdef __cplusplus
}
#endif

#endif
