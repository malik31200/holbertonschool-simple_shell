#include "env.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
* get_env - summons the cursed environment variable from the void
*
* Return: the dark string if it answers your call
*		  NULL if the void refuses
*/
char **get_env(void)
{
	char **copy;
	size_t i;

	if (environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
		;

	copy = malloc(sizeof(char *) * (i + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
		copy[i] = strdup(environ[i]);

	copy[i] = NULL;
	return (copy);
}

/**
* get_env_var - probes the dark corners of the environment for a variable
* @var: the the cursed variable to seek
*
* Return: the string if found in the abyss
*		  NULL if the void swallows it
*/
char *get_env_var(const char *var)
{
	char **copy_environ = get_env();
	char *copy;
	size_t i, len;

	if (var == NULL || copy_environ == NULL)
		return (NULL);

	len = strlen(var);
	for (i = 0; copy_environ[i] != NULL; i++)
	{
		if (strncmp(var, copy_environ[i], len) == 0 && copy_environ[i][len] == '=')
		{
			copy = strdup(copy_environ[i]);
			free_char_arr(copy_environ);
			return (copy);
		}
	}

	free_char_arr(copy_environ);
	return (NULL);
}

/**
* print_env - summons the environment variables from the abyss
*
* Return: void; if the void is empty, silence reigns
*/
void print_env(void)
{
	size_t i;

	if (environ == NULL)
		return;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}

/**
* path_finder - the quest for the PATH ends here
*
* Return: the PATH if fate allows, NULL if cursed
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
