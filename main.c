#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command;
	size_t len;
	ssize_t read;

	while (1)
	{
		printf("#cisfun$:");
		read = getline(&command, &len, stdin);

		if (read == -1)
		{
			printf("\nError incorrect read \n");
			break;
		}

		if ((_strcmp(command, "exit\n")) == 0)
		{	
			break;
		}

		printf("./shell: No such file or directory\n");

	}
	free(command);
	return (0);
}
