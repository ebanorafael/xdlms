/// @file

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /*  __cplusplus */

/*******************************************************************
 * EXTERNED DEFINES
 *******************************************************************/

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */
	
/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* System functioning includes start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "status.h"
#include "array.h"
#include "xdlms-hdlc.h"

/* System functioning includes end */

/* Module functioning includes start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

/*******************************************************************
 * EXTERNED TYPES
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * EXTERNED DATA
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * EXTERNED FUNCTIONS
 *******************************************************************/

/*!
 * @brief Parses MAC information from xDLMS HDLC frame
 * @param p_from Address of structure holding data to parse
 * @param p_to Address of structure to hold parsed data
 * @return Status of the operation
 */
status_t
xdlms_hdlc_parse_mac(
	array_t p_from[static const 1],
	hdlc_mac_info_t p_to[static 1]
);

#ifdef UNIT_TESTS

STATIC status_t
xdlms_hdlc_parse_mac_addresses(
	array_t p_from[static 1],
	hdlc_mac_address_t p_to[static 1]
);

STATIC status_t
xdlms_hdlc_parse_mac_format(
	array_t p_from[static 1],
	uint32_t p_to[static 1]
);

STATIC status_t
xdlms_hdlc_parse_and_validate_frame_length(
	array_t p_from[static 1],
	size_t p_length[static 1],
	bool p_segment[static 1]
);

STATIC status_t
xdlms_hdlc_parse_mac_addresses(
	array_t p_from[static 1],
	hdlc_mac_address_t p_to[static 1]
);

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
