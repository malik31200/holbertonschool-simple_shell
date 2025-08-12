#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* --- Function declarations --- */
void parse_new_line(char *str);

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
		parse_new_line(command);
		if (command[0] == '\0')
		{
			free(command);
			command = NULL;
			continue;
		}
		if ((_strcmp(command, "exit")) == 0)
		{
			free(command);
			exit(0);
		}
		simple_shell(command);
		free(command);
		command = NULL;
	}
	return (0);
}

/**
* parse_new_line - parse a new line if there is one
* @str: a string to parse
*
* Return : void
*/
void parse_new_line(char *str)
{
	size_t i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
}
