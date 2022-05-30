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

#define XDLMS_HDLC_CONTROL_MAX_SEQUENCE \
	0x07

#define XDLMS_HDLC_CONTROL_IS_I(CONTROL) \
  (((CONTROL) & (1 << 0)) == 0)

#define XDLMS_HDLC_CONTROL_IS_RR(CONTROL) \
  (((CONTROL) & (1 << 0)) == 1)

#define XDLMS_HDLC_CONTROL_IS_RNR(CONTROL) \
  (((CONTROL) & 0x0f) == ((1 << 2) | (1 << 0)))

#define XDLMS_HDLC_CONTROL_IS_SNRM(CONTROL) \
  (((CONTROL) & ~(1 << 4)) == ((1 << 7) | (1 << 1) | (1 << 0)))

#define XDLMS_HDLC_CONTROL_IS_DISC(CONTROL) \
  (((CONTROL) & ~(1 << 4)) == ((1 << 6) | (1 << 1) | (1 << 0)))

#define XDLMS_HDLC_CONTROL_IS_UA(CONTROL) \
  (((CONTROL) & ~(1 << 4)) == ((1 << 6) | (1 << 5) | (1 << 1) | (1 << 0)))

#define XDLMS_HDLC_CONTROL_IS_DM(CONTROL) \
  (((CONTROL) & 0x0f) == 0x0f)

#define XDLMS_HDLC_CONTROL_IS_FRMR(CONTROL) \
  (((CONTROL) & ~(1 << 4)) == ((1 << 7) | (1 << 2) | (1 << 1) | (1 << 0)))

#define XDLMS_HDLC_CONTROL_IS_UI(CONTROL) \
  (((CONTROL) & ~(1 << 4)) == ((1 << 1) | (1 << 0)))

#define XDLMS_HDLC_CONTROL_GET_RRR(CONTROL) \
	(((CONTROL) >> 5) & XDLMS_HDLC_CONTROL_MAX_SEQUENCE)

#define XDLMS_HDLC_CONTROL_GET_SSS(CONTROL) \
	(((CONTROL) >> 1) & XDLMS_HDLC_CONTROL_MAX_SEQUENCE)

#endif /* UNIT_TESTS */

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* System functioning includes start */

#include <stdint.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "xdlms-hdlc.h"

/* System functioning includes end */

/* Module functioning includes start */

#include "status.h"

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

/*******************************************************************
 * EXTERNED TYPES
 *******************************************************************/

typedef struct hdlc_seq_num_t {
	uint32_t rrr;
	uint32_t sss;
} hdlc_seq_num_t;

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

status_t
xdlms_hdlc_control_parse(
	const uint32_t control,
	hdlc_seq_num_t p_to[static 1]
);

#ifdef UNIT_TESTS

STATIC status_t
xdlms_hdlc_control_rnr_frame_handle(
	const uint32_t control,
	hdlc_seq_num_t p_to[static 1]
);

STATIC status_t
xdlms_hdlc_control_rr_frame_handle(
	hdlc_seq_num_t p_to[static 1]
);

STATIC status_t
xdlms_hdlc_control_i_frame_handle(
	const uint32_t from,
	hdlc_seq_num_t p_to[static 1]
);

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
