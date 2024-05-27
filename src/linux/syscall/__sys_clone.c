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

#error "Architecture needs specific implementation of __sys_clone()!"

/* XXX: the interface between different architectures is weirdly different,
 * so... we take a stack_size argument and don't use it most of the time. See
 * the clone(2) Linux man page for the descriptions of the differences.
 *
 * Per the manpage:
 *  - use SIGCHLD to get fork() behavior
 *  - stack can be NULL, just don't use CLONE_VM
 *  - in practice, parent_tid/child_tid can be NULL
 *  - in practice, tls can be 0... what else would it be?
 */

/*
pid_t __sys_clone(unsigned long flags, void *stack, int stack_size,
        int *parent_tid, int *child_tid, unsigned long tls)
{
#if (defined(__target_arch_x86_64) \
        || defined(__target_arch_sh) \
        || defined(__target_arch_tilegx) \
        || defined(__target_arch_alpha))
    return syscall(
        __NR_clone,
        flags,
        stack,
        parent_tid, child_tid, tls
    );

#elif (defined(__target_arch_i386) \
        || defined(__target_arch_score) \
        || defined(__target_arch_arm) \
        || defined(__target_arch_arm64) \
        || defined(__target_arch_parisc) \
        || defined(__target_arch_arc) \
        || defined(__target_arch_powerpc) \
        || defined(__target_arch_xtensa) \
        || defined(__target_arch_mips))
    return syscall(
        __NR_clone,
        flags,
        stack,
        parent_tid, tls, child_tid
    );

#elif (defined(__target_arch_cris) \
        || defined(__target_arch_s390))
    return syscall(
        __NR_clone,
        stack,
        flags,
        parent_tid, child_tid, tls
    );

#elif (defined(__target_arch_microblaze))
    return syscall(
        __NR_clone,
        flags,
        stack, stack_size,
        parent_tid, child_tid, tls
    );

#elif (defined(__target_arch_blackfin))
#error "Linux clone(2) not yet implemented for blackfin!"

#elif (defined(__target_arch_m68k))
#error "Linux clone(2) not yet implemented for m68k!"

#elif (defined(__target_arch_sparc))
    // sparc is special and needs assembly...
    return __syscall_clone(
        flags,
        stack,
        parent_tid, child_tid, tls
    );

#elif (defined(__target_arch_ia64))
#error "Linux clone(2) not yet implemented for ia64!"

#else
#error "Unknown architecture for Linux clone(2)!"
#endif
}
*/

