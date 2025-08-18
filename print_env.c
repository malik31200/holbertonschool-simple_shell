#include "shell.h"
#include <stdio.h>
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
