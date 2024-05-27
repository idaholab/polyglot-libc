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

#ifndef _LINUX_MIPS64_SIGNAL_H
#define _LINUX_MIPS64_SIGNAL_H _LINUX_MIPS64_SIGNAL_H

#define SIGEV_SIGNAL    0
#define SIGEV_NONE      1
#define SIGEV_THREAD    2

#define SIG_BLOCK       1
#define SIG_UNBLOCK     2
#define SIG_SETMASK     3

#define SIGHUP          1
#define SIGINT          2
#define SIGQUIT         3
#define SIGILL          4
#define SIGTRAP         5
#define SIGABRT         6
#define SIGFPE          8
#define SIGKILL         9
#define SIGBUS          10
#define SIGSEGV         11
#define SIGSYS          12
#define SIGPIPE         13
#define SIGALRM         14
#define SIGTERM         15
#define SIGUSR1         16
#define SIGUSR2         17
#define SIGCHLD         18
#define SIGURG          21
#define SIGPOLL         22
#define SIGSTOP         23
#define SIGTSTP         24
#define SIGCONT         25
#define SIGTTIN         26
#define SIGTTOU         27
#define SIGVTALRM       28
#define SIGPROF         29
#define SIGXCPU         30
#define SIGXFSZ         31

#define ILL_ILLOPC      1
#define ILL_ILLOPN      2
#define ILL_ILLADR      3
#define ILL_ILLTRP      4
#define ILL_PRVOPC      5
#define ILL_PRVREG      6
#define ILL_COPROC      7
#define ILL_BADSTK      8

#define FPE_INTDIV      1
#define FPE_INTOVF      2
#define FPE_FLTDIV      3
#define FPE_FLTOVF      4
#define FPE_FLTUND      5
#define FPE_FLTRES      6
#define FPE_FLTINV      7
#define FPE_FLTSUB      8

#define SEGV_MAPERR     1
#define SEGV_ACCERR     2

#define BUS_ADRALN      1
#define BUS_ADRERR      2
#define BUS_OBJERR      3

#define TRAP_BRKPT      1
#define TRAP_TRACE      2

#define CLD_EXITED      1
#define CLD_KILLED      2
#define CLD_DUMPED      3
#define CLD_TRAPPED     4
#define CLD_STOPPED     5
#define CLD_CONTINUED   6

#define POLL_IN         1
#define POLL_OUT        2
#define POLL_MSG        3
#define POLL_ERR        4
#define POLL_PRI        5
#define POLL_HUP        6

#define SI_USER         0x00000000
#define SI_QUEUE        0xffffffff
#define SI_TIMER        0xfffffffd
#define SI_ASYNCIO      0xfffffffe
#define SI_MESGQ        0xfffffffc

#define SA_NOCLDSTOP    0x00000001
#define SA_ONSTACK      0x08000000
#define SA_RESETHAND    0x80000000
#define SA_RESTART      0x10000000
#define SA_SIGINFO      0x00000008
#define SA_NOCLDWAIT    0x00010000
#define SA_NODEFER      0x40000000

#define SS_ONSTACK      0x00000001
#define SS_DISABLE      0x00000002

#define MINSIGSTKSZ     0x00000800
#define SIGSTKSZ        0x00002000

#if !defined(__ASSEMBLER__)

/* XXX: these are defined only if we aren't in assembly-land because they use
 * C-language tokens and cause the assembler to explode */

/* AFAIK, Linux always uses an unsigned long for its sigset unit; other
 * platforms don't (coughFreeBSDcough), which is why it's not hard-coded. */
typedef unsigned long __sigset_int_t;

#define SIG_DFL         ((void (*)(int))0)
#define SIG_ERR         ((void (*)(int))-1)
#define SIG_HOLD        __builtin_error("SIG_HOLD")
#define SIG_IGN         ((void (*)(int))1)

#include <signal.h>

typedef void __kernel_siginfo_t;

typedef void (*__kernel_sighandler_t)(int);
typedef void (*__kernel_sigrestorer_t)(void);
typedef void (*__kernel_sigaction_t)(int, __kernel_siginfo_t *, void *);

#define __KERNEL_RT_NSIG 128
#define __KERNEL_RT_SIGSET_NWORDS \
        (__KERNEL_RT_NSIG / (sizeof(__sigset_int_t) * 8))
#define __KERNEL_RT_SIGSET_BYTES \
        (sizeof(__sigset_int_t) * __KERNEL_RT_SIGSET_NWORDS)
typedef struct __kernel_rt_sigset {
    __sigset_int_t sig[__KERNEL_RT_SIGSET_NWORDS];
} __kernel_rt_sigset_t;

struct __kernel_rt_sigaction {
    unsigned int                sa_flags;
    union {
        __kernel_sighandler_t   sa_handler;
        __kernel_sigaction_t    sa_sigaction;
    };
    __kernel_rt_sigset_t        sa_mask;
};

int __rt_sigaction(int, const struct sigaction *, struct sigaction *);
int __rt_sigprocmask(int, const sigset_t *restrict, sigset_t *restrict);
int __rt_sigsuspend(const sigset_t *);

#define __KERNEL_NSIG (sizeof(__sigset_int_t) * 8)
#define __KERNEL_SIGSET_NWORDS 1
#define __KERNEL_SIGSET_BYTES (sizeof(__sigset_int_t))
typedef __sigset_int_t __kernel_sigset_t;

struct __kernel_sigaction {
    unsigned int                sa_flags;
    union {
        __kernel_sighandler_t   sa_handler;
        __kernel_sigaction_t    sa_sigaction;
    };
    __kernel_sigset_t           sa_mask;
};

int __sigaction(int, const struct sigaction *, struct sigaction *);
int __sigprocmask(int, const sigset_t *restrict, sigset_t *restrict);
int __sigsuspend(const sigset_t *);

#else // !__ASSEMBLER__

#define SIG_DFL         0
#define SIG_ERR         -1
#define SIG_IGN         1

#endif // !__ASSEMBLER__

#endif // _LINUX_MIPS64_SIGNAL_H
