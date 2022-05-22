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

#include <stdbool.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* System functioning includes end */

/* Module functioning includes start */

#include "hdlc-address.h"

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

/*******************************************************************
 * EXTERNED TYPES
 *******************************************************************/

typedef enum hdlc_defs_t {
	HDLC_FRAME_FORMAT = 0xa000,
	HDLC_FRAME_SEGMENT = 1 << 12,
	HDLC_FRAME_LEN_MASK = 0x07f,

} hdlc_defs_t;

typedef uint8_t hdlc_mac_control_t;

typedef struct hdlc_mac_address_t {
	hdlc_address_t src;
	hdlc_address_t dst;
} hdlc_mac_address_t;

typedef struct hdlc_mac_info_t {
	hdlc_mac_address_t address;
	hdlc_mac_control_t control;
	bool is_segmented;
	uint8_t *p_data;
} hdlc_mac_info_t;

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