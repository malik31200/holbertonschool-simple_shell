#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int lenght_tok(const char *line, const char *delimiter);

/**
 * split_token - Split a string
 * @line: Line of command.
 * @delimiter: the delimiter to parse with
 *
 * Return: NULL if failed
 * an array of strings if success.
 */
char **split_token(char *line, char *delimiter)
{
	char **argv = NULL;
	char *tok, *copy, *clean_tok;
	int i = 0;
	int n;

	if (line == NULL || *line == '\0')
		return (NULL);

	n = lenght_tok(line, delimiter);
	if (n <= 0)
		return (NULL);

	argv = malloc((n + 1) * sizeof(char *));
	if (argv == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}
	copy = strdup(line);
	if (copy == NULL)
	{
		free(argv);
		return (NULL);
	}

	tok = strtok(copy, delimiter);
	for (i = 0; tok != NULL; i++)
	{
		clean_tok = tok;
		if (tok[0] == '"' && tok[strlen(tok) - 1] == '"' && strlen(tok) > 1)
		{
			tok[strlen(tok) - 1] = '\0';
			clean_tok = tok + 1;
		}
		argv[i] = strdup(clean_tok);
		if (argv[i]  == NULL)
		{
			while (i > 0)
			{
				i--;
				free(argv[i]);
			}
			free(copy);
			free(argv);
			return (NULL);
		}
		tok = strtok(NULL, delimiter);
	}
	argv[i] = NULL;
	free(copy);
	return (argv);
}

/**
 * lenght_tok - Function that tokenizes a string.
 * @line: String to tokenize.
 * @delimiter: Delimiter betwen tokens.
 * Return: Number of token.
 */
int lenght_tok(const char *line, const char *delimiter)
{
	int i = 0;
	char *copy, *token;

	if (line == NULL || delimiter == NULL || *delimiter == '\0')
		return (-1);

	if (*line == '\0')
		return (0);

	copy = strdup(line);
	if (copy == NULL)
		return (-1);

	token = strtok(copy, delimiter);
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delimiter);
	}
	free(copy);
	return (i);
}
