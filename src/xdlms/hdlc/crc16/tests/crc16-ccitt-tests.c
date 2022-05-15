///@file

/**************************************************************************************************
 * INCLUDES
 *************************************************************************************************/

/* Unit Test file header files inclusion start */

#include "unity.h"

#include "crc16-ccitt-tests.h"
#include "crc16-ccitt.h"

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

void crc16_ccitt_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* success */
		const uint8_t from[] = { 0x03, 0x3f };

		uint32_t crc = 0xffff;
		crc = crc16_ccitt_complete((uint8_t *)&from[0], ARRAY_SIZE(from));

		TEST_ASSERT_EQUAL(crc, 0xec5b);
	}

	if (1) { /* success */
		const uint8_t from[] = {
			0xA8, 0x6C, 0x03, 0x17, 0x56, 0x0D, 0x71, 0xE6,
			0xE6, 0x00, 0xC1, 0x02, 0xC1, 0x00, 0x14, 0x00,
			0x00, 0x0D, 0x00, 0x00, 0xFF, 0x07, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x01, 0x5B, 0x01, 0x08, 0x02,
			0x03, 0x09, 0x01, 0x01, 0x09, 0x0C, 0x07, 0xE2,
			0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,
			0x2C, 0x00, 0x09, 0x01, 0x01, 0x02, 0x03, 0x09,
			0x01, 0x02, 0x09, 0x0C, 0x07, 0xE2, 0x05, 0x15,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x80,
			0x09, 0x01, 0x02, 0x02, 0x03, 0x09, 0x01, 0x03,
			0x09, 0x0C, 0x07, 0xE2, 0x05, 0x19, 0x05, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xF0, 0x80, 0x09, 0x01,
			0x03, 0x02, 0x03, 0x09, 0x01, 0x04, 0x09, 0x0C,
			0x07, 0xE2,
		};

		uint32_t crc = 0xffff;
		crc = crc16_ccitt_complete((uint8_t *)&from[0], ARRAY_SIZE(from));

		TEST_ASSERT_EQUAL(crc, 0x214f);
	}

  /* Tests end */

  return;
}

void crc16_ccitt_update_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) {
		const uint8_t from[] = { 0x03, 0x3f };
		const uint32_t expected =
			crc16_ccitt_partial((uint8_t *)&from[0],
			                   ARRAY_SIZE(from),
			                   0xffff);

		uint32_t crc = 0xffff;
		size_t index = 0;

		for (; index < ARRAY_SIZE(from); index++) {
			crc = crc16_ccitt_partial((uint8_t *)&from[index], 1, crc);

			if (~crc == expected) {
				break; /* should not reach here */
			}
		}

		TEST_ASSERT_EQUAL(index, ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(crc, expected);
	}

	if (1) {
		const uint8_t from[] = {
			0xA8, 0x6C, 0x03, 0x17, 0x56, 0x0D, 0x71, 0xE6,
			0xE6, 0x00, 0xC1, 0x02, 0xC1, 0x00, 0x14, 0x00,
			0x00, 0x0D, 0x00, 0x00, 0xFF, 0x07, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x01, 0x5B, 0x01, 0x08, 0x02,
			0x03, 0x09, 0x01, 0x01, 0x09, 0x0C, 0x07, 0xE2,
			0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,
			0x2C, 0x00, 0x09, 0x01, 0x01, 0x02, 0x03, 0x09,
			0x01, 0x02, 0x09, 0x0C, 0x07, 0xE2, 0x05, 0x15,
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x80,
			0x09, 0x01, 0x02, 0x02, 0x03, 0x09, 0x01, 0x03,
			0x09, 0x0C, 0x07, 0xE2, 0x05, 0x19, 0x05, 0x00,
			0x00, 0x00, 0x00, 0x00, 0xF0, 0x80, 0x09, 0x01,
			0x03, 0x02, 0x03, 0x09, 0x01, 0x04, 0x09, 0x0C,
			0x07, 0xE2,
		};
		const uint32_t expected =
			crc16_ccitt_partial((uint8_t *)&from[0],
			                   ARRAY_SIZE(from),
			                   0xffff);

		uint32_t crc = 0xffff;
		size_t index = 0;

		for (; index < ARRAY_SIZE(from); index++) {
			crc = crc16_ccitt_partial((uint8_t *)&from[index], 1, crc);

			if (~crc == expected) {
				break; /* should not reach here */
			}
		}

		TEST_ASSERT_EQUAL(index, ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(crc, expected);
	}

  /* Tests end */

  return;
}