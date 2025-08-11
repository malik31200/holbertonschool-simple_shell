#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t child;
	size_t i;
	int status;

	for (i = 0; i < 5; i++)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error :");
			return (1);
		}

		if (child == 0)
		{
			execve(argv[0], argv, NULL);
			perror("execve :");
			_exit(127);
		}
		else
		{
			wait(&status);
		}
	}
}
