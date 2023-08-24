#include "main.h"

/**
 * parse_line - parse the string into arguments
 * @line: pointer to the string
 * Return: pointer to the arguments
 */
char **parse_line(char *line)
{
	char **argv = NULL;
	char *token = NULL;
	int argc = 0;

	token = strtok(line, " \n");

	while (token)
	{
		char **new_argv = malloc((argc + 1) * sizeof(char *));
		int i;

		if (!new_argv)
		{
			perror("Memory Allocation Error");
			exit(1);
		}

		for (i = 0; i < argc; i++)
		{
			new_argv[i] = argv[i];
		}

		new_argv[argc++] = token;

		free(argv);
		argv = new_argv;
		token = strtok(NULL, " \"\n");
	}

	argv[argc] = NULL;
	return (argv);
}
