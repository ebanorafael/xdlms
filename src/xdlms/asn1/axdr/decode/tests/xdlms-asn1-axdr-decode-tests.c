///@file

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* Unit Test file header files inclusion start */

#include <time.h>
#include <string.h>
#include "unity.h"

#include "xdlms-asn1-axdr-decode-tests.h"
#include "xdlms-asn1-axdr-decode.h"
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


void xdlms_asn1_axdr_decode_tag_tests(void) {
	/* Global test variables start */

	xdlms_asn1_axdr_type_t type = XDLMS_ASN1_AXDR_TYPE_NULL_DATA;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid controlled buffer 1 */
		type = xdlms_asn1_axdr_decode_tag(NULL);
		TEST_ASSERT_EQUAL(type, XDLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) { /* invalid controlled buffer 2 */
		array_t from = ARRAY_FREE(NULL, 0);

		type = xdlms_asn1_axdr_decode_tag(&from);
		TEST_ASSERT_EQUAL(type, XDLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) { /* invalid controlled buffer 3 */
		uint8_t buffer[16];
		array_t from = ARRAY_FREE(&buffer, 0);

		type = xdlms_asn1_axdr_decode_tag(&from);
		TEST_ASSERT_EQUAL(type, XDLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) { /* invalid controlled buffer 3 */
		uint8_t buffer[16];
		array_t from = ARRAY_FREE(&buffer, 0);

		type = xdlms_asn1_axdr_decode_tag(&from);
		TEST_ASSERT_EQUAL(type, XDLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) {
		uint8_t rets[] = {
			[XDLMS_ASN1_AXDR_TYPE_NULL_DATA] = XDLMS_ASN1_AXDR_TYPE_NULL_DATA,
			[XDLMS_ASN1_AXDR_TYPE_ARRAY] = XDLMS_ASN1_AXDR_TYPE_ARRAY,
			[XDLMS_ASN1_AXDR_TYPE_STRUCTURE] = XDLMS_ASN1_AXDR_TYPE_STRUCTURE,
			[XDLMS_ASN1_AXDR_TYPE_BOOLEAN] = XDLMS_ASN1_AXDR_TYPE_BOOLEAN,
			[XDLMS_ASN1_AXDR_TYPE_BIT_STRING] = XDLMS_ASN1_AXDR_TYPE_BIT_STRING,
			[XDLMS_ASN1_AXDR_TYPE_INT32] = XDLMS_ASN1_AXDR_TYPE_INT32,
			[XDLMS_ASN1_AXDR_TYPE_UINT32] = XDLMS_ASN1_AXDR_TYPE_UINT32,
			[XDLMS_ASN1_AXDR_TYPE_OCTET_STRING] = XDLMS_ASN1_AXDR_TYPE_OCTET_STRING,
			[XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING] = XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING,
			[XDLMS_ASN1_AXDR_TYPE_UTF8_STRING] = XDLMS_ASN1_AXDR_TYPE_UTF8_STRING,
			[XDLMS_ASN1_AXDR_TYPE_BCD] = XDLMS_ASN1_AXDR_TYPE_BCD,
			[XDLMS_ASN1_AXDR_TYPE_INT8] = XDLMS_ASN1_AXDR_TYPE_INT8,
			[XDLMS_ASN1_AXDR_TYPE_INT16] = XDLMS_ASN1_AXDR_TYPE_INT16,
			[XDLMS_ASN1_AXDR_TYPE_UINT8] = XDLMS_ASN1_AXDR_TYPE_UINT8,
			[XDLMS_ASN1_AXDR_TYPE_UINT16] = XDLMS_ASN1_AXDR_TYPE_UINT16,
			[XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY] = XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY,
			[XDLMS_ASN1_AXDR_TYPE_INT64] = XDLMS_ASN1_AXDR_TYPE_INT64,
			[XDLMS_ASN1_AXDR_TYPE_UINT64] = XDLMS_ASN1_AXDR_TYPE_UINT64,
			[XDLMS_ASN1_AXDR_TYPE_ENUM] = XDLMS_ASN1_AXDR_TYPE_ENUM,
			[XDLMS_ASN1_AXDR_TYPE_FLOAT32] = XDLMS_ASN1_AXDR_TYPE_FLOAT32,
			[XDLMS_ASN1_AXDR_TYPE_FLOAT64] = XDLMS_ASN1_AXDR_TYPE_FLOAT64,
			[XDLMS_ASN1_AXDR_TYPE_DATE_TIME] = XDLMS_ASN1_AXDR_TYPE_DATE_TIME,
			[XDLMS_ASN1_AXDR_TYPE_DATE] = XDLMS_ASN1_AXDR_TYPE_DATE,
			[XDLMS_ASN1_AXDR_TYPE_TIME] = XDLMS_ASN1_AXDR_TYPE_TIME,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_INT8] = XDLMS_ASN1_AXDR_TYPE_DELTA_INT8,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_INT16] = XDLMS_ASN1_AXDR_TYPE_DELTA_INT16,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_INT32] = XDLMS_ASN1_AXDR_TYPE_DELTA_INT32,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_UINT8] = XDLMS_ASN1_AXDR_TYPE_DELTA_UINT8,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_UINT16] = XDLMS_ASN1_AXDR_TYPE_DELTA_UINT16,
			[XDLMS_ASN1_AXDR_TYPE_DELTA_UINT32] = XDLMS_ASN1_AXDR_TYPE_DELTA_UINT32,
			[XDLMS_ASN1_AXDR_TYPE_MAX] = XDLMS_ASN1_AXDR_TYPE_MAX,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_1] = XDLMS_ASN1_AXDR_TYPE_MAX,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_2] = XDLMS_ASN1_AXDR_TYPE_MAX,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_3] = XDLMS_ASN1_AXDR_TYPE_MAX,
			[XDLMS_ASN1_AXDR_TYPE_INVALID_4] = XDLMS_ASN1_AXDR_TYPE_MAX,
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(rets); index++) {
			uint8_t buffer[1] = { index };
			array_t from = ARRAY_USED(&buffer, sizeof(buffer));

			type = xdlms_asn1_axdr_decode_tag(&from);
			TEST_ASSERT_EQUAL(type, rets[index]);
		}
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_decode_len_tests(void) {
	/* Global test variables start */

	size_t size = 0;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid controlled buffer 1 */
		size = xdlms_asn1_axdr_decode_len(NULL);
		TEST_ASSERT_EQUAL(size, -1);
	}

	if (1) { /* invalid controlled buffer 2 */
		array_t from = ARRAY_FREE(NULL, 0);

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, -1);
	}

	if (1) { /* invalid controlled buffer 3 */
		uint8_t buffer[16];
		array_t from = ARRAY_FREE(&buffer, 0);

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, -1);
	}

	if (1) { /* size less than 0x80 */
		uint8_t sizes[] = { 0, 12, 59, 72, 103, 99, 125, 127 };
		for (uint32_t index = 0; index < ARRAY_SIZE(sizes); index++) {
			uint8_t buffer[1] = { sizes[index] };
			array_t from = ARRAY_USED(&buffer, sizeof(buffer));

			size = xdlms_asn1_axdr_decode_len(&from);
			TEST_ASSERT_EQUAL(size, sizes[index]);
		}
	}

	if (1) { /* size larger than 4GB */
		uint8_t buffer[] = { 0x85 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, -1);
	}

	if (1) { /* not enough bytes in buffer */
		uint8_t buffer[] = { 0x81 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, -1);
	}

	if (1) { /* not enough bytes in buffer */
		uint8_t buffer[] = { 0x82, 1 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, -1);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x81, 1 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, 1);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x80, 0x01 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, 0);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x82, 0x01, 0x00 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, 256);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x82, 0xf1, 0x3d };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, 0xf13d);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x83, 0x72, 0xd0, 0x00 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, 0x72d000);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x84, 0x12, 0xb8, 0x00, 0x00 };
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, 0x12b80000);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x84, 0xff, 0xff, 0xff, 0xff};
		array_t from = ARRAY_USED(&buffer, sizeof(buffer));

		size = xdlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_EQUAL(size, 0xffffffff);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_decode_standard_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* invalid input data */
		status = xdlms_asn1_axdr_decode_standard(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* fail: tag decoding fail */
		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = xdlms_asn1_axdr_decode_standard(NULL, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* fail: invalid tag */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_INVALID_3 };
		array_t from = ARRAY_USED(&in, sizeof(in));

		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = xdlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* fail: sequence data instead of standard data */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_OCTET_STRING };
		array_t from = ARRAY_USED(&in, sizeof(in));

		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = xdlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* fail: invalid output buffer */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_UINT8, 0x01 };
		array_t from = ARRAY_USED(&in, sizeof(in));

		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = xdlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_UINT8);
		TEST_ASSERT_EQUAL(to.meta.len, sizeof(uint8_t));
	}

	if (1) { /* fail: not enough input data */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_INT32, 0x01, 0x02, 0x03 };
		array_t from = ARRAY_USED(&in, sizeof(in));

		int32_t out = 0;
		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(&out);

		status = xdlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_INT32);
		TEST_ASSERT_EQUAL(to.meta.len, sizeof(out));
	}

	if (1) { /* fail: not enough input data */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_UINT16, 0x80, 0x00 };
		array_t from = ARRAY_USED(&in, sizeof(in));

		uint16_t out = 0;
		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(&out);

		status = xdlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_EQUAL(to.meta.len, sizeof(out));
		TEST_ASSERT_EQUAL(out, 0x8000);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_decode_sequence_of_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	if (1) { /* NULL pointer */
		status = xdlms_asn1_axdr_decode_sequence_of(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input data */
		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode_sequence_of(NULL, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_MAX);
		TEST_ASSERT_EQUAL(to.meta.len, -1);
	}

	if (1) { /* success */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_INT16, 0x3f, 0xff };
		array_t from = ARRAY_USED(&in[0], sizeof(in));

		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_INT16);
		TEST_ASSERT_EQUAL(to.meta.len, sizeof(uint16_t));
	}

	if (1) { /* success */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_NULL_DATA };
		array_t from = ARRAY_USED(&in[0], sizeof(in));

		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_NULL_DATA);
		TEST_ASSERT_EQUAL(to.meta.len, 0);
	}

	if (1) { /* fail: length decoding fail */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY };
		array_t from = ARRAY_USED(&in[0], sizeof(in));

		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_EQUAL(to.meta.len, 0);
	}

	if (1) { /* success */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_OCTET_STRING, 0x82, 0x01, 0x00 };
		array_t from = ARRAY_USED(&in[0], sizeof(in));

		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_EQUAL(to.meta.len, 256);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_decode_sequence_of_bytes_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input parameter */
		status = xdlms_asn1_axdr_decode_sequence_of_bytes(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* invalid input parameter */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 13 };

		array_t from = ARRAY_USED(&in[0], sizeof(in));
		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = xdlms_asn1_axdr_decode_sequence_of_bytes(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* success */
		uint8_t in[] = {
			XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 12,
			'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd'
		};
		array_t from = ARRAY_USED(&in, sizeof(in));

		uint8_t out[16] = { 0 };
		array_t seq = ARRAY_FREE(&out, sizeof(out));

		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(&seq);

		status = xdlms_asn1_axdr_decode_sequence_of_bytes(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		MODULE_TRACE(1, "Decoded (%u bytes): %s.\n", array_used(&seq), seq.p_array);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_decode_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* null output data pointer */
		status = xdlms_asn1_axdr_decode(NULL, NULL);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* null input data pointer */
		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode(NULL, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input buffer */
		xdlms_asn1_axdr_resource_t to;
		array_t from = ARRAY_USED(NULL, 0);

		status = xdlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* success */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_NULL_DATA };
		array_t from = ARRAY_USED(&in, sizeof(in));

		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_NULL_DATA);
		TEST_ASSERT_EQUAL(to.meta.len, 0);
	}

	if (1) { /* success */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_ARRAY, 0x81, 233 };
		array_t from = ARRAY_USED(&in, sizeof(in));

		xdlms_asn1_axdr_resource_t to;

		status = xdlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_EQUAL(to.meta.len, 233);
	}

	if (1) { /* success */
		uint8_t in[] = {
			XDLMS_ASN1_AXDR_TYPE_OCTET_STRING, 12,
			'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd'
		};
		array_t from = ARRAY_USED(&in, sizeof(in));

		uint8_t out[16] = { 0 };
		array_t seq = ARRAY_FREE(&out, sizeof(out));
		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(&seq);

		status = xdlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_EQUAL(to.meta.len, 12);
		TEST_ASSERT_EQUAL(out[0], 'H');
		TEST_ASSERT_EQUAL(out[1], 'e');
		TEST_ASSERT_EQUAL(out[2], 'l');
		TEST_ASSERT_EQUAL(out[3], 'l');
		TEST_ASSERT_EQUAL(out[4], 'o');
		TEST_ASSERT_EQUAL(out[5], ',');
		TEST_ASSERT_EQUAL(out[6], ' ');
		TEST_ASSERT_EQUAL(out[7], 'W');
		TEST_ASSERT_EQUAL(out[8], 'o');
		TEST_ASSERT_EQUAL(out[9], 'r');
		TEST_ASSERT_EQUAL(out[10], 'l');
		TEST_ASSERT_EQUAL(out[11], 'd');

		MODULE_TRACE(1, "Decoded (%u bytes): %s.\n",
			array_used(&seq), seq.p_array);

	}

	if (1) { /* success */
		uint8_t in[] = {
			XDLMS_ASN1_AXDR_TYPE_INT64,
			0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01
		};
		array_t from = ARRAY_USED(&in, sizeof(in));

		int64_t out = 0;
		xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(&out);

		status = xdlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to.meta.tag, XDLMS_ASN1_AXDR_TYPE_INT64);
		TEST_ASSERT_EQUAL(to.meta.len, sizeof(int64_t));
		TEST_ASSERT_EQUAL(out, 0x0807060504030201);

		MODULE_TRACE(1, "Decoded (%u bytes): 0x%016llx.\n", sizeof(out), out);
	}

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_decode_validate_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

  if (1) { /* invalid input buffer */
  	status = xdlms_asn1_axdr_decode_validate(NULL, NULL);
  	TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
  }

  if (1) { /* invalid input data descriptor */
  	array_t from = ARRAY_USED(NULL, 0);

  	status = xdlms_asn1_axdr_decode_validate(&from, NULL);
  	TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
  }

	/* End of assertion test cases */

	/* Tests start*/

  if (1) { /* invalid input data descriptor */
  	array_t from = ARRAY_USED(NULL, 0);
  	xdlms_asn1_axdr_resource_t to;

  	status = xdlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_FAIL);
  }

  if (1) { /* fail: unmatched data tag */
  	uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_INT32 };
  	array_t from = ARRAY_USED(&in, sizeof(in));

  	xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_ENCODE_ARRAY(5);

  	status = xdlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_TAG_UNMATCH);
  }

  if (1) { /* fail: unmatched data length */
  	uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_ARRAY, 49 };
  	array_t from = ARRAY_USED(&in, sizeof(in));

  	xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_ENCODE_ARRAY(1);

  	status = xdlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH);
  }

  if (1) { /* success: corrected from unknown (0) to 12 data entries */
  	uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 12 };
  	array_t from = ARRAY_USED(&in, sizeof(in));

  	xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(0);

  	status = xdlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

  	TEST_ASSERT_EQUAL(to.meta.len, 12);
  }

  if (1) { /* fail: unmatched data length */
  	uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 12 };
  	array_t from = ARRAY_USED(&in, sizeof(in));

  	xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(25);

  	status = xdlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH);
  }

  if (1) { /* fail: unmatched data length */
  	uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_ARRAY, 12 };
  	array_t from = ARRAY_USED(&in, sizeof(in));

  	xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_ENCODE_ARRAY(7);

  	status = xdlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH);
  }

  if (1) { /* success: corrected from unknown (0) to 1033 data entries */
  	uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_ARRAY, 0x82, 0x04, 0x21 };
  	array_t from = ARRAY_USED(&in, sizeof(in));

  	xdlms_asn1_axdr_resource_t to = XDLMS_ASN1_AXDR_ENCODE_ARRAY(0);

  	status = xdlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

  	TEST_ASSERT_EQUAL(to.meta.len, 1057);
  }

	/* Tests end */

	return;
}

void xdlms_asn1_axdr_decode_list_tests(void) {
	/* Global test variables start */

	status_t status = STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* invalid output data pointer */
		status = xdlms_asn1_axdr_decode_list(NULL, NULL, 0);
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input data */
		xdlms_asn1_axdr_resource_t to[] =  {
			[0] = XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL)
		};

		status = xdlms_asn1_axdr_decode_list(NULL, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* success */
		uint8_t in[] = { XDLMS_ASN1_AXDR_TYPE_ARRAY, 5 };
		array_t from = ARRAY_USED(&in, sizeof(in));

		xdlms_asn1_axdr_resource_t to[] =  {
			[0] = XDLMS_ASN1_AXDR_ENCODE_ARRAY(0)
		};

		status = xdlms_asn1_axdr_decode_list(&from, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to[0].meta.tag, XDLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_EQUAL(to[0].meta.len, 5);
	}

	if (1) { /* fail: unmatched data tag */
		uint8_t in[] = {
			XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 3,
				XDLMS_ASN1_AXDR_TYPE_INT16, 0x01, 0x00,
				XDLMS_ASN1_AXDR_TYPE_NULL_DATA,
				XDLMS_ASN1_AXDR_TYPE_UINT64, 1, 2, 3, 4, 5, 6, 7, 8,
		};
		array_t from = ARRAY_USED(&in, sizeof(in));

		struct {
			int16_t s16;
			uint8_t u8;
			uint64_t u64;
		} data = { 0, 0 ,0 };

		xdlms_asn1_axdr_resource_t to[] = {
			XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(3),
			XDLMS_ASN1_AXDR_ENCODE_INT16(&data.s16),
			XDLMS_ASN1_AXDR_ENCODE_UINT8(&data.u8),
			XDLMS_ASN1_AXDR_ENCODE_UINT64(&data.u64),
		};

		status = xdlms_asn1_axdr_decode_list(&from, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_EQUAL(status, STATUS_ASN1_AXDR_DECODE_TAG_UNMATCH);
	}

	if (1) { /* fail: unmatched data tag */
		uint8_t in[] = {
			XDLMS_ASN1_AXDR_TYPE_ARRAY, 2,
				XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 3,
					XDLMS_ASN1_AXDR_TYPE_INT16, 0x01, 0x00,
					XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 4, 'd', 'l', 'm', 's',
					XDLMS_ASN1_AXDR_TYPE_UINT64, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 1,
				XDLMS_ASN1_AXDR_TYPE_STRUCTURE, 3,
					XDLMS_ASN1_AXDR_TYPE_INT16, 0x02, 0x00,
					XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 5, 'c', 'o', 's', 'e', 'm',
					XDLMS_ASN1_AXDR_TYPE_UINT64, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 2,
		};
		array_t from = ARRAY_USED(&in, sizeof(in));

		struct {
			int16_t s16;
			char str[8];
			uint64_t u64;
		} data[] = {
			[0] = { 0, { "" }, 0 },
			[1] = { 0, { "" }, 0 }
		};

		array_t list[] = {
			[0] = ARRAY_FREE(&data[0].str[0], sizeof(data[0].str)),
			[1] = ARRAY_FREE(&data[1].str[0], sizeof(data[1].str)),
		};

		xdlms_asn1_axdr_resource_t to[] = {
			[0] = XDLMS_ASN1_AXDR_ENCODE_ARRAY(0),
				XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(3),
					XDLMS_ASN1_AXDR_ENCODE_INT16(&data[0].s16),
					XDLMS_ASN1_AXDR_ENCODE_VISIBLE(&list[0]),
					XDLMS_ASN1_AXDR_ENCODE_UINT64(&data[0].u64),
			  XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(3),
					XDLMS_ASN1_AXDR_ENCODE_INT16(&data[1].s16),
					XDLMS_ASN1_AXDR_ENCODE_VISIBLE(&list[1]),
					XDLMS_ASN1_AXDR_ENCODE_UINT64(&data[1].u64),
		};

		status = xdlms_asn1_axdr_decode_list(&from, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_EQUAL(status, STATUS_SUCCESS);

		TEST_ASSERT_EQUAL(to[0].meta.len, 2);

		TEST_ASSERT_EQUAL(data[0].s16, 256);
		TEST_ASSERT_EQUAL(data[1].s16, 512);
		TEST_ASSERT_EQUAL(data[0].u64, 0xffffffff00000001);
		TEST_ASSERT_EQUAL(data[1].u64, 0xffffffff00000002);
		TEST_ASSERT_EQUAL(strcmp(&(data[0].str)[0], "dlms"), 0);
		TEST_ASSERT_EQUAL(strcmp(&(data[1].str)[0], "cosem"), 0);
	}

	/* Tests end */

	return;
}
