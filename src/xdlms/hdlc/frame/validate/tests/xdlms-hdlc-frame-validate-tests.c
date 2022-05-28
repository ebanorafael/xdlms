///@file

/**************************************************************************************************
 * INCLUDES
 *************************************************************************************************/

/* Unit Test file header files inclusion start */

#include "unity.h"

#include "xdlms-hdlc-frame-validate-tests.h"
#include "xdlms-hdlc-frame-validate.h"
#include "xdlms-hdlc.h"

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

void hdlc_crc_validate_tests(void) {
	/* Global test variables start */

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* fail: null pointer */
		status_t status = STATUS_SUCCESS;

		status = hdlc_crc_validate(NULL, 0);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* fail: invalid sizes */
		const uint8_t from[] = { 0x00, 0x00 };

		for (size_t size = 0; size < ARRAY_SIZE(from); size++) {
			status_t status = STATUS_SUCCESS;

			status = hdlc_crc_validate(&from[0], size);
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
		}
	}

	if (1) { /* fail: invalid checksum */
		const uint8_t from[] = {
			0xA0, 0x13, 0x17, 0x03, 0xB4, 0xff, 0x00,
		};

		status_t status = STATUS_SUCCESS;

		status = hdlc_crc_validate(&from[0], ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
	}

	if (1) { /* success: header only */
		const uint8_t from[] = {
			0xA0, 0x13, 0x17, 0x03, 0xB4, 0x88, 0x13,
		};

		status_t status = STATUS_SUCCESS;

		status = hdlc_crc_validate(&from[0], ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
	}

	if (1) { /* success: hdlc frame */
		const uint8_t from[] = {
			0x7E,
			0xA0, 0x13, 0x17, 0x03, 0xB4, 0x88, 0x13,
			0xE6, 0xE7, 0x00,
			0xC5, 0x02, 0xC1, 0x00, 0x00, 0x00, 0x01, 0x0F, 0x03,
			0x7E
		};

		status_t status = STATUS_SUCCESS;

		status = hdlc_crc_validate(&from[1], 7);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
	}

	/* Tests end */

	return;
}

void hdlc_frame_hcs_valid_tests(void) {
	/* Global test variables start */

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* fail: invalid sizes */
		for (size_t size = 0; size < HDLC_FRAME_HEADER_MIN_SIZE; size++) {
			status_t status = STATUS_SUCCESS;

			status = hdlc_frame_hcs_valid(NULL, size);
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
		}
	}

	if (1) { /* fail: invalid sizes */
		for (size_t size = (HDLC_FRAME_HEADER_MAX_SIZE + 1);
				size < 2 * HDLC_FRAME_HEADER_MAX_SIZE;
				size++) {
			status_t status = STATUS_SUCCESS;

			status = hdlc_frame_hcs_valid(NULL, size);
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
		}
	}

	if (1) { /* fail: invalid frame checksum */
		const uint8_t from[] = {
			0x7E,
			0xA0, 0x6C, 0x03, 0x17, 0x7A, 0x43, 0xC1,
			0xE6, 0xE6, 0x00,
			0xC1, 0x03, 0xC1, 0x01, 0x00, 0x00, 0x00, 0x02,
			0x57, 0x03, 0x09, 0x01, 0x05, 0x09, 0x0C, 0x08,
			0x3C, 0x06, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00,
			0x00, 0xF0, 0x80, 0x09, 0x01, 0x03, 0x02, 0x03,
			0x09, 0x01, 0x06, 0x09, 0x0C, 0x07, 0xE2, 0x06,
			0x09, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
			0x80, 0x09, 0x01, 0x02, 0x02, 0x03, 0x09, 0x01,
			0x07, 0x09, 0x0C, 0x07, 0xE2, 0x06, 0x0D, 0x03,
			0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x80, 0x09,
			0x01, 0x01, 0x02, 0x03, 0x09, 0x01, 0x08, 0x09,
			0x0C, 0x07, 0xE2, 0x06, 0x12, 0x01, 0x00, 0x00,
			0x00, 0x00, 0x00, 0xF0, 0x80, 0x09, 0x01, 0x04,
			0x44, 0xEE,
			0x7E,
		};

		status_t status = STATUS_SUCCESS;

		status = hdlc_frame_hcs_valid(&from[1], 7);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
	}

	if (1) { /* success: hdlc frame */
		const uint8_t from[] = {
			0x7E,
			0xA0, 0x6C, 0x03, 0x17, 0x7A, 0x43, 0xC0,
			0xE6, 0xE6, 0x00,
			0xC1, 0x03, 0xC1, 0x01, 0x00, 0x00, 0x00, 0x02,
			0x57, 0x03, 0x09, 0x01, 0x05, 0x09, 0x0C, 0x08,
			0x3C, 0x06, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00,
			0x00, 0xF0, 0x80, 0x09, 0x01, 0x03, 0x02, 0x03,
			0x09, 0x01, 0x06, 0x09, 0x0C, 0x07, 0xE2, 0x06,
			0x09, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0,
			0x80, 0x09, 0x01, 0x02, 0x02, 0x03, 0x09, 0x01,
			0x07, 0x09, 0x0C, 0x07, 0xE2, 0x06, 0x0D, 0x03,
			0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x80, 0x09,
			0x01, 0x01, 0x02, 0x03, 0x09, 0x01, 0x08, 0x09,
			0x0C, 0x07, 0xE2, 0x06, 0x12, 0x01, 0x00, 0x00,
			0x00, 0x00, 0x00, 0xF0, 0x80, 0x09, 0x01, 0x04,
			0x47, 0xEE,
			0x7E,
		};

		status_t status = STATUS_SUCCESS;

		status = hdlc_frame_hcs_valid(&from[1], 7);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
	}

	/* Tests end */

	return;
}

void hdlc_frame_fcs_valid_tests(void) {
	/* Global test variables start */

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* fail: invalid null pointer */
		status_t status = STATUS_SUCCESS;

		status= hdlc_frame_fcs_valid(NULL, 0);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

	if (1) { /* success: complete frame */
		const uint8_t from[] = {
			0x7E,
			0xA0, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4,
			0x7E
		};
		status_t status = STATUS_SUCCESS;

		status= hdlc_frame_fcs_valid(&from[1], ARRAY_SIZE(from) - HDLC_FRAME_OVERHEAD);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
	}

	if (1) { /* success: complete frame */
		const uint8_t from[] = {
			0x7E,
			0xA8, 0x6C, 0x03, 0x17, 0x56, 0x0D, 0x71,
			0xE6, 0xE6, 0x00,
			0xC1, 0x02, 0xC1, 0x00, 0x14, 0x00, 0x00, 0x0D,
			0x00, 0x00, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x5B, 0x01, 0x08, 0x02, 0x03, 0x09,
			0x01, 0x01, 0x09, 0x0C, 0x07, 0xE2, 0x01, 0x01,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x2C, 0x00,
			0x09, 0x01, 0x01, 0x02, 0x03, 0x09, 0x01, 0x02,
			0x09, 0x0C, 0x07, 0xE2, 0x05, 0x15, 0x01, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xF0, 0x80, 0x09, 0x01,
			0x02, 0x02, 0x03, 0x09, 0x01, 0x03, 0x09, 0x0C,
			0x07, 0xE2, 0x05, 0x19, 0x05, 0x00, 0x00, 0x00,
			0x00, 0x00, 0xF0, 0x80, 0x09, 0x01, 0x03, 0x02,
			0x03, 0x09, 0x01, 0x04, 0x09, 0x0C, 0x07, 0xE2,
			0x4F, 0x21,
			0x7E
		};
		status_t status = STATUS_SUCCESS;

		status= hdlc_frame_fcs_valid(&from[1], ARRAY_SIZE(from) - HDLC_FRAME_OVERHEAD);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
	}

	/* Tests end */

	return;
}

void hdlc_frame_validate_tests(void) {
	/* Global test variables start */

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* fail: invalid parameter */
		status_t status = STATUS_SUCCESS;

		status = hdlc_frame_validate(NULL, 0);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* fail: invalid frame sizes */
		const uint8_t from[] = { 0x00, 0x00 };
		status_t status = STATUS_SUCCESS;

		for (size_t size = 0; size < ARRAY_SIZE(from); size++) {
			status =  hdlc_frame_validate(&from[0], size);

			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
		}
	}

	if (1) { /* fail: frame start flag  */
		uint8_t from[] = {
			0x7E,
			0xA0, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4,
			0x7E
		};

		for (size_t flag = 0; flag < HDLC_FRAME_LIMIT; flag++) {
			status_t status = STATUS_SUCCESS;
			from[0] = flag;

			status =  hdlc_frame_validate(&from[0], ARRAY_SIZE(from));
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_DELIMITER);
		}

		for (size_t flag = HDLC_FRAME_LIMIT + 1; flag < 0xff; flag++) {
			status_t status = STATUS_SUCCESS;
			from[0] = flag;

			status =  hdlc_frame_validate(&from[0], ARRAY_SIZE(from));
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_DELIMITER);
		}
	}

	if (1) { /* fail: frame end flag  */
		uint8_t from[] = {
			0x7E,
			0xA0, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4,
			0x7E
		};

		for (size_t flag = 0; flag < HDLC_FRAME_LIMIT; flag++) {
			status_t status = STATUS_SUCCESS;
			from[ARRAY_SIZE(from) - 1] = flag;

			status =  hdlc_frame_validate(&from[0], ARRAY_SIZE(from));
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_DELIMITER);
		}

		for (size_t flag = HDLC_FRAME_LIMIT + 1; flag < 0xff; flag++) {
			status_t status = STATUS_SUCCESS;
			from[ARRAY_SIZE(from) - 1] = flag;

			status =  hdlc_frame_validate(&from[0], ARRAY_SIZE(from));
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_DELIMITER);
		}
	}

	if (1) { /* success */
		const uint8_t from[] = {
			0x7E,
			0xA8, 0x6C, 0x03, 0x17, 0x56, 0x0D, 0x71,
			0xE6, 0xE6, 0x00,
			0xC1, 0x02, 0xC1, 0x00, 0x14, 0x00, 0x00, 0x0D,
			0x00, 0x00, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x5B, 0x01, 0x08, 0x02, 0x03, 0x09,
			0x01, 0x01, 0x09, 0x0C, 0x07, 0xE2, 0x01, 0x01,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x2C, 0x00,
			0x09, 0x01, 0x01, 0x02, 0x03, 0x09, 0x01, 0x02,
			0x09, 0x0C, 0x07, 0xE2, 0x05, 0x15, 0x01, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xF0, 0x80, 0x09, 0x01,
			0x02, 0x02, 0x03, 0x09, 0x01, 0x03, 0x09, 0x0C,
			0x07, 0xE2, 0x05, 0x19, 0x05, 0x00, 0x00, 0x00,
			0x00, 0x00, 0xF0, 0x80, 0x09, 0x01, 0x03, 0x02,
			0x03, 0x09, 0x01, 0x04, 0x09, 0x0C, 0x07, 0xE2,
			0x4F, 0x21,
			0x7E
		};
		status_t status = STATUS_SUCCESS;

		status = hdlc_frame_validate(&from[0], ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
	}

	/* Tests end */

	return;
}
