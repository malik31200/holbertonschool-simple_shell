#include "utils.h"
#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char **path_finder(void);

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

	commands = split_string(command, " \t\n");
	if (commands == NULL)
		return (0);

    if (commands[0] == NULL)
    {
		free(commands);
		return (1);
	}

	if (commands[0][0] == '/' || commands[0][0] == '.')
		return (execute_no_path(commands, shell_name));
	else
		return (execute_path(commands, shell_name));
}

