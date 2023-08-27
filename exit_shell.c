#include "main.h"

/**
 * exit_shell - exits the shell.
 * @command: array of strings representing the command and its arguments
 * @argc: the number of arguments.
 */

void exit_shell(char **command, int argc)
{
	int exit_value = 0, i;

	if (command[1] != NULL)
		exit_value = atoi(command[1]);

	if (exit_value == -1)
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %d\n", exit_value);
		exit_value = 2;
	}

	for (i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
	}

	free(command);
	exit(exit_value);
}

