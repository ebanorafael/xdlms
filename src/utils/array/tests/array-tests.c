///@file

/**************************************************************************************************
 * INCLUDES
 *************************************************************************************************/

/* Unit Test file header files inclusion start */

#include "unity.h"
#include "array-tests.h"
#include "array.h"

#include "utils.h"
#include <string.h>

/* Unit Test file header files inclusion end */

/**************************************************************************************************
 * PRIVATE DEFINES
 *************************************************************************************************/

/* Unit Test file defines start */

/* Unit Test file defines end */

/**************************************************************************************************
 * PRIVATE PROTOTYPES
 *************************************************************************************************/

/**************************************************************************************************
 * PRIVATE DATA
 *************************************************************************************************/

/**************************************************************************************************
 * FUNCTIONS
 *************************************************************************************************/

/* Mocked functions start */

/* Mocked functions end */

#if defined COPY

TEST_FUNCTION(funcion_name_tests) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */

  return;
}

#endif /* COPY */

void array_used_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* invalid parameter */
		size_t size = 0;

		size = array_used(NULL);
		TEST_ASSERT_EQUAL(size, (size_t)~0);
	}

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid parameter */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 1, .end = 2, .start = 0 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, (size_t)~0);
	}

	if (1) { /* invalid parameter */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 1, .end = 1, .start = 2 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, (size_t)~0);
	}

	if (1) { /* success */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 1, .end = 1, .start = 1 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, 0);
	}

	if (1) { /* success */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 8, .end = 5, .start = 2 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, 3);
	}

  /* Tests end */

  return;
}

void array_free_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* invalid parameter */
	  size_t size = 0;

	  size = array_free(NULL);
		TEST_ASSERT_EQUAL(size, (size_t)~0);
	}

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid paramter */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 1, .end = 2, .start = 0 };

		size = array_free(&from);
		TEST_ASSERT_EQUAL(size, (size_t)~0);
	}

	if (1) { /* success */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 12, .start = 4, .end = 8 };

		size = array_free(&from);
		TEST_ASSERT_EQUAL(size, 4);
	}

  /* Tests end */

  return;
}

void arrays_validate_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* invalid parameter */
		status_t status = STATUS_SUCCESS;

		status = arrays_validate(NULL, NULL, 0);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* invalid parameter */
		status_t status = STATUS_SUCCESS;
		array_t from = { .p_array = NULL, .size = 1, .start = 2, .end = 2 };

		status = arrays_validate(&from, NULL, 0);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* invalid parameter */
		status_t status = STATUS_SUCCESS;

		array_t from = ARRAY_USED(NULL, 8);
		array_t to = { .p_array = NULL, .size = 1, .start = 2, .end = 2 };

		status = arrays_validate(&from, &to, 0);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* invalid parameter */
		status_t status = STATUS_SUCCESS;

		array_t from = ARRAY_USED(NULL, 4);
		array_t to = ARRAY_FREE(NULL, 2);

		status = arrays_validate(&from, &to, 8);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_BUFFER_OVERFLOW);
	}

	if (1) { /* invalid parameter */
		status_t status = STATUS_SUCCESS;

		array_t from = ARRAY_USED(NULL, 4);
		array_t to = ARRAY_FREE(NULL, 2);

		status = arrays_validate(&from, &to, 3);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_BUFFER_OVERFLOW);
	}

	if (1) { /* invalid parameter */
		status_t status = STATUS_SUCCESS;

		array_t from = ARRAY_USED(NULL, 8);
		array_t to = ARRAY_FREE(NULL, 4);

		status = arrays_validate(&from, &to, 2);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* success */
		status_t status = STATUS_SUCCESS;

		const uint8_t from_array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		array_t from = ARRAY_USED(&from_array[0], ARRAY_SIZE(from_array));

		array_t to = ARRAY_FREE(NULL, 4);

		status = arrays_validate(&from, &to, 2);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */

  return;
}

void array_serialize_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* invalid parameter */
    status_t status = STATUS_SUCCESS;

    status = array_serialize(NULL, NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* success */
    status_t status = STATUS_ARRAY_INVALID_PARAMETER;

    const uint32_t data = 0x01020304;
    const array_t from = ARRAY_USED(&data, sizeof(data));

    uint8_t array[8] = { 0 };
    const array_t to = ARRAY_FREE(&array[0], ARRAY_SIZE(array));

    status = array_serialize(&from, &to, sizeof(data));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(array[0], 0x01);
		TEST_ASSERT_EQUAL(array[1], 0x02);
		TEST_ASSERT_EQUAL(array[2], 0x03);
		TEST_ASSERT_EQUAL(array[3], 0x04);

		MEMORY_TRACE(0, to.p_array, array_used(&to), "Serialized data (%u bytes): ",
		             (uint32_t)array_used(&to));
	}

  /* Tests end */

  return;
}

void array_drop_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid parameter */
    status_t status = STATUS_SUCCESS;

    status = array_drop(NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* invalid parameter */
    status_t status = STATUS_SUCCESS;
    array_t from = ARRAY_USED(NULL, 4);

    status = array_drop(&from, 8);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_BUFFER_OVERFLOW);
	}

	if (1) { /* success */
    status_t status = STATUS_SUCCESS;
    array_t from = ARRAY_USED(NULL, 12);

    status = array_drop(&from, 8);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		const size_t size = array_used(&from);
		TEST_ASSERT_EQUAL(size, 12 - 8);
	}

  /* Tests end */

  return;
}

void array_copy_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid parameters */
		status_t status = STATUS_SUCCESS;

		status = array_copy(NULL, NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* success */
		status_t status = STATUS_ARRAY_INVALID_PARAMETER;

		const uint8_t data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		array_t from = ARRAY_USED(&data[0], ARRAY_SIZE(data));

		uint8_t array[32] = { 0 };
		array_t to = ARRAY_FREE(&array[0], ARRAY_SIZE(array));

		status = array_copy(&from, &to, 4);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		int diff = memcmp(&array[0], &data[0], 4);
		TEST_ASSERT_EQUAL(diff, 0);
	}

  /* Tests end */

  return;
}

void array_move_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid paramter */
    status_t status = STATUS_SUCCESS;

    status = array_move(NULL, NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* success */
		status_t status = STATUS_ARRAY_INVALID_PARAMETER;

		const uint8_t data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		array_t from = ARRAY_USED(&data[0], ARRAY_SIZE(data));

		uint8_t array[32] = { 0 };
		array_t to = ARRAY_FREE(&array[0], ARRAY_SIZE(array));

		status = array_move(&from, &to, array_used(&from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		int diff = memcmp(&array[0], &data[0], array_used(&to));
		TEST_ASSERT_EQUAL(diff, 0);
	}

  /* Tests end */

  return;
}

void array_push_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid paramter */
    status_t status = STATUS_SUCCESS;

    status = array_push(NULL, NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* success */
		status_t status = STATUS_ARRAY_INVALID_PARAMETER;

		const uint8_t from[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

		uint8_t array[32] = { 0 };
		array_t to = ARRAY_FREE(&array[0], ARRAY_SIZE(array));

		status = array_push(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		int diff = memcmp(&array[0], &from[0], array_used(&to));
		TEST_ASSERT_EQUAL(diff, 0);
	}

  /* Tests end */

  return;
}

void array_pull_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid paramter */
    status_t status = STATUS_SUCCESS;

    status = array_pull(NULL, NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* success */
		status_t status = STATUS_ARRAY_INVALID_PARAMETER;

		uint8_t to[6] = { 0 };

		const uint8_t array[] = { 1, 2, 3, 4, 5, 6, 7, 8, [8 ... 31] = 0 };
		array_t from = ARRAY_USED(&array[0], ARRAY_SIZE(array));

		status = array_pull(&from, &to[0], 4);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		int diff = memcmp(&to[0], &array[0], 4);
		TEST_ASSERT_EQUAL(diff, 0);
	}

  /* Tests end */

  return;
}

void array_push_hton_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid paramter */
    status_t status = STATUS_SUCCESS;

    status = array_push_hton(NULL, NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* success */
		status_t status = STATUS_ARRAY_INVALID_PARAMETER;

		uint16_t from1 = 0x0102;
		int32_t  from2 = 0x08070605;

		uint8_t array[] = { 0, 0, 0, 0, 0, 0 };
		array_t to = ARRAY_FREE(&array, ARRAY_SIZE(array));

		status = array_push_hton((uint8_t *)&from1, &to, sizeof(from1));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(array[0], 0x01);
		TEST_ASSERT_EQUAL(array[1], 0x02);

		status = array_push_hton((uint8_t *)&from2, &to, sizeof(from2));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(array[0], 0x08);
		TEST_ASSERT_EQUAL(array[1], 0x07);
		TEST_ASSERT_EQUAL(array[2], 0x06);
		TEST_ASSERT_EQUAL(array[3], 0x05);
	}

  /* Tests end */

  return;
}

void array_pull_hton_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* invalid paramter */
    status_t status = STATUS_SUCCESS;

    status = array_pull_hton(NULL, NULL, -1);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* success */
		status_t status = STATUS_ARRAY_INVALID_PARAMETER;

		uint16_t to1 = 0xffff;
		int32_t  to2 = 0xffffffff;

		uint8_t array[] = { 0x03, 0x04, 0x01, 0x02, 0x07, 0x08 };
		array_t from = ARRAY_FREE(&array, ARRAY_SIZE(array));

		status = array_pull_hton(&from, (uint8_t *)&to1, sizeof(to1));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(array[0], 0x03);
		TEST_ASSERT_EQUAL(array[1], 0x04);

		status = array_pull_hton(&from, (uint8_t *)&to2, sizeof(to2));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(array[0], 0x01);
		TEST_ASSERT_EQUAL(array[1], 0x02);
		TEST_ASSERT_EQUAL(array[2], 0x07);
		TEST_ASSERT_EQUAL(array[3], 0x08);
	}

  /* Tests end */

  return;
}
