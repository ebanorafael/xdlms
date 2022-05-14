///@file

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* Unit Test file header files inclusion start */

#include <time.h>
#include <string.h>
#include "unity.h"

#include "xdlms-asn1-axdr-encode-tests.h"
#include "xdlms-asn1-axdr-encode.h"
#include "utils.h"

/* Unit Test file header files inclusion end */

/*******************************************************************
 * PRIVATE DEFINES
 *******************************************************************/

/* Unit Test file defines start */

/* Unit Test file defines end */

/*******************************************************************
 * PRIVATE PROTOTYPES
 *******************************************************************/

/*******************************************************************
 * PRIVATE DATA
 *******************************************************************/

/*******************************************************************
 * FUNCTIONS
 *******************************************************************/

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

void xdlms_asn1_axdr_get_size_tests(void) {
	/* Global test variables start */

	size_t size = -1;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) {
		uint8_t sizes[] = {
			[XDLMS_ASN1_AXDR_TYPE_NULL_DATA] = 0,
			[XDLMS_ASN1_AXDR_TYPE_ARRAY] = 0,
			[XDLMS_ASN1_AXDR_TYPE_STRUCTURE] = 0,
			[XDLMS_ASN1_AXDR_TYPE_BOOLEAN] = sizeof(int8_t),
			[XDLMS_ASN1_AXDR_TYPE_BIT_STRING] = 0,
			[XDLMS_ASN1_AXDR_TYPE_INT32] = sizeof(int32_t),
			[XDLMS_ASN1_AXDR_TYPE_UINT32] = sizeof(uint32_t),
			[XDLMS_ASN1_AXDR_TYPE_OCTET_STRING] = 0,
			[XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING] = 0,
			[XDLMS_ASN1_AXDR_TYPE_UTF8_STRING] = 0,
			[XDLMS_ASN1_AXDR_TYPE_BCD] = sizeof(int8_t),
			[XDLMS_ASN1_AXDR_TYPE_INT8] = sizeof(int8_t),
			[XDLMS_ASN1_AXDR_TYPE_INT16] = sizeof(int16_t),
			[XDLMS_ASN1_AXDR_TYPE_UINT8] = sizeof(uint8_t),
			[XDLMS_ASN1_AXDR_TYPE_UINT16] = sizeof(uint16_t),
			[XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY] = 0,
			[XDLMS_ASN1_AXDR_TYPE_INT64] = sizeof(int64_t),
			[XDLMS_ASN1_AXDR_TYPE_UINT64] = sizeof(uint64_t),
			[XDLMS_ASN1_AXDR_TYPE_ENUM] = sizeof(uint8_t),
			[XDLMS_ASN1_AXDR_TYPE_FLOAT32] = sizeof(float),
			[XDLMS_ASN1_AXDR_TYPE_FLOAT64] = sizeof(double),
			[XDLMS_ASN1_AXDR_TYPE_DATE_TIME] = 0,
			[XDLMS_ASN1_AXDR_TYPE_DATE] = 0,
			[XDLMS_ASN1_AXDR_TYPE_TIME] = 0,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_INT8] = 0,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_INT16] = 0,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_INT32] = 0,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_UINT8] = 0,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_UINT16] = 0,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_UINT32] = 0,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_1] = 0xff,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_2] = 0xff,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_3] = 0xff,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_4] = 0xff
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(sizes); index++) {
			xdlms_asn1_axdr_type_t tag = index;

			size = xdlms_asn1_axdr_get_size(tag);
			TEST_ASSERT_EQUAL(size, sizes[index]);
		}
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_tag_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid data type tags */
		xdlms_asn1_axdr_type_t tags[] = {
			XDLMS_ASN1_AXDR_TYPE_INVALID_1,
			XDLMS_ASN1_AXDR_TYPE_INVALID_2,
			XDLMS_ASN1_AXDR_TYPE_INVALID_3,
			XDLMS_ASN1_AXDR_TYPE_INVALID_4,
			XDLMS_ASN1_AXDR_TYPE_MAX
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(tags); index++) {
			status = xdlms_asn1_axdr_encode_tag(tags[index], NULL);
			TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* invalid output buffer 1 */
		status = xdlms_asn1_axdr_encode_tag(XDLMS_ASN1_AXDR_TYPE_NULL_DATA, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t buffer[1] = { 0 };
		array_t from = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_tag(XDLMS_ASN1_AXDR_TYPE_OCTET_STRING, &from);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], XDLMS_ASN1_AXDR_TYPE_OCTET_STRING);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_multi_byte_len_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid size */
		for (uint32_t size = 0; size < 128; size++) {
			status = xdlms_asn1_axdr_encode_multi_byte_len(size, NULL);
			TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* invalid output buffer 1 */
		status = xdlms_asn1_axdr_encode_multi_byte_len(128, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid output buffer 2 */
		array_t from = ARRAY_FREE(NULL, 0);

		status = xdlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid output buffer 3 */
		uint8_t buffer[16] = { 0 };
		array_t from = ARRAY_FREE(&buffer[0], 0);

		status = xdlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* buffer without enough space */
		uint8_t buffer[1] = { 0 };
		array_t from = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t buffer[2] = { 0 };
		array_t from = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], 0x81);
		TEST_ASSERT_EQUAL(buffer[1], 0x80);

		MEMORY_TRACE(1, buffer, 2, "Encoded (%u bytes): ", 2);
	}

	if (1) { /* success */
		uint8_t buffer[3] = { 0 };
		array_t from = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_multi_byte_len(0xf29b, &from);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], 0x82);
		TEST_ASSERT_EQUAL(buffer[1], 0xf2);
		TEST_ASSERT_EQUAL(buffer[2], 0x9b);

		MEMORY_TRACE(1, buffer, 3, "Encoded (%u bytes): ", 3);
	}

	if (1) { /* success */
		uint8_t buffer[4] = { 0 };
		array_t from = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_multi_byte_len(0x1cffff, &from);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], 0x83);
		TEST_ASSERT_EQUAL(buffer[1], 0x1c);
		TEST_ASSERT_EQUAL(buffer[2], 0xff);
		TEST_ASSERT_EQUAL(buffer[3], 0xff);

		MEMORY_TRACE(1, buffer, 4, "Encoded (%u bytes): ", 4);
	}

	if (1) { /* success */
		uint8_t buffer[5] = { 0 };
		array_t from = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_multi_byte_len(0xffffffff, &from);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], 0x84);
		TEST_ASSERT_EQUAL(buffer[1], 0xff);
		TEST_ASSERT_EQUAL(buffer[2], 0xff);
		TEST_ASSERT_EQUAL(buffer[3], 0xff);
		TEST_ASSERT_EQUAL(buffer[4], 0xff);

		MEMORY_TRACE(1, buffer, 5, "Encoded (%u bytes): ", 5);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_len_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid buffer 1 */
		status = xdlms_asn1_axdr_encode_len(0, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid buffer 2 */
		status = xdlms_asn1_axdr_encode_len(0xff, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* sucess */
		uint8_t buffer[1] = { 0 };
		array_t from = ARRAY_FREE(&buffer, sizeof(buffer));

		status = xdlms_asn1_axdr_encode_len(12, &from);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], 12);
	}

	if (1) { /* sucess */
		uint8_t buffer[4] = { 0 };
		array_t from = ARRAY_FREE(&buffer, sizeof(buffer));

		status = xdlms_asn1_axdr_encode_len(0xff80, &from);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], 0x82);
		TEST_ASSERT_EQUAL(buffer[1], 0xff);
		TEST_ASSERT_EQUAL(buffer[2], 0x80);

		MEMORY_TRACE(1, buffer, 3, "Encoded (%u bytes): ", 3);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_standard_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid data types: sequence */
		xdlms_asn1_axdr_type_t tags[] = {
			XDLMS_ASN1_AXDR_TYPE_NULL_DATA,
			XDLMS_ASN1_AXDR_TYPE_ARRAY,
			XDLMS_ASN1_AXDR_TYPE_STRUCTURE,
			XDLMS_ASN1_AXDR_TYPE_BIT_STRING,
			XDLMS_ASN1_AXDR_TYPE_OCTET_STRING,
			XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING,
			XDLMS_ASN1_AXDR_TYPE_UTF8_STRING,
			XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY,
			XDLMS_ASN1_AXDR_TYPE_DATE_TIME,
			XDLMS_ASN1_AXDR_TYPE_DATE,
			XDLMS_ASN1_AXDR_TYPE_TIME,
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(tags); index++) {
			status = xdlms_asn1_axdr_encode_standard(NULL, NULL, tags[index]);
			TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* invalid data types: invalid types */
		xdlms_asn1_axdr_type_t tags[] = {
			XDLMS_ASN1_AXDR_TYPE_INVALID_1,
			XDLMS_ASN1_AXDR_TYPE_INVALID_2,
			XDLMS_ASN1_AXDR_TYPE_INVALID_3,
			XDLMS_ASN1_AXDR_TYPE_INVALID_4,
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(tags); index++) {
			status = xdlms_asn1_axdr_encode_standard(NULL, NULL, tags[index]);
			TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* fail to encode tag */
		status = xdlms_asn1_axdr_encode_standard(NULL,
		                                        NULL,
		                                        XDLMS_ASN1_AXDR_TYPE_INT16);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* fail to encode data */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[1] = { 0 };
		array_t to = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        XDLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_EQUAL(buffer[0], XDLMS_ASN1_AXDR_TYPE_UINT32);
	}

	if (1) { /* success */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[3] = { 0 };
		array_t to = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        XDLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], XDLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_EQUAL(buffer[1], 0x02);
		TEST_ASSERT_EQUAL(buffer[2], 0x01);

		MEMORY_TRACE(1, buffer, 3, "Encoded (%u bytes): ", 3);
	}

	if (1) { /* success */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[32] = { 0 };
		array_t to = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        XDLMS_ASN1_AXDR_TYPE_INT32);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], XDLMS_ASN1_AXDR_TYPE_INT32);
		TEST_ASSERT_EQUAL(buffer[1], 0x04);
		TEST_ASSERT_EQUAL(buffer[2], 0x03);
		TEST_ASSERT_EQUAL(buffer[3], 0x02);
		TEST_ASSERT_EQUAL(buffer[4], 0x01);

		MEMORY_TRACE(1, buffer, 5, "Encoded (%u bytes): ", 5);
	}

	if (1) { /* success */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[32] = { 0 };
		array_t to = ARRAY_FREE(&buffer[0], sizeof(buffer));

		status = xdlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        XDLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(buffer[0], XDLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_EQUAL(buffer[1], 0x08);
		TEST_ASSERT_EQUAL(buffer[2], 0x07);
		TEST_ASSERT_EQUAL(buffer[3], 0x06);
		TEST_ASSERT_EQUAL(buffer[4], 0x05);
		TEST_ASSERT_EQUAL(buffer[5], 0x04);
		TEST_ASSERT_EQUAL(buffer[6], 0x03);
		TEST_ASSERT_EQUAL(buffer[7], 0x02);
		TEST_ASSERT_EQUAL(buffer[8], 0x01);

		MEMORY_TRACE(1, buffer, 9, "Encoded (%u bytes): ", 9);
	}


	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_bit_string_tests(void) {
	CONSOLE_TRACE("\nTest implementation pending!\n");

	/* Global test variables start */

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_sequence_of_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid data type tag */
		status = xdlms_asn1_axdr_encode_sequence_of(NULL,
		                                           XDLMS_ASN1_AXDR_TYPE_MAX,
		                                           0xffffffff);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* invalid output buffer */
		status = xdlms_asn1_axdr_encode_sequence_of(NULL,
		                                           XDLMS_ASN1_AXDR_TYPE_INT32,
		                                           sizeof(uint32_t));
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t out[2] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_sequence_of(&to,
		                                           XDLMS_ASN1_AXDR_TYPE_OCTET_STRING,
		                                           12);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_EQUAL(out[1], 12);

		MEMORY_TRACE(1, out, 2, "Encoded (%u bytes): ", 2);
	}

	if (1) { /* success */
		uint8_t out[3] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_sequence_of(&to,
		                                           XDLMS_ASN1_AXDR_TYPE_ARRAY,
		                                           155);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_EQUAL(out[1], 0x81);
		TEST_ASSERT_EQUAL(out[2], 155);

		MEMORY_TRACE(1, out, 3, "Encoded (%u bytes): ", 3);
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_sequence_of(&to,
		                                           XDLMS_ASN1_AXDR_TYPE_STRUCTURE,
		                                           70000);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_EQUAL(out[1], 0x83);
		TEST_ASSERT_EQUAL(out[2], 0x01);
		TEST_ASSERT_EQUAL(out[3], 0x11);
		TEST_ASSERT_EQUAL(out[4], 0x70);

		MEMORY_TRACE(1, out, 5, "Encoded (%u bytes): ", 5);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_sequence_of_bytes_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid parameters */
		status = xdlms_asn1_axdr_encode_sequence_of_bytes(NULL,
		                                                 NULL,
		                                                 XDLMS_ASN1_AXDR_TYPE_MAX);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* invalid output buffer */
		array_t from = ARRAY_USED(NULL, 12);

		uint8_t out[2] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_sequence_of_bytes(&from,
		                                                 &to,
		                                                 XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_EQUAL(out[1], 12);
	}

	if (1) { /* output buffer without enough space */
		uint8_t in[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		array_t from = ARRAY_USED(&in[0], 12);

		uint8_t out[6] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_sequence_of_bytes(&from,
		                                                 &to,
		                                                 XDLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_EQUAL(out[1], 12);
		TEST_ASSERT_EQUAL(out[2], 0);
		TEST_ASSERT_EQUAL(out[3], 0);
		TEST_ASSERT_EQUAL(out[4], 0);
		TEST_ASSERT_EQUAL(out[5], 0);
	}

	if (1) { /* output buffer without enough space */
		char in[] = { "Hello, world" };
		array_t from = ARRAY_USED(&in[0], sizeof(in));

		uint8_t out[32] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_sequence_of_bytes(&from,
		                                                 &to,
		                                                 XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		int diff = memcmp((void *)&in[2], (void *)&out, ARRAY_SIZE(in));

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_EQUAL(out[1], 13);
		TEST_ASSERT_EQUAL(diff, 0);

		MEMORY_TRACE(1, out, 15, "Encoded (%u bytes): ", 15);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_compact_array_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid output buffer */
		status = xdlms_asn1_axdr_encode_compact_array(NULL, NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid input template buffer */
		uint8_t out[4];
		array_t to = ARRAY_FREE(&out, sizeof(out));

		status = xdlms_asn1_axdr_encode_compact_array(NULL, NULL, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid input contents buffer 1 */
		uint8_t in_tpl[] = {
			XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 4,
			  XDLMS_ASN1_AXDR_TYPE_INT8,
			  XDLMS_ASN1_AXDR_TYPE_UINT64,
			  XDLMS_ASN1_AXDR_TYPE_UINT32,
			  XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING
		};
		array_t from_tpl = ARRAY_USED(&in_tpl, sizeof(in_tpl));

		uint8_t out[7];
		array_t to = ARRAY_FREE(&out, sizeof(out));

		status = xdlms_asn1_axdr_encode_compact_array(&from_tpl, NULL, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_EQUAL(out[1], XDLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_EQUAL(out[2], 4);
		TEST_ASSERT_EQUAL(out[3], XDLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_EQUAL(out[4], XDLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_EQUAL(out[5], XDLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_EQUAL(out[6], XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
	}

	if (1) { /* invalid input contents buffer 2 */
		uint8_t in_tpl[] = {
			XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 4,
			  XDLMS_ASN1_AXDR_TYPE_INT8,
			  XDLMS_ASN1_AXDR_TYPE_UINT64,
			  XDLMS_ASN1_AXDR_TYPE_UINT32,
			  XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING
		};
		array_t from_tpl = ARRAY_USED(&in_tpl, sizeof(in_tpl));
		array_t from_contents = ARRAY_USED(NULL, 2);

		uint8_t out[8];
		array_t to = ARRAY_FREE(&out, sizeof(out));

		status = xdlms_asn1_axdr_encode_compact_array(&from_tpl, &from_contents, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_EQUAL(out[1], XDLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_EQUAL(out[2], 4);
		TEST_ASSERT_EQUAL(out[3], XDLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_EQUAL(out[4], XDLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_EQUAL(out[5], XDLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_EQUAL(out[6], XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_EQUAL(out[7], 2);
	}

	if (1) { /* success */
		uint8_t in_tpl[] = {
			XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 4,
			  XDLMS_ASN1_AXDR_TYPE_INT8,
			  XDLMS_ASN1_AXDR_TYPE_UINT64,
			  XDLMS_ASN1_AXDR_TYPE_UINT32,
			  XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING
		};
		array_t from_tpl = ARRAY_USED(&in_tpl, sizeof(in_tpl));

		uint8_t in_contents[] = {
			0x01,
			0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01,
			0x00, 0x00, 0x00, 0x02,
			4, 'd', 'l', 'm', 's'
		};
		array_t from_contents = ARRAY_USED(&in_contents, sizeof(in_contents));

		uint8_t out[32];
		array_t to = ARRAY_FREE(&out, sizeof(out));

		status = xdlms_asn1_axdr_encode_compact_array(&from_tpl, &from_contents, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_EQUAL(out[1], XDLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_EQUAL(out[2], 4);
		TEST_ASSERT_EQUAL(out[3], XDLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_EQUAL(out[4], XDLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_EQUAL(out[5], XDLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_EQUAL(out[6], XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_EQUAL(out[7], sizeof(in_contents));

		MEMORY_TRACE(1, out, 8, "Encoded (%u bytes): ", 8);
	}

	if (1) { /* success */
		uint8_t in_tpl[] = {
			XDLMS_ASN1_AXDR_TYPE_UINT32,
		};
		array_t from_tpl = ARRAY_USED(&in_tpl, sizeof(in_tpl));

		uint8_t in_contents[] = {
			0x00, 0x00, 0x00, 0x01,
			0x00, 0x00, 0x00, 0x02,
			0x00, 0x00, 0x00, 0x03,
			0x00, 0x00, 0x00, 0x04,
			0x00, 0x00, 0x00, 0x05,
		};
		array_t from_contents = ARRAY_USED(&in_contents, sizeof(in_contents));

		uint8_t out[32];
		array_t to = ARRAY_FREE(&out, sizeof(out));

		status = xdlms_asn1_axdr_encode_compact_array(&from_tpl, &from_contents, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_EQUAL(out[1], XDLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_EQUAL(out[2], sizeof(in_contents));

		MEMORY_TRACE(1, out, 3 + ARRAY_SIZE(in_contents), "Encoded (%u bytes): ",
			3 + ARRAY_SIZE(in_contents));
	}

	/* Tests end */

	return;
}

void xdlms_ans1_axdr_encode_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) {
		status = xdlms_asn1_axdr_encode(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid tag */
		xdlms_asn1_axdr_resource_t from = {
			.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_MAX, .len = 0 },
			.data = { .contents.p_sequence = NULL }
		};
		status = xdlms_asn1_axdr_encode(&from, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_NULL;

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_NULL_DATA);

		MEMORY_TRACE(1, out, 1, "Encoded (%u bytes): ", 1);
	}

	if (1) { /* success: array */
		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_ARRAY(0x3fff);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_EQUAL(out[1], 0x82);
		TEST_ASSERT_EQUAL(out[2], 0x3f);
		TEST_ASSERT_EQUAL(out[3], 0xff);

		MEMORY_TRACE(1, out, 4, "Encoded (%u bytes): ", 4);
	}

	if (1) { /* success: structure */
		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(8);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_EQUAL(out[1], 0x08);

		MEMORY_TRACE(1, out, 2, "Encoded (%u bytes): ", 2);
	}

	if (1) { /* fail: bit-string */

	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		uint8_t in[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		array_t seq = ARRAY_USED(&in[0], sizeof(in));
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_OCTET(&seq);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_EQUAL(out[1], 12);
		TEST_ASSERT_EQUAL(out[2], 1);
		TEST_ASSERT_EQUAL(out[3], 2);
		TEST_ASSERT_EQUAL(out[4], 3);
		TEST_ASSERT_EQUAL(out[5], 4);
		TEST_ASSERT_EQUAL(out[6], 5);
		TEST_ASSERT_EQUAL(out[7], 6);
		TEST_ASSERT_EQUAL(out[8], 7);
		TEST_ASSERT_EQUAL(out[9], 8);
		TEST_ASSERT_EQUAL(out[10], 9);
		TEST_ASSERT_EQUAL(out[11], 10);
		TEST_ASSERT_EQUAL(out[12], 11);
		TEST_ASSERT_EQUAL(out[13], 12);

		MEMORY_TRACE(1, out, 14, "Encoded (%u bytes): ", 14);
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		char in[] = { "Hello, world" };
		array_t seq = ARRAY_USED(&in[0], sizeof(in));
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_VISIBLE(&seq);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_EQUAL(out[1], 13);
		TEST_ASSERT_EQUAL(out[2], 'H');
		TEST_ASSERT_EQUAL(out[3], 'e');
		TEST_ASSERT_EQUAL(out[4], 'l');
		TEST_ASSERT_EQUAL(out[5], 'l');
		TEST_ASSERT_EQUAL(out[6], 'o');
		TEST_ASSERT_EQUAL(out[7], ',');
		TEST_ASSERT_EQUAL(out[8], ' ');
		TEST_ASSERT_EQUAL(out[9], 'w');
		TEST_ASSERT_EQUAL(out[10], 'o');
		TEST_ASSERT_EQUAL(out[11], 'r');
		TEST_ASSERT_EQUAL(out[12], 'l');
		TEST_ASSERT_EQUAL(out[13], 'd');
		TEST_ASSERT_EQUAL(out[14], '\0');

		MEMORY_TRACE(1, out, 2 + ARRAY_SIZE(in), "Encoded (%u bytes): ", 2 + ARRAY_SIZE(in));
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		char in[] = { "Hello, world" };
		array_t seq = ARRAY_USED(&in[0], sizeof(in));
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_UTF8_STRING(&seq);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_UTF8_STRING);
		TEST_ASSERT_EQUAL(out[1], 13);
		TEST_ASSERT_EQUAL(out[2], 'H');
		TEST_ASSERT_EQUAL(out[3], 'e');
		TEST_ASSERT_EQUAL(out[4], 'l');
		TEST_ASSERT_EQUAL(out[5], 'l');
		TEST_ASSERT_EQUAL(out[6], 'o');
		TEST_ASSERT_EQUAL(out[7], ',');
		TEST_ASSERT_EQUAL(out[8], ' ');
		TEST_ASSERT_EQUAL(out[9], 'w');
		TEST_ASSERT_EQUAL(out[10], 'o');
		TEST_ASSERT_EQUAL(out[11], 'r');
		TEST_ASSERT_EQUAL(out[12], 'l');
		TEST_ASSERT_EQUAL(out[13], 'd');
		TEST_ASSERT_EQUAL(out[14], '\0');

		MEMORY_TRACE(1, out, 2 + ARRAY_SIZE(in), "Encoded (%u bytes): ", 2 + ARRAY_SIZE(in));
	}

	if (1) { /* fail: compact-array not implemented yet */

	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		int8_t in = -0x3f;
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_INT8(&in);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_EQUAL(out[1], (uint8_t)-0x3f);

		MEMORY_TRACE(1, out, 2, "Encoded (%u bytes): ", 2);
	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		uint16_t in = 0xff20;
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_UINT16(&in);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_EQUAL(out[1], 0xff);
		TEST_ASSERT_EQUAL(out[2], 0x20);

		MEMORY_TRACE(1, out, 3, "Encoded (%u bytes): ", 3);
	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		uint32_t in = 0x803cff20;
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_UINT32(&in);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_EQUAL(out[1], 0x80);
		TEST_ASSERT_EQUAL(out[2], 0x3c);
		TEST_ASSERT_EQUAL(out[3], 0xff);
		TEST_ASSERT_EQUAL(out[4], 0x20);

		MEMORY_TRACE(1, out, 5, "Encoded (%u bytes): ", 5);
	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		uint64_t in = 0xffffffff01020304;
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_UINT64(&in);

		status = xdlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(out[0], XDLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_EQUAL(out[1], 0xff);
		TEST_ASSERT_EQUAL(out[2], 0xff);
		TEST_ASSERT_EQUAL(out[3], 0xff);
		TEST_ASSERT_EQUAL(out[4], 0xff);
		TEST_ASSERT_EQUAL(out[5], 0x01);
		TEST_ASSERT_EQUAL(out[6], 0x02);
		TEST_ASSERT_EQUAL(out[7], 0x03);
		TEST_ASSERT_EQUAL(out[8], 0x04);

		MEMORY_TRACE(1, out, 9, "Encoded (%u bytes): ", 9);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_encode_list_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) {
		status = xdlms_asn1_axdr_encode_list(NULL, NULL, 0);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) {
		xdlms_asn1_axdr_resource_t from = XDLMS_ASN1_AXDR_ENCODE_NULL;

		status = xdlms_asn1_axdr_encode_list(&from, NULL, 1);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint16_t data[] = { 1, 2, 3 };
		xdlms_asn1_axdr_resource_t from[] = {
			[0] = XDLMS_ASN1_AXDR_ENCODE_ARRAY(ARRAY_SIZE(data)),
			[1] = XDLMS_ASN1_AXDR_ENCODE_UINT16(&data[0]),
			[2] = XDLMS_ASN1_AXDR_ENCODE_UINT16(&data[1]),
			[3] = XDLMS_ASN1_AXDR_ENCODE_UINT16(&data[2])
		};

		uint8_t out[16] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		MEMORY_TRACE(1, out, 11, "Encoded (%u bytes): ", 11);
	}

	if (1) { /* success */
		typedef struct event_t {
			uint32_t time;
			uint32_t code;
			uint32_t ctxt;
			uint32_t crc32;
		} event_t;

		event_t event[] = {
			[0] = { .time = 0x01, .code = 0x02, .ctxt = 0x00, .crc32 = 0x00ff },
			[1] = { .time = 0x02, .code = 0x02, .ctxt = 0x00, .crc32 = 0xff00 }
		};

		xdlms_asn1_axdr_resource_t from[] = {
			XDLMS_ASN1_AXDR_ENCODE_ARRAY(ARRAY_SIZE(event)),
			  XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(4), /* statically defined, but not by ARRAY_SIZE macro! */
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].time),
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].code),
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].ctxt),
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].crc32),
			  XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(4), /* statically defined, but not by ARRAY_SIZE macro! */
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].time),
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].code),
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].ctxt),
			    XDLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].crc32),
		};

		uint8_t out[128] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		MEMORY_TRACE(1, out, 46, "Encoded (%u bytes): ", 46);
	}

	if (1) { /* success */
		typedef struct data_t {
			uint8_t index;
			char string[8];
		} data_t;

		data_t event[] = {
			[0] = { .index = 0, .string = { "dlms" } },
			[1] = { .index = 1, .string = { "cosem" } },
			[2] = { .index = 2, .string = { "hello" } },
			[3] = { .index = 3, .string = { "world" } },
		};

		array_t array_list[] = {
			ARRAY_USED(&event[0].string[0], sizeof("dlms") - 1),
			ARRAY_USED(&event[1].string[0], sizeof("cosem") - 1),
			ARRAY_USED(&event[2].string[0], sizeof("hello") - 1),
			ARRAY_USED(&event[3].string[0], sizeof("world") - 1),
		};

		xdlms_asn1_axdr_resource_t from[] = {
			XDLMS_ASN1_AXDR_ENCODE_ARRAY(ARRAY_SIZE(event)),
			  XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    XDLMS_ASN1_AXDR_ENCODE_UINT8(&event[0].index),
			    XDLMS_ASN1_AXDR_ENCODE_VISIBLE(&array_list[0]),
			  XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    XDLMS_ASN1_AXDR_ENCODE_UINT8(&event[1].index),
			    XDLMS_ASN1_AXDR_ENCODE_VISIBLE(&array_list[1]),
			  XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    XDLMS_ASN1_AXDR_ENCODE_UINT8(&event[2].index),
			    XDLMS_ASN1_AXDR_ENCODE_VISIBLE(&array_list[2]),
			  XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    XDLMS_ASN1_AXDR_ENCODE_UINT8(&event[3].index),
			    XDLMS_ASN1_AXDR_ENCODE_VISIBLE(&array_list[3]),
		};

		uint8_t out[128] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		status = xdlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		MEMORY_TRACE(1, out, 57, "Encoded (%u bytes): ", 57);
	}

	if (1) { /* success */
		typedef struct data_t {
			uint8_t index;
			uint32_t code;
		} data_t;

		uint8_t out[128] = { 0 };
		array_t to = ARRAY_FREE(&out[0], sizeof(out));

		data_t in = {
			.index = 0, .code = 0x80
		};

		if (1) { /* wrong: find a better way! */
			xdlms_asn1_axdr_resource_t from[1] = { XDLMS_ASN1_AXDR_ENCODE_ARRAY(128/5) };

			status = xdlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
			TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);
		}

		while(status == STATUS_SUCCESS) {
			xdlms_asn1_axdr_resource_t from[] = {
				XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(2),
				  XDLMS_ASN1_AXDR_ENCODE_UINT8(&in.index),
				  XDLMS_ASN1_AXDR_ENCODE_UINT32(&in.code),
			};

			status = xdlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));

			in.index += 1;
			in.code += 2;
		}

//		MEMORY_TRACE(1, &to, "Encoded data [array, %u]", 0);
	}

	if (1) { /* success */
		uint8_t template[] = { XDLMS_ASN1_AXDR_TYPE_UINT64 };
		array_t from_template = ARRAY_USED(&template, sizeof(template));

		uint64_t contents[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		array_t from_contents = ARRAY_FREE(&contents, sizeof(contents));

		uint8_t out[128] = { 0 };
		array_t to = ARRAY_FREE(&out, sizeof(out));

		for (uint32_t index = 0; index < ARRAY_SIZE(contents); index++) {
			uint64_t temp = contents[index];
			(void) array_push_hton((uint8_t *)&temp, &from_contents, sizeof(temp));
		}

		xdlms_asn1_axdr_resource_t from[] = {
			[0] = {
				.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY, .len = 0 },
				.data = { .p_template = &from_template, .contents.p_sequence = &from_contents }
			}
		};

		status = xdlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

//		MEMORY_TRACE(1, &to, 67, "Encoded data [octet, %u]", 67);
	}

	/* Tests end */

	return;
}
