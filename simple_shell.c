#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Function declarations */
char **split_string(char *str, char *delimiter);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/**
* simple_shell - a function that deal with shell commands
* @command: a command line for simple_shell
*
* Return: 0 if succeed
* 1 if it fails
*/
int simple_shell(char *command)
{
	char **splitString;
	pid_t child;
	int status;
	size_t i;

	splitString = split_string(command, " \t\n");
	if (splitString == NULL)
	{
		return (0);
	}
	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		for (i = 0; splitString[i] != NULL; i++)
			free(splitString[i]);
		free(splitString);
		return (1);
	}
	else if (child == 0)
	{
		/* if execve fails */
		if (execve(splitString[0], splitString, environ) == -1)
		{
			perror(splitString[0]);
			_exit(127);
		}
	}
	else
	{
		wait(&status);
		for (i = 0; splitString[i] != NULL; i++)
			free(splitString[i]);
		free(splitString);
	}

	return (0);
}


