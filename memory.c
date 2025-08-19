#include "shell.h"
#include <stdlib.h>
/**
* free_char_arr - banishes the legion of strings back to the void
* @str: the array of cursed strings to exorcise
*
* Descend into the dark abyss, freeing each forsaken string one by one,
* then obliterate the array itself, leaving no trace in the mortal realm.
* If the void is empty (NULL), silence reigns and nothing happens.
*
* Return: nothing; the void consumes it all.
*/
void free_char_arr(char **str)
{
	size_t i;

	if (str == NULL)
		return;

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}

