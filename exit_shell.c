#include "main.h"

/**
 * exit_shell - exits the shell.
 * @args: array of strings representing the command and its arguments
 * @argc: the number of arguments.
 */

void exit_shell(char **args, int argc)
{
	int exit_value;

	if (strcmp(args[0], "exit") == 0)
	{
		if (argc > 1)
		{
			exit_value = atoi(args[1]);
			exit(exit_value);
		}
		else
		{
			exit(0);
		}
	}
}

