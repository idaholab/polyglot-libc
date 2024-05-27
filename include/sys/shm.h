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

#if !defined(_SYS_SHM_H)
#define _SYS_SHM_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <sys/ipc.h>
#include <target/shm.h>

/* TYPE DEFINITIONS ***********************************************************/

typedef unsigned long shmatt_t;

struct shmid_ds
{
    struct ipc_perm     shm_perm;
    size_t              shm_segsz;
    pid_t               shm_lpid;
    pid_t               shm_cpid;
    shmatt_t            shm_nattch;
    time_t              shm_atime;
    time_t              shm_dtime;
    time_t              shm_ctime;
};

/* FUNCTION PROTOTYPES ********************************************************/

void *shmat(int, const void *, int);
int shmctl(int, int, /* FIXME: struct shmid_ds */ void *);
int shmdt(const void *);
int shmget(key_t, size_t, int);

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_SHM_H
