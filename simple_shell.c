#include "utils.h"
#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char **path_finder(void);
char *_strchr(const char *str, int c);


/**
 * simple_shell - a function that deal with shell commands
 * @command: a command line for simple_shell
 * @shell_name: Name of the shell
 *
 * Return: exit codes
 */
int simple_shell(char *command, char *shell_name)
{
	char **commands;
	int status = 0;

	commands = split_string(command, " \t\n");
	if (commands == NULL)
	{
		return (0);
	}
	if (commands[0] == NULL)
	{
		_free_split_string(commands);
		return(0);
	}
	if (run_builtins(commands, &status))
	{
		_free_split_string(commands);
		return (status);
	}

	if (_strchr(commands[0], '/'))
	{
		status = (execute_no_path(commands, shell_name));
	}
	else
	{
		status = (execute_path(commands, shell_name));
	}
	_free_split_string(commands);
	return (status);
}


