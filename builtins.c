#include "shell.h"
#include "string_helper.h"
#include <stdlib.h>
#include <stdio.h>

/**
* run_builtins - a function that runs all of the builtins
* @command: the command to  verify
*
* Return: 1 if a command ran
* 0 if it didn't
*/
int run_builtins(char *command)
{
	size_t i;

	if (_strcmp(command, "exit") == 0)
	{
		free(command);
		exit(0);
	}
	if (_strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);

		return (1);
	}

	return (0);
}
