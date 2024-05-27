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

#if !defined(_SYS_MSG_H)
#define _SYS_MSG_H 1

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <sys/ipc.h>
#include <target/msg.h>

/* TYPE DEFINITIONS ***********************************************************/

typedef unsigned long msgqnum_t;
typedef unsigned long msglen_t;

#define MSG_NOERROR 010000

struct msqid_ds
{
    struct ipc_perm     msg_perm;
    msgqnum_t           msg_qnum;
    msglen_t            msg_qbytes;
    pid_t               msg_lspid;
    pid_t               msg_lrpid;
    time_t              msg_stime;
    time_t              msg_rtime;
    time_t              msg_ctime;
};

/* FUNCTION PROTOTYPES ********************************************************/

int msgctl(int, int, struct msqid_ds *);
int msgget(key_t, int);
ssize_t msgrcv(int, void *, size_t, long int, int);
int msgsnd(int, const void *, size_t, int);


/******************************************************************************/

#endif // _SYS_MSG_H
