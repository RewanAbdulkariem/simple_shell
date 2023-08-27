#include "main.h"

/**
 * exit_shell - exits the shell.
 * @command: array of strings representing the command and its arguments
 */

void exit_shell(char **command)
{
	int exit_value = 0, i;

	if (command[1] != NULL)
	{
		char *endptr;
		exit_value = strtol(command[1], &endptr, 10);
		if (*endptr != '\0')
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", command[1]);
			exit_value = 2;
		}
		if (exit_value < 0)
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %d\n", exit_value);
			exit_value = 2;
		}

	}

	for (i = 0; command[i] != NULL; i++)
		free(command[i]);

	free(command);
	exit(exit_value);
}

