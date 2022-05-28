///@file

/*******************************************************************
 * PRIVATE DEFINES
 *******************************************************************/

/* Module functioning defines start */

#define HDLC_CS_POSITION(SIZE) \
	((SIZE) - (HDLC_FRAME_FCS_POS))

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

#include "xdlms-hdlc-frame-validate.h"
#include "xdlms-hdlc.h"

/* System functioning includes end */

/* Module functioning includes start */

#include "utils.h"
#include "array.h"

#include "crc16-ccitt.h"

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

/*!
 * @brief Validates a xDLMS HDLC CRC
 * @param p_from Address of buffer holding data to validate
 * @param size Number of bytes of data to validate
 * @return Status of the operation
 */
STATIC status_t
hdlc_crc_validate(
	const uint8_t p_from[static 1],
	const size_t size
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
hdlc_crc_validate(
	const uint8_t p_from[static 1],
	const size_t size) {

	ASSERT(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);

	RETURN_IF_FALSE(!(size < (sizeof(uint16_t))),
		STATUS_HDLC_INVALID_FRAME);

	uint32_t crc[2] = { 0, 0 }; /* 0: received, 1: computed */
	array_t from =
		ARRAY_USED(&p_from[size - sizeof(uint16_t)], sizeof(uint16_t));

	(void) array_pull_hton(&from, (uint8_t *)&crc[0], sizeof(uint16_t));

	crc[1] = crc16_ccitt_complete((uint8_t *)p_from, size - sizeof(uint16_t));
	crc[1] = __builtin_bswap16(crc[1]);

	RETURN_IF_FALSE((uint16_t)crc[0] == (uint16_t)crc[1],
		STATUS_HDLC_INVALID_CHECKSUM);

	return STATUS_SUCCESS;
}

status_t
hdlc_frame_hcs_valid(
	const uint8_t p_from[static 1],
	const size_t size) {

	RETURN_IF_FALSE(!(size < HDLC_FRAME_HEADER_MIN_SIZE),
		STATUS_HDLC_INVALID_FRAME);
	RETURN_IF_FALSE(!(size > HDLC_FRAME_HEADER_MAX_SIZE),
		STATUS_HDLC_INVALID_FRAME);

	status_t status = hdlc_crc_validate(p_from, size);
	RETURN_IF_FALSE(status == STATUS_HDLC_INVALID_CHECKSUM, status);

	return STATUS_HDLC_INVALID_HEADER_CHECKSUM;
}

status_t
hdlc_frame_fcs_valid(
  const uint8_t p_from[static const 1],
  const size_t size) {

	status_t status = hdlc_crc_validate(p_from, size);
	RETURN_IF_FALSE(status == STATUS_HDLC_INVALID_CHECKSUM, status);

	return STATUS_HDLC_INVALID_FRAME_CHECKSUM;
}

status_t
hdlc_frame_validate(
	const uint8_t p_from[static 1],
	const size_t size) {

	ASSERT(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);

	RETURN_IF_FALSE(!(size < HDLC_FRAME_OVERHEAD),
	  STATUS_HDLC_INVALID_FRAME);
	RETURN_IF_FALSE(p_from[0] == HDLC_FRAME_LIMIT,
		STATUS_HDLC_INVALID_FRAME_DELIMITER);
	RETURN_IF_FALSE(p_from[size - 1] == HDLC_FRAME_LIMIT,
		STATUS_HDLC_INVALID_FRAME_DELIMITER);

	return hdlc_frame_fcs_valid(&p_from[1], size - HDLC_FRAME_OVERHEAD);
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
