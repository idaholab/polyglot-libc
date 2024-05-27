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

#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>


static void __alarm_handler(int sig __attribute__((unused)))
{
    return;
}

unsigned int __alarm_sleep(unsigned int seconds)
{
    sigset_t set, oset;
    struct sigaction action, oldaction;
    int remain;
    time_t before, total;

    if (seconds == 0) {
        return 0;
    }

    /* Temporarily block SIGALRM to be safe */
    sigemptyset(&set);
    sigaddset(&set, SIGALRM);
    sigprocmask(SIG_BLOCK, &set, &oset);

    /* Set our handler for SIGALRM */
    sigemptyset(&action.sa_mask);
    action.sa_handler = __alarm_handler;
    action.sa_flags = 0;
    if (sigaction(SIGALRM, &action, &oldaction) == -1) {
        return seconds;
    }

    /* Mark the start and actually set the alarm */
    before = time(NULL);
    remain = alarm(seconds);

    /* The Debian 1.1 libc5 provides a more complicated way of handling this
     * that allows us to coexist with other timers, but we are going to just
     * do this simply here to sidestep the problem for now. */
    if (remain != 0) {
        alarm(remain);
        return seconds;
    }

    /* Wait for the timer to go off */
    sigsuspend(&oset);

    /* Set the old action handler back and unblock the signal */
    sigaction(SIGALRM, &oldaction, NULL);
    sigprocmask(SIG_SETMASK, &oset, NULL);

    /* Figure out how much time has elapsed */
    total = time(NULL) - before;

    /* Return the remaining number of seconds, in case we were interrupted */
    return (total >= seconds ? 0 : seconds - total);
}


unsigned int sleep(unsigned int seconds)
{
    struct timespec req = {seconds, 0}, rem = {0, 0};
    errno = 0;
    if (nanosleep(&req, &rem)) {
        switch (errno) {
        case EINTR:
            return rem.tv_sec;

        /* If there is no underlying nanosleep call available, we should pass
         * that up the chain, rather than eating it here. */
        case ENOSYS:
            return __alarm_sleep(seconds);
        }
    }
    return 0;
}


