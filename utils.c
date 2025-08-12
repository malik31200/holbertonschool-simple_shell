#include "utils.h"
#include <stdlib.h>
/**
* _realloc - realloc a already malloced pointer
* @ptr: the original pointer
* @old_size: ptr current size
* @new_size: ptr new size
*
* Return: NULL if it fails
* a pointer to the newly allocated pointer
*/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *newptr = NULL;
	size_t min_size = 0, i;
	char *new_bytes, *old_bytes;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size == new_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
	{
		return (NULL);
	}

	if (old_size < new_size)
		min_size = old_size;
	else
		min_size = new_size;

	old_bytes = (char *)ptr;
	new_bytes = (char *)newptr;

	for (i = 0; i < min_size; i++)
		new_bytes[i] = old_bytes[i];

	free(ptr);
	return (newptr);
}
