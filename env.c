#include "env.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
* get_env - summons the cursed environment variable from the void
*
* Return: the dark string if it answers your call
* 		  NULL if the void refuses
*/
char **get_env(void)
{
	return (environ);
}

/**
* get_env_var - probes the dark corners of the environment for a variable
* @var: the the cursed variable to seek
*
* Return: the string if found in the abyss
* 		 NULL if the void swallows it
*/
char *get_env_var(const char *var)
{
	char **environ = get_env();
	size_t i, len;

	if (var == NULL || environ == NULL)
		return (NULL);

	len = strlen(var);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(var, environ[i], len) == 0 && environ[i][len] == '=')
			return (environ[i]);
	}

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
