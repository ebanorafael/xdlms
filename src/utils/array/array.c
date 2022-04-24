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

/* System functioning includes end */

/* Module functioning includes start */

#include "array.h"
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
arrays_validate(const array_t p_from[static 1],
                const array_t p_to[static 1],
                const size_t size) {
	const size_t from_size = array_used(p_from);
	const size_t to_size = array_used(p_to);

	RETURN_IF_FALSE(from_size != (size_t)-1, STATUS_ARRAY_INVALID_PARAMETER);
	RETURN_IF_FALSE(to_size != (size_t)-1, STATUS_ARRAY_INVALID_PARAMETER);

	RETURN_IF_FALSE(!(size > from_size), STATUS_ARRAY_BUFFER_OVERFLOW);
	RETURN_IF_FALSE(!(size > to_size), STATUS_ARRAY_BUFFER_OVERFLOW);

	RETURN_IF_FALSE(p_from->p_array != NULL, STATUS_ARRAY_INVALID_PARAMETER);
	RETURN_IF_FALSE(p_to->p_array != NULL, STATUS_ARRAY_INVALID_PARAMETER);

	return STATUS_SUCCESS;
}

STATIC status_t
array_serialize(const array_t p_from[static 1],
                const array_t p_to[static 1],
                size_t size) {
	status_t status = arrays_validate(p_from, p_to, size);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	uint8_t *p_src = (uint8_t *)&p_from->p_array[p_from->start + size - 1];
	uint8_t *p_dst = (uint8_t *)&p_from->p_array[p_from->end];

	while(size--) {
		*p_dst++ = *p_src++;
	}

	return STATUS_SUCCESS;
}

size_t
array_free(const array_t p_from[static 1]) {
	ASSERT_DEVELOP(p_from != NULL, (size_t)-1);

	RETURN_IF_FALSE(!(p_from->end > p_from->size), (size_t)-1);
	return p_from->size - p_from->end;
}

size_t
array_used(const array_t p_from[static 1]) {
	ASSERT_DEVELOP(p_from != NULL, (size_t)-1);

	/* end must no be larger than size */
	RETURN_IF_FALSE(!(p_from->end > p_from->size), (size_t)-1);

	/* start must not be larger than end */
	RETURN_IF_FALSE(!(p_from->start > p_from->end), (size_t)-1);

	return p_from->end - p_from->start;
}

status_t
array_drop(array_t p_from[static 1],
           const size_t size) {
	const size_t used = array_used(p_from);

	RETURN_IF_FALSE(used != (size_t)-1, STATUS_ARRAY_INVALID_PARAMETER);
	RETURN_IF_FALSE(!(size > used), STATUS_ARRAY_BUFFER_OVERFLOW);

	p_from->start += size;
	return STATUS_SUCCESS;
}

status_t
array_copy(const array_t p_from[static 1],
           array_t p_to[static 1],
           size_t size) {
	status_t status = arrays_validate(p_from, p_to, size);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	uint8_t *p_src = (uint8_t *)&p_from->p_array[p_from->start];
	uint8_t *p_dst = (uint8_t *)&p_from->p_array[p_from->end];

	while(size--) {
		*p_dst++ = *p_src++;
	}

	p_to->end += size;
	return STATUS_SUCCESS;
}

status_t
array_move(array_t p_from[static 1],
           array_t p_to[static 1],
           size_t size) {
	status_t status = array_copy(p_from, p_to, size);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	return array_drop(p_from, size);
}

status_t
array_push(const uint8_t p_from[static 1],
           array_t p_to[static 1],
           size_t size) {
	array_t from = ARRAY_USED(p_from, size);
	return array_move(&from, p_to, size);
}

status_t
array_pull(array_t p_from[static 1],
           const uint8_t p_to[static 1],
           const size_t size) {
	array_t to = ARRAY_FREE(p_to, size);
	return array_move(p_from, &to, size);
}

status_t
array_push_hton(const uint8_t p_from[static 1],
                const array_t p_to[static 1],
                const size_t size) {
	array_t from = ARRAY_USED(p_from, size);
	return array_serialize(&from, p_to, size);
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
