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

#include <stddef.h>
#include <stdint.h>

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

/*!
 * Read-Only Array
 */
typedef struct array_ro_t {
	uint8_t *p_base;
	const size_t size;
	size_t start;
} array_ro_t;

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
array_pull(array_ro_t *p_from, const size_t size, uint8_t p_to[size]);

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
