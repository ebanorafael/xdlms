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

#include "xdlms-asn1-axdr.h"
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

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Post includes defines end */

/*******************************************************************
 * EXTERNED TYPES
 *******************************************************************/

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

#ifdef UNIT_TESTS

STATIC status_t
xdlms_asn1_axdr_encode_tag(
  const xdlms_asn1_axdr_type_t tag,
  array_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode_multi_byte_len(
  const size_t from,
  array_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode_len(
  const size_t from,
  array_t p_to[static 1]
);

STATIC status_t
xdlms_asn1_axdr_encode_standard(
  const uint8_t p_from[static 1],
  array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t tag
);

STATIC status_t
xdlms_asn1_axdr_encode_sequence_of(
  array_t p_to[static 1],
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
