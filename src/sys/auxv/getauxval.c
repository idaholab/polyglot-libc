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

#include <sys/auxv.h>
#include <elf.h>
#include <errno.h>

#if __target_binfmt_elf

long getauxval(int name)
{
    struct elf_auxinfo *aux = (struct elf_auxinfo *)__auxv;

    for (; aux->a_type != AT_NULL; ++aux) {
        if (aux->a_type == name)
            return aux->a_val;
    }

    errno = ENOENT;
    return -1;
}

#else // __target_binfmt_elf

/* we can't actually do this on unsupported targets, but we can stub it out so
 * that it's -there- but always fails, and then issues a warning if we use it
 * from anywhere; seems like this is probably cleaner so we don't die linking */
long getauxval(int name)
{
    (void)name;
    errno = ENOENT;
    return -1;
}

#endif // __target_binfmt_elf
