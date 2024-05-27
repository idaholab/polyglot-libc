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

#ifndef _LINUX_SPARC_SIGNAL_H
#define _LINUX_SPARC_SIGNAL_H _LINUX_SPARC_SIGNAL_H

#define SIGEV_SIGNAL        0
#define SIGEV_NONE          1
#define SIGEV_THREAD        2
#define SIGEV_THREAD_ID     4

#define SIG_BLOCK           1
#define SIG_UNBLOCK         2
#define SIG_SETMASK         4

#define SIGHUP              1
#define SIGINT              2
#define SIGQUIT             3
#define SIGILL              4
#define SIGTRAP             5
#define SIGABRT             6
#define SIGIOT              6
#define SIGEMT              7
#define SIGFPE              8
#define SIGKILL             9
#define SIGBUS              10
#define SIGSEGV             11
#define SIGSYS              12
#define SIGPIPE             13
#define SIGALRM             14
#define SIGTERM             15
#define SIGURG              16
#define SIGSTOP             17
#define SIGTSTP             18
#define SIGCONT             19
#define SIGCHLD             20
#define SIGTTIN             21
#define SIGTTOU             22
#define SIGIO               23
#define SIGPOLL             SIGIO
#define SIGXCPU             24
#define SIGXFSZ             25
#define SIGVTALRM           26
#define SIGPROF             27
#define SIGWINCH            28
#define SIGLOST             29
#define SIGPWR              SIGLOST
#define SIGUSR1             30
#define SIGUSR2             31

/* SIGILL */
#define SUBSIG_STACK        0
#define SUBSIG_ILLINST      2
#define SUBSIG_PRIVINST     3
#define SUBSIG_BADTRAP(t)   (0x80 + (t))
/* SIGEMT */
#define SUBSIG_TAG          10
/* SIGFPE */
#define SUBSIG_FPDISABLED   0x400
#define SUBSIG_FPERROR      0x404
#define SUBSIG_FPINTOVFL    0x001
#define SUBSIG_FPSTSIG      0x002
#define SUBSIG_IDIVZERO     0x014
#define SUBSIG_FPINEXACT    0x0c4
#define SUBSIG_FPDIVZERO    0x0c8
#define SUBSIG_FPUNFLOW     0x0cc
#define SUBSIG_FPOPERROR    0x0d0
#define SUBSIG_FPOVFLOW     0x0d4
/* SIGBUS */
#define SUBSIG_BUSTIMEOUT   1
#define SUBSIG_ALIGNMENT    2
#define SUBSIG_MISCERROR    5
/* SIGSEGV */
#define SUBSIG_NOMAPPING    3
#define SUBSIG_PROTECTION   4
#define SUBSIG_SEGERROR     5

/* SIGILL -> si_code */
#define ILL_ILLOPC          1
#define ILL_ILLOPN          2
#define ILL_ILLADR          3
#define ILL_ILLTRP          4
#define ILL_PRVOPC          5
#define ILL_PRVREG          6
#define ILL_COPROC          7
#define ILL_BADSTK          8
/* SIGFPE -> si_code */
#define FPE_INTDIV          1
#define FPE_INTOVF          2
#define FPE_FLTDIV          3
#define FPE_FLTOVF          4
#define FPE_FLTUND          5
#define FPE_FLTRES          6
#define FPE_FLTINV          7
#define FPE_FLTSUB          8
/* SIGSEGV -> si_code */
#define SEGV_MAPERR         1
#define SEGV_ACCERR         2
/* SIGBUS -> si_code */
#define BUS_ADRALN          1
#define BUS_ADRERR          2
#define BUS_OBJERR          3
/* SIGTRAP -> si_code */
#define TRAP_BRKPT          1
#define TRAP_TRACE          2
/* SIGCHLD -> si_code */
#define CLD_EXITED          1
#define CLD_KILLED          2
#define CLD_DUMPED          3
#define CLD_TRAPPED         4
#define CLD_STOPPED         5
#define CLD_CONTINUED       6
/* SIGPOLL -> si_code */
#define POLL_IN             1
#define POLL_OUT            2
#define POLL_MSG            3
#define POLL_ERR            4
#define POLL_PRI            5
#define POLL_HUP            6
/* SIGEMT -> si_code */
#define EMT_TAGOVF          1

#define SI_ASYNCNL          -60
#define SI_TKILL            -6
#define SI_SIGIO            -5
#define SI_ASYNCIO          -4
#define SI_MESGQ            -3
#define SI_TIMER            -2
#define SI_QUEUE            -1
#define SI_USER             0
#define SI_KERNEL           0x80

#define SA_ONSTACK          0x001
#define SA_STACK            SA_ONSTACK
#define SA_RESTART          0x002
#define SA_ONESHOT          0x004
#define SA_RESETHAND        SA_ONESHOT
#define SA_NOCLDSTOP        0x008
#define SA_NOMASK           0x020
#define SA_NODEFER          SA_NOMASK
#define SA_NOCLDWAIT        0x100
#define SA_SIGINFO          0x200

#define SS_ONSTACK          1
#define SS_DISABLE          2

#define MINSIGSTKSZ         4096
#define SIGSTKSZ            16384

#if !defined(__ASSEMBLER__)

#define SIG_ERR     ((void(*)(int))-1)
#define SIG_DFL     ((void(*)(int)) 0)
#define SIG_IGN     ((void(*)(int)) 1)
#define SIG_HOLD    ((void(*)(int)) 2)

typedef unsigned long __sigset_int_t;

#include <signal.h>

typedef struct __kernel_sigcontext {
    int sigc_onstack;
    int sigc_mask;
    int sigc_sp;
    int sigc_pc;
    int sigc_npc;
    int sigc_psr;
    int sigc_g1;
    int sigc_o0;
    int sigc_oswins;
    char *sigc_spbuf[31];
    struct {
        unsigned long locals[8];
        unsigned long ins[8];
    } sigc_wbuf[31];
} __kernel_sigcontext_t;

typedef struct __kernel_siginfo {
    struct {
        unsigned long psr;
        unsigned long pc;
        unsigned long npc;
        unsigned long y;
        unsigned long u_regs[16];
    } si_regs;
    int si_mask;
} __kernel_siginfo_t;

typedef struct __kernel_siginfo_fpu {
    unsigned long si_float_regs[32];
    unsigned long si_fsr;
    unsigned long si_fpqdepth;
    struct {
        unsigned long *insn_addr;
        unsigned long insn;
    } si_fpqueue[16];
} __kernel_siginfo_fpu_t;

typedef void (*__kernel_sighandler_t)(int);
typedef void (*__kernel_sigrestorer_t)(void);
typedef void (*__kernel_sigaction_t)(int, __kernel_siginfo_t *, void *);

#define __KERNEL_RT_NSIG 64
#define __KERNEL_RT_SIGSET_NWORDS (__KERNEL_RT_NSIG / (sizeof(__sigset_int_t) * 8))
#define __KERNEL_RT_SIGSET_BYTES (sizeof(__sigset_int_t) * __KERNEL_RT_SIGSET_NWORDS)
typedef struct __kernel_rt_sigset {
    __sigset_int_t sig[__KERNEL_RT_SIGSET_NWORDS];
} __kernel_rt_sigset_t;

struct __kernel_rt_sigaction {
    __kernel_sighandler_t sa_handler;
    unsigned long sa_flags;
    __kernel_sigrestorer_t sa_restorer; /* unused */
    __kernel_rt_sigset_t sa_mask;
};

int __rt_sigaction(int, const struct sigaction *, struct sigaction *);
int __rt_sigprocmask(int, const sigset_t *restrict, sigset_t *restrict);
int __rt_sigsuspend(const sigset_t *);

#define __KERNEL_NSIG (sizeof(__sigset_int_t) * 8)
#define __KERNEL_SIGSET_NWORDS 1
#define __KERNEL_SIGSET_BYTES (sizeof(__sigset_int_t))
typedef __sigset_int_t __kernel_sigset_t;

struct __kernel_sigaction {
    __kernel_sighandler_t sa_handler;
    __kernel_sigset_t sa_mask;
    unsigned long sa_flags;
    __kernel_sigrestorer_t sa_restorer; /* unused */
};

int __sigaction(int, const struct sigaction *, struct sigaction *);
int __sigprocmask(int, const sigset_t *restrict, sigset_t *restrict);
int __sigsuspend(const sigset_t *);

#else // !__ASSEMBLER__

/* XXX: these are simplified definitions in case we need them from assembly */
#define SIG_ERR     -1
#define SIG_DFL     0
#define SIG_IGN     1
#define SIG_HOLD    2

#endif // !__ASSEMBLER__

#endif // _LINUX_SPARC_SIGNAL_H
