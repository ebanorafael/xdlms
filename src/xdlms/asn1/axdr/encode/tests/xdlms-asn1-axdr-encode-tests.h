///@file

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /*  __cplusplus */

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/*******************************************************************
 * PUBLIC DEFINES
 *******************************************************************/

/*******************************************************************
 * PUBLIC TYPES
 *******************************************************************/

/*******************************************************************
 * PUBLIC FUNCTIONS
 *******************************************************************/

void dlms_asn1_axdr_get_size_tests(void);

void xdlms_asn1_axdr_encode_tag_tests(void);
void xdlms_asn1_axdr_encode_multi_byte_len_tests(void);
void xdlms_asn1_axdr_encode_len_tests(void);
void xdlms_asn1_axdr_encode_standard_tests(void);
void xdlms_asn1_axdr_encode_sequence_of_tests(void);
void xdlms_asn1_axdr_encode_sequence_of_bytes_tests(void);
void xdlms_asn1_axdr_encode_compact_array_tests(void);
void xdlms_ans1_axdr_encode_tests(void);

void xdlms_asn1_axdr_encode_list_tests(void);

#ifdef __cplusplus
}
#endif /*  __cplusplus */

