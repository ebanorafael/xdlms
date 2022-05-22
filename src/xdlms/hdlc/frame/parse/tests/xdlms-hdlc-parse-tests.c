///@file

/**************************************************************************************************
 * INCLUDES
 *************************************************************************************************/

/* Unit Test file header files inclusion start */

#include "unity.h"

#include "xdlms-hdlc-parse-tests.h"
#include "xdlms-hdlc-parse.h"
#include "array.h"
#include "utils.h"

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

void function_name_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

  TEST_ASSERT_EQUAL(1, 1);
  
  /* Tests end */
  
  return;
}

#endif /* COPY */

void xdlms_hdlc_parse_mac_format_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* fail: null parameter */
		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac_format(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

  /* End of assertion test cases */

  /* Tests start*/


	if (1) { /* fail: null parameter */
		status_t status = STATUS_SUCCESS;
		uint32_t to = ~0;

		status = xdlms_hdlc_parse_mac_format(NULL, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
	}

	if (1) { /* fail: not enough data on input buffer */
		const uint8_t buffer[1] = { 0 };
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		uint32_t to = ~0;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac_format(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_BUFFER_OVERFLOW);
		TEST_ASSERT_EQUAL(to, 0);
	}

	if (1) { /* fail: invalid frame format field */
		const uint8_t buffer[] = { 0xff, 0xff };
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		uint32_t to = ~0;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac_format(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_FORMAT);
		TEST_ASSERT_EQUAL((uint16_t)to, (uint16_t)~0);
	}

	if (1) { /* success */
		const uint8_t buffer[] = { 0xaf, 0xff };
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		uint32_t to = ~0;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac_format(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
		TEST_ASSERT_EQUAL(to, 0xafff);
	}

  /* Tests end */

  return;
}
