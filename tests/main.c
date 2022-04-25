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

#include "unity.h"

/* System functioning includes end */

/* Module functioning includes start */

#include "array-tests.h"
#include "hdlc-address-tests.h"

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

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

int main(void) {
	UNITY_BEGIN();

	if (1) { RUN_TEST(array_used_tests); }
	if (1) { RUN_TEST(array_free_tests); }
	if (1) { RUN_TEST(arrays_validate_tests); }
	if (1) { RUN_TEST(array_serialize_tests); }
	if (1) { RUN_TEST(array_drop_tests); }
	if (1) { RUN_TEST(array_copy_tests); }
	if (1) { RUN_TEST(array_move_tests); }
	if (1) { RUN_TEST(array_push_tests); }
	if (1) { RUN_TEST(array_pull_tests); }
	if (1) { RUN_TEST(array_push_hton_tests); }
	if (1) { RUN_TEST(array_push_hton_tests); }


	if (0) { RUN_TEST(hdlc_parse_address_tests); }
	if (0) { RUN_TEST(hdlc_decode_address_tests); }
	if (0) { RUN_TEST(hdlc_pull_address_tests); }
	if (0) { RUN_TEST(hdlc_build_address_tests); }
	if (0) { RUN_TEST(hdlc_push_address_tests); }

	return UNITY_END();
}

void setUp(void) {
  return;
}

void tearDown(void) {
  return;
}
