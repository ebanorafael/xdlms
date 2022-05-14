/// @file

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /*  __cplusplus */

/*******************************************************************
 * EXTERNED DEFINES
 *******************************************************************/

#define STATUS(CLASS, VALUE)  ((CLASS << 8) | (VALUE))

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

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

/*******************************************************************
 * EXTERNED TYPES
 *******************************************************************/

typedef enum status_class_t {
  STATUS_CLASS_SYS = 0,
  STATUS_CLASS_ASN1 = 1,
  STATUS_CLASS_HDLC = 2,
  STATUS_CLASS_MAX
} status_class_t;

typedef enum status_t {
  STATUS_SUCCESS = 0,

  /* ARRAY status class */
  STATUS_ARRAY_INVALID_PARAMETER = STATUS(STATUS_CLASS_SYS, 1),
  STATUS_ARRAY_BUFFER_OVERFLOW = STATUS(STATUS_CLASS_SYS, 2),
  /* ASN.1 A-XDR status class */
	STATUS_ASN1_AXDR_INVALID_PARAMETER = STATUS(STATUS_CLASS_ASN1, 1),
	STATUS_ASN1_AXDR_DECODE_FAIL = STATUS(STATUS_CLASS_ASN1, 2),
	STATUS_ASN1_AXDR_ENCODE_FAIL = STATUS(STATUS_CLASS_ASN1, 3),
	STATUS_ASN1_AXDR_DECODE_TAG_UNMATCH = STATUS(STATUS_CLASS_ASN1, 4),
	STATUS_ASN1_AXDR_DECODE_LEN_UNMATCH = STATUS(STATUS_CLASS_ASN1, 5),
  /* HDLC status class*/
  STATUS_HDLC_INVALID_PARAMETER = STATUS(STATUS_CLASS_HDLC, 1),
  STATUS_HDLC_BUFFER_OVERFLOW = STATUS(STATUS_CLASS_HDLC, 2),
  STATUS_HDLC_ADDRESS_INVALID = STATUS(STATUS_CLASS_HDLC, 3),
  STATUS_HDLC_ADDRESS_PARSE_FAIL = STATUS(STATUS_CLASS_HDLC, 4),
  STATUS_HDLC_ADDRESS_BUILD_FAIL = STATUS(STATUS_CLASS_HDLC, 5),

} status_t;

/* no external use for this macro */
#ifdef STATUS
#undef STATUS
#endif /* STATUS */

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

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
