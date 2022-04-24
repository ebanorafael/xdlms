/// @file

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /*  __cplusplus */

/*******************************************************************
 * EXTERNED DEFINES
 *******************************************************************/

#define ARRAY_USED(P_FROM, SIZE) \
	(array_t){ .p_array = p_from, .size = size, .start = 0, .end = size }

#define ARRAY_FREE(P_TO, SIZE) \
	(array_t){ .p_array = P_TO, .size = size, .start = 0, .end = 0 }

#define ARRAY_FLUSH(P_TO) \
	(array_t){ \
	  .p_array = (P_TO)->p_array, \
	  .size = (P_TO)->size, \
	  .start = 0, \
	  .end = 0 \
	}

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

typedef struct array_t {
	const uint8_t *p_array;
	const size_t size;
	size_t end;
	size_t start;
} array_t;

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

size_t
array_free(const array_t p_from[static 1]);

size_t
array_used(const array_t p_from[static 1]) ;

status_t
array_drop(array_t p_from[static 1],
           const size_t size);

status_t
array_copy(const array_t p_from[static 1],
           array_t p_to[static 1],
           const size_t size);

status_t
array_move(array_t p_from[static 1],
           array_t p_to[static 1],
           size_t size);

status_t
array_push(const uint8_t p_from[static 1],
           array_t p_to[static 1],
           size_t size);

status_t
array_pull(array_t p_from[static 1],
           const uint8_t p_to[static 1],
           const size_t size);

status_t
array_push_hton(const uint8_t p_from[static 1],
                const array_t p_to[static 1],
                const size_t size);

#ifdef UNIT_TESTS

STATIC status_t
arrays_validate(const array_t p_from[static 1],
                const array_t p_to[static 1],
                const size_t size);

STATIC status_t
array_serialize(const array_t p_from[static 1],
                const array_t p_to[static 1],
                size_t size);

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
