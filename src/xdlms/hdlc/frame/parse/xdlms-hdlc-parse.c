///@file

/*******************************************************************
 * PRIVATE DEFINES
 *******************************************************************/

/* Module functioning defines start */

#ifdef UNIT_TESTS

#else

/*! @brief Hides internal function definitions when not in unit test environment */
#define STATIC    static

#endif /* UNIT_TESTS */

/* Module functioning defines end */

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* System functioning includes start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "xdlms-hdlc-parse.h"
#include "xdlms-hdlc-frame-validate.h"

/* System functioning includes end */

/* Module functioning includes start */

#include "utils.h"

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

/*******************************************************************
 * PRIVATE TYPES
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * PRIVATE PROTOTYPES
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

STATIC status_t
xdlms_hdlc_parse_mac_addresses(
	array_t p_from[static 1],
	hdlc_mac_address_t p_to[static 1]
);

#endif /* UNIT_TESTS */

/*******************************************************************
 * PRIVATE DATA
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * FUNCTIONS
 *******************************************************************/

STATIC status_t
xdlms_hdlc_parse_mac_addresses(
	array_t p_from[static 1],
	hdlc_mac_address_t p_to[static 1]) {
	ASSERT(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);
	ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	status_t status = STATUS_SUCCESS;

	status = hdlc_pull_address(p_from, &p_to->dst);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	status = hdlc_pull_address(p_from, &p_to->src);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	return STATUS_SUCCESS;
}

status_t
xdlms_hdlc_parse_mac(
	array_t p_from[static const 1],
	hdlc_mac_info_t p_to[static 1]) {
	status_t status = STATUS_SUCCESS;

	status = hdlc_frame_is_complete(p_from->p_array,
	                                array_used(p_from),
	                                ~0);
	RETURN_IF_FALSE(status != STATUS_SUCCESS, status);

	status = array_drop(p_from, sizeof(uint8_t));
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	const uint32_t format = 0;
	status = array_pull_hton(p_from,
	                         (uint8_t *)&format,
	                         sizeof(uint16_t));
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	if ((format & HDLC_FRAME_FORMAT) != HDLC_FRAME_FORMAT) {
		return STATUS_HDLC_INVALID_FRAME_FORMAT;
	}

	const uint32_t len = format & HDLC_FRAME_LEN_MASK;
	RETURN_IF_FALSE(array_used(p_from) == len,
		STATUS_HDLC_INVALID_FRAME_LENGTH);

	p_to->is_segmented = format & HDLC_FRAME_SEGMENT;
	return xdlms_hdlc_parse_mac_addresses(p_from, &p_to->address);
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
