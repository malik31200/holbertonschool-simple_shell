#include "../Unity/unity.h"  // Unity testing framework header
#include "../string_helper.h"
#include "capture.h"         // Helpers to capture stdout/stderr output
#include <stdlib.h>          // For exit()
#include <stdio.h>

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

// testing basic usage
void test_strlen_basic(void)
{
    char *str = "Hello";

	printf("Testing : %s\n", str);
	printf("Expecting : 5\n");
	TEST_ASSERT_EQUAL_INT(5, _strlen(str));
}

// testing empty string
void test_strlen_empty(void)
{
    char *str = "";

	printf("Testing : %s\n", str);
	printf("Expecting : 0\n");
	TEST_ASSERT_EQUAL_INT(0, _strlen(str));
}

// testing null string
void test_strlen_null(void)
{
    char *str = NULL;

	printf("Testing : NULL\n");
	printf("Expecting : 0\n");
	TEST_ASSERT_EQUAL_INT(0, _strlen(str));
}

// Main function to run Unity tests
int main(void)
{
    UNITY_BEGIN();            // Start Unity test session
    RUN_TEST(test_strlen_basic);
	RUN_TEST(test_strlen_empty);
	RUN_TEST(test_strlen_null);
    return UNITY_END();       // End Unity session and return result
}
