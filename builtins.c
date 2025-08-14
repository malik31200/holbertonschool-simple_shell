#include "shell.h"
#include "string_helper.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

/* function declarations */
int is_number(char *str);

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
	char **commands;
	int code;

	commands = split_string(command, " \n\t");
	if (_strcmp(commands[0], "exit") == 0)
	{
		if (commands[1] != NULL && is_number(commands[1]))
		{
			code = atoi(commands[1]);
			free(command);
			_free_split_string(commands);
			exit(code);
		}
		if (commands[1] != NULL && !is_number(commands[1]))
		{
			free(command);
			fprintf(stderr, "exit: %s: numeric argument required\n", commands[1]);
			_free_split_string(commands);
			exit(2);
		}
		_free_split_string(commands);
		free(command);
		exit(0);
	}
	if (_strcmp(commands[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);

		_free_split_string(commands);
		return (1);
	}

	_free_split_string(commands);
	return (0);
}

/**
* is_number - a function that returns if a string is a number
* @str: a string to test
*
* Return: 0 if it's not a number
* 1 if it is
*/
int is_number(char *str)
{
	size_t i;

	if (str == NULL || str[0] == '\0')
		return (0);

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);

	return (1);
}
