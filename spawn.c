#include "shell.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/**
* execute_command - execute a command
* @command: a command to execute
* @commands: the command and its parameters
*
* Return: 1 if it fails,
* child exit code if it succeed
*/
int execute_command(char *command, char **argv)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		_free_split_string(argv);
		free(command);
		return (1);
	}
	else if (child == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			int e = errno;
			perror("execve failed");
			_free_split_string(argv);
			_exit(e == ENOENT ? 127 : 126);
		}
	}
	else
	{
		while (waitpid(child, &status, 0) == -1 && errno == EINTR)
		{
		}
	}
		_free_split_string(argv);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (1);
}
