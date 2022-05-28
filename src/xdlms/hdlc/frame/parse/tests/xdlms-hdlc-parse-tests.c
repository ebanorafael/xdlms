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

	if (1) { /* fail: invalid frame delimiter */
		const uint8_t buffer[] = {
			0xff, 0xA0, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4, 0x7E
		};
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
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
			0x7e, 0xff, 0x07, 0x17, 0x03, 0x91, 0xf4, 0xcb, 0x7e
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
			 0x7e, 0xa0, 0x12, 0x17, 0x03, 0x91, 0x9c, 0x79, 0x7e
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
			0x7E, 0xA0, 0x07, 0x17, 0x03, 0x91, 0x6a, 0xd4, 0x7E
		};
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		size_t len = 0;
		bool is_seg = true;

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_and_validate_frame_length(&from, &len, &is_seg);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(len, 7);
		TEST_ASSERT_EQUAL(is_seg, false);
	}

  /* Tests end */

  return;
}

void xdlms_hdlc_parse_mac_addresses_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* fail: null pointer */
		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac_addresses(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

	if (1) { /* fail: null pointer */
		status_t status = STATUS_SUCCESS;
		array_t from = ARRAY_FREE(NULL, 0);

		status = xdlms_hdlc_parse_mac_addresses(&from, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* fail: invalid array */
		status_t status = STATUS_SUCCESS;
		array_t from = ARRAY_FREE(NULL, 0);
		hdlc_mac_address_t to = { 0 };

		status = xdlms_hdlc_parse_mac_addresses(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_BUFFER_OVERFLOW);
	}

	if (1) { /* fail: incomplete data */
		const uint8_t buffer[] = { 0x80, 0x41 };
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		hdlc_mac_address_t to = { 0 };

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac_addresses(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ARRAY_BUFFER_OVERFLOW);

		TEST_ASSERT_EQUAL(to.dst.value, 0x2041);
		TEST_ASSERT_EQUAL(to.dst.size, sizeof(uint16_t));
	}

	if (1) { /* success */
		const uint8_t buffer[] = {
			0x80, 0x41, 0x48, 0x68, 0xfe, 0xff
		};
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		hdlc_mac_address_t to = { 0 };

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac_addresses(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.dst.value, 0x2041);
		TEST_ASSERT_EQUAL(to.dst.size, sizeof(uint16_t));

		TEST_ASSERT_EQUAL(to.src.value, 0x12343fff);
		TEST_ASSERT_EQUAL(to.src.size, sizeof(uint32_t));
	}

  /* Tests end */

  return;
}

void xdlms_hdlc_parse_mac_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* fail: null pointer */
		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* fail: buffer without valid information */
		array_t from = ARRAY_FREE(NULL, 0);
		hdlc_mac_info_t to = { 0 };

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

	if (1) { /* success */
		const uint8_t buffer[] = {
			0x7e, 0xa0, 0x6c, 0x03, 0x17, 0x7a, 0x43, 0xc0,
			0xe6, 0xe6, 0x00, 0xc1, 0x03, 0xc1, 0x01, 0x00,
			0x00, 0x00, 0x02, 0x57, 0x03, 0x09, 0x01, 0x05,
			0x09, 0x0c, 0x08, 0x3c, 0x06, 0x05, 0x02, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xf0, 0x80, 0x09, 0x01,
			0x03, 0x02, 0x03, 0x09, 0x01, 0x06, 0x09, 0x0c,
			0x07, 0xe2, 0x06, 0x09, 0x06, 0x00, 0x00, 0x00,
			0x00, 0x00, 0xf0, 0x80, 0x09, 0x01, 0x02, 0x02,
			0x03, 0x09, 0x01, 0x07, 0x09, 0x0c, 0x07, 0xe2,
			0x06, 0x0d, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
			0xf0, 0x80, 0x09, 0x01, 0x01, 0x02, 0x03, 0x09,
			0x01, 0x08, 0x09, 0x0c, 0x07, 0xe2, 0x06, 0x12,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x80,
			0x09, 0x01, 0x04, 0x47, 0xee, 0x7e
		};
		array_t from = ARRAY_USED(buffer, ARRAY_SIZE(buffer));
		hdlc_mac_info_t to = { 0 };

		status_t status = STATUS_SUCCESS;

		status = xdlms_hdlc_parse_mac(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.frame_len, buffer[2]);
		TEST_ASSERT_EQUAL(to.address.dst.value, 1);
		TEST_ASSERT_EQUAL(to.address.dst.size, sizeof(uint8_t));
		TEST_ASSERT_EQUAL(to.address.src.value, 11);
		TEST_ASSERT_EQUAL(to.address.src.size, sizeof(uint8_t));
		TEST_ASSERT_EQUAL(to.is_segmented, false);
	}

  /* Tests end */

  return;
}
