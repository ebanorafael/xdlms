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

/*! Describes a DLMS ASN.1 A-XDR invalid data type (initialization purposes) */
#define XDLMS_ASN1_AXDR_ENCODE_INVALID \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_MAX, .len = (size_t)~0 }, \
		}

/*! Describes a DLMS ASN.1 A-XDR NULL data type */
#define XDLMS_ASN1_AXDR_ENCODE_NULL \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_NULL_DATA, .len = 0 }, \
	.data = { .contents.p_standard = NULL } \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Array data type
 * @param LEN Number of elements of the array
 */
#define XDLMS_ASN1_AXDR_ENCODE_ARRAY(LEN) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_ARRAY, .len = (LEN) }, \
	.data = { .contents.p_sequence = NULL } \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Structure data type
 * @param LEN Number of elements of the array
 */
#define XDLMS_ASN1_AXDR_ENCODE_STRUCTURE(LEN) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_STRUCTURE, .len = (LEN) }, \
	.data = { .contents.p_sequence = NULL } \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Octet String data type
 * @param P_FROM Address o Byte-Array Fifo that controls access to data
 */
#define XDLMS_ASN1_AXDR_ENCODE_OCTET(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_OCTET_STRING, .len = 0 }, \
	.data = { .contents.p_sequence = (P_FROM) } \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Visible String data type
 * @param P_FROM Address o Byte-Array Fifo that controls access to data
 */
#define XDLMS_ASN1_AXDR_ENCODE_VISIBLE(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING, .len = 0 }, \
	.data = { .contents.p_sequence = (P_FROM) } \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR UTF-8 encoded String data type
 * @param P_FROM Address o Byte-Array Fifo that controls access to data
 */
#define XDLMS_ASN1_AXDR_ENCODE_UTF8_STRING(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_UTF8_STRING, .len = 0 }, \
	.data = { .contents.p_sequence = (P_FROM) } \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Signed Integer of 8-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_INT8(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_INT8, .len = sizeof(int8_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(uint8_t *)(P_FROM) }, \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Unsigned Integer of 8-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_UINT8(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_UINT8, .len = sizeof(uint8_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(P_FROM) }, \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Signed Integer of 16-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_INT16(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_INT16, .len = sizeof(int16_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(P_FROM) }, \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Unsigned Integer of 16-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_UINT16(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_UINT16, .len = sizeof(uint16_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(P_FROM) }, \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Signed Integer of 32-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_INT32(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_INT32, .len = sizeof(int32_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(P_FROM) }, \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Unsigned Integer of 32-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_UINT32(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_UINT32, .len = sizeof(uint32_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(P_FROM) }, \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Signed Integer of 64-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_INT64(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_INT64, .len = sizeof(int64_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(P_FROM) }, \
		}

/*!
 * @brief Describes a DLMS ASN.1 A-XDR Unsigned Integer of 64-bits
 * @param P_FROM Address of variable holding data
 */
#define XDLMS_ASN1_AXDR_ENCODE_UINT64(P_FROM) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_UINT64, .len = sizeof(uint64_t) }, \
	.data = { .contents.p_standard = (uint8_t *)(P_FROM) }, \
		}

#define XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(P_TO) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_MAX, .len = -1 }, \
	.data = { .contents.p_standard = (uint8_t *)(P_TO) } \
		}

#define XDLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(P_TO) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_MAX, .len = -1 }, \
	.data = { .contents.p_sequence = (array_t *)(P_TO) } \
		}

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

/*!
 * @brief Formats a list of data information as DLMS ASN.1 A-XDR encoding
 * @param p_from Address of list of resources and it's DLMS ASN.1 A-XDR data
 * description
 * @param p_to Address of buffer to hold encoded data
 * @param size Size of the list of resources
 * @return Status of the operation
 */
status_t
xdlms_asn1_axdr_encode_list(
  const xdlms_asn1_axdr_resource_t p_from[static 1],
  array_t p_to[static 1],
  const size_t size
);

/*!
 * @brief Populates data given information as DLMS ASN.1 A-XDR format encoding
 * @param p_from Address of buffer holding encoded data
 * @param p_to Address of list of resources and it's DLMS ASN.1 A-XDR data
 * description to hold encoded data
 * @param size Size of the list of resources
 * @return Status of the operation
 */
status_t
xdlms_asn1_axdr_decode_list(
  array_t p_from[static 1],
  const xdlms_asn1_axdr_resource_t p_to[static 1],
  const size_t size
);

#ifdef UNIT_TESTS

STATIC size_t
xdlms_asn1_axdr_get_size(
  const xdlms_asn1_axdr_type_t tag
);

STATIC xdlms_asn1_axdr_type_t
xdlms_asn1_axdr_decode_tag(
  const array_t p_from[static 1]
);

STATIC size_t
xdlms_asn1_axdr_decode_len(
  const array_t p_from[static 1]
);

STATIC status_t
xdlms_asn1_axdr_decode_standard(
  const array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_decode_sequence_of(
  const array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_decode_sequence_of_bytes(
  array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_decode(
  array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_decode_validate(
  const array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode_tag(
  const xdlms_asn1_axdr_type_t tag,
  const array_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode_multi_byte_len(
  const size_t from,
  const array_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode_len(
  const size_t from,
  const array_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode_standard(
  const uint8_t p_from[static 1],
  const array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t tag
);

STATIC status_t
xdlms_asn1_axdr_encode_sequence_of(
  const array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t type,
  const size_t size
);

STATIC status_t
xdlms_asn1_axdr_encode_sequence_of_bytes(
  array_t p_from[static 1],
  array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t tag
);

STATIC status_t
xdlms_asn1_axdr_encode_compact_array(
  array_t p_from_template[static 1],
  array_t p_from_contents[static 1],
  array_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode(
  const xdlms_asn1_axdr_resource_t p_from[static 1],
  array_t p_to[static 1]
);

#endif /* UNIT_TESTS */

#ifdef __cplusplus
}
#endif /*  __cplusplus */
