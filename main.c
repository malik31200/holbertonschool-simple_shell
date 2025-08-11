#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <unistd.h>

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
			printf("#cisfun$:");

		nRead = getline(&command, &len, stdin);

		if (nRead == -1)
			break;

		if ((_strcmp(command, "exit\n")) == 0)
		{	
			break;
		}

		printf("./shell: No such file or directory\n");
	}
	free(command);
	return (0);
}
