#!/bin/sh -e
#
# Copyright (C) 2010, 2012, 2016  Internet Systems Consortium, Inc. ("ISC")
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

# $Id: sign.sh,v 1.2 2010/06/21 02:31:45 marka Exp $

SYSTEMTESTTOP=../..
. $SYSTEMTESTTOP/conf.sh

RANDFILE=../random.data1
RANDFILE2=../random.data2

zone=example.
infile=example.db.in
zonefile=example.db

zskname=`$KEYGEN -q -r $RANDFILE -a RSASHA1 -b 768 -n zone $zone`
kskname=`$KEYGEN -q -r $RANDFILE -a RSASHA1 -b 1024 -f KSK -n zone $zone`

cat $infile $zskname.key $kskname.key > $zonefile

$SIGNER -P -e +1000d -r $RANDFILE -o $zone $zonefile > /dev/null

# ksk
keyname=`$KEYGEN -q -r $RANDFILE2 -a RSASHA1 -b 1024 -n zone \
	-f KSK -P +20 -A +1h -R +6h -I +1d -D +1mo $zone`

echo $keyname > keyname
