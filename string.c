#include "string_helper.h"
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/* function declarations */
int tok_length(char *str, char *delimiter);

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
	return (str1[i] - str2[i]);
}

/**
 * _strlen - return the size of the string
 * @str: a string
 *
 * Return: the size of the string
 * 0 if it's NULL
 */
size_t _strlen(const char *str)
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

/**
 * _strncmp - a function that compare 2 string until n
 * @str1: a string
 * @str2: a string
 * @n: number of bytes to compare
 *
 * Return: the ascii diference of str1 - str2
 * 0 if it similar
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	size_t i = 0;

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
	{

		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}

	return (0);
}

/**
 * split_string - split a string into it's components
 * @str: a string to parse
 * @delimiter: a string containing the delimiters to split the string
 *
 * Return: NULL if it fails
 * an array of strings if it succeed
 */
char **split_string(char *str, char *delimiter)
{
	char **tokens = NULL;
	char *token, *copy;
	size_t count = 0, lenTok = 0;

	if (str == NULL)
		return (NULL);

	copy = _strdup(str);
	if (copy == NULL)
		return (NULL);

	lenTok = tok_length(str, delimiter);
	if (lenTok == 0)
	{
		free(copy);
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * (lenTok + 1));
	if (tokens == NULL)
	{
		free(copy);
		return (NULL);
	}

	token = strtok(copy, delimiter); /* getting first token */
	while (token != NULL)
	{
		tokens[count] = _strdup(token);
		if (tokens[count] == NULL)
		{
			free(copy);
			_free_split_string(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		count++;
	}

	tokens[count] = NULL;
	free(copy);
	return (tokens);
}

