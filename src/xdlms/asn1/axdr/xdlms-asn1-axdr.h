/// @file

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /*  __cplusplus */

/*******************************************************************
 * EXTERNED DEFINES
 *******************************************************************/

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* System functioning includes start */

#include <stddef.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* System functioning includes end */

/* Module functioning includes start */

#include "array.h"

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "status.h"

/* Module functioning includes end */

/* Post includes defines start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Post includes defines end */

/*******************************************************************
 * EXTERNED TYPES
 *******************************************************************/

/*! DLMS ASN.1 A-XDR Data types tags, as specified in DLMS UA Green Book, 9.5 */
typedef enum xdlms_asn1_axdr_type_t {
	/*! DLMS ASN.1 A-XDR NULL data type */
	XDLMS_ASN1_AXDR_TYPE_NULL_DATA = 0,
	/*! DLMS ASN.1 A-XDR Array data type */
	XDLMS_ASN1_AXDR_TYPE_ARRAY = 1,
	/*! DLMS ASN.1 A-XDR Structure data type */
	XDLMS_ASN1_AXDR_TYPE_STRUCTURE = 2,
	/*! DLMS ASN.1 A-XDR Boolean data type */
	XDLMS_ASN1_AXDR_TYPE_BOOLEAN = 3,
	/*! DLMS ASN.1 A-XDR Bit-String data type */
	XDLMS_ASN1_AXDR_TYPE_BIT_STRING = 4,
	/*! DLMS ASN.1 A-XDR Integer 32-bits data type */
	XDLMS_ASN1_AXDR_TYPE_INT32 = 5,
	/*! DLMS ASN.1 A-XDR Unsigned Integer 32-bits data type */
	XDLMS_ASN1_AXDR_TYPE_UINT32 = 6,
	/*! DLMS ASN.1 A-XDR Octet-String data type */
	XDLMS_ASN1_AXDR_TYPE_OCTET_STRING = 9,
	/*! DLMS ASN.1 A-XDR Visible String data type */
	XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING = 10,
	/*! DLMS ASN.1 A-XDR UTF-8 Encoded String data type */
	XDLMS_ASN1_AXDR_TYPE_UTF8_STRING = 12,
	/*! DLMS ASN.1 A-XDR Binay-Coded Decimal data type */
	XDLMS_ASN1_AXDR_TYPE_BCD = 13,
	/*! DLMS ASN.1 A-XDR Integer 8-bits data type */
	XDLMS_ASN1_AXDR_TYPE_INT8 = 15,
	/*! DLMS ASN.1 A-XDR Integer 16-bits data type */
	XDLMS_ASN1_AXDR_TYPE_INT16 = 16,
	/*! DLMS ASN.1 A-XDR Unsigned Integer 8-bits data type */
	XDLMS_ASN1_AXDR_TYPE_UINT8 = 17,
	/*! DLMS ASN.1 A-XDR Unsigned Integer 16-bits data type */
	XDLMS_ASN1_AXDR_TYPE_UINT16 = 18,
	/*! DLMS ASN.1 A-XDR Compact Array data type */
	XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY = 19,
	/*! DLMS ASN.1 A-XDR Integer 64-bits data type */
	XDLMS_ASN1_AXDR_TYPE_INT64 = 20,
	/*! DLMS ASN.1 A-XDR Unsigned Integer 64-bits data type */
	XDLMS_ASN1_AXDR_TYPE_UINT64 = 21,
	/*! DLMS ASN.1 A-XDR Enumerated data type */
	XDLMS_ASN1_AXDR_TYPE_ENUM = 22,
	/*! DLMS ASN.1 A-XDR Float 32-bits data type */
	XDLMS_ASN1_AXDR_TYPE_FLOAT32 = 23,
	/*! DLMS ASN.1 A-XDR Float 64-bits data type */
	XDLMS_ASN1_AXDR_TYPE_FLOAT64 = 24,
	/*! DLMS ASN.1 A-XDR Date-Time data type */
	XDLMS_ASN1_AXDR_TYPE_DATE_TIME = 25,
	/*! DLMS ASN.1 A-XDR Date data type */
	XDLMS_ASN1_AXDR_TYPE_DATE = 26,
	/*! DLMS ASN.1 A-XDR Time data type */
	XDLMS_ASN1_AXDR_TYPE_TIME = 27,
	/*! DLMS ASN.1 A-XDR Delta Integer 8-bits data type */
	XDLMS_ASN1_AXDR_TYPE_DELTA_INT8 = 28,
	/*! DLMS ASN.1 A-XDR Delta Integer 16-bits data type */
	XDLMS_ASN1_AXDR_TYPE_DELTA_INT16 = 29,
	/*! DLMS ASN.1 A-XDR Delta Integer 32-bits data type */
	XDLMS_ASN1_AXDR_TYPE_DELTA_INT32 = 30,
	/*! DLMS ASN.1 A-XDR Delta Unsigned Integer 8-bits data type */
	XDLMS_ASN1_AXDR_TYPE_DELTA_UINT8 = 31,
	/*! DLMS ASN.1 A-XDR Delta Unsigned Integer 16-bits data type */
	XDLMS_ASN1_AXDR_TYPE_DELTA_UINT16 = 32,
	/*! DLMS ASN.1 A-XDR Delta Unsigned Integer 32-bits data type */
	XDLMS_ASN1_AXDR_TYPE_DELTA_UINT32 = 33,
	/*! DLMS ASN.1 A-XDR Max value data type */
	XDLMS_ASN1_AXDR_TYPE_MAX,
	/* ---------------------------- */
	/*! DLMS ASN.1 A-XDR invalid data type */
	XDLMS_ASN1_AXDR_TYPE_INVALID_1 = 7,
	/*! DLMS ASN.1 A-XDR invalid data type */
	XDLMS_ASN1_AXDR_TYPE_INVALID_2 = 8,
	/*! DLMS ASN.1 A-XDR invalid data type */
	XDLMS_ASN1_AXDR_TYPE_INVALID_3 = 11,
	/*! DLMS ASN.1 A-XDR invalid data type */
	XDLMS_ASN1_AXDR_TYPE_INVALID_4 = 14,
} xdlms_asn1_axdr_type_t;

/*! DLMS ASN.1 A-XDR Meta-data type */
typedef struct xdlms_asn1_axdr_meta_t {
	/*! DLMS ASN.1 A-XDR Data type tag (byte) */
	xdlms_asn1_axdr_type_t tag;
	/*! DLMS ASN.1 A-XDR Data type length */
	size_t len;
} xdlms_asn1_axdr_meta_t;

/*! DLMS ASN.1 A-XDR lib data type address */
typedef struct dlms_axdr_data_t {
	/*! Standard or Sequence data address */
	union {
		/*! Address for standard types access (integers, boolean, enumerated) */
		uint8_t *p_standard;
		/*! Address for sequence of bytes types access (byte-arrays and strings) */
		array_t *p_sequence;
	} contents;
	/*! Address for template of data (compact-array type) */
	array_t *p_template;
} xdlms_axdr_data_t;

/*! DLMS ASN.1 A-XDR lib resource */
typedef struct xdlms_asn1_axdr_resource_t {
	/*! Meta data information */
	xdlms_asn1_axdr_meta_t meta;
	/*! Data contents information */
	xdlms_axdr_data_t data;
} xdlms_asn1_axdr_resource_t;

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * EXTERNED DATA
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */

/*******************************************************************
 * EXTERNED FUNCTIONS
 *******************************************************************/

size_t
xdlms_asn1_axdr_get_size(
  const xdlms_asn1_axdr_type_t tag
);

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#ifdef __cplusplus
}
#endif /*  __cplusplus */
