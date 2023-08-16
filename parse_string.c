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
		argv = realloc(argv, (argc + 1) * sizeof(char *));
		if (!argv)
		{
			perror("Memory Allocation Error");
			exit(1);
		}
		argv[argc++] = token;
		token = strtok(NULL, " \"\n");
	}
	argv[argc] = NULL;
	return (argv);
}
