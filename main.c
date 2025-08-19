#include "shell.h"
#include "env.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Entry point of the program.
 * @argc: Number of the arguments
 * @argv: Array containing the arguments.
 * Return: Always 0 (Success).
 */
int main(int argc, char **argv)
{
	char *line = NULL, **args = NULL;
	ssize_t n = -1;
	size_t len = 0;
	int interactive = isatty(STDIN_FILENO);
	int status = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "($) ", 4);

		n = getline(&line, &len, stdin);

		if (n == -1)
		{
			free(line);
			exit(0);
		}
		if (n > 0 && line[n - 1] == '\n')
		{
			line[n - 1] = '\0';
			n--;
		}
		if (*line == '\0')
			continue;
		args = split_token(line, " \t");
		if (args == NULL)
			{
				continue;
			}
		if (run_builtins(args, &status, line) == 1)
		{
			free_char_arr(args);
			continue;
		}

		status = chose_path(args);
		free_char_arr(args);
	}
	free(line);
	return (0);
}
