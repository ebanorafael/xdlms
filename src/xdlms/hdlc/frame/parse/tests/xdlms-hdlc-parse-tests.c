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

void xdlms_hdlc_parse_and_validate_frame_length_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* fail: null pointer */
		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_and_validate_frame_length(NULL, NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

	if (1) { /* fail: null pointer */
		size_t len = 0;
		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_and_validate_frame_length(NULL, &len, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);

		TEST_ASSERT_EQUAL(len, 0);
	}

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* fail: frame not complete */
		const uint8_t buffer[] = {
			0x7E, 0xA0, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4, 0x7E
		};
		array_t from = ARRAY_USED(buffer, 7);
		size_t len = 0;
		bool is_seg = true;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_and_validate_frame_length(&from, &len, &is_seg);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_DELIMITER);

		TEST_ASSERT_EQUAL(len, (size_t)~0);
		TEST_ASSERT_EQUAL(is_seg, false);
	}

	if (1) { /* fail: invalid frame format */
		const uint8_t buffer[] = {
			0x7e, 0xff, 0x07, 0x17, 0x03, 0x91, 0xcb, 0xf4, 0x7e
		};
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		size_t len = 0;
		bool is_seg = true;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_and_validate_frame_length(&from, &len, &is_seg);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_FORMAT);

		TEST_ASSERT_EQUAL(len, (size_t)~0);
		TEST_ASSERT_EQUAL(is_seg, false);
	}

	if (1) { /* fail: invalid frame size */
		const uint8_t buffer[] = {
			 0x7e, 0xa0, 0x12, 0x17, 0x03, 0x91, 0x79, 0x9c, 0x7e
		};
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		size_t len = 0;
		bool is_seg = true;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_and_validate_frame_length(&from, &len, &is_seg);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_LENGTH);

		TEST_ASSERT_EQUAL(len, (size_t)~0);
		TEST_ASSERT_EQUAL(is_seg, false);
	}

	if (1) { /* success */
		const uint8_t buffer[] = {
			 0x7e, 0xa0, 0x07, 0x17, 0x03, 0x91, 0xd4, 0x6a, 0x7e
		};
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		size_t len = 0;
		bool is_seg = true;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_and_validate_frame_length(&from, &len, &is_seg);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(len, buffer[2]);
		TEST_ASSERT_EQUAL(is_seg, false);
	}

  /* Tests end */

  return;
}

