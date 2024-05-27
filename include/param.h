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

/* FIXME: This needs to be reworked some to be consistent with other <param.h>
 * implementations; ours is based solely on bits we've pulled out. Also add
 * non-GCC implementations of things (even if they're naive). */

#if !defined(_PARAM_H)
#define _PARAM_H 1

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

#if defined(__GNUC__)

#define GENERIC_MAX(x, y) \
    ({ \
        __typeof__(x) _x = (x); \
        __typeof__(y) _y = (y); \
        _x > _y ? _x : _y; \
    })
#define GENERIC_MIN(x, y) \
    ({ \
        __typeof__(x) _x = (x); \
        __typeof__(y) _y = (y); \
        _x < _y ? _x : _y; \
    })

#define ENSURE_TYPE(t, x) _Generic((x), t: (x))

#define MAX(t, x, y) (t)GENERIC_MAX(ENSURE_TYPE(t, x), ENSURE_TYPE(t, y))
#define MIN(t, x, y) (t)GENERIC_MIN(ENSURE_TYPE(t, x), ENSURE_TYPE(t, y))

#else
#error "MIN/MAX macros not defined for non-GCC compilers."
#endif

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _PARAM_H
