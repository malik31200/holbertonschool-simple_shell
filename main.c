#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
 * main - Entry point of the program.
 * @argc: Number of the arguments
 * @argv: Array containing the arguments.
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv)
{
	char *line = NULL, *blank, **args = NULL;
	ssize_t n = -1;
	size_t len = 0;
	int interactive = isatty(STDIN_FILENO);
	int i = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (interactive)
			printf("($) ");

		n = getline(&line, &len, stdin);

		if (n == -1)
			break;
		/* remove the final '\n' */
		if (n > 0 && line[n - 1] == '\n')
		{
			line[n - 1] = '\0';
			n--;
		}
		blank = line;
		while (*blank == ' ' || *blank == '\t')
			blank++;
		if (*blank == '\0')
			continue;

		if (strcmp(blank, "exit") == 0)
			break;
		args = split_token(blank);
		execute_command(args);
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
	free(line);
	return (0);
}
