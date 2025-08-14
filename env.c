#include "env.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
* get_env - returns the environement system variable
*
* Return: the environement system variable if it succeed
* NULL if it fails
*/
char **get_env(void)
{
	return (environ);
}

/**
* get_env_var - searches for a vairable in environ
* @var: the variable to search
*
* Return: the string containing the variable
* NULL if it fails
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
* print_env - prints the environ variable if it's not null
*
* Return: void
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
* path_finder - it found the path and the doom in it
*
* Return: the PATH is yours
* NULL if it's not found
*/
char *path_finder(void)
{
	return (get_env_var("PATH"));
}
