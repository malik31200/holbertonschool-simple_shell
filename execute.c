#include "shell.h"
#include "utils.h"
#include "string_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Function declarations */
char **path_finder(void);

/**
 * execute_no_path - execute a command without a path search
 * command starting with '/' or '.'
 * @commands: an array of string containing all of the command datas
 * @shell_name: the name of the shell (executable)
 *
 * Return: 127 if the file is not found
 * 126 if the file is not executable
 * exit code of execute_command if it succeed
 */
int execute_no_path(char **commands, char *shell_name)
{
	if (access(commands[0], F_OK) == -1)
	{
		fprintf(stderr, "%s: %s: not found\n", shell_name, commands[0]);
		_free_split_string(commands);
		return (127);
	}
	if (access(commands[0], X_OK) == -1)
	{
		fprintf(stderr, "%s: %s: Permission denied\n", shell_name, commands[0]);
		_free_split_string(commands);
		return (126);
	}
	return (execute_command(commands[0], commands));
}

/**
 * execute_path - a function to find a command in a file
 * @commands: an array of string containing all the information
 * of a command
 * @shell_name: the name of the shell (current executable)
 *
 * Return: 1 if it fails
 * exit code if it succed
 */
int execute_path(char **commands, char *shell_name)
{
	char **path;
	size_t i;
	char *command, *temp;

	path = path_finder();
	if (path == NULL)
	{
		fprintf(stderr, "%s: %s: not found\n", shell_name, commands[0]);
		_free_split_string(commands);
		return (127);
	}
	for (i = 0; path[i] != NULL; i++)
	{
		command = NULL;
		if (path[i][0] == '\0')
			command = _strdup(".");
		else
			command = _strdup(path[i]);

		if (command == NULL)
		{
			perror("strdup failed");
			_free_split_string(commands);
			_free_split_string(path);
			return (1);
		}
		if (command[_strlen(command) - 1] != '/')
		{
			temp = strcat_realloc("/", command);
			if (temp == NULL)
			{
				perror("strcat failed");
				_free_split_string(commands);
				_free_split_string(path);
				return (1);
			}
			command = temp;
		}
		temp = strcat_realloc(commands[0], command);
		if (temp == NULL)
		{
			perror("strcat failed");
			_free_split_string(commands);
			_free_split_string(path);
			return (1);
		}
		command = temp;
		if (access(command, F_OK | X_OK) == 0)
		{
			_free_split_string(path);
			return (execute_command(command, commands));
		}
		free(command);
		command = NULL;
	}
	fprintf(stderr, "%s: %s: not found\n", shell_name, commands[0]);
	_free_split_string(commands);
	_free_split_string(path);
	return (1);
}

/**
 * path_finder - Find the path
 *
 * Return: NULL if not find
 * The path directory if found
 */
char **path_finder(void)
{
	size_t i;
	char *path_copy;
	char **result;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			path_copy = _strdup(environ[i]);
			if (path_copy == NULL)
				return (NULL);

			result = split_string(path_copy + 5, ":");
			free(path_copy);
			return (result);
		}

	}
	return (NULL);
}

