#include "env.h"
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
* print_env - invokes the spirits to reveal all environmental secrets
*
* Summons every forsaken variable from the void and lays them bare
* before mortal eyes. If the void is empty, silence reigns eternal.
*
* Return: nothing; the void may speak, or remain mute.
*/
void print_env(void)
{
	size_t i;
	char **copy_environ = get_env();

	if (copy_environ == NULL)
		return;

	for (i = 0; copy_environ[i] != NULL; i++)
		printf("%s\n", copy_environ[i]);

	free_char_arr(copy_environ);
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
