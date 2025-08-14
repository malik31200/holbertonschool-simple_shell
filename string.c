#include "string_helper.h"
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
	char **tokens = NULL, **temp;
	char *token;
	size_t count = 0, i = 0;

	if (str == NULL)
		return (NULL);

	token = strtok(str, delimiter); /* getting first token */
	while (token != NULL)
	{
		/* reallocating the size needed to add a token and NULL */
		temp = _realloc(tokens, sizeof(char *) * count,
						sizeof(char *) * (count + 2));
		if (temp == NULL)
		{
			/* free allocated memory */
			for (i = 0; i < count; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		tokens = temp;
		tokens[count] = _strdup(token);
		if (tokens[count] == NULL)
		{
			/* free allocated memory */
			for (i = 0; i < count; i++)
				free(tokens[i]);

			free(tokens);
			return (NULL);
		}
		/* taking next token */
		token = strtok(NULL, delimiter);
		count++;
	}
	if (tokens != NULL)
		tokens[count] = NULL;

	return (tokens);
}
