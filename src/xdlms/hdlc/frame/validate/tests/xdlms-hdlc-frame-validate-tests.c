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

void hdlc_frame_is_complete_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* fail: null pointer */
		status_t status = STATUS_SUCCESS;

		status = hdlc_frame_is_complete(NULL, 0, 0);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
	}

	if (1) { /* fail: invalid frame size */
		status_t status = STATUS_SUCCESS;
		const uint8_t from[] = { 0x00 };

		for (size_t size = 0; size < HDLC_FRAME_COMPLETE_MIN_SIZE; size++) {
			status = hdlc_frame_is_complete(&from[0], size, 0);
			TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
		}
	}

	if (1) { /* fail: invalid frame delimiter start */
		const uint8_t from[HDLC_FRAME_COMPLETE_MIN_SIZE] = { 0x00 };
		status_t status = STATUS_SUCCESS;

		status = hdlc_frame_is_complete(&from[0], ARRAY_SIZE(from), 0);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_DELIMITER);
	}

	if (1) { /* fail: invalid frame delimiter end */
		const uint8_t from[HDLC_FRAME_COMPLETE_MIN_SIZE] = {
			[0]= 0x00, [HDLC_FRAME_COMPLETE_MIN_SIZE - 1] = 0
		};
		status_t status = STATUS_SUCCESS;

		status = hdlc_frame_is_complete(&from[0], ARRAY_SIZE(from), 0);
		TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME_DELIMITER);
	}

  /* End of assertion test cases */

  /* Tests start*/

  if (1) { /* fail: invalid checksum */
  	const uint8_t from[] = {
  		0x7E, 0xA1, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4, 0x7E
  	};
  	status_t status = STATUS_SUCCESS;

  	status = hdlc_frame_is_complete(&from[0], ARRAY_SIZE(from), ~0);
  	TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
  }

  if (1) { /* fail: invalid checksum */
  	const uint8_t from[] = {
  		0x7E, 0xA0, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4, 0x7E
  	};
  	status_t status = STATUS_SUCCESS;

  	status = hdlc_frame_is_complete(&from[0], ARRAY_SIZE(from), 0x6ad5);
  	TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_FRAME);
  }

  if (1) { /* success */
  	const uint8_t from[] = {
  		0x7E, 0xA0, 0x07, 0x17, 0x03, 0x91, 0x6A, 0xD4, 0x7E
  	};
  	status_t status = STATUS_SUCCESS;

  	status = hdlc_frame_is_complete(&from[0], ARRAY_SIZE(from), 0x6ad4);
  	TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
  }

  /* Tests end */

  return;
}
