#include "shell.h"
#include "string_helper.h"
#include <unistd.h>
#include <stdio.h>

/**
 * 
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
 * 
 */
int run_builtins(char **commands, int *status)
{
    int st;

    if (commands == NULL || commands[0] == NULL)
        return (0);
    if (_strcmp(commands[0], "env") == 0)
        st = builtin_env(commands);
    if (status != NULL)
        *status = st;
    return (1);
}
