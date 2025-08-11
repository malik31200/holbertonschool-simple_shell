#include "string_helper.h"
#include <stddef.h>
#include <stdlib.h>
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
	size_t i = 0;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (str1[i] - str2[i]);;
}

/**
* _strlen - return the size of the string
* @str: a string
*
* Return: the size of the string
* 0 if it's NULL
*/
size_t _strlen(char *str)
{
	size_t len;

	if (str == NULL)
		return (0);

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}
/**
* _strdup - return a malloced copy of a string
* @str: the string to copy
*
* Return: a malloced copy of str
* NULL if it fails
*/
char *_strdup(char *str)
{
	char *res = NULL;
	size_t i;

	if (str == NULL)
		return (NULL);

	res = malloc(_strlen(str) + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		res[i] = str[i];
	}

	res[i] = '\0';
	return (res);
}
