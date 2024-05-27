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

#ifndef _PTHREAD_H
#define _PTHREAD_H _PTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

/* XXX: this is a very, very fake pthread implementation... */

typedef long pthread_t;
typedef void *pthread_attr_t;
typedef void *pthread_key_t;
typedef void *pthread_mutex_t;
typedef void *pthread_mutexattr_t;

// these are "implemented" (i.e. shimmed to work in a non-threaded way)

int pthread_attr_init(pthread_attr_t*);
int pthread_create(pthread_t*, const pthread_attr_t*, void *(*)(void*), void*);
int pthread_join(pthread_t, void**);
int pthread_key_create(pthread_key_t*, void(*)(void*));
int pthread_key_delete(pthread_key_t);
int pthread_mutex_destroy(pthread_mutex_t*);
int pthread_mutex_init(pthread_mutex_t*, const pthread_mutexattr_t*);
int pthread_mutex_lock(pthread_mutex_t*);
int pthread_mutex_trylock(pthread_mutex_t*);
int pthread_mutex_unlock(pthread_mutex_t*);
int pthread_setspecific(pthread_key_t, const void*);
pthread_t pthread_self(void);
void *pthread_getspecific(pthread_key_t);
void pthread_cleanup_pop(int);
void pthread_cleanup_push(void (*)(void*), void*);

struct __pthread_key
{
    void *value;
    void (*destructor)(void*);
};

#ifdef __cplusplus
} // extern C
#endif

#endif // _PTHREAD_H
