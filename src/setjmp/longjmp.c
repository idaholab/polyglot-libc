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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <setjmp.h>
#include <signal.h>


void __longjmp(jmp_buf, int) __attribute__((noreturn));


__attribute__((noreturn))
void longjmp(jmp_buf env, int val)
{
    /* restore the mask if needed */
    if (env->mask_saved)
        if (sigprocmask(SIG_SETMASK, &env->mask, NULL) == -1) {
            /* FIXME: this could be sort of extreme, but chances are that if
             * we're expecting the mask to be restored, and the mask is -not-
             * restored, execution may do weird things... this could/should be
             * handled with longjmperror, but we don't have that implemented,
             * so this will work for now */
            fprintf(stderr, "**** LONGJMP sigprocmask() failed (%s/%d)\n",
                    strerror(errno), errno);
            abort();
        }
    /* actually do the longjmp (assembly) */
    __longjmp(env, val);
}

void _longjmp(jmp_buf, int) __attribute__((alias("longjmp"), noreturn));
void siglongjmp(jmp_buf, int) __attribute__((alias("longjmp"), noreturn));

