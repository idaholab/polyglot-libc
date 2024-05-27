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

#ifndef _SIGNAL_H
#define _SIGNAL_H _SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/* XXX: this has to be forward-declared so that the target signal header can use
 * pointers to it in its function declarations... */
typedef struct __sigset sigset_t;
struct sigaction;

/* INCLUDES *******************************************************************/

#include <sys/types.h>
#include <time.h>
#include <target/signal.h>
#ifdef __target_os_solaris
#include <ucontext.h> // FIXME: not sure if including this is POSIX-allowable
#endif

/* MACRO DEFINITIONS **********************************************************/

// FIXME: we need to figure these out
#define SIGRTMIN __builtin_error("SIGRTMIN")
#define SIGRTMAX __builtin_error("SIGRTMAX")
#define RTSIG_MAX __builtin_error("RTSIG_MAX")

// Define the target number of signals we should generically support.
#define __SIGSET_NSIG 512

/* We define our number of sigset words based on the target number of signal
 * bits to handle and the size of the sigset member int; we have to define this
 * variably because Linux uses unsigned longs, but FreeBSD uses unsigned ints.
 * We can't just reinterpret the memory due to endianness, and we'd rather have
 * it all use one type for any single platform. In general, people shouldn't be
 * using direct access into the sigset members anyway... */
#define __SIGSET_NWORDS (__SIGSET_NSIG / (8 * sizeof(__sigset_int_t)))


/* TYPE DEFINITIONS ***********************************************************/

/* FIXME: This structure isn't defined here because the threading functionality
 * isn't implemented at this point in time.
 *
 * struct sigevent
 * {
 *     int sigev_notify;
 *     int sigev_signo;
 *     union sigval sigev_value;
 *     void (*sigev_notify_function)(union sigval)
 *     pthread_attr_t *sigev_notify_attributes;
 * };
 */

typedef int sig_atomic_t;

union sigval
{
    int sival_int;
    void *sival_ptr;
};

typedef struct __siginfo siginfo_t;
struct __siginfo
{
    int si_signo;
    int si_code;
    int si_errno;
    pid_t si_pid;
    uid_t si_uid;
    void *si_addr;
    int si_status;
    long si_band;
    union sigval si_value;
};

struct __sigset
{
    __sigset_int_t sig[__SIGSET_NWORDS];
};

struct sigaction
{
    union {
        void (*sa_handler)(int);
        void (*sa_sigaction)(int, siginfo_t *, void *);
    };
    sigset_t sa_mask;
    int sa_flags;
};

typedef struct __stack stack_t;
struct __stack
{
    void *ss_sp;
    size_t ss_size;
    int ss_flags;
};

/* FIXME: this structure is platform-dependent, so we need to do something more
 * clever with how this is laid out; for now we just make it very stupid. */
typedef struct __mcontext mcontext_t;
struct __mcontext
{
    int __unused;
};

/*
FIXME: ucontext has to be a void* for now
typedef struct __ucontext ucontext_t;
struct __ucontext
{
    ucontext_t *uc_link;
    sigset_t uc_sigmask;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
};
*/

/* FUNCTION PROTOTYPES ********************************************************/

int kill(pid_t, int);
int raise(int);
int sigaction(int, const struct sigaction *restrict,
                struct sigaction *restrict);
int sigaddset(sigset_t *, int);
int sigdelset(sigset_t *, int);
int sigemptyset(sigset_t *);
int sigfillset(sigset_t *);
int sigismember(const sigset_t *, int);
void (*signal(int, void (*)(int)))(int);
int sigprocmask(int, const sigset_t *restrict, sigset_t *restrict);
int sigsuspend(const sigset_t *);

/*
 * FIXME: the following functions are unimplemented:
 *
 *   - int killpg(pid_t, int);
 *   - void psiginfo(const siginfo_t *, const char *);
 *   - void psignal(int, const char *);
 *   - int pthread_kill(pthread_t, int);
 *   - int pthread_sigmask(int, const sigset_t *restrict, sigset_t *restrict);
 *   - int sigaltstack(const stack_t *restrict, stack_t *restrict);
 *   - int sighold(int);
 *   - int sigignore(int);
 *   - int siginterrupt(int, int);
 *   - int sigpause(int);
 *   - int sigpending(sigset_t *);
 *   - int sigqueue(pid_t, int, union sigval);
 *   - int sigrelse(int);
 *   - void (*sigset(int, void (*)(int)))(int);
 *   - int sigtimedwait(const sigset_t *restrict, siginfo_t *restrict,
 *                 const struct timespec *restrict);
 *   - int sigwait(const sigset_t *restrict, int *restrict);
 *   - int sigwaitinfo(const sigset_t *restrict, siginfo_t *restrict);
 */

#define __sigmask(n) (1ul << (((n) - 1) % (8 * sizeof(__sigset_int_t))))
#define __sigword(n) (((n) - 1) / (8 * sizeof(__sigset_int_t)))

void __sigemptyset(__sigset_int_t *set, ssize_t len);
void __sigfillset(__sigset_int_t *set, ssize_t len);
int  __sigisemptyset(const __sigset_int_t *set, ssize_t len);
void __sigcopyset(__sigset_int_t *dest, ssize_t dest_len, __sigset_int_t *src, ssize_t src_len);
void __sigandset(__sigset_int_t *dest, __sigset_int_t *left, __sigset_int_t *right, ssize_t len);
void __sigorset(__sigset_int_t *dest, __sigset_int_t *left, __sigset_int_t *right, ssize_t len);
int  __sigismember(const __sigset_int_t *set, ssize_t len, int sig);
void __sigaddset(__sigset_int_t *set, ssize_t len, int sig);
void __sigdelset(__sigset_int_t *set, ssize_t len, int sig);

/******************************************************************************/

#ifdef __cplusplus
} // extern C
#endif

#endif // _SIGNAL_H
