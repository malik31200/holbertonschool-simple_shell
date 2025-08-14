#include "shell.h"
#include "utils.h"
#include "string_helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Function declarations */
char **path_finder(void);
char *build_path(char *command, char *path);

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
		return (127);
	}
	if (access(commands[0], X_OK) == -1)
	{
		fprintf(stderr, "%s: %s: Permission denied\n", shell_name, commands[0]);
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
 * 127 if file not founds
 * 126 if file found but not executable
 */
int execute_path(char **commands, char *shell_name)
{
	char **path;
	size_t i;
	char *command;
	int ret = 127;

	path = path_finder();
	if (path == NULL)
	{
		fprintf(stderr, "%s: %s: not found\n", shell_name, commands[0]);
		return (127);
	}
	for (i = 0; path[i] != NULL; i++)
	{
		command = NULL;
		command = build_path(commands[0], path[i]);
		if (command == NULL)
		{
			ret = 1;
			break;
		}
		if (access(command, F_OK) == 0)
		{
			if (access(command, X_OK) == 0)
			{
				ret = execute_command(command, commands);
				free(command);
				break;
			}
			else
			{
				fprintf(stderr, "%s: %s: permission denied\n", shell_name, commands[0]);
				free(command);
				ret = 126;
				break;
			}
		}
		free(command);
	}
	if (ret == 127)
		fprintf(stderr, "%s: %s: not found\n", shell_name, commands[0]);

	_free_split_string(path);
	return (ret);
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

/**
* build_path - a function that returns a built path of a command
* @command: a command like 'ls'
* @path: a path like '/bin'
*
* Return: NULL if it fails
* the fully built path if it suceed
*/
char *build_path(char *command, char *path)
{
	char *built_path, *temp;

	if (path[0] == '\0')
		built_path = _strdup(".");
	else
		built_path = _strdup(path);

	if (built_path == NULL)
	{
		perror("strdup failed");
		return (NULL);
	}

	if (built_path[_strlen(built_path) - 1] != '/')
	{
		temp = _strcat(built_path, "/");
		free(built_path);
		if (temp == NULL)
		{
			perror("strcat failed");
			return (NULL);
		}
		built_path = temp;
	}
	temp = _strcat(built_path, command);
	if (temp == NULL)
	{
		free(built_path);
		perror("strcat failed");
		return (NULL);
	}
	free(built_path);
	return (temp);
}
