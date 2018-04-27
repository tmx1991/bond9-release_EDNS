/*
 * Copyright (C) 2017  Internet Systems Consortium, Inc. ("ISC")
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef NS_XFROUT_H
#define NS_XFROUT_H 1

/*****
 ***** Module Info
 *****/

/*! \file
 * \brief
 * Outgoing zone transfers (AXFR + IXFR).
 */

/***
 *** Functions
 ***/

void
ns_xfr_start(ns_client_t *client, dns_rdatatype_t xfrtype);

#endif /* NS_XFROUT_H */
