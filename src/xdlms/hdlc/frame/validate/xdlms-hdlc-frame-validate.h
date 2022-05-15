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

status_t
hdlc_frame_is_complete(
  const uint8_t p_from[static const 1],
  const size_t size,
  const uint32_t crc
);

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
