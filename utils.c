#include "utils.h"
#include <stdlib.h>

/**
 * _free_split_string - Free an array of strings
 * @string_arr: Array of strings
 *
 * Return: Void
 */
void _free_split_string(char **string_arr)
{
	size_t i;

	if (string_arr == NULL)
		return;

	for (i = 0; string_arr[i] != NULL; i++)
		free(string_arr[i]);
	free(string_arr);
}
