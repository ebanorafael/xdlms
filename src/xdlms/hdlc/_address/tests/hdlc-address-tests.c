///@file

/**************************************************************************************************
 * INCLUDES
 *************************************************************************************************/

/* Unit Test file header files inclusion start */

#include "unity.h"

/* Unit Test file header files inclusion end */

#include "hdlc-address-tests.h"
#include "hdlc-address.h"

#include "utils.h"

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

void funcion_name_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */
  
  return;
}

#endif /* COPY */

void hdlc_parse_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

  if (1) { /* invalid size: 0 */
    uint8_t data[] =  { 0xff, 0xff, 0xff };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    uint32_t address = hdlc_parse_address(&from, 0);
    TEST_ASSERT_EQUAL(address, (uint32_t)~0);
  }

  if (1) { /* invalid size: 3 */
    uint8_t data[] =  { 0xff, 0xff, 0xff };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    uint32_t address = hdlc_parse_address(&from, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(address, (uint32_t)~0);
  }

	if (1) { /* invalid size: 5 */
    uint32_t address = hdlc_parse_address(NULL, sizeof(uint32_t) + 1);
    TEST_ASSERT_EQUAL(address, (uint32_t)~0);
  }

  if (1) { /* success */
    uint8_t data[] =  { 0xff };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    uint32_t address = hdlc_parse_address(&from, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(address, 0x7f);
  }

  if (1) { /* success */
    uint8_t data[] =  { 0xfe, 0xff };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    uint32_t address = hdlc_parse_address(&from, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(address, 0x3fff);
  }

  if (1) { /* success: DLMS UA Green Book ed. 10 sec 8.4.2.3 */
    uint8_t data[] = { 0x48, 0x68, 0xfe, 0xff };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    uint32_t address = hdlc_parse_address(&from, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(address, 0x12343fff);
  }

  if (1) { /* success */
    uint8_t data[] = { 0xfe, 0xfe, 0xfe, 0xff };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    uint32_t address = hdlc_parse_address(&from, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(address, 0x3fff3fff);
  }

  /* Tests end */

  return;
}

void hdlc_decode_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* fail: null pointer */
    status_t status = hdlc_decode_address(NULL, NULL, -1);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

	if (1) { /* fail: null pointer */
		array_t from = ARRAY_FREE(NULL, 0);

    status_t status = hdlc_decode_address(&from, NULL, -1);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

	if (1) { /* fail: zero size */
		array_t from = ARRAY_FREE(NULL, 0);
		hdlc_address_t to = { 0 };

    status_t status = hdlc_decode_address(&from, &to, 0);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

	if (1) { /* fail: size larger than 4 bytes */
		array_t from = ARRAY_FREE(NULL, 0);
		hdlc_address_t to = { 0 };

    status_t status = hdlc_decode_address(&from, &to, sizeof(uint32_t) + 1);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

	if (1) { /* fail: LSB not set */
		uint8_t data[] = { 0xff, 0xfe };
		array_t from = ARRAY_USED(data, ARRAY_SIZE(data));
		hdlc_address_t to = { 0 };

    status_t status = hdlc_decode_address(&from, &to, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_INVALID);

    TEST_ASSERT_EQUAL(to.value, (uint32_t)~0);
    TEST_ASSERT_EQUAL(to.size, (uint32_t)~0);
	}

	if (1) { /* fail: invalid address size (3) */
		uint8_t data[] = { 0xff, 0xff, 0xff };
		array_t from = ARRAY_USED(data, ARRAY_SIZE(data));
		hdlc_address_t to = { 0 };

    status_t status = hdlc_decode_address(&from, &to, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_PARSE_FAIL);

    TEST_ASSERT_EQUAL(to.value, (uint32_t)~0);
    TEST_ASSERT_EQUAL(to.size, (uint32_t)~0);
	}

	if (1) { /* fail: invalid address size (3) */
		uint8_t data[] = { 0x48, 0x68, 0xfe, 0xff };
		array_t from = ARRAY_USED(data, ARRAY_SIZE(data));
		hdlc_address_t to = { 0 };

    status_t status = hdlc_decode_address(&from, &to, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to.value, 0x12343fff);
    TEST_ASSERT_EQUAL(to.size, 4);
	}

  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */

  return;
}

void hdlc_pull_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* fail: null pointer */
    status_t status = hdlc_pull_address(NULL, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  /* End of assertion test cases */

  /* Tests start*/

  if (1) { /* fail: array of data with 0 size */
    array_t from = ARRAY_USED(NULL, 0);
    hdlc_address_t to = { 0 };

    status_t status = hdlc_pull_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_ARRAY_BUFFER_OVERFLOW);
  }

  if (1) { /* fail: address with LSB not set */
    const uint8_t data[] = { 0xfe, 0xfe, 0xfe, 0xfe };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    hdlc_address_t to = { 0 };

    status_t status = hdlc_pull_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) { /* success */
    const uint8_t data[] = { 0x80, 0x41 };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));
    hdlc_address_t to = { 0 };

    status_t status = hdlc_pull_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to.value, 0x2041);
    TEST_ASSERT_EQUAL(to.size, sizeof(uint16_t));
  }

  /* Tests end */

  return;
}

void hdlc_build_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  if (1) { /* fail: null pointer */
    status_t status = hdlc_build_address(NULL, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

   if (1) { /* fail: null pointer */
    const hdlc_address_t from;

    status_t status = hdlc_build_address(&from, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  /* End of assertion test cases */

  /* Tests start*/

  if (1) { /* fail: invalid array */
    const hdlc_address_t from = { .value = (uint32_t)~0, .size = 3 };
    array_t to = { .start = 5, .end = 2, .size = 1 };

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_ARRAY_INVALID_PARAMETER);
  }

  if (1) { /* fail: not enought bytes in array */
    const hdlc_address_t from = { .value = (uint32_t)~0, .size = 3 };
    array_t to = ARRAY_FREE(NULL, 1);

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_BUFFER_OVERFLOW);
  }

  if (1) { /* fail: invalid address size (0) */
    const hdlc_address_t from = { .size = 0 };
    uint8_t data[16] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_BUILD_FAIL);
  }

  if (1) { /* fail: invalid address size (3) */
    const hdlc_address_t from = { .size = 3 };
    uint8_t data[16] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_BUILD_FAIL);
  }

  if (1) { /* fail: invalid address size (5) */
    const hdlc_address_t from = { .size = sizeof(uint32_t) + 1 };
    uint8_t data[16] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_BUILD_FAIL);
  }

  if (1) { /* success */
    const hdlc_address_t from = { .value = 0x7f, .size = 1 };
    uint8_t data[16] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(data[0], 0xff);
  }

  if (1) { /* success */
    const hdlc_address_t from = { .value = 0x3fff, .size = 2 };
    uint8_t data[8] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(data[0], 0xfe);
    TEST_ASSERT_EQUAL(data[1], 0xff);
  }

  if (1) { /* success */
    const hdlc_address_t from = { .value = 0x12343fff, .size = 4 };
    uint8_t data[8] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(data[0], 0x48);
    TEST_ASSERT_EQUAL(data[1], 0x68);
    TEST_ASSERT_EQUAL(data[2], 0xfe);
    TEST_ASSERT_EQUAL(data[3], 0xff);
  }

  if (1) { /* success */
    const hdlc_address_t from = { .value = 0x3fff3fff, .size = 4 };
    uint8_t data[8] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_build_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(data[0], 0xfe);
    TEST_ASSERT_EQUAL(data[1], 0xfe);
    TEST_ASSERT_EQUAL(data[2], 0xfe);
    TEST_ASSERT_EQUAL(data[3], 0xff);
  }

  /* Tests end */

  return;
}

void hdlc_push_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

	if (1) { /* fail: null pointer */
    status_t status = hdlc_push_address(NULL, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) { /* success */
    const hdlc_address_t from = { .value = 0x3fff3fff, .size = 4 };
    uint8_t data[8] = { 0 };
    array_t to = ARRAY_FREE(data, ARRAY_SIZE(data));

    status_t status = hdlc_push_address(&from, &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(data[0], 0xfe);
    TEST_ASSERT_EQUAL(data[1], 0xfe);
    TEST_ASSERT_EQUAL(data[2], 0xfe);
    TEST_ASSERT_EQUAL(data[3], 0xff);
  }

  /* Tests end */

  return;
}
