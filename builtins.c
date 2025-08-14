#include "shell.h"
#include "string_helper.h"
#include <unistd.h>
#include <stdio.h>

/**
 * builtin_env - Prints all environnement
 * @argv: Command
 *
 * Return: 0 on success
 */
int builtin_env(char **argv)
{
	size_t i, len;

	(void)argv;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * run_builtins - Cheks if a command matches a buit-in and excecutes
 * @commands: Array of strings
 * @status: Pointer
 *
 * Return: 1 if command is recognize and execute
 * 0 if no match
 */
int run_builtins(char **commands, int *status)
{
	int st;
	int handled = 0;

	if (commands == NULL || commands[0] == NULL)
		return (0);
	if (_strcmp(commands[0], "env") == 0)
	{
		st = builtin_env(commands);
		handled = 1;
	}
	if (handled && status != NULL)
		*status = st;
	return (handled);
}
