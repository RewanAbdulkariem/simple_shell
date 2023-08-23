#include "main.h"
/**
 * excute_command - function to fork a process to excute command
 * @argv: argument to be excute a command
 */
void excute_command(char **argv)
{
	pid_t child;
	int status;

	child = fork();

	if (child == -1)
	{
		perror("Error");
		exit(1);
	}
	if (child == 0)
	{
		execve(argv[0], argv, NULL);
		perror("Execve failed");
	}
	else
	{
		wait(&status);
	}
}
