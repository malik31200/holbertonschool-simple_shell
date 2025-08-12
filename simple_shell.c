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
