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


#endif /* UNIT_TESTS */

/* System functioning includes end */

/* Module functioning includes start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

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

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */
 
#ifdef __cplusplus
}
#endif /*  __cplusplus */
