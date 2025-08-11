#include <stdio.h>
#include <unistd.h>

/**
*/
int main(void)
{
	pid_t parent;

	parent = getpid();
	printf("%u\n", parent);

	sleep(5);

	return (0);
}
