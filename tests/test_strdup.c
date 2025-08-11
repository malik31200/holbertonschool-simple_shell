#include "../Unity/unity.h"  // Unity testing framework header
#include "capture.h"         // Helpers to capture stdout/stderr output
#include <stdlib.h>          // For exit()
#include "../string_helper.h"

// This function runs before each test
void setUp(void)
{
    // Optional: initialize variables, allocate memory, etc.
}

// This function runs after each test
void tearDown(void)
{
    // Optional: free resources, reset states, etc.
}

// testing basic strdup usage
void test_strdup_basic(void)
{
    char *orig = "Hello";
	char *dup = _strdup(orig);

	printf("original : %s\n", orig);
	printf("duplicate : %s\n", dup);
	TEST_ASSERT_NOT_NULL(dup);
	TEST_ASSERT_EQUAL_STRING(orig, dup);
	TEST_ASSERT_NOT_EQUAL(orig, dup);

	free(dup);
}

// testing empty string
void test_strdup_empty(void)
{
    char *orig = "";
	char *dup = _strdup(orig);

	printf("original : %s\n", orig);
	printf("duplicate : %s\n", dup);
	TEST_ASSERT_NOT_NULL(dup);
	TEST_ASSERT_EQUAL_STRING(orig, dup);
	TEST_ASSERT_NOT_EQUAL(orig, dup);

	free(dup);
}

// testing empty null
void test_strdup_null(void)
{
    char *orig = NULL;
	char *dup = _strdup(orig);

	if (orig == NULL)
		printf("original : NULL\n");
	else
    	printf("original : %s\n", orig);
	TEST_ASSERT_NULL(dup);
}

// Main function to run Unity tests
int main(void)
{
    UNITY_BEGIN();            // Start Unity test session
    RUN_TEST(test_strdup_basic);
	RUN_TEST(test_strdup_empty);
	RUN_TEST(test_strdup_null);
    return UNITY_END();       // End Unity session and return result
}
