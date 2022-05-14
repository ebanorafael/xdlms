///@file

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /*  __cplusplus */

/*******************************************************************
 * INCLUDES
 *******************************************************************/

#include "fw_confs.h"

/*******************************************************************
 * PUBLIC DEFINES
 *******************************************************************/

/*******************************************************************
 * PUBLIC TYPES
 *******************************************************************/

/*******************************************************************
 * PUBLIC FUNCTIONS
 *******************************************************************/

TEST_FUNCTION(dlms_asn1_axdr_get_size_tests);

TEST_FUNCTION(dlms_asn1_axdr_decode_tag_tests);
TEST_FUNCTION(dlms_asn1_axdr_decode_len_tests);
TEST_FUNCTION(dlms_asn1_axdr_decode_standard_tests);
TEST_FUNCTION(dlms_asn1_axdr_decode_sequence_of_tests);
TEST_FUNCTION(dlms_asn1_axdr_decode_sequence_of_bytes_tests);
TEST_FUNCTION(dlms_asn1_axdr_decode_tests);
TEST_FUNCTION(dlms_asn1_axdr_decode_validate_tests);

TEST_FUNCTION(dlms_asn1_axdr_encode_tag_tests);
TEST_FUNCTION(dlms_asn1_axdr_encode_multi_byte_len_tests);
TEST_FUNCTION(dlms_asn1_axdr_encode_len_tests);
TEST_FUNCTION(dlms_asn1_axdr_encode_standard_tests);
TEST_FUNCTION(dlms_asn1_axdr_encode_sequence_of_tests);
TEST_FUNCTION(dlms_asn1_axdr_encode_sequence_of_bytes_tests);
TEST_FUNCTION(dlms_asn1_axdr_encode_compact_array_tests);
TEST_FUNCTION(dlms_ans1_axdr_encode_tests);

TEST_FUNCTION(dlms_asn1_axdr_encode_list_tests);
TEST_FUNCTION(dlms_asn1_axdr_decode_list_tests);

#ifdef __cplusplus
}
#endif /*  __cplusplus */

