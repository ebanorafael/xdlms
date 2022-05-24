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

#include "status.h"
#include "array.h"

/* System functioning includes end */

/* Module functioning includes start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

/*******************************************************************
 * EXTERNED TYPES
 *******************************************************************/

typedef struct hdlc_address_t {
	uint32_t value;
	size_t size;
} hdlc_address_t;

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
hdlc_push_address(
  const hdlc_address_t p_from[static const 1],
  array_t p_to[static 1]
);

/*!
 * @brief Pulls HDLC Address
 * @param p_from Address of structure holding data to be parsed
 * @param p_to Address of structure to hold parsed data
 * @return Status of the operation
 */
status_t
hdlc_pull_address(
  array_t p_from[static 1],
  hdlc_address_t p_to[static 1]
);

#ifdef UNIT_TESTS

STATIC uint32_t
hdlc_parse_address(
  array_t p_from[static 1],
  const size_t size
);

STATIC status_t
hdlc_decode_address(
  array_t p_from[static const 1],
  hdlc_address_t p_to[static 1],
  const size_t size);

STATIC status_t
hdlc_build_address(
  const hdlc_address_t p_from[static 1],
  array_t p_to[static 1]
);

#endif /* UNIT_TESTS */

#ifdef __cplusplus
}
#endif /*  __cplusplus */
