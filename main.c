#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t nRead = -1;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			printf("($) ");

		nRead = getline(&command, &len, stdin);

		if (nRead == -1)
		{
			free(command);
			exit(0);
		}

		if ((_strcmp(command, "exit\n")) == 0)
		{
			free(command);
			break;
		}
		simple_shell(command);
		free(command);
		command = NULL;
	}
	return (0);
}
