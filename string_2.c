#include "string_helper.h"
#include "utils.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strcat - Append src to dest
 * @src: the string to append
 * @dest: the string to append into
 *
 * Return: NULL if malloc failed
 * appended string
 */
char *_strcat(char *dest, const char *src)
{
	size_t i, j;
	size_t size_dest = dest ? _strlen(dest) : 0;
	size_t size_src = src ? _strlen(src) : 0;
	char *temp;

	if (src == NULL || size_src == 0)
		return (dest);

	temp = malloc(size_dest + size_src + 1);
	if (temp == NULL)
		return (NULL);

	for (i = 0; i < size_dest; i++)
		temp[i] = dest[i];

	for (j = 0; i + j < size_dest + size_src; j++)
		temp[i + j] = src[j];

	temp[i + j] = '\0';
	return (temp);
}

/**
 * tok_length - a function that returns how many tokens will be generated
 * @str: a string to tokenise
 * @delimiter: the delimiter of for strtok calls
 *
 * Return: 0 on failure
 * the number of token on success
 */
int tok_length(char *str, char *delimiter)
{
	char *copy, *token;
	size_t nbTok = 0;

	copy = _strdup(str);
	if (copy == NULL)
		return (0);

	token = strtok(copy, delimiter); /* getting first token */
	while (token != NULL)
	{
		/* taking next token */
		token = strtok(NULL, delimiter);
		nbTok++;
	}

	free(copy);
	return (nbTok);
}

