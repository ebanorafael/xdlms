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
    TEST_ASSERT_EQUAL(address, (uint32_t)-1);
  }

  if (1) { /* invalid size: 3 */
    uint8_t data[] =  { 0xff, 0xff, 0xff };
    array_t from = ARRAY_USED(data, ARRAY_SIZE(data));

    uint32_t address = hdlc_parse_address(&from, ARRAY_SIZE(data));
    TEST_ASSERT_EQUAL(address, (uint32_t)-1);
  }

	if (1) { /* invalid size: 5 */
    uint32_t address = hdlc_parse_address(NULL, sizeof(uint32_t) + 1);
    TEST_ASSERT_EQUAL(address, (uint32_t)-1);
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
#if 0
  if (1) {
    status_t status = hdlc_decode_address(0, NULL, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) {
    uint8_t from[1];

    status_t status = hdlc_decode_address(0, &from[0], NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) {
    uint8_t from[5];
    hdlc_address_t to;

    status_t status = hdlc_decode_address(ARRAY_SIZE(from), &from[0], &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) {
    uint8_t from[] = { 0xfe, 0xfe, 0xfe, 0xfe };

    for (size_t size = 1; size <= sizeof(uint32_t); size <<= 1) {
      hdlc_address_t to = { 0 };

      status_t status = hdlc_decode_address(ARRAY_SIZE(from), &from[0], &to);
      TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_INVALID);

      TEST_ASSERT_EQUAL(to.address, 0xffffffff);
      TEST_ASSERT_EQUAL(to.size, 0xffffffff);
    }
  }

  if (1) {
    uint8_t from[] = { 0xfe, 0xfe, 0xff };
    hdlc_address_t to = { 0 };

    status_t status = hdlc_decode_address(ARRAY_SIZE(from), &from[0], &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_PARSE_FAIL);

    TEST_ASSERT_EQUAL(to.address, 0xffffffff);
    TEST_ASSERT_EQUAL(to.size, 0xffffffff);
  }

  if (1) {
    uint8_t from[] = { 0x48, 0x68, 0xfe, 0xff };
    hdlc_address_t to = { 0 };

    status_t status = hdlc_decode_address(ARRAY_SIZE(from), &from[0], &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to.address, 0x12343fff);
    TEST_ASSERT_EQUAL(to.size, sizeof(uint32_t));
  }

#endif
  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */

  return;
}

void hdlc_pull_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */
#if 0
  if (1) {
    status_t status = hdlc_pull_address(NULL, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) {
    const uint8_t from[] = { 0xfe, 0xfe, 0xfe, 0xfe };
    hdlc_address_t to = { 0 };

    status_t status = hdlc_pull_address(&from[0], &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) {
    const uint8_t from[] = { 0xfe, 0xfe, 0xfe, 0xfe };
    hdlc_address_t to = { 0 };

    status_t status = hdlc_pull_address(&from[0], &to);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (1) {
    const uint8_t from[] = { 0x80, 0x41 };
    hdlc_address_t to = { 0 };

    status_t status = hdlc_pull_address(&from[0], &to);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to.address, 0x2041);
    TEST_ASSERT_EQUAL(to.size, sizeof(uint16_t));
  }
#endif
  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */

  return;
}

void hdlc_build_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

#if 0

  if (0) { /* null pointer */
    status_t status = hdlc_build_address(NULL, 0, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

   if (0) { /* null pointer */
    const hdlc_address_t from;

    status_t status = hdlc_build_address(&from, 0, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

#endif
  /* End of assertion test cases */

  /* Tests start*/

#if 0
  if (0) { /* invalid address size: 5 */
    const hdlc_address_t from = { .size = 5 };
    uint8_t to[1];

    status_t status = hdlc_build_address(&from, ARRAY_SIZE(to), &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (0) { /* address size larger than buffer to hold it */
    const hdlc_address_t from = { .size = 4 };
    uint8_t to[2];

    status_t status = hdlc_build_address(&from, ARRAY_SIZE(to), &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_BUFFER_OVERFLOW);
  }

  if (0) { /* invalid address sizes: 0 and 3 */
    hdlc_address_t from;
    uint8_t to[2];
    status_t status;

    from.size = 0;
    status = hdlc_build_address(&from, from.size, &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_BUILD_FAIL);

    from.size = 3;
    status = hdlc_build_address(&from, from.size, &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_ADDRESS_BUILD_FAIL);
  }

  if (1) { /* success */
    const hdlc_address_t from = { .size = 1, .address = 0x7f };
    uint8_t to[8] = { 0 };

    status_t status = hdlc_build_address(&from, ARRAY_SIZE(to), &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to[0], 0xff);
  }

  if (0) { /* success */
    const hdlc_address_t from = { .size = 2, .address = 0x3fff };
    uint8_t to[8] = { 0 };

    status_t status = hdlc_build_address(&from, ARRAY_SIZE(to), &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to[0], 0xfe);
    TEST_ASSERT_EQUAL(to[1], 0xff);
  }

  if (0) { /* success */
    const hdlc_address_t from = { .size = 4, .address = 0x12343fff };
    uint8_t to[8] = { 0 };

    status_t status = hdlc_build_address(&from, ARRAY_SIZE(to), &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to[0], 0x48);
    TEST_ASSERT_EQUAL(to[1], 0x68);
    TEST_ASSERT_EQUAL(to[2], 0xfe);
    TEST_ASSERT_EQUAL(to[3], 0xff);
  }

  if (0) { /* success */
    const hdlc_address_t from = { .size = 4, .address = 0x3fff3fff };
    uint8_t to[8] = { 0 };

    status_t status = hdlc_build_address(&from, ARRAY_SIZE(to), &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to[0], 0xfe);
    TEST_ASSERT_EQUAL(to[1], 0xfe);
    TEST_ASSERT_EQUAL(to[2], 0xfe);
    TEST_ASSERT_EQUAL(to[3], 0xff);
  }
#endif
  /* Tests end */

  return;
}

void hdlc_push_address_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/
#if 0
  if (0) {
    status_t status = hdlc_push_address(NULL, 0, NULL);
    TEST_ASSERT_EQUAL(status, STATUS_HDLC_INVALID_PARAMETER);
  }

  if (0) { /* success */
    const hdlc_address_t from = { .size = 4, .address = 0x3fff3fff };
    uint8_t to[8] = { 0 };

    status_t status = hdlc_push_address(&from, ARRAY_SIZE(to), &to[0]);
    TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

    TEST_ASSERT_EQUAL(to[0], 0xfe);
    TEST_ASSERT_EQUAL(to[1], 0xfe);
    TEST_ASSERT_EQUAL(to[2], 0xfe);
    TEST_ASSERT_EQUAL(to[3], 0xff);
  }
#endif
  /* Tests end */

  return;
}
