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

#include <bits/linux/param.h>
#include <sys/types.h>
#include <sys/auxv.h>
#include <elf.h>

/* XXX: not very many Linux architectures have a getpagesize() syscall natively
 * (SPARC, for example, does, but x86/_64 does not), so we use that if it's
 * available, but otherwise try to pull the value from the ELF AUXV pointer (if
 * this is an ELF file), or just return a static value that *seems* okay based
 * on the Linux headers. */

size_t __getpagesize_nosys()
{
    int pagesz;
#if defined(__target_binfmt_elf)
    if ((pagesz = getauxval(AT_PAGESZ)) != -1)
        return pagesz;
#endif
    return EXEC_PAGESIZE;
}

