///@file

/*******************************************************************
 * PRIVATE DEFINES
 *******************************************************************/

/* Module functioning defines start */

#ifdef UNIT_TESTS

#else

/*! @brief Hides internal function definitions when not in unit test environment */
#define STATIC    static

#endif /* UNIT_TESTS */

/* Module functioning defines end */

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* System functioning includes start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "unity.h"

/* System functioning includes end */

/* Module functioning includes start */

#include "array-tests.h"
#include "xdlms-asn1-axdr-encode-tests.h"
#include "xdlms-asn1-axdr-decode-tests.h"
#include "hdlc-address-tests.h"

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "utils.h"

/* Module functioning includes end */

/*******************************************************************
 * PRIVATE TYPES
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * PRIVATE PROTOTYPES
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * PRIVATE DATA
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * FUNCTIONS
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

int main(void) {
	UNITY_BEGIN();

	PRINT("===== Array lib. Tests =====\n\n");

	if (1) { RUN_TEST(array_used_tests); }
	if (1) { RUN_TEST(array_free_tests); }
	if (1) { RUN_TEST(arrays_validate_tests); }
	if (1) { RUN_TEST(array_serialize_tests); }
	if (1) { RUN_TEST(array_drop_tests); }
	if (1) { RUN_TEST(array_copy_tests); }
	if (1) { RUN_TEST(array_move_tests); }
	if (1) { RUN_TEST(array_push_tests); }
	if (1) { RUN_TEST(array_pull_tests); }
	if (1) { RUN_TEST(array_push_hton_tests); }
	if (1) { RUN_TEST(array_push_hton_tests); }

	PRINT("\n===== xDLMS ASN.1 A-XDR Encode lib. Tests =====\n\n");

	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_tag_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_multi_byte_len_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_len_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_standard_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_sequence_of_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_sequence_of_bytes_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_compact_array_tests); }
	if (1) { RUN_TEST(xdlms_ans1_axdr_encode_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_encode_list_tests); }

	PRINT("\n===== xDLMS ASN.1 A-XDR Decode lib. Tests =====\n\n");

	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_tag_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_len_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_standard_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_sequence_of_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_sequence_of_bytes_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_validate_tests); }
	if (1) { RUN_TEST(xdlms_asn1_axdr_decode_list_tests); }

	PRINT("\n===== xDLMS HDLC Address lib. Tests =====\n\n");

	if (1) { RUN_TEST(hdlc_parse_address_tests); }
	if (1) { RUN_TEST(hdlc_decode_address_tests); }
	if (1) { RUN_TEST(hdlc_pull_address_tests); }
	if (1) { RUN_TEST(hdlc_build_address_tests); }
	if (1) { RUN_TEST(hdlc_push_address_tests); }

	return UNITY_END();
}

void setUp(void) {
  return;
}

void tearDown(void) {
  return;
}
