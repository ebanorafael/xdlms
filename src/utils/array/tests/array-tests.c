///@file

/**************************************************************************************************
 * INCLUDES
 *************************************************************************************************/

/* Unit Test file header files inclusion start */

#include "unity.h"
#include "array-tests.h"
#include "array.h"

/* Unit Test file header files inclusion end */

/**************************************************************************************************
 * PRIVATE DEFINES
 *************************************************************************************************/

/* Unit Test file defines start */

/* Unit Test file defines end */

/**************************************************************************************************
 * PRIVATE PROTOTYPES
 *************************************************************************************************/

/**************************************************************************************************
 * PRIVATE DATA
 *************************************************************************************************/

/**************************************************************************************************
 * FUNCTIONS
 *************************************************************************************************/

/* Mocked functions start */

/* Mocked functions end */

#if defined COPY

TEST_FUNCTION(funcion_name_tests) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */
  
  return;
}

#endif /* COPY */

void array_used_tests(void) {
  /* Global test variables start */

  /* Global test variables end */

  /* Start of assertion test cases */

	if (1) { /* invalid parameter */
		size_t size = 0;

		size = array_used(NULL);
		TEST_ASSERT_EQUAL(size, (size_t)-1);
	}

	if (1) { /* invalid parameter */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 1, .end = 2, .start = 0 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, (size_t)-1);
	}

	if (1) { /* invalid parameter */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 1, .end = 1, .start = 2 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, (size_t)-1);
	}

	if (1) { /* success */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 1, .end = 1, .start = 1 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, 0);
	}

	if (1) { /* success */
		size_t size = 0;
		const array_t from = { .p_array = NULL, .size = 8, .end = 5, .start = 2 };

		size = array_used(&from);
		TEST_ASSERT_EQUAL(size, 3);
	}

  /* End of assertion test cases */

  /* Tests start*/

  /* Tests end */

  return;
}
