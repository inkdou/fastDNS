#   BSD LICENSE
#
#   Copyright(c) 2010-2014 Intel Corporation. All rights reserved.
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions
#   are met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in
#       the documentation and/or other materials provided with the
#       distribution.
#     * Neither the name of Intel Corporation nor the names of its
#       contributors may be used to endorse or promote products derived
#       from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

ifeq ($(RTE_SDK),)
$(error "Please define RTE_SDK environment variable")
endif

# Default target, can be overridden by command line or environment
RTE_TARGET ?= x86_64-native-linuxapp-gcc

include $(RTE_SDK)/mk/rte.vars.mk

# binary name
APP = fastDNS

FASTDNS_SRCS += \
	netdev.c \
	ipv4.c	

NSD_SRCS += \
	$(SRCDIR)/nsd/answer.c \
	$(SRCDIR)/nsd/buffer.c \
	$(SRCDIR)/nsd/query.c \
	$(SRCDIR)/nsd/configlexer.c \
	$(SRCDIR)/nsd/configparser.c \
	$(SRCDIR)/nsd/dbaccess.c \
	$(SRCDIR)/nsd/dbcreate.c \
	$(SRCDIR)/nsd/dname.c \
	$(SRCDIR)/nsd/edns.c \
	$(SRCDIR)/nsd/dns.c \
	$(SRCDIR)/nsd/tsig.c \
	$(SRCDIR)/nsd/difffile.c \
	$(SRCDIR)/nsd/tsig-openssl.c \
	$(SRCDIR)/nsd/namedb.c \
	$(SRCDIR)/nsd/nsec3.c \
	$(SRCDIR)/nsd/options.c \
	$(SRCDIR)/nsd/packet.c \
	$(SRCDIR)/nsd/radtree.c \
	$(SRCDIR)/nsd/rbtree.c \
	$(SRCDIR)/nsd/rdata.c \
	$(SRCDIR)/nsd/region-allocator.c \
	$(SRCDIR)/nsd/util.c \
	$(SRCDIR)/nsd/zlexer.c \
	$(SRCDIR)/nsd/zonec.c \
	$(SRCDIR)/nsd/udbradtree.c \
	$(SRCDIR)/nsd/udbzone.c \
	$(SRCDIR)/nsd/udb.c \
	$(SRCDIR)/nsd/zparser.c \
	$(SRCDIR)/nsd/iterated_hash.c \
	$(SRCDIR)/nsd/lookup3.c \
	$(SRCDIR)/nsd/fdns.c 

COMPAT_SRCS += \
	$(SRCDIR)/compat/b64_ntop.c  \
	$(SRCDIR)/compat/b64_pton.c   \
	$(SRCDIR)/compat/basename.c  \
	$(SRCDIR)/compat/inet_aton.c  \
	$(SRCDIR)/compat/inet_ntop.c  \
	$(SRCDIR)/compat/inet_pton.c  \
	$(SRCDIR)/compat/strlcat.c  \
	$(SRCDIR)/compat/strlcpy.c  \
	$(SRCDIR)/compat/strptime.c  


# all source are stored in SRCS-y
SRCS-y := main.c ${FASTDNS_SRCS} ${NSD_SRCS} ${COMPAT_SRCS}

CFLAGS += -O3 -Wno-error -Wno-error=cast-qual -Wno-error=sign-compare -Wno-error=pointer-arith -Wno-error=discarded-qualifiers -Wno-error=old-style-definition -Wno-error=missing-prototypes -Wno-error=unused-function
CFLAGS += $(WERROR_FLAGS) -I $(SRCDIR)/include -I $(SRCDIR)/compat 
LDFLAGS += -lssl -lcrypto

include $(RTE_SDK)/mk/rte.extapp.mk
