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

/*!
 * @brief Parses MAC HDLC Frame Format field for xDLMS
 * @param p_from Address of structure holding array of data
 * @param p_to Address of variable to hold parsed Frame Format field
 * @return Status of the operation
 */
STATIC status_t
xdlms_hdlc_parse_mac_format(
	array_t p_from[static 1],
	uint32_t p_to[static 1]
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

STATIC status_t
xdlms_hdlc_parse_mac_format(
	array_t p_from[static 1],
	uint32_t p_to[static 1]) {
	ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	p_to[0] = 0;

	status_t status = STATUS_SUCCESS;
	status = array_pull_hton(p_from,
	                         (uint8_t *)p_to,
	                         sizeof(uint16_t));
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	const uint32_t type = p_to[0] >> HDLC_FRAME_FORMAT_TYPE_POS;
	if (type != HDLC_FRAME_FORMAT_TYPE) {
		return STATUS_HDLC_INVALID_FRAME_FORMAT;
	}

	return STATUS_SUCCESS;
}

STATIC status_t
xdlms_hdlc_parse_and_validate_frame_length(
	array_t p_from[static 1],
	size_t p_length[static 1],
	bool p_segment[static 1]) {

	p_length[0] = (size_t)~0;
	p_segment[0] = false;

	status_t status = STATUS_SUCCESS;
	status = hdlc_frame_is_complete(p_from->p_array,
																	array_used(p_from),
																	~0);
	RETURN_IF_FALSE(status != STATUS_SUCCESS, status);

	status = array_drop(p_from, sizeof(uint8_t)); /* drop 0x7e */
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	uint32_t format = 0;

	status = xdlms_hdlc_parse_mac_format(p_from, &format);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	p_length[0] = (size_t)(format & HDLC_FRAME_LEN_MASK);
	RETURN_IF_FALSE(array_used(p_from) == p_length[0],
		STATUS_HDLC_INVALID_FRAME_LENGTH);


	p_segment[0] = format & HDLC_FRAME_SEGMENTATION_MASK;
	return STATUS_SUCCESS;
}

status_t
xdlms_hdlc_parse_mac(
	array_t p_from[static const 1],
	hdlc_mac_info_t p_to[static 1]) {

	status_t status =
		xdlms_hdlc_parse_and_validate_frame_length(p_from,
		                                           &p_to->frame_len,
		                                           &p_to->is_segmented);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	return xdlms_hdlc_parse_mac_addresses(p_from, &p_to->address);
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
