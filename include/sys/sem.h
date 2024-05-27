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

#if !defined(_SYS_SEM_H)
#define _SYS_SEM_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <sys/ipc.h>
#include <target/sem.h>

/* TYPE DEFINITIONS ***********************************************************/

struct semid_ds
{
    struct ipc_perm     sem_perm;
    unsigned short      sem_nsems;
    time_t              sem_otime;
    time_t              sem_ctime;
};

struct sembuf
{
    unsigned short      sem_num;
    short               sem_op;
    short               sem_flg;
};

/* FUNCTION PROTOTYPES ********************************************************/

int semctl(int, int, int, ...);
int semget(key_t, int, int);
int semop(int, struct sembuf *, size_t);

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SYS_SEM_H
