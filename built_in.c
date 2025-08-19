#include "shell.h"
#include "env.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * print_env - Print all variable of environnement.
 *
 * Return: Void.
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
/**
 * run_builtins - Function that runs builtins
 *
 * @commands: Token line's command
 * @status: Exit status
 * @line: Line of command
 *
 * Return: 0 if builtins no found
 * 1 if it found
 */
int run_builtins(char **commands, int *status, char *line)
{
	if (commands == NULL || commands[0] == NULL)
		return (0);

	if (strcmp(commands[0], "exit") == 0)
	{
		*status = 0;
		free_char_arr(commands);
		free(line);
		exit(*status);
	}
	if (strcmp(commands[0], "env") == 0)
	{
		print_env();
		*status = 0;
		return (1);
	}

	return (0);
}
