/*      -*- linux-c -*-
 *
 * (C) Copyright IBM Corp. 2004, 2006
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. This
 * file and program are licensed under a BSD style license. See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 */

#ifndef __EL2EVENT_H
#define __EL2EVENT_H

#define HPIDUP_STRING  "_HPIDUP"

#define NO_OVR     0x00000000  /* No overrides */
#define OVR_SEV    0x00000001  /* Override Error Log's severity */
#define OVR_RID    0x00000010  /* Override Error Log's source */
#define OVR_EXP    0x00000100  /* Override Error Log's source for expansion cards */
#define OVR_VMM    0x00001000  /* Override Error Log's source for VMM */
#define OVR_MM1    0x00010000  /* Override Error Log's source for MM 1 */
#define OVR_MM2    0x00100000  /* Override Error Log's source for MM 2 */

typedef struct {
        gchar *event;
	SaHpiSeverityT event_sev;
	unsigned int   event_ovr;
        short          event_dup;
} ErrLog2EventInfoT;

/* Global "Error Log to Event" mapping hash table and usage count */
extern GHashTable *errlog2event_hash;
extern unsigned int errlog2event_hash_use_count;

SaErrorT errlog2event_hash_init(struct snmp_bc_hnd *custom_handle);
SaErrorT errlog2event_hash_free(void);

/* XML event code and mapping structures */
extern char *eventxml;

struct errlog2event_hash_info {
	GHashTable *hashtable;
};

#endif
