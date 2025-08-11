#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t _strlen(char *str);
char *_strdup(char *str);
char **split_string(char *toSplit);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ssize_t nRead = 0;
	char *command = NULL;
	size_t len = 0, i;
	char **splitString = NULL;

	while (1)
	{
		printf("$ ");
		nRead = getline(&command, &len, stdin);
		if (nRead == -1)
		{
			exit (127);
		}
		splitString = split_string(command);

		for (i = 0; splitString[i] != NULL; i++)
		{
			printf("%s\n", splitString[i]);
		}

		for (i = 0; splitString[i] != NULL; i++)
		{
			free(splitString[i]);
		}
		free(splitString);
		splitString = NULL;
	}
	return (0);
}

char **split_string(char *toSplit)
{
	char **result = NULL, **tempRes;
	char *temp;
	size_t count = 0, i;

	if (toSplit == NULL)
		return (NULL);

	temp = strtok(toSplit, " \t\n");
	
	while (temp != NULL)
	{
		tempRes = realloc(result, sizeof(char *) * (count + 2));
		if (tempRes == NULL)
		{
			free(result);
			return (NULL);
		}

		result = tempRes;
		result[count] = _strdup(temp);
		if (result[count] == NULL)
		{
			for (i = 0; i < count; i++)
			{
				free(result[i]);
			}
			free (result);
			return (NULL);
		}

		count++;
		temp = strtok(NULL, " \t\n");
	}

	if (result != NULL)
		result[count] = NULL;

	return (result);
}

/**
* _strlen - return the size of the string
* @str: a string
*
* Return: the size of the string
* 0 if it's NULL
*/
size_t _strlen(char *str)
{
	size_t len;

	if (str == NULL)
		return (0);

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}

/**
* _strdup - return a malloced copy of a string
* @str: the string to copy
*
* Return: a malloced copy of str
* NULL if it fails
*/
char *_strdup(char *str)
{
	char *res = NULL;
	size_t i;

	if (str == NULL)
		return (NULL);

	res = malloc(_strlen(str) + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		res[i] = str[i];
	}

	res[i] = '\0';
	return (res);
}
