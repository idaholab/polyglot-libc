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
#include <errno.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>


int __setjmp_sig_save(jmp_buf env, int savemask)
{
    /* save the mask if we were asked to */
    env->mask_saved = 0;
    if (savemask) {
        if (sigprocmask(SIG_SETMASK, NULL, &env->mask) != -1) {
            env->mask_saved = 1;
        } else {
            /* FIXME: this could be sort of extreme, but chances are that if
             * we're expecting the mask to get saved, and the mask is -not-
             * saved, execution may do weird things... */
            fprintf(stderr, "**** SETJMP sigprocmask() failed (%s/%d)\n",
                    strerror(errno), errno);
            abort();
        }
    }
    /* always returns zero */
    return 0;
}


