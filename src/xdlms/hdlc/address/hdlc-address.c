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

#include <string.h>

#ifdef UNIT_TESTS

#endif /* UNIT_TESTS */

#include "utils.h"
#include "array.h"
#include "log.h"

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
                   const uint8_t p_from[static 1]);

STATIC status_t
hdlc_decode_address(const size_t size,
                    const uint8_t p_from[static 1],
                    hdlc_address_t p_to[static 1]);

STATIC status_t
hdlc_build_address(const hdlc_address_t p_from[static 1],
                   const size_t size,
                   uint8_t p_to[static 1]);

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
hdlc_build_address(const hdlc_address_t p_from[static 1],
                   array_t p_to[static 1]) {
	ASSERT(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);
	ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	const size_t free = array_free(p_to);
	RETURN_IF_FALSE(free != (size_t)~0, STATUS_ARRAY_INVALID_PARAMETER);
	RETURN_IF_FALSE(!(free < p_from->size), STATUS_HDLC_BUFFER_OVERFLOW);

	uint8_t to[sizeof(uint32_t)] = { 0 };

	switch(p_from->size) {
		default: {
			return STATUS_HDLC_ADDRESS_BUILD_FAIL;
		}
		case(sizeof(uint8_t)): {
			to[0] = ((p_from->value << 1) >> 0) | 0x01;

			break;
		}
		case(sizeof(uint16_t)): {
			to[0] = ((p_from->value << 2) >> 8) & 0xfe;
			to[1] = ((p_from->value << 0) >> 0) | 0x01;

			break;
		}
		case(sizeof(uint32_t)): {
			to[0] = ((p_from->value << 2) >> 24) & 0xfe;
			to[1] = ((p_from->value << 1) >> 16) & 0xfe;
			to[2] = ((p_from->value << 2) >>  8) & 0xfe;
			to[3] = ((p_from->value << 0) >>  0) | 0x01;

			break;
		}
	}

	return array_push(&to[0], p_to, p_from->size);
}

STATIC uint32_t
hdlc_parse_address(array_t p_from[static 1],
                   const size_t size) {
	RETURN_IF_FALSE(!(size > sizeof(uint32_t)), (uint32_t)~0);

	uint32_t addr = 0;
	uint32_t temp = 0;

	status_t status = array_pull_hton(p_from, (uint8_t *)&temp, size);
	RETURN_IF_FALSE(status == STATUS_SUCCESS, (uint32_t)~0);

	switch(size) {
		default: {
			addr = (uint32_t)~0;
			break;
		}
		case(sizeof(uint8_t)): {
			addr = ((temp & 0x000000ff) >> 1);
			break;
		}
		case(sizeof(uint16_t)): {
			addr = ((temp & 0x0000ff00) >> 2) |
					   ((temp & 0x000000ff) >> 0);
			break;
		}
		case(sizeof(uint32_t)): {
			addr = ((temp & 0xff00ff00) >> 2) |
					   ((temp & 0x00ff0000) >> 1) |
					   ((temp & 0x000000ff) >> 0);
			break;
		}
	}

	return addr;
}

STATIC status_t
hdlc_decode_address(array_t p_from[static const 1],
                    hdlc_address_t p_to[static 1],
                    const size_t size) {
	ASSERT(p_from != NULL, STATUS_HDLC_INVALID_PARAMETER);
	ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);
	RETURN_IF_FALSE(!(size == 0), STATUS_HDLC_INVALID_PARAMETER);
	RETURN_IF_FALSE(!(size > sizeof(uint32_t)), STATUS_HDLC_INVALID_PARAMETER);

	static const hdlc_address_t hdlc_address_invalid = {
	  .value = (uint32_t)~0,
	  .size = (size_t)~0
	};

	p_to[0] = hdlc_address_invalid;

	const size_t offs = p_from->start + size - 1;
	RETURN_IF_FALSE((p_from->p_array[offs] & 0x01) != 0, STATUS_HDLC_ADDRESS_INVALID);

	uint32_t address = hdlc_parse_address(p_from, size);
	RETURN_IF_FALSE(address != (uint32_t)~0, STATUS_HDLC_ADDRESS_PARSE_FAIL);

	p_to[0] = (hdlc_address_t){ .value = address, .size = size };
	return STATUS_SUCCESS;
}

status_t
hdlc_push_address(const hdlc_address_t p_from[static const 1],
                  array_t p_to[static 1]) {
	return hdlc_build_address(p_from, p_to);
}

status_t
hdlc_pull_address(array_t p_from[static 1],
                  hdlc_address_t p_to[static 1]) {
	ASSERT(p_to != NULL, STATUS_HDLC_INVALID_PARAMETER);

	size_t size = 1;

	for (; size <= sizeof(uint32_t); size <<= 1) {
		uint32_t address = (uint32_t)~0;
		array_t temp = p_from[0];

		status_t status = array_pull_hton(&temp, (uint8_t *)&address, size);
		RETURN_IF_FALSE(status == STATUS_SUCCESS, status);

		if ((address & 0x00000001) != 0) {
			break;
		}
	}

	return hdlc_decode_address(p_from, p_to, size);
}

#ifdef UNIT_TESTS

#else /* UNIT_TESTS */

#endif /* UNIT_TESTS */
