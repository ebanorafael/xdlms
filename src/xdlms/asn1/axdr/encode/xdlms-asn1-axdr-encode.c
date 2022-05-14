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

#include "xdlms-asn1-axdr-encode.h"

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

STATIC status_t xdlms_asn1_axdr_encode_tag(
  const xdlms_asn1_axdr_type_t tag,
  array_t p_to[static 1]) {
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

	status_t status = array_push_hton((uint8_t *)&tag, p_to, sizeof(uint8_t));
	RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);

	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_multi_byte_len(
  const size_t from,
  array_t p_to[static 1]) {
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

	status |= array_push_hton((uint8_t *)&len, p_to, sizeof(uint8_t));
	status |= array_push_hton((uint8_t *)&from, p_to, len & 0x7f);

	RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);
	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_len(
  const size_t from,
  array_t p_to[static 1]) {
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
  array_t p_to[static 1],
  const xdlms_asn1_axdr_type_t tag) {

	const size_t size = xdlms_asn1_axdr_get_size(tag);
	RETURN_IF_FALSE(size != 0, STATUS_ASN1_AXDR_INVALID_PARAMETER);
	RETURN_IF_FALSE(size != 0xff, STATUS_ASN1_AXDR_INVALID_PARAMETER);

	status_t status = STATUS_SUCCESS;
	status |= array_push_hton((uint8_t *)&tag, p_to, sizeof(uint8_t));
	status |= array_push_hton(p_from, p_to, size);

	RETURN_IF_FALSE(status == STATUS_SUCCESS, STATUS_ASN1_AXDR_ENCODE_FAIL);
	return STATUS_SUCCESS;
}

STATIC status_t xdlms_asn1_axdr_encode_sequence_of(
  array_t p_to[static 1],
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

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
