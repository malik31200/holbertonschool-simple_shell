#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * execute_command - Function that execute command.
 * @argv: Line of a command.
 *
 * Return: -1 if failed.
 * child's code if success.
 */

int execute_command(char **argv)
{
	pid_t pid;
	int status;

	if (argv == NULL || argv[0] == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve failed");
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
	}
	return (-1);
}

