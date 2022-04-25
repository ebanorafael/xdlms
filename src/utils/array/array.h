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
	(array_t){ .p_array = (uint8_t *)(P_FROM), .size = (SIZE), .start = 0, .end = (SIZE) }

#define ARRAY_FREE(P_TO, SIZE) \
	(array_t){ .p_array = (uint8_t *)(P_TO), .size = (SIZE), .start = 0, .end = 0 }

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

/*!
 * @brief Structure holding array information
 */
typedef struct array_t {
	/*! Address of array */
	const uint8_t *p_array;
	/*! Number of data hold by the array */
	const size_t size;
	/*! Current end of the array */
	size_t end;
	/*! Current start of the array */
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

/*!
 * @brief Validates two arrays
 * @param p_from Array to validate
 * @param p_to Array to validate
 * @param size Number of data to validate arrays
 * @return Status of the operation
 */
STATIC status_t
arrays_validate(const array_t p_from[static 1],
                const array_t p_to[static 1],
                const size_t size);

/*!
 * @brief Serializes data between two arrays (as big-endian)
 * @param p_from Structure holding information of data to serialize from
 * @param p_to Structure to hold information of serialized data
 * @param size Number of data to be serialized
 * @return Status of the operation
 */
STATIC status_t
array_serialize(const array_t p_from[static 1],
                const array_t p_to[static 1],
                size_t size);

#endif /* UNIT_TESTS */

/*******************************************************************
 * EXTERNED FUNCTIONS
 *******************************************************************/

/*!
 * @brief Computes how much of an array is currently used
 * @param p_from Address of structure holding array information
 * @return If successful: number o data used, if fail: -1
 */
size_t
array_used(const array_t p_from[static 1]) ;

/*!
 * @brief Computes how much of an array is currently not used
 * @param p_from Address of structure holding array information
 * @return If successful: number of data not used, if fail: -1
 */
size_t
array_free(const array_t p_from[static 1]);

/*!
 * @brief Drops a number of used data from an array
 * @param p_from Address of structure holding array information
 * @param size Number of data to drop
 * @return Status of the operation
 */
status_t
array_drop(array_t p_from[static 1],
           const size_t size);

/*!
 * @brief Copies a number of data between two arrays
 * @param p_from Address of structure to copy data from
 * @param p_to Address of structure to copy data to
 * @param size Number of data to copy
 * @return Status of the operation
 */
status_t
array_copy(const array_t p_from[static 1],
           array_t p_to[static 1],
           const size_t size);

/*!
 * @brief Moves a number of data between two arrays
 * @param p_from Address of structure to move data from
 * @param p_to Address of structure to move data to
 * @param size Number of data to move
 * @return Status of the operation
 */
status_t
array_move(array_t p_from[static 1],
           array_t p_to[static 1],
           size_t size);

/*!
 * @brief Pushes a number of data to an array
 * @param p_from Address of structure to push data to
 * @param p_to Address of data to push to array
 * @param size Number of data to push to array
 * @return Status of the operation
 */
status_t
array_push(const uint8_t p_from[static 1],
           array_t p_to[static 1],
           size_t size);

/*!
 * @brief Pulls a number of data from an array
 * @param p_from Address of structure to pull data from
 * @param p_to Address of data to receive pulled data to
 * @param size Number of data to pull from array
 * @return Status of the opereration
 */
status_t
array_pull(array_t p_from[static 1],
           const uint8_t p_to[static 1],
           const size_t size);

/*!
 * @brief Pushes a number of data in big-endian
 * @param p_from Address of data to push
 * @param p_to Address of structure holding data as array
 * @param size Number of data to push
 * @return Status of the operation
 */
status_t
array_push_hton(const uint8_t p_from[static 1],
                const array_t p_to[static 1],
                const size_t size);

/*!
 * @brief Pulls a number of data as big-endian
 * @param p_from Address of structure holding data to pull from
 * @param p_to Address to hold received data
 * @param size Number of data to be pulled
 * @return Status of the operation
 */
status_t
array_pull_hton(const array_t p_from[static 1],
                const uint8_t p_to[static 1],
                size_t size);

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
