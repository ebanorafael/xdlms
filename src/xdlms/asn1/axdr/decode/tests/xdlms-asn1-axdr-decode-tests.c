///@file

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* Unit Test file header files inclusion start */

#include <time.h>
#include <string.h>

#include "dlms_asn1_axdr-tests.h"
#include "dlms_asn1_axdr.h"
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

TEST_FUNCTION(funcion_name_tests) {
	/* Global test variables start */

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	/* Tests end */

	return;
}

#endif /* COPY */

TEST_FUNCTION(dlms_asn1_axdr_get_size_tests) {
	/* Global test variables start */

	size_t size = -1;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) {
		uint8_t sizes[] = {
			[DLMS_ASN1_AXDR_TYPE_NULL_DATA] = 0,
			[DLMS_ASN1_AXDR_TYPE_ARRAY] = 0,
			[DLMS_ASN1_AXDR_TYPE_STRUCTURE] = 0,
			[DLMS_ASN1_AXDR_TYPE_BOOLEAN] = sizeof(int8_t),
			[DLMS_ASN1_AXDR_TYPE_BIT_STRING] = 0,
			[DLMS_ASN1_AXDR_TYPE_INT32] = sizeof(int32_t),
			[DLMS_ASN1_AXDR_TYPE_UINT32] = sizeof(uint32_t),
			[DLMS_ASN1_AXDR_TYPE_OCTET_STRING] = 0,
			[DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING] = 0,
			[DLMS_ASN1_AXDR_TYPE_UTF8_STRING] = 0,
			[DLMS_ASN1_AXDR_TYPE_BCD] = sizeof(int8_t),
			[DLMS_ASN1_AXDR_TYPE_INT8] = sizeof(int8_t),
			[DLMS_ASN1_AXDR_TYPE_INT16] = sizeof(int16_t),
			[DLMS_ASN1_AXDR_TYPE_UINT8] = sizeof(uint8_t),
			[DLMS_ASN1_AXDR_TYPE_UINT16] = sizeof(uint16_t),
			[DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY] = 0,
			[DLMS_ASN1_AXDR_TYPE_INT64] = sizeof(int64_t),
			[DLMS_ASN1_AXDR_TYPE_UINT64] = sizeof(uint64_t),
			[DLMS_ASN1_AXDR_TYPE_ENUM] = sizeof(uint8_t),
			[DLMS_ASN1_AXDR_TYPE_FLOAT32] = sizeof(float),
			[DLMS_ASN1_AXDR_TYPE_FLOAT64] = sizeof(double),
			[DLMS_ASN1_AXDR_TYPE_DATE_TIME] = 0,
			[DLMS_ASN1_AXDR_TYPE_DATE] = 0,
			[DLMS_ASN1_AXDR_TYPE_TIME] = 0,
			[DLMS_ASN1_AXDR_TYPE_DELTA_INT8] = 0,
			[DLMS_ASN1_AXDR_TYPE_DELTA_INT16] = 0,
			[DLMS_ASN1_AXDR_TYPE_DELTA_INT32] = 0,
			[DLMS_ASN1_AXDR_TYPE_DELTA_UINT8] = 0,
			[DLMS_ASN1_AXDR_TYPE_DELTA_UINT16] = 0,
			[DLMS_ASN1_AXDR_TYPE_DELTA_UINT32] = 0,
			[DLMS_ASN1_AXDR_TYPE_INVALID_1] = 0xff,
			[DLMS_ASN1_AXDR_TYPE_INVALID_2] = 0xff,
			[DLMS_ASN1_AXDR_TYPE_INVALID_3] = 0xff,
			[DLMS_ASN1_AXDR_TYPE_INVALID_4] = 0xff
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(sizes); index++) {
			dlms_asn1_axdr_type_t tag = index;

			size = dlms_asn1_axdr_get_size(tag);
			TEST_ASSERT_INT_EQUAL(size, sizes[index]);
		}
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_decode_tag_tests) {
	/* Global test variables start */

	dlms_asn1_axdr_type_t type = DLMS_ASN1_AXDR_TYPE_NULL_DATA;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid controlled buffer 1 */
		type = dlms_asn1_axdr_decode_tag(NULL);
		TEST_ASSERT_INT_EQUAL(type, DLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) { /* invalid controlled buffer 2 */
		baf_t from = BAF_FREE(NULL, 0);

		type = dlms_asn1_axdr_decode_tag(&from);
		TEST_ASSERT_INT_EQUAL(type, DLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) { /* invalid controlled buffer 3 */
		uint8_t buffer[16];
		baf_t from = BAF_FREE(&buffer, 0);

		type = dlms_asn1_axdr_decode_tag(&from);
		TEST_ASSERT_INT_EQUAL(type, DLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) { /* invalid controlled buffer 3 */
		uint8_t buffer[16];
		baf_t from = BAF_FREE(&buffer, 0);

		type = dlms_asn1_axdr_decode_tag(&from);
		TEST_ASSERT_INT_EQUAL(type, DLMS_ASN1_AXDR_TYPE_MAX);
	}

	if (1) {
		uint8_t rets[] = {
			[DLMS_ASN1_AXDR_TYPE_NULL_DATA] = DLMS_ASN1_AXDR_TYPE_NULL_DATA,
			[DLMS_ASN1_AXDR_TYPE_ARRAY] = DLMS_ASN1_AXDR_TYPE_ARRAY,
			[DLMS_ASN1_AXDR_TYPE_STRUCTURE] = DLMS_ASN1_AXDR_TYPE_STRUCTURE,
			[DLMS_ASN1_AXDR_TYPE_BOOLEAN] = DLMS_ASN1_AXDR_TYPE_BOOLEAN,
			[DLMS_ASN1_AXDR_TYPE_BIT_STRING] = DLMS_ASN1_AXDR_TYPE_BIT_STRING,
			[DLMS_ASN1_AXDR_TYPE_INT32] = DLMS_ASN1_AXDR_TYPE_INT32,
			[DLMS_ASN1_AXDR_TYPE_UINT32] = DLMS_ASN1_AXDR_TYPE_UINT32,
			[DLMS_ASN1_AXDR_TYPE_OCTET_STRING] = DLMS_ASN1_AXDR_TYPE_OCTET_STRING,
			[DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING] = DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING,
			[DLMS_ASN1_AXDR_TYPE_UTF8_STRING] = DLMS_ASN1_AXDR_TYPE_UTF8_STRING,
			[DLMS_ASN1_AXDR_TYPE_BCD] = DLMS_ASN1_AXDR_TYPE_BCD,
			[DLMS_ASN1_AXDR_TYPE_INT8] = DLMS_ASN1_AXDR_TYPE_INT8,
			[DLMS_ASN1_AXDR_TYPE_INT16] = DLMS_ASN1_AXDR_TYPE_INT16,
			[DLMS_ASN1_AXDR_TYPE_UINT8] = DLMS_ASN1_AXDR_TYPE_UINT8,
			[DLMS_ASN1_AXDR_TYPE_UINT16] = DLMS_ASN1_AXDR_TYPE_UINT16,
			[DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY] = DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY,
			[DLMS_ASN1_AXDR_TYPE_INT64] = DLMS_ASN1_AXDR_TYPE_INT64,
			[DLMS_ASN1_AXDR_TYPE_UINT64] = DLMS_ASN1_AXDR_TYPE_UINT64,
			[DLMS_ASN1_AXDR_TYPE_ENUM] = DLMS_ASN1_AXDR_TYPE_ENUM,
			[DLMS_ASN1_AXDR_TYPE_FLOAT32] = DLMS_ASN1_AXDR_TYPE_FLOAT32,
			[DLMS_ASN1_AXDR_TYPE_FLOAT64] = DLMS_ASN1_AXDR_TYPE_FLOAT64,
			[DLMS_ASN1_AXDR_TYPE_DATE_TIME] = DLMS_ASN1_AXDR_TYPE_DATE_TIME,
			[DLMS_ASN1_AXDR_TYPE_DATE] = DLMS_ASN1_AXDR_TYPE_DATE,
			[DLMS_ASN1_AXDR_TYPE_TIME] = DLMS_ASN1_AXDR_TYPE_TIME,
			[DLMS_ASN1_AXDR_TYPE_DELTA_INT8] = DLMS_ASN1_AXDR_TYPE_DELTA_INT8,
			[DLMS_ASN1_AXDR_TYPE_DELTA_INT16] = DLMS_ASN1_AXDR_TYPE_DELTA_INT16,
			[DLMS_ASN1_AXDR_TYPE_DELTA_INT32] = DLMS_ASN1_AXDR_TYPE_DELTA_INT32,
			[DLMS_ASN1_AXDR_TYPE_DELTA_UINT8] = DLMS_ASN1_AXDR_TYPE_DELTA_UINT8,
			[DLMS_ASN1_AXDR_TYPE_DELTA_UINT16] = DLMS_ASN1_AXDR_TYPE_DELTA_UINT16,
			[DLMS_ASN1_AXDR_TYPE_DELTA_UINT32] = DLMS_ASN1_AXDR_TYPE_DELTA_UINT32,
			[DLMS_ASN1_AXDR_TYPE_MAX] = DLMS_ASN1_AXDR_TYPE_MAX,
			[DLMS_ASN1_AXDR_TYPE_INVALID_1] = DLMS_ASN1_AXDR_TYPE_MAX,
			[DLMS_ASN1_AXDR_TYPE_INVALID_2] = DLMS_ASN1_AXDR_TYPE_MAX,
			[DLMS_ASN1_AXDR_TYPE_INVALID_3] = DLMS_ASN1_AXDR_TYPE_MAX,
			[DLMS_ASN1_AXDR_TYPE_INVALID_4] = DLMS_ASN1_AXDR_TYPE_MAX,
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(rets); index++) {
			uint8_t buffer[1] = { index };
			baf_t from = BAF_USED(&buffer, sizeof(buffer));

			type = dlms_asn1_axdr_decode_tag(&from);
			TEST_ASSERT_INT_EQUAL(type, rets[index]);
		}
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_decode_len_tests) {
	/* Global test variables start */

	size_t size = 0;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid controlled buffer 1 */
		size = dlms_asn1_axdr_decode_len(NULL);
		TEST_ASSERT_INT_EQUAL(size, -1);
	}

	if (1) { /* invalid controlled buffer 2 */
		baf_t from = BAF_FREE(NULL, 0);

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, -1);
	}

	if (1) { /* invalid controlled buffer 3 */
		uint8_t buffer[16];
		baf_t from = BAF_FREE(&buffer, 0);

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, -1);
	}

	if (1) { /* size less than 0x80 */
		uint8_t sizes[] = { 0, 12, 59, 72, 103, 99, 125, 127 };
		for (uint32_t index = 0; index < ARRAY_SIZE(sizes); index++) {
			uint8_t buffer[1] = { sizes[index] };
			baf_t from = BAF_USED(&buffer, sizeof(buffer));

			size = dlms_asn1_axdr_decode_len(&from);
			TEST_ASSERT_INT_EQUAL(size, sizes[index]);
		}
	}

	if (1) { /* size larger than 4GB */
		uint8_t buffer[] = { 0x85 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, -1);
	}

	if (1) { /* not enough bytes in buffer */
		uint8_t buffer[] = { 0x81 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, -1);
	}

	if (1) { /* not enough bytes in buffer */
		uint8_t buffer[] = { 0x82, 1 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, -1);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x81, 1 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, 1);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x80, 0x01 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, 0);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x82, 0x01, 0x00 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, 256);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x82, 0xf1, 0x3d };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, 0xf13d);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x83, 0x72, 0xd0, 0x00 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, 0x72d000);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x84, 0x12, 0xb8, 0x00, 0x00 };
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, 0x12b80000);
	}

	if (1) { /* success */
		uint8_t buffer[] = { 0x84, 0xff, 0xff, 0xff, 0xff};
		baf_t from = BAF_USED(&buffer, sizeof(buffer));

		size = dlms_asn1_axdr_decode_len(&from);
		TEST_ASSERT_INT_EQUAL(size, 0xffffffff);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_decode_standard_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* invalid input data */
		status = dlms_asn1_axdr_decode_standard(NULL, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* fail: tag decoding fail */
		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = dlms_asn1_axdr_decode_standard(NULL, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* fail: invalid tag */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_INVALID_3 };
		baf_t from = BAF_USED(&in, sizeof(in));

		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = dlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* fail: sequence data instead of standard data */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_OCTET_STRING };
		baf_t from = BAF_USED(&in, sizeof(in));

		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = dlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* fail: invalid output buffer */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_UINT8, 0x01 };
		baf_t from = BAF_USED(&in, sizeof(in));

		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = dlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_UINT8);
		TEST_ASSERT_INT_EQUAL(to.meta.len, sizeof(uint8_t));
	}

	if (1) { /* fail: not enough input data */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_INT32, 0x01, 0x02, 0x03 };
		baf_t from = BAF_USED(&in, sizeof(in));

		int32_t out = 0;
		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(&out);

		status = dlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_INT32);
		TEST_ASSERT_INT_EQUAL(to.meta.len, sizeof(out));
	}

	if (1) { /* fail: not enough input data */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_UINT16, 0x80, 0x00 };
		baf_t from = BAF_USED(&in, sizeof(in));

		uint16_t out = 0;
		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(&out);

		status = dlms_asn1_axdr_decode_standard(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_INT_EQUAL(to.meta.len, sizeof(out));
		TEST_ASSERT_INT_EQUAL(out, 0x8000);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_decode_sequence_of_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	if (1) { /* NULL pointer */
		status = dlms_asn1_axdr_decode_sequence_of(NULL, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input data */
		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode_sequence_of(NULL, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_MAX);
		TEST_ASSERT_INT_EQUAL(to.meta.len, -1);
	}

	if (1) { /* success */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_INT16, 0x3f, 0xff };
		baf_t from = BAF_USED(&in[0], sizeof(in));

		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_INT16);
		TEST_ASSERT_INT_EQUAL(to.meta.len, sizeof(uint16_t));
	}

	if (1) { /* success */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_NULL_DATA };
		baf_t from = BAF_USED(&in[0], sizeof(in));

		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_NULL_DATA);
		TEST_ASSERT_INT_EQUAL(to.meta.len, 0);
	}

	if (1) { /* fail: length decoding fail */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY };
		baf_t from = BAF_USED(&in[0], sizeof(in));

		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_INT_EQUAL(to.meta.len, 0);
	}

	if (1) { /* success */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_OCTET_STRING, 0x82, 0x01, 0x00 };
		baf_t from = BAF_USED(&in[0], sizeof(in));

		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode_sequence_of(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_INT_EQUAL(to.meta.len, 256);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_decode_sequence_of_bytes_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input parameter */
		status = dlms_asn1_axdr_decode_sequence_of_bytes(NULL, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* invalid input parameter */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 13 };

		baf_t from = BAF_USED(&in[0], sizeof(in));
		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL);

		status = dlms_asn1_axdr_decode_sequence_of_bytes(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* success */
		uint8_t in[] = {
			DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 12,
			'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd'
		};
		baf_t from = BAF_USED(&in, sizeof(in));

		uint8_t out[16] = { 0 };
		baf_t seq = BAF_FREE(&out, sizeof(out));

		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(&seq);

		status = dlms_asn1_axdr_decode_sequence_of_bytes(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		BAF_PRINT(&seq, "Decoded [octet, %u]", 13);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_decode_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* null output data pointer */
		status = dlms_asn1_axdr_decode(NULL, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* null input data pointer */
		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode(NULL, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input buffer */
		dlms_asn1_axdr_resource_t to;
		baf_t from = BAF_USED(NULL, 0);

		status = dlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	if (1) { /* success */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_NULL_DATA };
		baf_t from = BAF_USED(&in, sizeof(in));

		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_NULL_DATA);
		TEST_ASSERT_INT_EQUAL(to.meta.len, 0);
	}

	if (1) { /* success */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_ARRAY, 0x81, 233 };
		baf_t from = BAF_USED(&in, sizeof(in));

		dlms_asn1_axdr_resource_t to;

		status = dlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_INT_EQUAL(to.meta.len, 233);
	}

	if (1) { /* success */
		uint8_t in[] = {
			DLMS_ASN1_AXDR_TYPE_OCTET_STRING, 12,
			'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd'
		};
		baf_t from = BAF_USED(&in, sizeof(in));

		uint8_t out[16] = { 0 };
		baf_t seq = BAF_FREE(&out, sizeof(out));
		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(&seq);

		status = dlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_INT_EQUAL(to.meta.len, 12);
		TEST_ASSERT_INT_EQUAL(out[0], 'H');
		TEST_ASSERT_INT_EQUAL(out[1], 'e');
		TEST_ASSERT_INT_EQUAL(out[2], 'l');
		TEST_ASSERT_INT_EQUAL(out[3], 'l');
		TEST_ASSERT_INT_EQUAL(out[4], 'o');
		TEST_ASSERT_INT_EQUAL(out[5], ',');
		TEST_ASSERT_INT_EQUAL(out[6], ' ');
		TEST_ASSERT_INT_EQUAL(out[7], 'W');
		TEST_ASSERT_INT_EQUAL(out[8], 'o');
		TEST_ASSERT_INT_EQUAL(out[9], 'r');
		TEST_ASSERT_INT_EQUAL(out[10], 'l');
		TEST_ASSERT_INT_EQUAL(out[11], 'd');

		BAF_PRINT(&seq, "Decoded data [octet, %u]", 12);
	}

	if (1) { /* success */
		uint8_t in[] = {
			DLMS_ASN1_AXDR_TYPE_INT64,
			0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01
		};
		baf_t from = BAF_USED(&in, sizeof(in));

		int64_t out = 0;
		dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(&out);

		status = dlms_asn1_axdr_decode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to.meta.tag, DLMS_ASN1_AXDR_TYPE_INT64);
		TEST_ASSERT_INT_EQUAL(to.meta.len, sizeof(int64_t));
		TEST_ASSERT_INT_EQUAL(out, 0x0807060504030201);

		PRINTF("Decoded data [s64]: " GREEN("0x%016llX\n"), out);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_decode_validate_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

  if (1) { /* invalid input buffer */
  	status = dlms_asn1_axdr_decode_validate(NULL, NULL);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
  }

  if (1) { /* invalid input data descriptor */
  	baf_t from = BAF_USED(NULL, 0);

  	status = dlms_asn1_axdr_decode_validate(&from, NULL);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
  }

	/* End of assertion test cases */

	/* Tests start*/

  if (1) { /* invalid input data descriptor */
  	baf_t from = BAF_USED(NULL, 0);
  	dlms_asn1_axdr_resource_t to;

  	status = dlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_FAIL);
  }

  if (1) { /* fail: unmatched data tag */
  	uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_INT32 };
  	baf_t from = BAF_USED(&in, sizeof(in));

  	dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_ENCODE_ARRAY(5);

  	status = dlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_TAG_UNMATCH);
  }

  if (1) { /* fail: unmatched data length */
  	uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_ARRAY, 49 };
  	baf_t from = BAF_USED(&in, sizeof(in));

  	dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_ENCODE_ARRAY(1);

  	status = dlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH);
  }

  if (1) { /* success: corrected from unknown (0) to 12 data entries */
  	uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_STRUCTURE, 12 };
  	baf_t from = BAF_USED(&in, sizeof(in));

  	dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_ENCODE_STRUCTURE(0);

  	status = dlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

  	TEST_ASSERT_INT_EQUAL(to.meta.len, 12);
  }

  if (1) { /* fail: unmatched data length */
  	uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_STRUCTURE, 12 };
  	baf_t from = BAF_USED(&in, sizeof(in));

  	dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_ENCODE_STRUCTURE(25);

  	status = dlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH);
  }

  if (1) { /* fail: unmatched data length */
  	uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_ARRAY, 12 };
  	baf_t from = BAF_USED(&in, sizeof(in));

  	dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_ENCODE_ARRAY(7);

  	status = dlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH);
  }

  if (1) { /* success: corrected from unknown (0) to 1033 data entries */
  	uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_ARRAY, 0x82, 0x04, 0x21 };
  	baf_t from = BAF_USED(&in, sizeof(in));

  	dlms_asn1_axdr_resource_t to = DLMS_ASN1_AXDR_ENCODE_ARRAY(0);

  	status = dlms_asn1_axdr_decode_validate(&from, &to);
  	TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

  	TEST_ASSERT_INT_EQUAL(to.meta.len, 1057);
  }

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_tag_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid data type tags */
		dlms_asn1_axdr_type_t tags[] = {
			DLMS_ASN1_AXDR_TYPE_INVALID_1,
			DLMS_ASN1_AXDR_TYPE_INVALID_2,
			DLMS_ASN1_AXDR_TYPE_INVALID_3,
			DLMS_ASN1_AXDR_TYPE_INVALID_4,
			DLMS_ASN1_AXDR_TYPE_MAX
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(tags); index++) {
			status = dlms_asn1_axdr_encode_tag(tags[index], NULL);
			TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* invalid output buffer 1 */
		status = dlms_asn1_axdr_encode_tag(DLMS_ASN1_AXDR_TYPE_NULL_DATA, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t buffer[1] = { 0 };
		baf_t from = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_tag(DLMS_ASN1_AXDR_TYPE_OCTET_STRING, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], DLMS_ASN1_AXDR_TYPE_OCTET_STRING);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_multi_byte_len_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid size */
		for (uint32_t size = 0; size < 128; size++) {
			status = dlms_asn1_axdr_encode_multi_byte_len(size, NULL);
			TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* invalid output buffer 1 */
		status = dlms_asn1_axdr_encode_multi_byte_len(128, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid output buffer 2 */
		baf_t from = BAF_FREE(NULL, 0);

		status = dlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid output buffer 3 */
		uint8_t buffer[16] = { 0 };
		baf_t from = BAF_FREE(&buffer[0], 0);

		status = dlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* buffer without enough space */
		uint8_t buffer[1] = { 0 };
		baf_t from = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t buffer[2] = { 0 };
		baf_t from = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_multi_byte_len(128, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], 0x81);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0x80);

		baf_t temp = BAF_USED(&buffer[0], sizeof(uint16_t));
		BAF_PRINT(&temp, "Encoded len [%u]", 0x80);
	}

	if (1) { /* success */
		uint8_t buffer[3] = { 0 };
		baf_t from = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_multi_byte_len(0xf29b, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], 0x82);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0xf2);
		TEST_ASSERT_INT_EQUAL(buffer[2], 0x9b);

		baf_t temp = BAF_USED(&buffer[0], sizeof(uint16_t) + 1);
		BAF_PRINT(&temp, "Encoded len [%u]", 0xf29b);
	}

	if (1) { /* success */
		uint8_t buffer[4] = { 0 };
		baf_t from = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_multi_byte_len(0x1cffff, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], 0x83);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0x1c);
		TEST_ASSERT_INT_EQUAL(buffer[2], 0xff);
		TEST_ASSERT_INT_EQUAL(buffer[3], 0xff);

		baf_t temp = BAF_USED(&buffer[0], sizeof(uint32_t));
		BAF_PRINT(&temp, "Encoded len [%u]", 0x1cffff);
	}

	if (1) { /* success */
		uint8_t buffer[5] = { 0 };
		baf_t from = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_multi_byte_len(0xffffffff, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], 0x84);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0xff);
		TEST_ASSERT_INT_EQUAL(buffer[2], 0xff);
		TEST_ASSERT_INT_EQUAL(buffer[3], 0xff);
		TEST_ASSERT_INT_EQUAL(buffer[4], 0xff);

		baf_t temp = BAF_USED(&buffer[0], sizeof(uint32_t) + 1);
		BAF_PRINT(&temp, "Encoded len [%u]", 0xffffffff);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_len_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid buffer 1 */
		status = dlms_asn1_axdr_encode_len(0, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid buffer 2 */
		status = dlms_asn1_axdr_encode_len(0xff, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* sucess */
		uint8_t buffer[1] = { 0 };
		baf_t from = BAF_FREE(&buffer, sizeof(buffer));

		status = dlms_asn1_axdr_encode_len(12, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], 12);
	}

	if (1) { /* sucess */
		uint8_t buffer[4] = { 0 };
		baf_t from = BAF_FREE(&buffer, sizeof(buffer));

		status = dlms_asn1_axdr_encode_len(0xff80, &from);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], 0x82);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0xff);
		TEST_ASSERT_INT_EQUAL(buffer[2], 0x80);

		baf_t temp = BAF_USED(&buffer[0], sizeof(uint16_t) + 1);
		BAF_PRINT(&temp, "Encoded len [%u]", 0xff80);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_standard_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid data types: sequence */
		dlms_asn1_axdr_type_t tags[] = {
			DLMS_ASN1_AXDR_TYPE_NULL_DATA,
			DLMS_ASN1_AXDR_TYPE_ARRAY,
			DLMS_ASN1_AXDR_TYPE_STRUCTURE,
			DLMS_ASN1_AXDR_TYPE_BIT_STRING,
			DLMS_ASN1_AXDR_TYPE_OCTET_STRING,
			DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING,
			DLMS_ASN1_AXDR_TYPE_UTF8_STRING,
			DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY,
			DLMS_ASN1_AXDR_TYPE_DATE_TIME,
			DLMS_ASN1_AXDR_TYPE_DATE,
			DLMS_ASN1_AXDR_TYPE_TIME,
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(tags); index++) {
			status = dlms_asn1_axdr_encode_standard(NULL, NULL, tags[index]);
			TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* invalid data types: invalid types */
		dlms_asn1_axdr_type_t tags[] = {
			DLMS_ASN1_AXDR_TYPE_INVALID_1,
			DLMS_ASN1_AXDR_TYPE_INVALID_2,
			DLMS_ASN1_AXDR_TYPE_INVALID_3,
			DLMS_ASN1_AXDR_TYPE_INVALID_4,
		};

		for (uint32_t index = 0; index < ARRAY_SIZE(tags); index++) {
			status = dlms_asn1_axdr_encode_standard(NULL, NULL, tags[index]);
			TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
		}
	}

	if (1) { /* fail to encode tag */
		status = dlms_asn1_axdr_encode_standard(NULL,
		                                        NULL,
		                                        DLMS_ASN1_AXDR_TYPE_INT16);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* fail to encode data */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[1] = { 0 };
		baf_t to = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        DLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_INT_EQUAL(buffer[0], DLMS_ASN1_AXDR_TYPE_UINT32);
	}

	if (1) { /* success */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[3] = { 0 };
		baf_t to = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        DLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], DLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0x02);
		TEST_ASSERT_INT_EQUAL(buffer[2], 0x01);

		baf_t temp = BAF_USED(&buffer[0], sizeof(uint16_t) + 1);
		BAF_PRINT(&temp, "Encoded u%u", 16);
	}

	if (1) { /* success */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[32] = { 0 };
		baf_t to = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        DLMS_ASN1_AXDR_TYPE_INT32);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], DLMS_ASN1_AXDR_TYPE_INT32);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0x04);
		TEST_ASSERT_INT_EQUAL(buffer[2], 0x03);
		TEST_ASSERT_INT_EQUAL(buffer[3], 0x02);
		TEST_ASSERT_INT_EQUAL(buffer[4], 0x01);

		baf_t temp = BAF_USED(&buffer[0], sizeof(int32_t) + 1);
		BAF_PRINT(&temp, "Encoded s%u", 32);
	}

	if (1) { /* success */
		uint64_t from = 0x0807060504030201;
		uint8_t buffer[32] = { 0 };
		baf_t to = BAF_FREE(&buffer[0], sizeof(buffer));

		status = dlms_asn1_axdr_encode_standard((uint8_t*) &from,
		                                        &to,
		                                        DLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(buffer[0], DLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_INT_EQUAL(buffer[1], 0x08);
		TEST_ASSERT_INT_EQUAL(buffer[2], 0x07);
		TEST_ASSERT_INT_EQUAL(buffer[3], 0x06);
		TEST_ASSERT_INT_EQUAL(buffer[4], 0x05);
		TEST_ASSERT_INT_EQUAL(buffer[5], 0x04);
		TEST_ASSERT_INT_EQUAL(buffer[6], 0x03);
		TEST_ASSERT_INT_EQUAL(buffer[7], 0x02);
		TEST_ASSERT_INT_EQUAL(buffer[8], 0x01);

		baf_t temp = BAF_USED(&buffer[0], sizeof(uint64_t));
		BAF_PRINT(&temp, "Encoded u%u", 64);
	}


	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_bit_string_tests) {
	CONSOLE_TRACE(PRINTF, FMT_NONE("\nTest implementation pending!\n"));

	/* Global test variables start */

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_sequence_of_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid data type tag */
		status = dlms_asn1_axdr_encode_sequence_of(NULL,
		                                           DLMS_ASN1_AXDR_TYPE_MAX,
		                                           0xffffffff);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* invalid output buffer */
		status = dlms_asn1_axdr_encode_sequence_of(NULL,
		                                           DLMS_ASN1_AXDR_TYPE_INT32,
		                                           sizeof(uint32_t));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t out[2] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_sequence_of(&to,
		                                           DLMS_ASN1_AXDR_TYPE_OCTET_STRING,
		                                           12);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_INT_EQUAL(out[1], 12);

		BAF_PRINT(&to, "Encoded sequence of [octet, %u]", 12);
	}

	if (1) { /* success */
		uint8_t out[3] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_sequence_of(&to,
		                                           DLMS_ASN1_AXDR_TYPE_ARRAY,
		                                           155);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_INT_EQUAL(out[1], 0x81);
		TEST_ASSERT_INT_EQUAL(out[2], 155);

		BAF_PRINT(&to, "Encoded sequence of [array, %u]", 155);
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_sequence_of(&to,
		                                           DLMS_ASN1_AXDR_TYPE_STRUCTURE,
		                                           70000);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_INT_EQUAL(out[1], 0x83);
		TEST_ASSERT_INT_EQUAL(out[2], 0x01);
		TEST_ASSERT_INT_EQUAL(out[3], 0x11);
		TEST_ASSERT_INT_EQUAL(out[4], 0x70);

		BAF_PRINT(&to, "Encoded sequence of [structure, %u]", 70000);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_sequence_of_bytes_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid parameters */
		status = dlms_asn1_axdr_encode_sequence_of_bytes(NULL,
		                                                 NULL,
		                                                 DLMS_ASN1_AXDR_TYPE_MAX);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* invalid output buffer */
		baf_t from = BAF_USED(NULL, 12);

		uint8_t out[2] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_sequence_of_bytes(&from,
		                                                 &to,
		                                                 DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_INT_EQUAL(out[1], 12);
	}

	if (1) { /* output buffer without enough space */
		uint8_t in[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		baf_t from = BAF_USED(&in[0], 12);

		uint8_t out[6] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_sequence_of_bytes(&from,
		                                                 &to,
		                                                 DLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_INT_EQUAL(out[1], 12);
		TEST_ASSERT_INT_EQUAL(out[2], 0);
		TEST_ASSERT_INT_EQUAL(out[3], 0);
		TEST_ASSERT_INT_EQUAL(out[4], 0);
		TEST_ASSERT_INT_EQUAL(out[5], 0);
	}

	if (1) { /* output buffer without enough space */
		char in[] = { "Hello, world" };
		baf_t from = BAF_USED(&in[0], sizeof(in));

		uint8_t out[32] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_sequence_of_bytes(&from,
		                                                 &to,
		                                                 DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_INT_EQUAL(out[1], 13);
		TEST_ASSERT_INT_EQUAL(out[2], 'H');
		TEST_ASSERT_INT_EQUAL(out[3], 'e');
		TEST_ASSERT_INT_EQUAL(out[4], 'l');
		TEST_ASSERT_INT_EQUAL(out[5], 'l');
		TEST_ASSERT_INT_EQUAL(out[6], 'o');
		TEST_ASSERT_INT_EQUAL(out[7], ',');
		TEST_ASSERT_INT_EQUAL(out[8], ' ');
		TEST_ASSERT_INT_EQUAL(out[9], 'w');
		TEST_ASSERT_INT_EQUAL(out[10], 'o');
		TEST_ASSERT_INT_EQUAL(out[11], 'r');
		TEST_ASSERT_INT_EQUAL(out[12], 'l');
		TEST_ASSERT_INT_EQUAL(out[13], 'd');
		TEST_ASSERT_INT_EQUAL(out[14], '\0');

		BAF_PRINT(&to, "Encoded sequence of bytes [visible, %u]", 13);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_compact_array_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid output buffer */
		status = dlms_asn1_axdr_encode_compact_array(NULL, NULL, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid input template buffer */
		uint8_t out[4];
		baf_t to = BAF_FREE(&out, sizeof(out));

		status = dlms_asn1_axdr_encode_compact_array(NULL, NULL, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* invalid input contents buffer 1 */
		uint8_t in_tpl[] = {
			DLMS_ASN1_AXDR_TYPE_STRUCTURE, 4,
			  DLMS_ASN1_AXDR_TYPE_INT8,
			  DLMS_ASN1_AXDR_TYPE_UINT64,
			  DLMS_ASN1_AXDR_TYPE_UINT32,
			  DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING
		};
		baf_t from_tpl = BAF_USED(&in_tpl, sizeof(in_tpl));

		uint8_t out[7];
		baf_t to = BAF_FREE(&out, sizeof(out));

		status = dlms_asn1_axdr_encode_compact_array(&from_tpl, NULL, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_INT_EQUAL(out[1], DLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_INT_EQUAL(out[2], 4);
		TEST_ASSERT_INT_EQUAL(out[3], DLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_INT_EQUAL(out[4], DLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_INT_EQUAL(out[5], DLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_INT_EQUAL(out[6], DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
	}

	if (1) { /* invalid input contents buffer 2 */
		uint8_t in_tpl[] = {
			DLMS_ASN1_AXDR_TYPE_STRUCTURE, 4,
			  DLMS_ASN1_AXDR_TYPE_INT8,
			  DLMS_ASN1_AXDR_TYPE_UINT64,
			  DLMS_ASN1_AXDR_TYPE_UINT32,
			  DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING
		};
		baf_t from_tpl = BAF_USED(&in_tpl, sizeof(in_tpl));
		baf_t from_cts = BAF_USED(NULL, 2);

		uint8_t out[8];
		baf_t to = BAF_FREE(&out, sizeof(out));

		status = dlms_asn1_axdr_encode_compact_array(&from_tpl, &from_cts, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_INT_EQUAL(out[1], DLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_INT_EQUAL(out[2], 4);
		TEST_ASSERT_INT_EQUAL(out[3], DLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_INT_EQUAL(out[4], DLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_INT_EQUAL(out[5], DLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_INT_EQUAL(out[6], DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_INT_EQUAL(out[7], 2);
	}

	if (1) { /* success */
		uint8_t in_tpl[] = {
			DLMS_ASN1_AXDR_TYPE_STRUCTURE, 4,
			  DLMS_ASN1_AXDR_TYPE_INT8,
			  DLMS_ASN1_AXDR_TYPE_UINT64,
			  DLMS_ASN1_AXDR_TYPE_UINT32,
			  DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING
		};
		baf_t from_tpl = BAF_USED(&in_tpl, sizeof(in_tpl));

		uint8_t in_cts[] = {
			0x01,
			0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01,
			0x00, 0x00, 0x00, 0x02,
			4, 'd', 'l', 'm', 's'
		};
		baf_t from_cts = BAF_USED(&in_cts, sizeof(in_cts));

		uint8_t out[32];
		baf_t to = BAF_FREE(&out, sizeof(out));

		status = dlms_asn1_axdr_encode_compact_array(&from_tpl, &from_cts, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_INT_EQUAL(out[1], DLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_INT_EQUAL(out[2], 4);
		TEST_ASSERT_INT_EQUAL(out[3], DLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_INT_EQUAL(out[4], DLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_INT_EQUAL(out[5], DLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_INT_EQUAL(out[6], DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_INT_EQUAL(out[7], sizeof(in_cts));

		BAF_PRINT(&to,
		          "Encoded data [octet %u]",
		          (uint32_t)(1 + sizeof(in_tpl) + sizeof(in_cts)));
	}

	if (1) { /* success */
		uint8_t in_tpl[] = {
			DLMS_ASN1_AXDR_TYPE_UINT32,
		};
		baf_t from_tpl = BAF_USED(&in_tpl, sizeof(in_tpl));

		uint8_t in_cts[] = {
			0x00, 0x00, 0x00, 0x01,
			0x00, 0x00, 0x00, 0x02,
			0x00, 0x00, 0x00, 0x03,
			0x00, 0x00, 0x00, 0x04,
			0x00, 0x00, 0x00, 0x05,
		};
		baf_t from_cts = BAF_USED(&in_cts, sizeof(in_cts));

		uint8_t out[32];
		baf_t to = BAF_FREE(&out, sizeof(out));

		status = dlms_asn1_axdr_encode_compact_array(&from_tpl, &from_cts, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY);
		TEST_ASSERT_INT_EQUAL(out[1], DLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_INT_EQUAL(out[2], sizeof(in_cts));

		BAF_PRINT(&to,
		          "Encoded data [octet %u]",
		          (uint32_t)(1 + sizeof(in_tpl) + sizeof(in_cts)));
	}

	/* Tests end */

	return;
}


TEST_FUNCTION(dlms_ans1_axdr_encode_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) {
		status = dlms_asn1_axdr_encode(NULL, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid tag */
		dlms_asn1_axdr_resource_t from = {
			.meta = { .tag = DLMS_ASN1_AXDR_TYPE_MAX, .len = 0 },
			.data = { .cts.p_seq = NULL }
		};
		status = dlms_asn1_axdr_encode(&from, NULL);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_NULL;

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_NULL_DATA);

		BAF_PRINT(&to, "Encoded data [NULL, %u]", 0);
	}

	if (1) { /* success: array */
		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_ARRAY(0x3fff);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_INT_EQUAL(out[1], 0x82);
		TEST_ASSERT_INT_EQUAL(out[2], 0x3f);
		TEST_ASSERT_INT_EQUAL(out[3], 0xff);

		BAF_PRINT(&to, "Encoded data [array, %u]", 0x3fff);
	}

	if (1) { /* success: structure */
		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_STRUCTURE(8);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_STRUCTURE);
		TEST_ASSERT_INT_EQUAL(out[1], 0x08);

		BAF_PRINT(&to, "Encoded data [structure, %u]", 8);
	}

	if (1) { /* fail: bit-string */

	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		uint8_t in[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		baf_t seq = BAF_USED(&in[0], sizeof(in));
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_OCTET(&seq);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_OCTET_STRING);
		TEST_ASSERT_INT_EQUAL(out[1], 12);
		TEST_ASSERT_INT_EQUAL(out[2], 1);
		TEST_ASSERT_INT_EQUAL(out[3], 2);
		TEST_ASSERT_INT_EQUAL(out[4], 3);
		TEST_ASSERT_INT_EQUAL(out[5], 4);
		TEST_ASSERT_INT_EQUAL(out[6], 5);
		TEST_ASSERT_INT_EQUAL(out[7], 6);
		TEST_ASSERT_INT_EQUAL(out[8], 7);
		TEST_ASSERT_INT_EQUAL(out[9], 8);
		TEST_ASSERT_INT_EQUAL(out[10], 9);
		TEST_ASSERT_INT_EQUAL(out[11], 10);
		TEST_ASSERT_INT_EQUAL(out[12], 11);
		TEST_ASSERT_INT_EQUAL(out[13], 12);

		BAF_PRINT(&to, "Encoded data [octet, %u]", 12);
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		char in[] = { "Hello, world" };
		baf_t seq = BAF_USED(&in[0], sizeof(in));
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_VISIBLE(&seq);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING);
		TEST_ASSERT_INT_EQUAL(out[1], 13);
		TEST_ASSERT_INT_EQUAL(out[2], 'H');
		TEST_ASSERT_INT_EQUAL(out[3], 'e');
		TEST_ASSERT_INT_EQUAL(out[4], 'l');
		TEST_ASSERT_INT_EQUAL(out[5], 'l');
		TEST_ASSERT_INT_EQUAL(out[6], 'o');
		TEST_ASSERT_INT_EQUAL(out[7], ',');
		TEST_ASSERT_INT_EQUAL(out[8], ' ');
		TEST_ASSERT_INT_EQUAL(out[9], 'w');
		TEST_ASSERT_INT_EQUAL(out[10], 'o');
		TEST_ASSERT_INT_EQUAL(out[11], 'r');
		TEST_ASSERT_INT_EQUAL(out[12], 'l');
		TEST_ASSERT_INT_EQUAL(out[13], 'd');
		TEST_ASSERT_INT_EQUAL(out[14], '\0');

		BAF_PRINT(&to, "Encoded data [visible, %u]", 14);
	}

	if (1) { /* success */
		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		char in[] = { "Hello, world" };
		baf_t seq = BAF_USED(&in[0], sizeof(in));
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_UTF8_STRING(&seq);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_UTF8_STRING);
		TEST_ASSERT_INT_EQUAL(out[1], 13);
		TEST_ASSERT_INT_EQUAL(out[2], 'H');
		TEST_ASSERT_INT_EQUAL(out[3], 'e');
		TEST_ASSERT_INT_EQUAL(out[4], 'l');
		TEST_ASSERT_INT_EQUAL(out[5], 'l');
		TEST_ASSERT_INT_EQUAL(out[6], 'o');
		TEST_ASSERT_INT_EQUAL(out[7], ',');
		TEST_ASSERT_INT_EQUAL(out[8], ' ');
		TEST_ASSERT_INT_EQUAL(out[9], 'w');
		TEST_ASSERT_INT_EQUAL(out[10], 'o');
		TEST_ASSERT_INT_EQUAL(out[11], 'r');
		TEST_ASSERT_INT_EQUAL(out[12], 'l');
		TEST_ASSERT_INT_EQUAL(out[13], 'd');
		TEST_ASSERT_INT_EQUAL(out[14], '\0');

		BAF_PRINT(&to, "Encoded data [visible, %u]", 14);
	}

	if (1) { /* fail: compact-array not implemented yet */

	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		int8_t in = -0x3f;
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_INT8(&in);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_INT8);
		TEST_ASSERT_INT_EQUAL(out[1], (uint8_t)-0x3f);

		BAF_PRINT(&to, "Encoded data [s%u]", 8);
	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		uint16_t in = 0xff20;
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_UINT16(&in);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_UINT16);
		TEST_ASSERT_INT_EQUAL(out[1], 0xff);
		TEST_ASSERT_INT_EQUAL(out[2], 0x20);

		BAF_PRINT(&to, "Encoded data [s%u]", 16);
	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		uint32_t in = 0x803cff20;
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_UINT32(&in);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_UINT32);
		TEST_ASSERT_INT_EQUAL(out[1], 0x80);
		TEST_ASSERT_INT_EQUAL(out[2], 0x3c);
		TEST_ASSERT_INT_EQUAL(out[3], 0xff);
		TEST_ASSERT_INT_EQUAL(out[4], 0x20);

		BAF_PRINT(&to, "Encoded data [s%u]", 32);
	}

	if (1) { /* success */
		uint8_t out[32] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		uint64_t in = 0xffffffff01020304;
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_UINT64(&in);

		status = dlms_asn1_axdr_encode(&from, &to);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(out[0], DLMS_ASN1_AXDR_TYPE_UINT64);
		TEST_ASSERT_INT_EQUAL(out[1], 0xff);
		TEST_ASSERT_INT_EQUAL(out[2], 0xff);
		TEST_ASSERT_INT_EQUAL(out[3], 0xff);
		TEST_ASSERT_INT_EQUAL(out[4], 0xff);
		TEST_ASSERT_INT_EQUAL(out[5], 0x01);
		TEST_ASSERT_INT_EQUAL(out[6], 0x02);
		TEST_ASSERT_INT_EQUAL(out[7], 0x03);
		TEST_ASSERT_INT_EQUAL(out[8], 0x04);

		BAF_PRINT(&to, "Encoded data [s%u]", 64);
	}

	/* Tests end */

	return;
}

TEST_FUNCTION(dlms_asn1_axdr_encode_list_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) {
		status = dlms_asn1_axdr_encode_list(NULL, NULL, 0);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) {
		dlms_asn1_axdr_resource_t from = DLMS_ASN1_AXDR_ENCODE_NULL;

		status = dlms_asn1_axdr_encode_list(&from, NULL, 1);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	if (1) { /* success */
		uint16_t data[] = { 1, 2, 3 };
		dlms_asn1_axdr_resource_t from[] = {
			[0] = DLMS_ASN1_AXDR_ENCODE_ARRAY(ARRAY_SIZE(data)),
			[1] = DLMS_ASN1_AXDR_ENCODE_UINT16(&data[0]),
			[2] = DLMS_ASN1_AXDR_ENCODE_UINT16(&data[1]),
			[3] = DLMS_ASN1_AXDR_ENCODE_UINT16(&data[2])
		};

		uint8_t out[16] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		BAF_PRINT(&to, "Encoded data [array, %u]", 4);
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

		dlms_asn1_axdr_resource_t from[] = {
			DLMS_ASN1_AXDR_ENCODE_ARRAY(ARRAY_SIZE(event)),
			  DLMS_ASN1_AXDR_ENCODE_STRUCTURE(4), /* statically defined, but not by ARRAY_SIZE macro! */
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].time),
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].code),
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].ctxt),
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[0].crc32),
			  DLMS_ASN1_AXDR_ENCODE_STRUCTURE(4), /* statically defined, but not by ARRAY_SIZE macro! */
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].time),
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].code),
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].ctxt),
			    DLMS_ASN1_AXDR_ENCODE_UINT32(&event[1].crc32),
		};

		uint8_t out[128] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		BAF_PRINT(&to, "Encoded data [array, %u]", 2);
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

		baf_t baf_list[] = {
			BAF_USED(&event[0].string[0], sizeof("dlms") - 1),
			BAF_USED(&event[1].string[0], sizeof("cosem") - 1),
			BAF_USED(&event[2].string[0], sizeof("hello") - 1),
			BAF_USED(&event[3].string[0], sizeof("world") - 1),
		};

		dlms_asn1_axdr_resource_t from[] = {
			DLMS_ASN1_AXDR_ENCODE_ARRAY(ARRAY_SIZE(event)),
			  DLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    DLMS_ASN1_AXDR_ENCODE_UINT8(&event[0].index),
			    DLMS_ASN1_AXDR_ENCODE_VISIBLE(&baf_list[0]),
			  DLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    DLMS_ASN1_AXDR_ENCODE_UINT8(&event[1].index),
			    DLMS_ASN1_AXDR_ENCODE_VISIBLE(&baf_list[1]),
			  DLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    DLMS_ASN1_AXDR_ENCODE_UINT8(&event[2].index),
			    DLMS_ASN1_AXDR_ENCODE_VISIBLE(&baf_list[2]),
			  DLMS_ASN1_AXDR_ENCODE_STRUCTURE(2), /* statically defined, but not by ARRAY_SIZE macro! */
			    DLMS_ASN1_AXDR_ENCODE_UINT8(&event[3].index),
			    DLMS_ASN1_AXDR_ENCODE_VISIBLE(&baf_list[3]),
		};

		uint8_t out[128] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		status = dlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		BAF_PRINT(&to, "Encoded data [array, %u]", 2);
	}

	if (1) { /* success */
		typedef struct data_t {
			uint8_t index;
			uint32_t code;
		} data_t;

		uint8_t out[128] = { 0 };
		baf_t to = BAF_FREE(&out[0], sizeof(out));

		data_t in = {
			.index = 0, .code = 0x80
		};

		if (1) { /* wrong: find a better way! */
			dlms_asn1_axdr_resource_t from[1] = { DLMS_ASN1_AXDR_ENCODE_ARRAY(128/5) };

			status = dlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
			TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);
		}

		while(status == DLMS_STATUS_SUCCESS) {
			dlms_asn1_axdr_resource_t from[] = {
				DLMS_ASN1_AXDR_ENCODE_STRUCTURE(2),
				  DLMS_ASN1_AXDR_ENCODE_UINT8(&in.index),
				  DLMS_ASN1_AXDR_ENCODE_UINT32(&in.code),
			};

			status = dlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));

			in.index += 1;
			in.code += 2;
		}

		BAF_PRINT(&to, "Encoded data [array, %u]", 0);
	}

	if (1) { /* success */
		uint8_t tpl[] = { DLMS_ASN1_AXDR_TYPE_UINT64 };
		baf_t from_tpl = BAF_USED(&tpl, sizeof(tpl));

		uint64_t cts[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
		baf_t from_cts = BAF_FREE(&cts, sizeof(cts));

		uint8_t out[128] = { 0 };
		baf_t to = BAF_FREE(&out, sizeof(out));

		for (uint32_t index = 0; index < ARRAY_SIZE(cts); index++) {
			uint64_t temp = cts[index];
			(void) baf_push_hton((uint8_t *)&temp, &from_cts, sizeof(temp));
		}

		dlms_asn1_axdr_resource_t from[] = {
			[0] = {
				.meta = { .tag = DLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY, .len = 0 },
				.data = { .p_tpl = &from_tpl, .cts.p_seq = &from_cts }
			}
		};

		status = dlms_asn1_axdr_encode_list(&from[0], &to, ARRAY_SIZE(from));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		BAF_PRINT(&to, "Encoded data [octet, %u]", 67);
	}

	/* Tests end */

	return;
}


TEST_FUNCTION(dlms_asn1_axdr_decode_list_tests) {
	/* Global test variables start */

	dlms_status_t status = DLMS_STATUS_SUCCESS;

	/* Global test variables end */

	/* Start of assertion test cases */

	if (1) { /* invalid output data pointer */
		status = dlms_asn1_axdr_decode_list(NULL, NULL, 0);
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	/* End of assertion test cases */

	/* Tests start*/

	if (1) { /* invalid input data */
		dlms_asn1_axdr_resource_t to[] =  {
			[0] = DLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(NULL)
		};

		status = dlms_asn1_axdr_decode_list(NULL, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_INVALID_PARAMETER);
	}

	if (1) { /* success */
		uint8_t in[] = { DLMS_ASN1_AXDR_TYPE_ARRAY, 5 };
		baf_t from = BAF_USED(&in, sizeof(in));

		dlms_asn1_axdr_resource_t to[] =  {
			[0] = DLMS_ASN1_AXDR_ENCODE_ARRAY(0)
		};

		status = dlms_asn1_axdr_decode_list(&from, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to[0].meta.tag, DLMS_ASN1_AXDR_TYPE_ARRAY);
		TEST_ASSERT_INT_EQUAL(to[0].meta.len, 5);
	}

	if (1) { /* fail: unmatched data tag */
		uint8_t in[] = {
			DLMS_ASN1_AXDR_TYPE_STRUCTURE, 3,
				DLMS_ASN1_AXDR_TYPE_INT16, 0x01, 0x00,
				DLMS_ASN1_AXDR_TYPE_NULL_DATA,
				DLMS_ASN1_AXDR_TYPE_UINT64, 1, 2, 3, 4, 5, 6, 7, 8,
		};
		baf_t from = BAF_USED(&in, sizeof(in));

		struct {
			int16_t s16;
			uint8_t u8;
			uint64_t u64;
		} data = { 0, 0 ,0 };

		dlms_asn1_axdr_resource_t to[] = {
			DLMS_ASN1_AXDR_ENCODE_STRUCTURE(3),
			DLMS_ASN1_AXDR_ENCODE_INT16(&data.s16),
			DLMS_ASN1_AXDR_ENCODE_UINT8(&data.u8),
			DLMS_ASN1_AXDR_ENCODE_UINT64(&data.u64),
		};

		status = dlms_asn1_axdr_decode_list(&from, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_ASN1_AXDR_DECODE_TAG_UNMATCH);
	}

	if (1) { /* fail: unmatched data tag */
		uint8_t in[] = {
			DLMS_ASN1_AXDR_TYPE_ARRAY, 2,
				DLMS_ASN1_AXDR_TYPE_STRUCTURE, 3,
					DLMS_ASN1_AXDR_TYPE_INT16, 0x01, 0x00,
					DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 4, 'd', 'l', 'm', 's',
					DLMS_ASN1_AXDR_TYPE_UINT64, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 1,
				DLMS_ASN1_AXDR_TYPE_STRUCTURE, 3,
					DLMS_ASN1_AXDR_TYPE_INT16, 0x02, 0x00,
					DLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, 5, 'c', 'o', 's', 'e', 'm',
					DLMS_ASN1_AXDR_TYPE_UINT64, 0xff, 0xff, 0xff, 0xff, 0, 0, 0, 2,
		};
		baf_t from = BAF_USED(&in, sizeof(in));

		struct {
			int16_t s16;
			char str[8];
			uint64_t u64;
		} data[] = {
			[0] = { 0, { "" }, 0 },
			[1] = { 0, { "" }, 0 }
		};

		baf_t list[] = {
			[0] = BAF_FREE(&data[0].str[0], sizeof(data[0].str)),
			[1] = BAF_FREE(&data[1].str[0], sizeof(data[1].str)),
		};

		dlms_asn1_axdr_resource_t to[] = {
			[0] = DLMS_ASN1_AXDR_ENCODE_ARRAY(0),
				DLMS_ASN1_AXDR_ENCODE_STRUCTURE(3),
					DLMS_ASN1_AXDR_ENCODE_INT16(&data[0].s16),
					DLMS_ASN1_AXDR_ENCODE_VISIBLE(&list[0]),
					DLMS_ASN1_AXDR_ENCODE_UINT64(&data[0].u64),
			  DLMS_ASN1_AXDR_ENCODE_STRUCTURE(3),
					DLMS_ASN1_AXDR_ENCODE_INT16(&data[1].s16),
					DLMS_ASN1_AXDR_ENCODE_VISIBLE(&list[1]),
					DLMS_ASN1_AXDR_ENCODE_UINT64(&data[1].u64),
		};

		status = dlms_asn1_axdr_decode_list(&from, &to[0], ARRAY_SIZE(to));
		TEST_ASSERT_INT_EQUAL(status, DLMS_STATUS_SUCCESS);

		TEST_ASSERT_INT_EQUAL(to[0].meta.len, 2);

		TEST_ASSERT_INT_EQUAL(data[0].s16, 256);
		TEST_ASSERT_INT_EQUAL(data[1].s16, 512);
		TEST_ASSERT_INT_EQUAL(data[0].u64, 0xffffffff00000001);
		TEST_ASSERT_INT_EQUAL(data[1].u64, 0xffffffff00000002);
		TEST_ASSERT_INT_EQUAL(strcmp(&(data[0].str)[0], "dlms"), 0);
		TEST_ASSERT_INT_EQUAL(strcmp(&(data[1].str)[0], "cosem"), 0);
	}

	/* Tests end */

	return;
}
