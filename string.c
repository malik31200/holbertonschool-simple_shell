#include "string.h"
#include <stddef.h>
/**
* _strcmp - a function that compare 2 string
* @str1: a string
* @str2: a string
*
* Return: the ascii diference of str1 - str2
* 0 if it similar
*/
int _strcmp(char *str1, char *str2)
{
	size_t i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}
