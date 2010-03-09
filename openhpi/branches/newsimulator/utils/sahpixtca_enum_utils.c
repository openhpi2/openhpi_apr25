/*      -*- linux-c -*-
 *
 * (C) Copyright IBM Corp. 2004
 * (C) Copyright Pigeon Point Systems. 2010
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  This
 * file and program are licensed under a BSD style license.  See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 *
 * Author(s):
 *      Steve Sherman <stevees@us.ibm.com> 
 *      Anton Pak <anton.pak@pigeonpoint.com>
 */

#include <strings.h>

#include <SaHpi.h>
#include <oh_utils.h>

/**
 * oh_lookup_xtcahpiledcolor:
 * @value: enum value of type XtcaHpiLedColorT.
 *
 * Converts @value into a string based on @value's HPI enum definition.
 * 
 * Returns:
 * string - normal operation.
 * NULL - if @value not a valid XtcaHpiLedColorT.
 **/

char * oh_lookup_xtcahpiledcolor(XtcaHpiLedColorT value)
{
        switch (value) {
        case XTCAHPI_LED_COLOR_RESERVED:
                return "COLOR_RESERVED";
        case XTCAHPI_LED_COLOR_BLUE:
                return "COLOR_BLUE";
        case XTCAHPI_LED_COLOR_RED:
                return "COLOR_RED";
        case XTCAHPI_LED_COLOR_GREEN:
                return "COLOR_GREEN";
        case XTCAHPI_LED_COLOR_AMBER:
                return "COLOR_AMBER";
        case XTCAHPI_LED_COLOR_ORANGE:
                return "COLOR_ORANGE";
        case XTCAHPI_LED_COLOR_WHITE:
                return "COLOR_WHITE";
        case XTCAHPI_LED_COLOR_NO_CHANGE:
                return "COLOR_NO_CHANGE";
        case XTCAHPI_LED_COLOR_USE_DEFAULT:
                return "COLOR_USE_DEFAULT";
        default:
                return NULL;
        }
}

struct oh_xtcahpiledcolor_map xtcahpiledcolor_strings[] = {
       {XTCAHPI_LED_COLOR_RESERVED, "COLOR_RESERVED"},
       {XTCAHPI_LED_COLOR_BLUE, "COLOR_BLUE"},
       {XTCAHPI_LED_COLOR_RED, "COLOR_RED"},
       {XTCAHPI_LED_COLOR_GREEN, "COLOR_GREEN"},
       {XTCAHPI_LED_COLOR_AMBER, "COLOR_AMBER"},
       {XTCAHPI_LED_COLOR_ORANGE, "COLOR_ORANGE"},
       {XTCAHPI_LED_COLOR_WHITE, "COLOR_WHITE"},
       {XTCAHPI_LED_COLOR_NO_CHANGE, "COLOR_NO_CHANGE"},
       {XTCAHPI_LED_COLOR_USE_DEFAULT, "COLOR_USE_DEFAULT"},
};

/**
 * oh_encode_xtcahpiledcolor:
 * @buffer: Pointer to SaHpiTextBufferT that contains enum's string representation.
 * @type: Location (of XtcaHpiLedColorT) to place encoded result.
 * 
 * Converts a @buffer->Data string, generated by oh_lookup_xtcahpiledcolor(), back 
 * into an XtcaHpiLedColorT type. 
 *
 * Returns:
 * XtcaHpiLedColorT value - normal operation.
 * SA_ERR_HPI_INVALID_PARAMS - if @buffer or @type is NULL or @buffer->Data empty.
 * SA_ERR_HPI_INVALID_DATA - if @buffer->Data is invalid.
 **/
SaErrorT oh_encode_xtcahpiledcolor(SaHpiTextBufferT *buffer, XtcaHpiLedColorT *type)
{
	int i, found;

	if (!buffer || !type || buffer->Data == NULL || buffer->Data[0] == '\0') {
		return(SA_ERR_HPI_INVALID_PARAMS);
	}
	
	found = 0;
	for (i=0; i<OH_MAX_XTCAHPILEDCOLOR; i++) {
		if (strcasecmp((char *)buffer->Data, xtcahpiledcolor_strings[i].str) == 0) {
			found++;
			break;
		}
	}

	if (found) {
		*type = xtcahpiledcolor_strings[i].entity_type;
	}
	else {
		return(SA_ERR_HPI_INVALID_DATA);
	}
	
	return(SA_OK);
}

/**
 * oh_lookup_xtcahpiresourceledmode:
 * @value: enum value of type XtcaHpiResourceLedModeT.
 *
 * Converts @value into a string based on @value's HPI enum definition.
 * 
 * Returns:
 * string - normal operation.
 * NULL - if @value not a valid XtcaHpiResourceLedModeT.
 **/

char * oh_lookup_xtcahpiresourceledmode(XtcaHpiResourceLedModeT value)
{
        switch (value) {
        case XTCAHPI_LED_AUTO:
                return "AUTO";
        case XTCAHPI_LED_MANUAL:
                return "MANUAL";
        case XTCAHPI_LED_LAMP_TEST:
                return "LAMP_TEST";
        default:
                return NULL;
        }
}

struct oh_xtcahpiresourceledmode_map xtcahpiresourceledmode_strings[] = {
       {XTCAHPI_LED_AUTO, "AUTO"},
       {XTCAHPI_LED_MANUAL, "MANUAL"},
       {XTCAHPI_LED_LAMP_TEST, "LAMP_TEST"},
};

/**
 * oh_encode_xtcahpiresourceledmode:
 * @buffer: Pointer to SaHpiTextBufferT that contains enum's string representation.
 * @type: Location (of XtcaHpiResourceLedModeT) to place encoded result.
 * 
 * Converts a @buffer->Data string, generated by oh_lookup_xtcahpiresourceledmode(), back 
 * into an XtcaHpiResourceLedModeT type. 
 *
 * Returns:
 * XtcaHpiResourceLedModeT value - normal operation.
 * SA_ERR_HPI_INVALID_PARAMS - if @buffer or @type is NULL or @buffer->Data empty.
 * SA_ERR_HPI_INVALID_DATA - if @buffer->Data is invalid.
 **/
SaErrorT oh_encode_xtcahpiresourceledmode(SaHpiTextBufferT *buffer, XtcaHpiResourceLedModeT *type)
{
	int i, found;

	if (!buffer || !type || buffer->Data == NULL || buffer->Data[0] == '\0') {
		return(SA_ERR_HPI_INVALID_PARAMS);
	}
	
	found = 0;
	for (i=0; i<OH_MAX_XTCAHPIRESOURCELEDMODE; i++) {
		if (strcasecmp((char *)buffer->Data, xtcahpiresourceledmode_strings[i].str) == 0) {
			found++;
			break;
		}
	}

	if (found) {
		*type = xtcahpiresourceledmode_strings[i].entity_type;
	}
	else {
		return(SA_ERR_HPI_INVALID_DATA);
	}
	
	return(SA_OK);
}

/**
 * oh_lookup_xtcahpiledbrsupport:
 * @value: enum value of type XtcaHpiLedBrSupportT.
 *
 * Converts @value into a string based on @value's HPI enum definition.
 * 
 * Returns:
 * string - normal operation.
 * NULL - if @value not a valid XtcaHpiLedBrSupportT.
 **/

char * oh_lookup_xtcahpiledbrsupport(XtcaHpiLedBrSupportT value)
{
        switch (value) {
        case XTCAHPI_LED_BR_SUPPORTED:
                return "BR_SUPPORTED";
        case XTCAHPI_LED_BR_NOT_SUPPORTED:
                return "BR_NOT_SUPPORTED";
        case XTCAHPI_LED_BR_UNKNOWN:
                return "BR_UNKNOWN";
        default:
                return NULL;
        }
}

struct oh_xtcahpiledbrsupport_map xtcahpiledbrsupport_strings[] = {
       {XTCAHPI_LED_BR_SUPPORTED, "BR_SUPPORTED"},
       {XTCAHPI_LED_BR_NOT_SUPPORTED, "BR_NOT_SUPPORTED"},
       {XTCAHPI_LED_BR_UNKNOWN, "BR_UNKNOWN"},
};

/**
 * oh_encode_xtcahpiledbrsupport:
 * @buffer: Pointer to SaHpiTextBufferT that contains enum's string representation.
 * @type: Location (of XtcaHpiLedBrSupportT) to place encoded result.
 * 
 * Converts a @buffer->Data string, generated by oh_lookup_xtcahpiledbrsupport(), back 
 * into an XtcaHpiLedBrSupportT type. 
 *
 * Returns:
 * XtcaHpiLedBrSupportT value - normal operation.
 * SA_ERR_HPI_INVALID_PARAMS - if @buffer or @type is NULL or @buffer->Data empty.
 * SA_ERR_HPI_INVALID_DATA - if @buffer->Data is invalid.
 **/
SaErrorT oh_encode_xtcahpiledbrsupport(SaHpiTextBufferT *buffer, XtcaHpiLedBrSupportT *type)
{
	int i, found;

	if (!buffer || !type || buffer->Data == NULL || buffer->Data[0] == '\0') {
		return(SA_ERR_HPI_INVALID_PARAMS);
	}
	
	found = 0;
	for (i=0; i<OH_MAX_XTCAHPILEDBRSUPPORT; i++) {
		if (strcasecmp((char *)buffer->Data, xtcahpiledbrsupport_strings[i].str) == 0) {
			found++;
			break;
		}
	}

	if (found) {
		*type = xtcahpiledbrsupport_strings[i].entity_type;
	}
	else {
		return(SA_ERR_HPI_INVALID_DATA);
	}
	
	return(SA_OK);
}

/**
 * oh_lookup_xtcahpientitytype:
 * @value: enum value of type SaHpiEntityTypeT.
 *
 * Converts @value into a string based on @value's HPI enum definition.
 * 
 * Returns:
 * string - normal operation.
 * NULL - if @value not a valid SaHpiEntityTypeT.
 **/

char * oh_lookup_xtcahpientitytype(SaHpiEntityTypeT value)
{
        switch (value) {
        case XTCAHPI_ENT_POWER_SLOT:
                return "POWER_SLOT";
        case XTCAHPI_ENT_SHELF_FRU_DEVICE_SLOT:
                return "SHELF_FRU_DEVICE_SLOT";
        case XTCAHPI_ENT_SHELF_MANAGER_SLOT:
                return "SHELF_MANAGER_SLOT";
        case XTCAHPI_ENT_FAN_TRAY_SLOT:
                return "FAN_TRAY_SLOT";
        case XTCAHPI_ENT_FAN_FILTER_TRAY_SLOT:
                return "FAN_FILTER_TRAY_SLOT";
        case XTCAHPI_ENT_ALARM_SLOT:
                return "ALARM_SLOT";
        case XTCAHPI_ENT_AMC_SLOT:
                return "AMC_SLOT";
        case XTCAHPI_ENT_PMC_SLOT:
                return "PMC_SLOT";
        case XTCAHPI_ENT_RTM_SLOT:
                return "RTM_SLOT";
        case XTCAHPI_ENT_CARRIER_MANAGER_SLOT:
                return "CARRIER_MANAGER_SLOT";
        case XTCAHPI_ENT_CARRIER_SLOT:
                return "CARRIER_SLOT";
        case XTCAHPI_ENT_COM_E_SLOT:
                return "COM_E_SLOT";
        default:
                return NULL;
        }
}

struct oh_xtcahpientitytype_map xtcahpientitytype_strings[] = {
       {XTCAHPI_ENT_POWER_SLOT, "POWER_SLOT"},
       {XTCAHPI_ENT_SHELF_FRU_DEVICE_SLOT, "SHELF_FRU_DEVICE_SLOT"},
       {XTCAHPI_ENT_SHELF_MANAGER_SLOT, "SHELF_MANAGER_SLOT"},
       {XTCAHPI_ENT_FAN_TRAY_SLOT, "FAN_TRAY_SLOT"},
       {XTCAHPI_ENT_FAN_FILTER_TRAY_SLOT, "FAN_FILTER_TRAY_SLOT"},
       {XTCAHPI_ENT_ALARM_SLOT, "ALARM_SLOT"},
       {XTCAHPI_ENT_AMC_SLOT, "AMC_SLOT"},
       {XTCAHPI_ENT_PMC_SLOT, "PMC_SLOT"},
       {XTCAHPI_ENT_RTM_SLOT, "RTM_SLOT"},
       {XTCAHPI_ENT_CARRIER_MANAGER_SLOT, "CARRIER_MANAGER_SLOT"},
       {XTCAHPI_ENT_CARRIER_SLOT, "CARRIER_SLOT"},
       {XTCAHPI_ENT_COM_E_SLOT, "COM_E_SLOT"},
};

/**
 * oh_encode_xtcahpientitytype:
 * @buffer: Pointer to SaHpiTextBufferT that contains enum's string representation.
 * @type: Location (of SaHpiEntityTypeT) to place encoded result.
 * 
 * Converts a @buffer->Data string, generated by oh_lookup_xtcahpientitytype(), back 
 * into an SaHpiEntityTypeT type. 
 *
 * Returns:
 * SaHpiEntityTypeT value - normal operation.
 * SA_ERR_HPI_INVALID_PARAMS - if @buffer or @type is NULL or @buffer->Data empty.
 * SA_ERR_HPI_INVALID_DATA - if @buffer->Data is invalid.
 **/
SaErrorT oh_encode_xtcahpientitytype(SaHpiTextBufferT *buffer, SaHpiEntityTypeT *type)
{
	int i, found;

	if (!buffer || !type || buffer->Data == NULL || buffer->Data[0] == '\0') {
		return(SA_ERR_HPI_INVALID_PARAMS);
	}
	
	found = 0;
	for (i=0; i<OH_MAX_XTCAHPIENTITYTYPE; i++) {
		if (strcasecmp((char *)buffer->Data, xtcahpientitytype_strings[i].str) == 0) {
			found++;
			break;
		}
	}

	if (found) {
		*type = xtcahpientitytype_strings[i].entity_type;
	}
	else {
		return(SA_ERR_HPI_INVALID_DATA);
	}
	
	return(SA_OK);
}

