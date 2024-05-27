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

//#include <polyglot/syscall_choice.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


extern void (*__debug_init)();

#if 0
//__attribute__((section(debug_data_section)))
struct __choice_info *__choice_info_head = NULL;
//__attribute__((section(debug_data_section)))
struct __choice_info *__choice_info_tail = NULL;


//__attribute__((section(debug_text_section)))
void __syscall_debug_init()
{
    int i;
    const char *static_env;
    char env[128], *ptr = env, *tok;
    struct __choice_info *info;

    /* get our config env var; if we weren't given one, we can just bail here
     * and be done with it */
    if ((static_env = getenv("POLYGLOT_SYSCALL")) == NULL)
        return;

    /* because we need to rewrite it a bit, copy it out */
    strncpy(env, static_env, sizeof(env) - 1);
    /* make sure we're null-terminated, since we could not be */
    env[sizeof(env) - 1] = 0;

    /* if our storage was too small, truncate to the last full option */
    if (strlen(static_env) >= sizeof(env)) {
        *(strrchr(env, ',')) = 0;
        fprintf(stderr, "**** SYSCALL DEBUG: config too long (%d > %d), "
                        "truncated to '%s'\n", strlen(static_env),
                        sizeof(env) - 1, env);
    }

    while (ptr && *ptr) {
        /* get the syscall name token */
        tok = strsep(&ptr, "=");
        /* try to find a matching entry in the linked list */
        for (info = __choice_info_head;
             info && strcmp(info->name, tok);
             info = info->next);

        /* if we didn't find the syscall, warn the user */
        if (!info)
            fprintf(stderr, "**** SYSCALL DEBUG: unknown syscall '%s'\n", tok);

        /* get the value token */
        tok = strsep(&ptr, ",");

        /* if we failed to locate a syscall, just move on */
        if (!info)
            continue;

        /* try to find a matching value */
        for (i = 0; info->options[i] && strcmp(info->options[i], tok); ++i);

        /* if the value didn't match, move on */
        if (!info->options[i]) {
            fprintf(stderr, "**** SYSCALL DEBUG: invalid value '%s' for "
                            "syscall '%s'; valid options: ", tok, info->name);
            for (i = 0; info->options[i]; ++i)
                fprintf(stderr, i ? ", '%s'" : "'%s'", info->options[i]);
            fprintf(stderr, "\n");
            continue;
        }

        /* store the new choice */
        *info->choice = i;
    }
}

__attribute__((section(debug_text_section)))
void __set_debug_init(int argc, char **argv)
{
    __debug_init = __syscall_debug_init;
}
__attribute__((section(debug_preinit_section), used))
static void (*__set_debug_init_ptr)() = __set_debug_init;
#endif

