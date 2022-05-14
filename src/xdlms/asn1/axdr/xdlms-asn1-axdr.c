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

#include <stdint.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* System functioning includes end */

/* Module functioning includes start */

#include "xdlms-asn1-axdr.h"

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

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

/*!
 * @brief Retrieves the size of data given its type
 * @param tag Tag type of the data
 * @return Standard: data size,
 *         Sequence: 0,
 *         Invalid: 0xff
 */
STATIC size_t
xdlms_asn1_axdr_get_size(
		const xdlms_asn1_axdr_type_t tag
);

/*!
 * @brief Decodes a DLMS ASN.1 A-XDR Data tag
 * @param p_from Byte-Array Fifo controlled structure address to pull data from
 * @return Decoded tag if success, ASN.1 A-XDR tags number if fail
 */
STATIC xdlms_asn1_axdr_type_t
xdlms_asn1_axdr_decode_tag(
		const array_t p_from[static 1]
);

/*!
 * @brief Decodes a DLMS ASN.1 A-XDR Data length
 * @param p_from Byte-Array Fifo controlled structure address to pull data from
 * @return Size decoded if success, -1 if fail
 */
STATIC size_t
xdlms_asn1_axdr_decode_len(
		const array_t p_from[static 1]
);

/*!
 * @brief Decodes a DLMS ASN.1 A-XDR Standard data (integer, boolean, enum)
 * @param p_from Byte-Array Fifo controlled structure address to pull data from
 * @param p_to DLMS ASN.1 A-XDR resource to hold Data information
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_decode_standard(
		const array_t p_from[static 1],
		const xdlms_asn1_axdr_resource_t p_to[static 1]
);

/*!
 * @brief Decodes a DLMS ASN.1 A-XDR Sequence-Of
 * @param p_from Byte-Array Fifo controlled structure address to pull data from
 * @param p_to DLMS ASN.1 A-XDR resource to hold Data information
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_decode_sequence_of(
		const array_t p_from[static 1],
		const xdlms_asn1_axdr_resource_t p_to[static 1]
);

/*!
 * @brief Decodes a DLMS ASN.1 A-XDR Sequence of bytes data
 * @param p_from Byte-Array Fifo controlled structure address to pull data from
 * @param p_to DLMS ASN.1 A-XDR resource to hold Data information
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_decode_sequence_of_bytes(
		const array_t p_from[static 1],
		const xdlms_asn1_axdr_resource_t p_to[static 1]
);

/*!
 * @brief Decodes a DLMS ASN.1 A-XDR meta-data (tag and length, if needed) and
 * data
 * @param p_from Byte-Array Fifo controlled structure address to push data to
 * @param p_to Address of DLMS ASN.1 A-XDR lib. resource holding data descriptor and
 * contents
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_decode(
		const array_t p_from[static 1],
		const xdlms_asn1_axdr_resource_t p_to[static 1]
);

/*!
 * @brief Validates input data against expected data (meta-data!)
 * @param p_from
 * @param p_from Byte-Array Fifo controlled structure address to push data to
 * @param p_to Address of DLMS ASN.1 A-XDR lib. resource holding data descriptor
 */
STATIC status_t
xdlms_asn1_axdr_decode_validate(
		const array_t p_from[static 1],
		const xdlms_asn1_axdr_resource_t p_to[static 1]
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR Data tag
 * @param tag Data type tag to encode
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @return Decoded tag if success, ASN.1 A-XDR tags number if fail
 */
STATIC status_t
xdlms_asn1_axdr_encode_tag(
		const xdlms_asn1_axdr_type_t tag,
		const array_t p_to[static 1]
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR Data multi-byte length
 * @param from Size to encode
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_encode_multi_byte_len(
		const size_t from,
		const array_t p_to[static 1]
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR Data length
 * @param from Size to encode
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_encode_len(
		const size_t from,
		const array_t p_to[static 1]
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR Standard data type (integer, boolean, enumerations)
 * @param p_from Address of data to encode
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @param tag DLMS ASN.1 A-XDR data type tag to encode
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_encode_standard(
		const uint8_t p_from[static 1],
		const array_t p_to[static 1],
		const xdlms_asn1_axdr_type_t tag
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR sequence of information (tag and length)
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @param type DLMS ASN.1 A-XDR data type tag
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_encode_sequence_of(
		const array_t p_to[static 1],
		const xdlms_asn1_axdr_type_t type,
		const size_t size
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR sequence of bytes meta-data
 * (tag and length) and it's data
 * @param p_from Byte-Array Fifo controlled structure address to push data to
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @param type DLMS ASN.1 A-XDR data type tag
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_encode_sequence_of_bytes(
		const array_t p_from[static 1],
		const array_t p_to[static 1],
		const xdlms_asn1_axdr_type_t tag
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR a Compact-Array data type
 * @param p_from_tpl Byte-Array Fifo controlled structure address with template
 * @param p_from_ctc Byte-Array Fifo controlled structure address with contents
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_encode_compact_array(
		const array_t p_from_template[static 1],
		const array_t p_from_contents[static 1],
		const array_t p_to[static 1]
);

/*!
 * @brief Encodes a DLMS ASN.1 A-XDR meta-data (tag and length, if needed) and
 * data
 * @param p_from Address of DLMS ASN.1 A-XDR lib. resource holding data descriptor and
 * contents
 * @param p_to Byte-Array Fifo controlled structure address to push data to
 * @return Status of the operation
 */
STATIC status_t
xdlms_asn1_axdr_encode(
		const xdlms_asn1_axdr_resource_t p_from[static 1],
		const array_t p_to[static 1]
);

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

size_t xdlms_asn1_axdr_get_size(
  const xdlms_asn1_axdr_type_t tag) {
	static const uint8_t xdlms_asn1_axdr_type_size[] = {
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
	  [XDLMS_ASN1_AXDR_TYPE_INVALID_4] = 0xff,
	  [XDLMS_ASN1_AXDR_TYPE_MAX] = 0xff
	};

	return xdlms_asn1_axdr_type_size[tag];
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
