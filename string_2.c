#include "string_helper.h"
#include "utils.h"
/**
 * strcat_realloc - Append src to dest
 * @src: the string to append
 * @dest: the string to append into
 *
 * Return: NULL if malloc failed
 * appended string
 */
char *strcat_realloc(char *dest, const char *src)
{
	size_t i;
	size_t size_dest = dest ? _strlen(dest) : 0;
	size_t size_src = src ? _strlen(src) : 0;
	char *temp;

	if (src == NULL || size_src == 0)
		return (dest);

	if (dest == NULL)
	{
		temp = _realloc(dest, 0, size_src + 1);
		if (temp == NULL)
			return (NULL);
	}
	else
	{
		temp = _realloc(dest, size_dest + 1, size_src + size_dest + 1);
		if (temp == NULL)
			return (NULL);
	}
	for (i = 0; i < size_src; i++)
		temp[i + size_dest] = src[i];

	temp[i + size_dest] = '\0';
	return (temp);
}
