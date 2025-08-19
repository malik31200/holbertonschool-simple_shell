#include "env.h"
#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
* get_env - summons the cursed spirits of the environment from the void
*
* Descend into the ethereal plane and conjure a mortal copy of all
* environment strings. Beware, each string is a fragment of the void.
*
* Return: a mortal copy of the abyssal strings if they heed your call,
*         NULL if the void remains silent.
*/
char **get_env(void)
{
	char **copy;
	size_t i, len;

	if (environ == NULL)
		return (NULL);

	for (len = 0; environ[len] != NULL; len++)
		;

	copy = malloc(sizeof(char *) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		copy[i] = strdup(environ[i]);
		if (copy[i] == NULL)
		{
			/* The void rejected one of the fragments, banish all previous */
			free_char_arr(copy);
			return (NULL);
		}
	}
	copy[i] = NULL;
	return (copy);
}

/**
* get_env_var - probes the dark corners of the environment
* for a forsaken variable
* @var: the cursed sigil to seek in the abyss
*
* Traverse the haunted corridors of the copied environment, searching
* for a variable marked by @var. Only the worthy shall receive a mortal copy.
*
* Return: the string if it dares emerge from the void,
*         NULL if the abyss swallows it whole.
*
* Note: Caller must free the returned string
*/
char *get_env_var(const char *var)
{
	size_t i, len;

	if (var == NULL || environ == NULL)
		return (NULL);

	len = strlen(var);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(var, environ[i], len) == 0 && environ[i][len] == '=')
			return (strdup(environ[i] + len + 1)); /* Skip past "VAR=" */
	}

	return (NULL);
}

/**
* path_finder - embarks on the heroic quest for the legendary PATH
*
* Brave the void in search of the sacred PATH variable. Only those
* who dare may glimpse its eternal flame.
*
* Return: the PATH if fate deems it worthy, NULL if cursed.
*/
char *path_finder(void)
{
	return (get_env_var("PATH"));
}

