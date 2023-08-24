#include "main.h"
#define MAX_SIZE 1024
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
<<<<<<< HEAD
	int i;
=======

	argv = malloc((MAX_SIZE + 1) * sizeof(char *));
	if (!argv)
	{
		perror("Memory Allocation Error");
		exit(1);
	}
>>>>>>> d37395f9b5a1de3f3974c35b2028dde59019fe61

	token = strtok(line, " \n");

	while (token)
	{
<<<<<<< HEAD
		char **new_argv = malloc((argc + 1) * sizeof(char *));
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
=======
		argv[argc++] = token;
>>>>>>> d37395f9b5a1de3f3974c35b2028dde59019fe61
		token = strtok(NULL, " \"\n");
	}

	argv[argc] = NULL;
	return (argv);
}
