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

// testing basic strcmp usage
void test_strcmp_basic(void)
{
    char *str1 = "Hello";
	char *str2 = "Hello";

	printf("comparing : %s and %s\n", str1, str2);
	printf("Expecting: 0\n");

	TEST_ASSERT_EQUAL_INT(0, _strcmp(str1, str2));
}

// testing lexical negative
void test_strcmp_negative_dif(void)
{
    char *str1 = "Hello";
	char *str2 = "Hzllo";

	printf("comparing : %s and %s\n", str1, str2);
	printf("Expecting: str1 < str2 (negative result)\n");


	TEST_ASSERT_TRUE(_strcmp(str1, str2) < 0);
}

// testing lexical positive
void test_strcmp_positive_dif(void)
{
    char *str1 = "Hello";
	char *str2 = "Hehho";

	printf("comparing : %s and %s\n", str1, str2);
	printf("Expecting: str1 > str2 (positive result)\n");


	TEST_ASSERT_TRUE(_strcmp(str1, str2) > 0);
}

// testing 2 empty strings
void test_two_empty_string(void)
{
    char *str1 = "";
	char *str2 = "";

	printf("comapring 2 empty strings\n");
	printf("Expecting: 0\n");

	TEST_ASSERT_EQUAL_INT(0,_strcmp(str1, str2));
}
// testing left empty strings
void test_left_empty_string(void)
{
    char *str1 = "";
	char *str2 = "Hello";

	printf("comparing left empty string\n");
	printf("Expecting: < 0\n");

	TEST_ASSERT_TRUE(_strcmp(str1, str2) < 0);
}

// testing right empty strings
void test_right_empty_string(void)
{
    char *str1 = "Hello";
	char *str2 = "";

	printf("comparing left empty string\n");
	printf("Expecting: > 0\n");

	TEST_ASSERT_TRUE(_strcmp(str1, str2) > 0);
}

// testing incomplete strings
void test_incomplete_strings(void)
{
    char *str1 = "Hello";
	char *str2 = "Hell";

	printf("comparing incomplete string\n");
	printf("Expecting: > 0\n");

	TEST_ASSERT_TRUE(_strcmp(str1, str2) > 0);
}

//testing differing in the first character
void test_strcmp_first_char_dif(void)
{
    char *str1 = "Apple";
	char *str2 = "Banana";

	printf("comparing : %s and %s\n", str1, str2);
	printf("Expecting: < 0\n");

	TEST_ASSERT_TRUE(_strcmp(str1, str2) < 0);
}

//testing special char
void test_strcmp_special_char_dif(void)
{
    char *str1 = "Hi?";
	char *str2 = "Hi!";

	printf("comparing : %s and %s\n", str1, str2);
	printf("Expecting: > 0\n");

	TEST_ASSERT_TRUE(_strcmp(str1, str2) > 0);
}
//testing case sensitivity
void test_strcmp_case_sensitivity(void)
{
    char *str1 = "Apple";
	char *str2 = "apple";

	printf("comparing : %s and %s\n", str1, str2);
	printf("Expecting: < 0\n");

	TEST_ASSERT_TRUE(_strcmp(str1, str2) < 0);
}

// Main function to run Unity tests
int main(void)
{
    UNITY_BEGIN();            // Start Unity test session
    RUN_TEST(test_strcmp_basic);
	RUN_TEST(test_strcmp_negative_dif);
	RUN_TEST(test_strcmp_positive_dif);
	RUN_TEST(test_two_empty_string);
	RUN_TEST(test_left_empty_string);
	RUN_TEST(test_right_empty_string);
	RUN_TEST(test_incomplete_strings);
	RUN_TEST(test_strcmp_first_char_dif);
	RUN_TEST(test_strcmp_special_char_dif);
	RUN_TEST(test_strcmp_case_sensitivity);
    return UNITY_END();       // End Unity session and return result
}
