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

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* System functioning includes end */

/* Module functioning includes start */

#include "status.h"

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
 * @brief Validates a xDLMS HDLC frame header checksum
 * @param p_from Address of first byte of the header
 * @param size Number of bytes in header, including its checksum
 * @return Status of the operation
 * @note: The checksum of the header are the last 2 bytes
 */
status_t
hdlc_frame_hcs_valid(
	const uint8_t p_from[static 1],
	const size_t size
);

/*!
 * @brief Validate a xDLMS HDLC frame by its checksum
 * @param p_from Address of buffer holding frame data
 * @param size Number of data in the frame
 * @return Status of the operation
 * @note The last two bytes of data is the received crc
 */
status_t
hdlc_frame_fcs_valid(
  const uint8_t p_from[static const 1],
  const size_t size
);

/*!
 * @brief Validates a xDLMS HDLC frame
 * @param p_from Address of buffer holding frame bytes
 * @param size Number of byte in frame to validate
 * @return Status of the Operation
 */
status_t
hdlc_frame_validate(
	const uint8_t p_from[static 1],
	const size_t size
);

#ifdef UNIT_TESTS

STATIC status_t
hdlc_crc_validate(
	const uint8_t p_from[static 1],
	const size_t size
);
#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
