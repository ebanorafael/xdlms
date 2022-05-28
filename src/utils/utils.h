/// @file

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif /*  __cplusplus */

/*******************************************************************
 * EXTERNED DEFINES
 *******************************************************************/

#define ARRAY_SIZE(NAME) \
	(sizeof((NAME)) / sizeof((NAME)[0]))

#define RETURN_IF_FALSE(CONDITION, RETURN) \
  do { if (!(CONDITION)) { return RETURN; } } while(0)

#if defined (UNIT_TESTS)

#include <stdio.h>
#define PRINTF	printf

#endif /* UNIT_TESTS */

#if defined (DEBUG)

#define ASSERT(CONDITION, RETURN) \
	RETURN_IF_FALSE(CONDITION, RETURN)

#define PRINT(...) \
	do { \
		PRINTF(__VA_ARGS__); \
	} while(0)

#define CONSOLE_TRACE(...) \
	do { \
		PRINT("%s, %d - ", __FUNCTION__, __LINE__); \
		PRINT(__VA_ARGS__); \
	} while(0)

#define MODULE_TRACE(ENABLED, ...) \
	do { if ((ENABLED)) { CONSOLE_TRACE(__VA_ARGS__); } } while(0)

#define MEMORY_TRACE(ENABLED, P_FROM, SIZE, ...) \
	do { \
		if ((ENABLED)) { \
			CONSOLE_TRACE(__VA_ARGS__); \
			for (int index = 0; index < (int)(SIZE); index++) { \
				PRINT("%02x", P_FROM[index]); \
			} \
				PRINT("\n"); \
		} \
  } while(0)

#else /* DEBUG */

#define DEVELOP_ASSERT(CONDITION, RETURN)
#define PRINT(...)
#define CONSOLE_TRACE(...)
#define MODULE_TRACE(ENABLED, ...)
#define MEMORY_TRACE(ENABLED, P_FROM, SIZE, ...)

#endif /* DEBUG */

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
