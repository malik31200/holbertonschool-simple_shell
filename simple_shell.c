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
 * split_string - split a string into it's components
 * @str: a string to parse
 *
 * Return: NULL if it fails
 * an array of strings if it succeed
 */
char **split_string(char *str, char *delimiter)
{
	char **tokens = NULL, **temp;
	char *token;
	size_t count = 0, i = 0;

	if (str == NULL)
		return (NULL);

	token = strtok(str, delimiter); /* getting first token */
	while (token != NULL)
	{
		/* reallocating the size needed to add a token and NULL */
		temp = _realloc(tokens, sizeof(char *) * count,
						sizeof(char *) * (count + 2));
		if (temp == NULL)
		{
			/* free allocated memory */
			for (i = 0; i < count; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		tokens = temp;
		tokens[count] = _strdup(token);
		if (tokens[count] == NULL)
		{
			/* free allocated memory */
			for (i = 0; i < count; i++)
				free(tokens[i]);

			free(tokens);
			return (NULL);
		}
		/* taking next token */
		token = strtok(NULL, delimiter);
		count++;
	}

	if (tokens != NULL)
		tokens[count] = NULL;

	return (tokens);
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
