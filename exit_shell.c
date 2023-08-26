#include "main.h"

/**
 * exit_shell - exits the shell.
 * @args: array of strings representing the command and its arguments
 * @argc: the number of arguments.
 */

void exit_shell(char **command, int argc)
{
	int exit_value = 0, i;

	if (argc > 1)
	{
		exit_value = atoi(command[1]);
	}
	for (i = 0; command[i] != NULL; i++)
			free(command[i]);
		free(command);
	exit(exit_value);
}

