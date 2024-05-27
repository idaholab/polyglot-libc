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

#include <polyglot/syscall_choice.h>
#include <bits/linux/syscall.h>
#include <sys/types.h>

syscall_choice(
    /* syscall   */ shmctl,
    /* return    */ int,
    /* args      */ (
                        int, shmid,
                        int, cmd,
                        void* /* struct shmid_ds* */, buf
                    ),
    /* failure   */ -1,
#ifdef __NR_shmctl
    /* option    */ SHMCTL, __sys_shmctl,
#endif
#ifdef HAS_NATIVE_ipc
    /* option    */ IPC, __shmctl_via_ipc,
#endif
)
