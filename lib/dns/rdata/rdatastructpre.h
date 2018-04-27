/*
 * Copyright (C) 1999-2001, 2004, 2007, 2016  Internet Systems Consortium, Inc. ("ISC")
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/* $Id: rdatastructpre.h,v 1.16 2007/06/19 23:47:17 tbox Exp $ */

#ifndef DNS_RDATASTRUCT_H
#define DNS_RDATASTRUCT_H 1

#include <isc/lang.h>
#include <isc/sockaddr.h>

#include <dns/name.h>
#include <dns/types.h>

ISC_LANG_BEGINDECLS

typedef struct dns_rdatacommon {
	dns_rdataclass_t			rdclass;
	dns_rdatatype_t				rdtype;
	ISC_LINK(struct dns_rdatacommon)	link;
} dns_rdatacommon_t;

#define DNS_RDATACOMMON_INIT(_data, _rdtype, _rdclass) \
	do { \
		(_data)->common.rdtype = (_rdtype); \
		(_data)->common.rdclass = (_rdclass); \
		ISC_LINK_INIT(&(_data)->common, link); \
	} while (0)