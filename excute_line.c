#include "main.h"
/**
 * excute_command - function to fork a process to excute command
 * @argv: argument to be excute a command
 */
void excute_command(char **argv)
{
	pid_t child;

	child = fork();

	if (child == -1)
	{
		perror("Error");
		exit(1);
	}
	if (child == 0)
	{
		execvp(argv[0], argv);
		perror("Execve failed");
	}
	else
	{
		wait(NULL);
	}
}
