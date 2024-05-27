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

export libc = $(call pgt_paths,DATA,libs/libc)
export lib_dirs = $(libc)

define libc_header_target
$(headercache)/$(strip $1): FORCE \
    $(call expand_paths,$(libc),include/$(strip $1))
endef

sources += $(libc_sources) $(libpthread_sources)

################################################################################

include target-lib.mk

################################################################################
ifeq ($(need_goals),yes)
################################################################################

.PHONY: all
all: crt-all libs-all

.PHONY: install
install: crt-install libs-install

#-------------------------------------------------------------------------------

.PHONY: crt-all
crt-all: crt-objects

.PHONY: crt-install
crt-install: crt-all
	@mkdir -p $(libdir)
	@$(call MSG2,CP,$(notdir $(call object_paths,$(crt_sources))))
	$Qcp -f $(call object_paths,$(crt_sources)) $(libdir)/

.PHONY: crt-objects
crt-objects: $(call object_paths,$(crt_sources))

#-------------------------------------------------------------------------------

.PHONY: libs-all
libs-all: \
    libc-objects \
    $(cachedir)/libc.a \
    libpthread-objects \
    $(cachedir)/libpthread.a

#    libc-objects \
#    libpthread-objects \

.PHONY: libs-install
libs-install: \
    $(libdir)/libc.a \
    $(libdir)/libpthread.a

#@mkdir -p $(libdir)

.PHONY: libc-objects
libc-objects: $(call object_paths,$(libc_sources))
$(cachedir)/libc.a: $(call link_paths,$(libc_sources))

.PHONY: libpthread-objects
libpthread-objects: $(call object_paths,$(libpthread_sources))
$(cachedir)/libpthread.a: $(call link_paths,$(libpthread_sources))

#@mkdir -p $(@D)
#@$(call MSG2,AR,libc.a (updating $(words $?) objects))
#$Q$(AR) cru $@ $?

#$(libdir)/libc.a: $(cachedir)/libc.a
#@mkdir -p $(@D)
#@$(call MSG2,CP,libc.a)
#$Qcp -f $(cachedir)/libc.a $(libdir)/
#@$(call MSG2,CP,libpthread.a)
#$Qcp -f $(cachedir)/libpthread.a $(libdir)/
#
#$(libdir)/libpthread.a: $(cachedir)/libpthread.a
#@mkdir -p $(@D)
#@$(call MSG2,CP,libc.a)
#$Qcp -f $(cachedir)/libc.a $(libdir)/
#@$(call MSG2,CP,libpthread.a)
#$Qcp -f $(cachedir)/libpthread.a $(libdir)/

################################################################################
endif
