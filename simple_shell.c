#include "utils.h"
#include "shell.h"
#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
char **path_finder(void);

/**
* simple_shell - a function that deal with shell commands
* @command: a command line for simple_shell
* @shell_name: Name of the shell
*
* Return: 0 if succeed
* 1 if it fails
*/
int simple_shell(char *command, char *shell_name)
{
	char **splitString;
	pid_t child;
	int status;
	size_t i;
	char **path;
	char *tosearch;

	splitString = split_string(command, " \t\n");
	if (splitString == NULL)
	{
		return (0);
	}
	if (splitString[0][0] == '/' || splitString[0][0] == '.')
	{
		if (access(splitString[0], F_OK) == -1)
		{
			fprintf(stderr, "%s: %s: not found\n", shell_name, command);
			return (127);
		}
		if (access(splitString[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: %s: Permission denied\n", shell_name, command);
			return (126);
		}
		child = fork();
		if (child == -1)
		{
			perror("fork failed");
			_free_split_string(splitString);
			return (1);
		}
		else if (child == 0)
		{
			if (execve(splitString[0], splitString, environ) == -1)
			{
				perror(splitString[0]);
				_exit(127);
			}
		}
		else
		{
			wait(&status);
			_free_split_string(splitString);
		}
	}
	else
	{
		path = path_finder();
		if (path == NULL)
		{
			fprintf(stderr, "%s: %s: not found\n",
            shell_name, splitString[0]);
		}
		for (i = 0; path[i] != NULL; i++)
		{
			tosearch = NULL;
			if (path[i][0] == '\0')
				continue;
			
			tosearch = _strdup(path[i]);
			tosearch = strcat_realloc("/", tosearch);
			if (tosearch == NULL)
			{
				perror("realloc failed");
				_free_split_string(path);
				_free_split_string(splitString);
				return (1);
			}
			tosearch = strcat_realloc(splitString[0], tosearch);
			if (tosearch == NULL)
			{
				perror("realloc failed");
				_free_split_string(path);
				_free_split_string(splitString);
				return (1);
			}
				if (access(tosearch, X_OK) == 0)
				{
					child = fork();
					if (child == -1)
					{
						perror("fork failed");
						_free_split_string(path);
						_free_split_string(splitString);
						return (1);
					}
					else if (child == 0)
					{
						if (execve(tosearch, splitString, environ) == -1)
						{
							perror(tosearch);
							_exit(127);
						}
					}
					else
					{
						wait(&status);
						_free_split_string(path);
						_free_split_string(splitString);
						free(tosearch);
					}
					break;
				}
			
		}
	}

	return (0);
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

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
			return (split_string(environ[i] + 5, ":"));

	}
	return (NULL);
}

