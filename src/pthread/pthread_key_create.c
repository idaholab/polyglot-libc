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

#include <pthread.h>
#include <stdlib.h>

int pthread_key_create(pthread_key_t *key, void(*destructor)(void*))
{
    struct __pthread_key *item;
    item = (struct __pthread_key*)malloc(sizeof(struct __pthread_key));
    if (item == NULL)
        return -1;

    item->value = NULL;
    item->destructor = destructor;

    *key = (pthread_key_t)item;
    return 0;
}

