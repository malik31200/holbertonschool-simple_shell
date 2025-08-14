#include "string_helper.h"
#include "utils.h"
#include <stdlib.h>

/**
 * _strcat - Append src to dest
 * @src: the string to append
 * @dest: the string to append into
 *
 * Return: NULL if malloc failed
 * appended string
 */
char *_strcat(const char *src, char *dest)
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

	for(j = 0; i + j < size_dest + size_src; j++)
		temp[i + j] = src[j];

	temp[i + j] = '\0';
	return (temp);
}
