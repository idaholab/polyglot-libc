# This file is part of the Polyglot C Library.
#
# Copyright (C) 2024, Battelle Energy Alliance, LLC ALL RIGHTS RESERVED
#
# The Polyglot C Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the License,
# or (at your option) any later version.
#
# The Polyglot C library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
# for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, see <https://www.gnu.org/licenses/>.

.PHONY: common-headers
common-headers: $(call expand_paths,$(libc),include)
	$(call do_rsync, <headercache>/*, $(^:%=%/), $(headercache)/, \
        -Lcrd --include='*.h' --include='*.hpp' --exclude='bits/' \
        --include='*/' --exclude='*')

$(call libc_header_target, bits/$(target_arch))
$(call libc_header_target, bits/$(target_os))

header_targets += \
    common-headers \
    $(headercache)/bits/$(target_arch) \
    $(headercache)/bits/$(target_os) \
    $(headercache)/bits/$(target_os)/$(target_arch) \
# end of list

source_paths += \
    $(call expand_paths,$(libc),src) \
    $(call pgt_paths,SUPPORT,external) \
# end of list

# pdclib
libc_sources += \
    _PDCLIB/_PDCLIB_Exit.c \
    _PDCLIB/_PDCLIB_atomax.c \
    _PDCLIB/_PDCLIB_close.c \
    _PDCLIB/_PDCLIB_closeall.c \
    _PDCLIB/_PDCLIB_digits.c \
    _PDCLIB/_PDCLIB_filemode.c \
    _PDCLIB/_PDCLIB_fillbuffer.c \
    _PDCLIB/_PDCLIB_flushbuffer.c \
    _PDCLIB/_PDCLIB_getstream.c \
    _PDCLIB/_PDCLIB_init_file_t.c \
    _PDCLIB/_PDCLIB_is_leap.c \
    _PDCLIB/_PDCLIB_isstream.c \
    _PDCLIB/_PDCLIB_lc_message.c \
    _PDCLIB/_PDCLIB_load_lc_collate.c \
    _PDCLIB/_PDCLIB_load_lc_ctype.c \
    _PDCLIB/_PDCLIB_load_lc_messages.c \
    _PDCLIB/_PDCLIB_load_lc_monetary.c \
    _PDCLIB/_PDCLIB_load_lc_numeric.c \
    _PDCLIB/_PDCLIB_load_lc_time.c \
    _PDCLIB/_PDCLIB_load_lines.c \
    _PDCLIB/_PDCLIB_open.c \
    _PDCLIB/_PDCLIB_prepread.c \
    _PDCLIB/_PDCLIB_prepwrite.c \
    _PDCLIB/_PDCLIB_print.c \
    _PDCLIB/_PDCLIB_realpath.c \
    _PDCLIB/_PDCLIB_remove.c \
    _PDCLIB/_PDCLIB_rename.c \
    _PDCLIB/_PDCLIB_scan.c \
    _PDCLIB/_PDCLIB_seed.c \
    _PDCLIB/_PDCLIB_seek.c \
    _PDCLIB/_PDCLIB_stdinit.c \
    _PDCLIB/_PDCLIB_strtok.c \
    _PDCLIB/_PDCLIB_strtox_main.c \
    _PDCLIB/_PDCLIB_strtox_prelim.c \
    _PDCLIB/assert.c \
    _PDCLIB/errno.c \
    _PDCLIB/stdarg.c \
    _tzcode/_PDCLIB_gmtcheck.c \
    _tzcode/_PDCLIB_gmtsub.c \
    _tzcode/_PDCLIB_increment_overflow.c \
    _tzcode/_PDCLIB_init_ttinfo.c \
    _tzcode/_PDCLIB_localsub.c \
    _tzcode/_PDCLIB_localtime_tzset.c \
    _tzcode/_PDCLIB_mktime_tzname.c \
    _tzcode/_PDCLIB_timesub.c \
    _tzcode/_PDCLIB_tzload.c \
    _tzcode/_PDCLIB_tzparse.c \
    _tzcode/_PDCLIB_tzset_unlocked.c \
    _tzcode/_PDCLIB_update_tzname_etc.c \
    arpa/inet/htonl.c \
    arpa/inet/htons.c \
    arpa/inet/inet_aton.c \
    arpa/inet/inet_ntoa.c \
    arpa/inet/inet_ntop.c \
    arpa/inet/inet_pton.c \
    ctype/isalnum.c \
    ctype/isalpha.c \
    ctype/isblank.c \
    ctype/iscntrl.c \
    ctype/isdigit.c \
    ctype/isgraph.c \
    ctype/islower.c \
    ctype/isprint.c \
    ctype/ispunct.c \
    ctype/isspace.c \
    ctype/isupper.c \
    ctype/isxdigit.c \
    ctype/tolower.c \
    ctype/toupper.c \
    dirent/closedir.c \
    dirent/dirfd.c \
    dirent/opendir.c \
    dirent/readdir.c \
    dirent/rewinddir.c \
    dirent/seekdir.c \
    dirent/telldir.c \
    err/__err_print.c \
    err/err.c \
    err/errx.c \
    err/verr.c \
    err/verrx.c \
    err/vwarn.c \
    err/vwarnx.c \
    err/warn.c \
    err/warnx.c \
    fcntl/fcntl.c \
    fcntl/open.c \
    fcntl/openat.c \
    grp/__grp.c \
    grp/endgrent.c \
    grp/getgrent.c \
    grp/getgrgid.c \
    grp/getgrnam.c \
    grp/setgrent.c \
    inttypes/imaxabs.c \
    inttypes/imaxdiv.c \
    inttypes/strtoimax.c \
    inttypes/strtoumax.c \
    libintl/gettext.c \
    locale/localeconv.c \
    locale/setlocale.c \
    netdb/__netdb_common.c \
    netdb/__netdb_dns.c \
    netdb/__netdb_host.c \
    netdb/__netdb_net.c \
    netdb/__netdb_proto.c \
    netdb/__netdb_serv.c \
    netdb/endhostent.c \
    netdb/endnetent.c \
    netdb/endprotoent.c \
    netdb/endservent.c \
    netdb/freeaddrinfo.c \
    netdb/gai_strerror.c \
    netdb/getaddrinfo.c \
    netdb/gethostbyaddr.c \
    netdb/gethostbyname.c \
    netdb/gethostbyname2.c \
    netdb/gethostent.c \
    netdb/getnetbyaddr.c \
    netdb/getnetbyname.c \
    netdb/getnetent.c \
    netdb/getprotobyname.c \
    netdb/getprotobynumber.c \
    netdb/getprotoent.c \
    netdb/getservbyname.c \
    netdb/getservbyport.c \
    netdb/getservent.c \
    netdb/sethostent.c \
    netdb/setnetent.c \
    netdb/setprotoent.c \
    netdb/setservent.c \
    netinet/in/in6addr.c \
    polyglot/__check_version.c \
    polyglot/__choice_append.c \
    polyglot/__db_common.c \
    polyglot/__file_at.c \
    polyglot/__libc_init.c \
    polyglot/__libc_main.c \
    polyglot/__platform_init.c \
    polyglot/__syscall_debug_init.c \
    polyglot/builtins.c \
    pwd/__pwd.c \
    pwd/endpwent.c \
    pwd/getpwent.c \
    pwd/getpwnam.c \
    pwd/getpwuid.c \
    pwd/setpwent.c \
    setjmp/__longjmp.S \
    setjmp/__setjmp_sig_save.c \
    setjmp/longjmp.c \
    setjmp/setjmp.S \
    shadow/__shadow.c \
    shadow/endspent.c \
    shadow/getspent.c \
    shadow/getspnam.c \
    shadow/setspent.c \
    signal/raise.c \
    signal/signal.c \
    signal/sigset.c \
    stdio/clearerr.c \
    stdio/fclose.c \
    stdio/fdopen.c \
    stdio/feof.c \
    stdio/ferror.c \
    stdio/fflush.c \
    stdio/fgetc.c \
    stdio/fgetpos.c \
    stdio/fgets.c \
    stdio/fileno.c \
    stdio/fopen.c \
    stdio/fprintf.c \
    stdio/fputc.c \
    stdio/fputs.c \
    stdio/fread.c \
    stdio/freopen.c \
    stdio/fscanf.c \
    stdio/fseek.c \
    stdio/fsetpos.c \
    stdio/ftell.c \
    stdio/fwrite.c \
    stdio/getc.c \
    stdio/getchar.c \
    stdio/perror.c \
    stdio/printf.c \
    stdio/putc.c \
    stdio/putchar.c \
    stdio/puts.c \
    stdio/rename.c \
    stdio/rewind.c \
    stdio/scanf.c \
    stdio/setbuf.c \
    stdio/setvbuf.c \
    stdio/snprintf.c \
    stdio/sprintf.c \
    stdio/sscanf.c \
    stdio/tmpnam.c \
    stdio/ungetc.c \
    stdio/vfprintf.c \
    stdio/vfscanf.c \
    stdio/vprintf.c \
    stdio/vscanf.c \
    stdio/vsnprintf.c \
    stdio/vsprintf.c \
    stdio/vsscanf.c \
    stdlib/_Exit.c \
    stdlib/__env_verify.c \
    stdlib/abort.c \
    stdlib/abort_handler_s.c \
    stdlib/abs.c \
    stdlib/at_quick_exit.c \
    stdlib/atexit.c \
    stdlib/atof.c \
    stdlib/atoi.c \
    stdlib/atol.c \
    stdlib/atoll.c \
    stdlib/bsearch.c \
    stdlib/bsearch_s.c \
    stdlib/clearenv.c \
    stdlib/div.c \
    stdlib/dlmalloc.c \
    stdlib/exit.c \
    stdlib/getenv.c \
    stdlib/ignore_handler_s.c \
    stdlib/labs.c \
    stdlib/ldiv.c \
    stdlib/llabs.c \
    stdlib/lldiv.c \
    stdlib/putenv.c \
    stdlib/qsort.c \
    stdlib/qsort_s.c \
    stdlib/quick_exit.c \
    stdlib/rand.c \
    stdlib/realpath.c \
    stdlib/set_constraint_handler_s.c \
    stdlib/setenv.c \
    stdlib/srand.c \
    stdlib/strtol.c \
    stdlib/strtoll.c \
    stdlib/strtoul.c \
    stdlib/strtoull.c \
    stdlib/system.c \
    stdlib/unsetenv.c \
    string/memchr.c \
    string/memcmp.c \
    string/memcpy.c \
    string/memcpy_s.c \
    string/memmove.c \
    string/memmove_s.c \
    string/memset.c \
    string/memset_s.c \
    string/memset_s.c \
    string/stpcpy.c \
    string/stpncpy.c \
    string/strcat.c \
    string/strcat_s.c \
    string/strchr.c \
    string/strchrnul.c \
    string/strcmp.c \
    string/strcoll.c \
    string/strcpy.c \
    string/strcpy_s.c \
    string/strcspn.c \
    string/strdup.c \
    string/strerror.c \
    string/strerror_s.c \
    string/strerrorlen_s.c \
    string/strlen.c \
    string/strncat.c \
    string/strncat_s.c \
    string/strncmp.c \
    string/strncpy.c \
    string/strncpy_s.c \
    string/strnlen.c \
    string/strpbrk.c \
    string/strrchr.c \
    string/strsep.c \
    string/strspn.c \
    string/strstr.c \
    string/strtok.c \
    string/strtok_s.c \
    string/strxfrm.c \
    strings/bzero.c \
    strings/strcasecmp.c \
    strings/strncasecmp.c \
    sys/auxv/getauxval.c \
    termios/cfmakeraw.c \
    termios/isatty.c \
    time/asctime.c \
    time/ctime.c \
    time/difftime.c \
    time/gmtime_s.c \
    time/localtime_s.c \
    time/strftime.c \
    time/asctime_s.c \
    time/ctime_s.c \
    time/gmtime.c \
    time/localtime.c \
    time/mktime.c \
    unistd/__getcwd_generic.c \
    unistd/gethostname.c \
    unistd/sbrk.c \
    unistd/sleep.c \
    unistd/usleep.c \
# end of list

# currently disabled and/or unimplemented:
#   fcntl/__openat_generic.c \
#   fcntl/__openat_generic_v.c \
#   stdio/remove.c \
#   time/asctime.c \
#   time/asctime_r.c \
#   time/asctime_s.c \
#   time/ctime.c \
#   time/ctime_r.c \
#   time/ctime_s.c \
#   time/difftime.c \
#   time/gmtime.c \
#   time/gmtime_r.c \
#   time/gmtime_s.c \
#   time/localtime.c \
#   time/localtime_s.c \
#   time/mktime.c \
#   time/strftime.c \
#   time/tzlock.c \
#   time/tzset_r.c \

# previously existed, but currently unimplemented:
#   time/asctime.c \
#   time/clock.c \
#   time/ctime.c \
#   time/difftime.c \
#   time/gettzinfo.c \
#   time/gmtime.c \
#   time/localtime.c \
#   time/mktime.c \
#   time/month_lengths.c \
#   time/strftime.c \
#   time/strptime.c \
#   time/tzcalc_limits.c \
#   time/tzset.c \
#   time/tzvars.c \
#   time/wcsftime.c \

libpthread_sources += \
    pthread/pthread_attr_init.c \
    pthread/pthread_create.c \
    pthread/pthread_key_create.c \
    pthread/pthread_mutex_init.c \
    pthread/pthread_mutex_unlock.c \
    pthread/pthread_cleanup_pop.c \
    pthread/pthread_getspecific.c \
    pthread/pthread_key_delete.c \
    pthread/pthread_mutex_lock.c \
    pthread/pthread_self.c \
    pthread/pthread_cleanup_push.c \
    pthread/pthread_join.c \
    pthread/pthread_mutex_destroy.c \
    pthread/pthread_mutex_trylock.c \
    pthread/pthread_setspecific.c \
# end of list

