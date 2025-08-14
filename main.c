#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* --- Function declarations --- */
void parse_new_line(char *str);
void handle_sigint(int sig);

/**
 * main - Entry point of the program
 *@argc: Number of arguments
 *@argv: Array containing the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t nRead = -1;
	int interactive = isatty(STDIN_FILENO);

	signal(SIGINT, handle_sigint);
	(void)argc;

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
		if (run_builtins(command) == 1)
			continue;
		simple_shell(command, argv[0]);
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

/**
* handle_sigint - a function to handle signals
* @sig: a signal
*
* Return: void;
*/
void handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n($) ", 5);
	fflush(stdout);
}
