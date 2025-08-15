#include "env.h"
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Function declarations */
int no_path(char **argv);
int find_the_path(char **argv);
char *build_command(char *path, char *command);
int search_path(char **path, char **argv);

/**
 * chose_path - a function that chose a path
 * @argv: arguments containing the command
 *
 * Return: 127 if not found
 * 126 if not executable and not found
 * -1 if it fails
 */
int chose_path(char **argv)
{
	if (*(*argv) == '/' ||
		(*(*argv) == '.' && ((*argv)[1] == '.' || (*argv)[1] == '/')))
		return (no_path(argv));
	else
		return (find_the_path(argv));
}
/**
 * no_path - a function that execute a command directly
 * @argv: the argument containing the command
 *
 * Return: 127 fi the command is nt found
 * 126 if it's not executable
 * -1 if it fails
 */
int no_path(char **argv)
{
	if (access(argv[0], F_OK) == -1)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return (127);
	}
	if (access(argv[0], X_OK) == -1)
	{
		fprintf(stderr, "%s: permission denied\n", argv[0]);
		return (126);
	}
	return (execute_command(argv));
}

/**
 * find_the_path - a function that execute
 * a command if a command exist and is executable
 * @argv: command and it's argument
 *
 * Return: -1 if it fails
 * 127 if command is not found
 * 126 if permission denied
 * 0 if it succeed
 */
int find_the_path(char **argv)
{
	char *path;
	char **arr_path;
	int ret;

	path = path_finder();
	if (path == NULL)
		return (-1);

	arr_path = split_token(path, ":");
	if (arr_path == NULL)
	{
		free(path);
		return (-1);
	}
	free(path);
	ret = search_path(arr_path, argv);
	if (ret == 127)
		fprintf(stderr, "%s: command not found\n", argv[0]);
	if (ret == 126)
		fprintf(stderr, "%s: command not found\n", argv[0]);

	free_char_arr(arr_path);
	return (ret);
}

/**
* build_command - a function to build a command
* @path: the path to build
* @command: the command to attach to the path
*
* Return: NULL if it fails
* a newly allocated string of the command if it succeed
*/
char *build_command(char *path, char *command)
{
	char *built_command;
	size_t len;

	if (path == NULL || command == NULL)
		return (NULL);

	len = strlen(path) + 1 + strlen(command) + 1;
	built_command = malloc(len);
	if (built_command == NULL)
		return (NULL);

	strcpy(built_command, path);
	if (path[strlen(path) - 1] != '/')
		strcat(built_command, "/");

	strcat(built_command, command);

	return (built_command);
}

/**
* search_path - a function that search and execute a command
* @path: an array containing all the paths
* @argv: the command with it's arguments
*
* Return: 0 if it succeed
* 126 if permission denied
* 127 if not found
* -1 if it fails
*/
int search_path(char **path, char **argv)
{
	size_t i = 0;
	char *command;

	(void)path;
	for (i = 0; path[i] != NULL; i++)
	{
		command = NULL;
		command = build_command(path[i], argv[0]);
		if (command == NULL)
		{
			return (-1);
		}

		if (access(command, F_OK) == 0)
		{
			if (access(command, X_OK) == 0)
			{
				free(argv[0]);
				argv[0] = command;
				return (execute_command(argv));
			}
			else
			{
				free(command);
				return (126);
			}
		}
		free(command);
	}
	return (127);
}
