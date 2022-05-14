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

/* System functioning includes end */

/* Module functioning includes start */

#include "utils.h"

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "xdlms-asn1-axdr.h"

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

STATIC size_t xdlms_asn1_axdr_get_size(
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
	  [XDLMS_ASN1_AXDR_TYPE_MAX] = 0xff };

	return xdlms_asn1_axdr_type_size[tag];
}

/* ========= DLMS ASN.1 AXDR Decode functions start ========= */

STATIC xdlms_asn1_axdr_type_t xdlms_asn1_axdr_decode_tag(
  const array_t p_from[static 1]) {
	xdlms_asn1_axdr_type_t tag = XDLMS_ASN1_AXDR_TYPE_NULL_DATA;

	status_t status = STATUS_SUCCESS;

	status = array_pull_hton(p_from, (uint8_t *) &tag, sizeof(uint8_t));
	RETURN_IF_FALSE(status == STATUS_SUCCESS, XDLMS_ASN1_AXDR_TYPE_MAX);

	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_1,
	                   XDLMS_ASN1_AXDR_TYPE_MAX);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_2,
	                   XDLMS_ASN1_AXDR_TYPE_MAX);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_3,
	                   XDLMS_ASN1_AXDR_TYPE_MAX);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_4,
	                   XDLMS_ASN1_AXDR_TYPE_MAX);

	return tag;
}

STATIC size_t xdlms_asn1_axdr_decode_len(
  const array_t p_from[static 1]) {

	size_t len = 0;
	status_t status = STATUS_SUCCESS;

	status = array_pull_hton(p_from, (uint8_t *) &len, sizeof(uint8_t));
	RETURN_IF_FALSE(status == STATUS_SUCCESS, (size_t) ~0);

	if ((len & 0x80) == 0) {
		return len;
	}

	len &= 0x7f;

	/* more than 4GB of data to deserialize */
	RETURN_IF_FALSE(!(len > sizeof(uint32_t)), (size_t) ~0);

	status = array_pull_hton(p_from, (uint8_t *) &len, len);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, (size_t) ~0);

	return len;
}

STATIC status_t xdlms_asn1_axdr_decode_standard(
  const array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]) {
	ASSERT(p_to != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	p_to[0] = (xdlms_asn1_axdr_resource_t )
			XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(p_to->data.contents.p_standard);

	const xdlms_asn1_axdr_type_t tag = xdlms_asn1_axdr_decode_tag(p_from);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_MAX,
	                   STATUS_ASN1_AXDR_DECODE_FAIL);

	const size_t size = xdlms_asn1_axdr_get_size(tag);
	RETURN_IF_FALSE(size != 0, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	p_to->meta.tag = tag;
	p_to->meta.len = size;
	status_t arr_status = array_pull_hton(p_from,
	                                      p_to->data.contents.p_standard,
	                                      p_to->meta.len);
	RETURN_IF_FALSE(arr_status == STATUS_SUCCESS,
	                   STATUS_ASN1_AXDR_DECODE_FAIL);

	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_decode_sequence_of(
  const array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]) {
	ASSERT(p_to != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	p_to[0] = (xdlms_asn1_axdr_resource_t )
		XDLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(p_to->data.contents.p_sequence);

	const xdlms_asn1_axdr_type_t tag = xdlms_asn1_axdr_decode_tag(p_from);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_MAX,
	                   STATUS_ASN1_AXDR_DECODE_FAIL);

	size_t size = xdlms_asn1_axdr_get_size(tag);
	p_to->meta.tag = tag;
	p_to->meta.len = size;

	RETURN_IF_FALSE(size == 0, STATUS_SUCCESS);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_NULL_DATA, STATUS_SUCCESS);

	/* 'sequence of' and 'sequence of bytes' types */
	size = xdlms_asn1_axdr_decode_len(p_from);
	RETURN_IF_FALSE(size != (size_t) ~0, STATUS_ASN1_AXDR_DECODE_FAIL);

	p_to->meta.len = size;
	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_decode_sequence_of_bytes(
  array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]) {

	const status_t axdr_status = xdlms_asn1_axdr_decode_sequence_of(p_from, p_to);
	RETURN_IF_FALSE(axdr_status == STATUS_SUCCESS, axdr_status);

	const status_t arr_status = array_move(p_from,
	                                       p_to->data.contents.p_sequence,
	                                       p_to->meta.len);
	RETURN_IF_FALSE(arr_status == STATUS_SUCCESS,
	                   STATUS_ASN1_AXDR_DECODE_FAIL);

	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_decode(
  array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]) {
	ASSERT(p_to != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	ASSERT(p_from != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	p_to[0] = (xdlms_asn1_axdr_resource_t )
		XDLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(p_to->data.contents.p_standard);

	if (1) { /* capture data information first */
		array_t from = p_from[0];

		const status_t status = xdlms_asn1_axdr_decode_sequence_of(&from, p_to);
		RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	switch(p_to->meta.tag) {
		case (XDLMS_ASN1_AXDR_TYPE_NULL_DATA): {
			return xdlms_asn1_axdr_decode_tag(p_from);
		}
		case (XDLMS_ASN1_AXDR_TYPE_ARRAY):
		case (XDLMS_ASN1_AXDR_TYPE_STRUCTURE): {
			return xdlms_asn1_axdr_decode_sequence_of(p_from, p_to);
		}
		case (XDLMS_ASN1_AXDR_TYPE_BIT_STRING): {
			/* @ToDo: Implementation pending */
			break;
		}
		case (XDLMS_ASN1_AXDR_TYPE_OCTET_STRING):
		case (XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING):
		case (XDLMS_ASN1_AXDR_TYPE_UTF8_STRING): {
			return xdlms_asn1_axdr_decode_sequence_of_bytes(p_from, p_to);
		}
		case (XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY): {
			/* @ToDo: Implementation pending */
			break;
		}
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_1):
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_2):
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_3):
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_4):
		case (XDLMS_ASN1_AXDR_TYPE_MAX): {
			break;
		}
		default: { /* standard data types: integer, boolean and enumerated */
			return xdlms_asn1_axdr_decode_standard(p_from, p_to);
		}
	}

	return STATUS_ASN1_AXDR_DECODE_FAIL;
}

STATIC status_t xdlms_asn1_axdr_decode_validate(
  const array_t p_from[static 1],
  xdlms_asn1_axdr_resource_t p_to[static 1]) {
	ASSERT(p_from != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	ASSERT(p_to != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	xdlms_asn1_axdr_resource_t to =
	XDLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(NULL);

	if (1) { /* capture data tag and length */
		array_t from = p_from[0];

		status_t status = xdlms_asn1_axdr_decode_sequence_of(&from, &to);
		RETURN_IF_FALSE(status == STATUS_SUCCESS, status);
	}

	if (p_to->meta.tag != to.meta.tag) { /* @ToDo: log event */
		return STATUS_ASN1_AXDR_DECODE_TAG_UNMATCH;
	}

	if (p_to->meta.len == 0) {
		if ((p_to->meta.tag == XDLMS_ASN1_AXDR_TYPE_ARRAY) || (p_to->meta.tag == XDLMS_ASN1_AXDR_TYPE_STRUCTURE)) {
			p_to->meta.len = to.meta.len;
		}

		return STATUS_SUCCESS;
	}

	if (p_to->meta.len != to.meta.len) { /* @ToDo: log event */
		return STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH;
	}

	return STATUS_SUCCESS;
}

/* ========== DLMS ASN.1 AXDR Decode functions end ========== */

/* ========= DLMS ASN.1 AXDR Encode functions start ========= */

STATIC status_t xdlms_asn1_axdr_encode_tag(
  const xdlms_asn1_axdr_type_t tag,
  const array_t p_to[static 1]) {
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_1,
	                   STATUS_ASN1_AXDR_INVALID_PARAMETER);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_2,
	                   STATUS_ASN1_AXDR_INVALID_PARAMETER);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_3,
	                   STATUS_ASN1_AXDR_INVALID_PARAMETER);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_INVALID_4,
	                   STATUS_ASN1_AXDR_INVALID_PARAMETER);
	RETURN_IF_FALSE(tag != XDLMS_ASN1_AXDR_TYPE_MAX,
	                   STATUS_ASN1_AXDR_INVALID_PARAMETER);

	status_t status = array_push_hton((uint8_t *) &tag, p_to, sizeof(uint8_t));
	RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);

	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_multi_byte_len(
  const size_t from,
  const array_t p_to[static 1]) {
	RETURN_IF_FALSE(from > 127, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	size_t len = 0x80;

	if ((from & 0x000000ff) != 0) {
		len = 0x81;
	}

	if ((from & 0x0000ff00) != 0) {
		len = 0x82;
	}

	if ((from & 0x00ff0000) != 0) {
		len = 0x83;
	}

	if ((from & 0xff000000) != 0) {
		len = 0x84;
	}

	/* max. in 4GB data */

	status_t status = STATUS_SUCCESS;

	status |= array_push_hton((uint8_t *) &len, p_to, sizeof(uint8_t));
	status |= array_push_hton((uint8_t *) &from, p_to, len & 0x7f);

	RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);
	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_len(
  const size_t from,
  const array_t p_to[static 1]) {
	if (from < 0x80) {
		const status_t status = array_push_hton((uint8_t *) &from,
		                                        p_to,
		                                        sizeof(uint8_t));
		RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);
		return STATUS_SUCCESS;
	}

	return xdlms_asn1_axdr_encode_multi_byte_len(from, p_to);
}

STATIC status_t xdlms_asn1_axdr_encode_standard(
  const uint8_t p_from[static 1],
  const array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t tag) {

	const size_t size = xdlms_asn1_axdr_get_size(tag);
	RETURN_IF_FALSE(size != 0, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	RETURN_IF_FALSE(size != 0xff, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	status_t status = STATUS_SUCCESS;
	status |= array_push_hton((uint8_t *) &tag, p_to, sizeof(uint8_t));
	status |= array_push_hton(p_from, p_to, size);

	RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);
	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_sequence_of(
  const array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t type,
  const size_t size) {

	status_t status = xdlms_asn1_axdr_encode_tag(type, p_to);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	status = xdlms_asn1_axdr_encode_len(size, p_to);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_sequence_of_bytes(
  array_t p_from[static 1],
  array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t tag) {

	size_t len = 0;
	status_t status = STATUS_SUCCESS;

	len = array_used(p_from);
	status = xdlms_asn1_axdr_encode_sequence_of(p_to, tag, len);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

	len = array_used(p_from);
	status = array_move(p_from, p_to, len);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);

	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_compact_array(
  array_t p_from_template[static 1],
  array_t p_from_contents[static 1],
  array_t p_to[static 1]) {

	status_t axdr_status =
		xdlms_asn1_axdr_encode_tag(XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY, p_to);
	RETURN_IF_FALSE(axdr_status == STATUS_SUCCESS, axdr_status);

	size_t size = array_used(p_from_template);
	status_t arr_status = array_move(p_from_template, p_to, size);
	RETURN_IF_FALSE(arr_status == STATUS_SUCCESS,
	                   STATUS_ASN1_AXDR_ENCODE_FAIL);

	size = array_used(p_from_contents);
	RETURN_IF_FALSE(size != (size_t)~0, STATUS_ASN1_AXDR_ENCODE_FAIL);

	axdr_status = xdlms_asn1_axdr_encode_len(size, p_to);
	RETURN_IF_FALSE(axdr_status == STATUS_SUCCESS, axdr_status);

	arr_status = array_move(p_from_contents, p_to, size);
	RETURN_IF_FALSE(arr_status == STATUS_SUCCESS,
	                   STATUS_ASN1_AXDR_ENCODE_FAIL);

	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode(
  const xdlms_asn1_axdr_resource_t p_from[static 1],
  array_t p_to[static 1]) {
	ASSERT(p_from != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	switch(p_from->meta.tag) {
		case (XDLMS_ASN1_AXDR_TYPE_NULL_DATA): {
			return xdlms_asn1_axdr_encode_tag(p_from->meta.tag, p_to);
		}
		case (XDLMS_ASN1_AXDR_TYPE_ARRAY):
		case (XDLMS_ASN1_AXDR_TYPE_STRUCTURE): {
			return xdlms_asn1_axdr_encode_sequence_of(p_to,
			                                          p_from->meta.tag,
			                                          p_from->meta.len);
		}
		case (XDLMS_ASN1_AXDR_TYPE_BIT_STRING): {
			/* @ToDo: Implementation pending */
			break;
		}
		case (XDLMS_ASN1_AXDR_TYPE_OCTET_STRING):
		case (XDLMS_ASN1_AXDR_TYPE_VISIBLE_STRING):
		case (XDLMS_ASN1_AXDR_TYPE_UTF8_STRING): {
			return xdlms_asn1_axdr_encode_sequence_of_bytes(p_from->data.contents.p_sequence,
			                                                p_to,
			                                                p_from->meta.tag);
		}
		case (XDLMS_ASN1_AXDR_TYPE_COMPACT_ARRAY): {
			return xdlms_asn1_axdr_encode_compact_array(p_from->data.p_template,
			                                            p_from->data.contents.p_sequence,
			                                            p_to);
		}
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_1):
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_2):
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_3):
		case (XDLMS_ASN1_AXDR_TYPE_INVALID_4):
		case (XDLMS_ASN1_AXDR_TYPE_MAX): {
			break;
		}
		default: { /* standard data types: integer, boolean and enumerated */
			return xdlms_asn1_axdr_encode_standard(p_from->data.contents.p_standard,
			                                       p_to,
			                                       p_from->meta.tag);
		}
	}

	return STATUS_ASN1_AXDR_ENCODE_FAIL;
}

/* ========== DLMS ASN.1 AXDR Encode functions end ========== */

/* ======== DLMS ASN.1 AXDR lib. API functions start ======== */

status_t xdlms_asn1_axdr_encode_list(
  const xdlms_asn1_axdr_resource_t p_from[static 1],
  array_t p_to[static 1],
  const size_t size) {
	ASSERT(p_from != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	for (size_t index = 0; index < size; index++) {
		status_t status = xdlms_asn1_axdr_encode(&p_from[index], p_to);
		RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);
	}

	return STATUS_SUCCESS;
}

status_t xdlms_asn1_axdr_decode_list(
  array_t p_from[static 1],
  const xdlms_asn1_axdr_resource_t p_to[static 1],
  const size_t size) {
	ASSERT(p_to != NULL, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	for (size_t index = 0; index < size; index++) {
		xdlms_asn1_axdr_resource_t *p_dst = (xdlms_asn1_axdr_resource_t *)&p_to[index];

		if (1) { /* validate input data against expected */
			status_t status = xdlms_asn1_axdr_decode_validate(p_from, p_dst);
			RETURN_IF_FALSE(status == STATUS_SUCCESS, status);
		}

		status_t status = xdlms_asn1_axdr_decode(p_from, p_dst);
		RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_DECODE_FAIL);
	}

	return STATUS_SUCCESS;
}

/* ======== DLMS ASN.1 AXDR lib. API functions end ======== */

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
