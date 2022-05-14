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

void xdlms_asn1_axdr_decode_tag_tests(void);
void xdlms_asn1_axdr_decode_len_tests(void);
void xdlms_asn1_axdr_decode_standard_tests(void);
void xdlms_asn1_axdr_decode_sequence_of_tests(void);
void xdlms_asn1_axdr_decode_sequence_of_bytes_tests(void);
void xdlms_asn1_axdr_decode_tests(void);
void xdlms_asn1_axdr_decode_validate_tests(void);
void xdlms_asn1_axdr_decode_list_tests(void);

#ifdef __cplusplus
}
#endif /*  __cplusplus */

