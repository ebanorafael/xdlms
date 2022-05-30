///@file

/*******************************************************************
 * PRIVATE DEFINES
 *******************************************************************/

/* Module functioning defines start */

#ifdef UNIT_TESTS

#else

/*! @brief Hides internal function definitions when not in unit test environment */
#define STATIC    static

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
	(((CONTROL) & (0xe0)) >> 5)

#define XDLMS_HDLC_CONTROL_GET_SSS(CONTROL) \
	(((CONTROL) & (0x0e)) >> 1)

#endif /* UNIT_TESTS */

/* Module functioning defines end */

/*******************************************************************
 * INCLUDES
 *******************************************************************/

/* System functioning includes start */

#include <stdbool.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "utils.h"
#include "xdlms-hdlc-control.h"

/* System functioning includes end */

/* Module functioning includes start */

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

/* Module functioning includes end */

/*******************************************************************
 * PRIVATE TYPES
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

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

/*******************************************************************
 * PRIVATE PROTOTYPES
 *******************************************************************/

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

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

STATIC status_t
xdlms_hdlc_control_rnr_frame_handle(
	const uint32_t control,
	hdlc_seq_num_t p_to[static 1]) {

	ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	return STATUS_SUCCESS;
}

STATIC status_t
xdlms_hdlc_control_rr_frame_handle(
	hdlc_seq_num_t p_to[static 1]) {

	ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	p_to[0] = (hdlc_seq_num_t) { .rrr = 0, .sss = 0 };
	return STATUS_SUCCESS;
}

STATIC status_t
xdlms_hdlc_control_i_frame_handle(
	const uint32_t from,
	hdlc_seq_num_t p_to[static 1]) {

  ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	hdlc_seq_num_t rx_curr = {
		.rrr = XDLMS_HDLC_CONTROL_GET_RRR(from),
		.sss = XDLMS_HDLC_CONTROL_GET_SSS(from)
	};

	if (rx_curr.rrr != p_to->sss) {
		/* rx counter does not match tx counter */
		return STATUS_HDLC_INVALID_RX_SEQ_NUMBER;
	}

	if (rx_curr.sss < p_to->rrr) {
		/* tx counter does not match rx counter */
		return STATUS_HDLC_INVALID_TX_SEQ_NUMBER;
	}

	p_to->rrr += 1;
	if (p_to->rrr == XDLMS_HDLC_CONTROL_MAX_SEQUENCE) {
		p_to->rrr = 0;
	}

	return STATUS_SUCCESS;
}

status_t
xdlms_hdlc_control_parse(
	const uint32_t control,
	hdlc_seq_num_t p_to[static 1]) {

	if (XDLMS_HDLC_CONTROL_IS_I(control) == true) {
		return xdlms_hdlc_control_i_frame_handle(control, p_to);
	}

	if (XDLMS_HDLC_CONTROL_IS_RR(control) == true) {
		return xdlms_hdlc_control_rr_frame_handle(p_to);
	}

	if (XDLMS_HDLC_CONTROL_IS_RNR(control) == true) {
		return xdlms_hdlc_control_rnr_frame_handle(control, p_to);
	}

	if (XDLMS_HDLC_CONTROL_IS_DISC(control) == true) {
		return STATUS_SUCCESS;
	}

	if (XDLMS_HDLC_CONTROL_IS_UA(control) == true) {
		return STATUS_SUCCESS;
	}

	if (XDLMS_HDLC_CONTROL_IS_DM(control) == true) {
		return STATUS_SUCCESS;
	}

	if (XDLMS_HDLC_CONTROL_IS_FRMR(control) == true) {
		return STATUS_SUCCESS;
	}

	if (XDLMS_HDLC_CONTROL_IS_UI(control) == true) {
		return STATUS_SUCCESS;
	}

	return STATUS_SUCCESS;
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
