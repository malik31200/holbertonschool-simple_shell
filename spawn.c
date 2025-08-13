#include "shell.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* execute_command - execute a command
* @command: a command to execute
* @commands: the command and its parameters
*
* Return: 1 if it fails,
* child exit code if it succeed
*/
int execute_command(char *command, char **commands)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		_free_split_string(commands);
		return (1);
	}
	else if (child == 0)
	{
		if (execve(command, commands, environ) == -1)
		{
			perror("execve failed");
			_exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
	}

	_free_split_string(commands);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (1);
}
