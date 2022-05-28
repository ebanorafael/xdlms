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

#include <stdint.h>
#include <stddef.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

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
 * @brief Computes a CRC-16 CCITT partially, based on previous computation
 * @param p_from Address of buffer to compute crc over
 * @param size Number of bytes to compute crc over
 * @param crc Previous partial crc computed
 * @return Updated computed crc
 */
uint32_t
crc16_ccitt_partial(
  uint8_t p_from[static 1],
  size_t size,
  uint32_t crc
);

/*!
 * @brief Computes as CRC-16 CCITT completly
 * @param p_from Address of buffer to compute crc over
 * @param size Number of bytes to compute crc over
 * @return CRC-16 CCITT
 */
uint32_t
crc16_ccitt_complete(
  uint8_t p_from[static 1],
  size_t size
);

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
