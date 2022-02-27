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

#include "utils.h"

/* System functioning includes end */

/* Module functioning includes start */

#include "hdlc-address.h"

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

STATIC uint32_t
hdlc_parse_address(const size_t size,
                   const uint8_t p_from[size]);

STATIC status_t
hdlc_decode_address(const size_t size,
                    const uint8_t p_from[size],
                    hdlc_address_t *p_to);

STATIC status_t
hdlc_build_address(const hdlc_address_t *p_from,
                   const size_t size,
                   uint8_t p_to[size]);

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
hdlc_build_address(const hdlc_address_t *p_from,
                   const size_t size,
                   uint8_t p_to[size]) {
	ASSERT_DEVELOP(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);
	ASSERT_DEVELOP(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	RETURN_IF_FALSE(!(p_from->size > sizeof(uint32_t)),
	                STATUS_HDLC_INVALID_PARAMETER);
	RETURN_IF_FALSE(!(p_from->size > size), STATUS_HDLC_BUFFER_OVERFLOW);

	switch(p_from->size) {
		default: { /* { 0, 3 or larger than 4 } */
			return STATUS_HDLC_ADDRESS_BUILD_FAIL;
		}
		case(sizeof(uint8_t)): {
			p_to[0] = ((p_from->address << 1) >> 0) | 0x01;

			break;
		}
		case(sizeof(uint16_t)): {
			p_to[0] = ((p_from->address << 2) >> 8) & 0xfe;
			p_to[1] = ((p_from->address << 0) >> 0) | 0x01;

			break;
		}
		case(sizeof(uint32_t)): {
			p_to[0] = ((p_from->address << 2) >> 24) & 0xfe;
			p_to[1] = ((p_from->address << 1) >> 16) & 0xfe;
			p_to[2] = ((p_from->address << 2) >> 8) & 0xfe;
			p_to[3] = ((p_from->address << 0) >> 0) | 0x01;

			break;
		}
	}

	return STATUS_SUCCESS;
}

STATIC uint32_t
hdlc_parse_address(const size_t size,
                   const uint8_t p_from[size]) {
	ASSERT_DEVELOP(p_from != NULL, 0xffffffff);
	ASSERT_DEVELOP(size != 0, 0xffffffff);

	RETURN_IF_FALSE(!(size > sizeof(uint32_t)), 0xffffffff);

	uint32_t address = 0x00000000;
	switch(size) {
		default: { /* { 0, 3 or larger than 4 } */
			address = 0xffffffff;
			break;
		}
		case(sizeof(uint8_t)): {
			uint8_t temp = p_from[0];
			address = (temp >> 1) & 0xff;
			break;
		}
		case(sizeof(uint16_t)): {
			uint16_t temp = __builtin_bswap16(*(uint16_t *) &p_from[0]);
			address = ((temp & 0xff00) >> 2) | ((temp & 0x00ff) >> 0);
			break;
		}
		case(sizeof(uint32_t)): {
			uint32_t temp = __builtin_bswap32(*(uint32_t *) &p_from[0]);
			address = ((temp & 0xff00ff00) >> 2) | ((temp & 0x00ff0000) >> 1) | ((temp & 0x000000ff) >> 0);
			break;
		}
	}

	return address;
}

STATIC status_t
hdlc_decode_address(const size_t size,
                    const uint8_t p_from[size],
                    hdlc_address_t *p_to) {
	ASSERT_DEVELOP(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);
	ASSERT_DEVELOP(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	RETURN_IF_FALSE(size <= sizeof(uint32_t), STATUS_HDLC_INVALID_PARAMETER);

	static const hdlc_address_t hdlc_address_invalid = {
	  .address = 0xffffffff,
	  .size = 0xffffffff
	};

	*p_to = hdlc_address_invalid;

	RETURN_IF_FALSE((p_from[size - 1] & 0x01) != 0, STATUS_HDLC_ADDRESS_INVALID);

	uint32_t address = hdlc_parse_address(size, p_from);
	RETURN_IF_FALSE(address != 0xffffffff, STATUS_HDLC_ADDRESS_PARSE_FAIL);

	*p_to = (hdlc_address_t ) { .address = address, .size = size };
	return STATUS_SUCCESS;
}

status_t
hdlc_push_address(const hdlc_address_t *p_from,
                  const size_t size,
                  uint8_t p_to[size]) {
	status_t status = hdlc_build_address(p_from, size, p_to);
	if (status != STATUS_SUCCESS) {
		log_event(status);
	}

	return status;
}

status_t
hdlc_pull_address(const uint8_t p_from[4],
                  hdlc_address_t *p_to) {
	ASSERT_DEVELOP(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);

	size_t size = 1;

	for (; size <= sizeof(uint32_t); size <<= 1) {
		if ((p_from[size - 1] & 0x01) != 0) {
			break;
		}
	}

	status_t status = hdlc_decode_address(size, p_from, p_to);
	if (status != STATUS_SUCCESS) {
		log_event(status);
	}

	return status;
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
