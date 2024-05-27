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

#ifndef _SYS_AUXV_H
#define _SYS_AUXV_H _SYS_AUXV_H

#include <_platform.h>
EXTERN_C_START

// pull in feature-test macros so we can check for support
#include <target/features.h>

#define NEED_basic_AT_macros
#define NEED_elf32_auxinfo
#define NEED_elf64_auxinfo

// FIXME: this shouldn't be hard-coded, but needs to be for the moment
#if defined(__target_binfmt_elf)
#define HAS_aux_vector 1
#endif

#if defined(HAS_aux_vector)
#define NEED_getauxval
#define NEED___auxv
#define NEED_elf_auxinfo
#endif

// we let the target provide more auxvec definitions
#include <target/auxv.h>

#if defined(NEED_basic_AT_macros)
// this seems to be the fairly standard chunk of the auxvec entries
#define AT_NULL     0
#define AT_IGNORE   1
#define AT_EXECFD   2
#define AT_PHDR     3
#define AT_PHENT    4
#define AT_PHNUM    5
#define AT_PAGESZ   6
#define AT_BASE     7
#define AT_FLAGS    8
#define AT_ENTRY    9
#define AT_NOTELF   10
#define AT_UID      11
#define AT_EUID     12
#define AT_GID      13
#define AT_EGID     14
#endif

#if defined(NEED_getauxval)
/* Issue a warning if this is used on an unsupported target, but still provide
 * the symbol, since it -does- exist (just is stubbed to always fail). */
#if !defined(HAS_aux_vector)
__polyglot_warning("using getauxval() on an unsupported target!")
#endif
long getauxval(int);
#endif

#if defined(NEED___auxv)
/* We only define this if we're inside Polyglot code proper. Because we should
 * always be feature-testing in our own code, we just die if the feature isn't
 * present and it's ever used. */
#if !defined(HAS_aux_vector)
__polyglot_unavailable("target doesn't support aux vector")
#endif
extern void **__auxv;
#endif 

#if defined(NEED_elf32_auxinfo)
struct elf32_auxinfo {
    int a_type;
    union {
        long a_val;
        void *a_ptr;
    };
};
#endif

#if defined(NEED_elf64_auxinfo)
struct elf64_auxinfo {
    long a_type;
    union {
        long a_val;
        void *a_ptr;
    };
};
#endif

#if defined(NEED_elf_auxinfo)
#if !defined(HAS_aux_vector)
__polyglot_warning("defining struct elf_auxinfo on an unsupported target!")
#endif
#if __SIZEOF_POINTER__ == 8
#define elf_auxinfo elf64_auxinfo
#else
#define elf_auxinfo elf32_auxinfo
#endif
#endif

#undef NEED_basic_AT_macros
#undef NEED_elf32_auxinfo
#undef NEED_elf64_auxinfo
#undef NEED_getauxval
#undef NEED___auxv
#undef NEED_elf_auxinfo

EXTERN_C_END
#endif // _SYS_AUXV_H
