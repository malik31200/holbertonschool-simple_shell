#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * main - Entry point of the program.
 * @argc: Number of the arguments
 * @argv: Array containing the arguments.
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	ssize_t n = -1;
	size_t len = 0;
	int interactive = isatty(STDIN_FILENO);
	char *blank;

	(void)argc;
	(void)argv;

	/* Print $ in interactif mode */
	while (1)
	{
		if (interactive)
			printf("($) ");

		n = getline(&line, &len, stdin);

		/* EOF - exit ctrl + d */
		if (n == -1)
			break;

		/* remove the final '\n' */
		if (n > 0 && line[n - 1] == '\n')
		{
			line[n - 1] = '\0';
			n--;
		}

		/* handle the blank */
		blank = line;
		while (*blank == ' ' || *blank == '\t')
			blank++;
		if (*blank == '\0')
			continue;

		if (_strcmp(blank, "exit") == 0)
			break;
	}
	free(line);
	return (0);
}
