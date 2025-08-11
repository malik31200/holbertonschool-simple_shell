#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Function declarations */
char **split_string(char *str);
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

	splitString = split_string(command);
	if (splitString == NULL)
	{
		perror("split failed");
		return (1);
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
		if (execve(splitString[0], splitString, NULL) == -1)
		{
			perror("execve failed");
			_exit(127);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}

/**
 * split_string - split a string into it's components
 * @str: a string to parse
 *
 * Return: NULL if it fails
 * an array of string sif it succeed
 */
char **split_string(char *str)
{
	char **tokens = NULL, **temp;
	char *token;
	size_t count = 0, i = 0;

	if (str == NULL)
		return (NULL);

	token = strtok(str, " \t\n"); /* getting first token */
	while (token != NULL)
	{
		/* reallocating the size needed to add a token and NULL */
		temp = realloc(tokens, sizeof(char *) * (count + 2));
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
		token = strtok(NULL, " \t\n");
		count++;
	}

	if (tokens != NULL)
		tokens[count] = NULL;

	return (tokens);
}
