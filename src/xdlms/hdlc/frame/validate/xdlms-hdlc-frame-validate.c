///@file

/*******************************************************************
 * PRIVATE DEFINES
 *******************************************************************/

/* Module functioning defines start */

#define HDLC_FCS_POSITION(SIZE) \
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

status_t
hdlc_frame_is_complete(
  const uint8_t p_from[static const 1],
  const size_t size,
  const uint32_t crc) {
	ASSERT(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);

	RETURN_IF_FALSE(!(size < HDLC_FRAME_COMPLETE_MIN_SIZE),
		STATUS_HDLC_INVALID_FRAME);
	RETURN_IF_FALSE(p_from[0] == HDLC_FRAME_LIMIT,
		STATUS_HDLC_INVALID_FRAME_DELIMITER);
	RETURN_IF_FALSE(p_from[size - 1] == HDLC_FRAME_LIMIT,
		STATUS_HDLC_INVALID_FRAME_DELIMITER);

	uint32_t rx_crc = 0;
  array_t from =
		ARRAY_USED(&p_from[HDLC_FCS_POSITION(size)],
		           sizeof(uint16_t));

  (void) array_pull_hton(&from, (uint8_t *)&rx_crc, sizeof(uint16_t));

  uint32_t cx_crc = crc;
  if (crc == ~0) { /* computed crc not given: compute from frame */
  	cx_crc = crc16_ccitt_complete((uint8_t *)&p_from[1],
  	                              HDLC_FCS_POSITION(size) - 1);
  }

  RETURN_IF_FALSE((uint16_t)cx_crc == (uint16_t)rx_crc,
  	STATUS_HDLC_INVALID_FRAME);

	return STATUS_SUCCESS;
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
