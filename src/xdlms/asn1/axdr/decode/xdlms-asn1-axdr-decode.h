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

#define XDLMS_ASN1_AXDR_DECODE_INITIALIZE_STD(P_TO) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_MAX, .len = (size_t)~0 }, \
	.data = { .contents.p_standard = (uint8_t *)(P_TO) } \
		}

#define XDLMS_ASN1_AXDR_DECODE_INITIALIZE_SEQ(P_TO) \
		{ \
	.meta = { .tag = XDLMS_ASN1_AXDR_TYPE_MAX, .len = (size_t)~0 }, \
	.data = { .contents.p_sequence = (array_t *)(P_TO) } \
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

#endif /* UNIT_TESTS */

#ifdef __cplusplus
}
#endif /*  __cplusplus */
