#include "main.h"
/**
 * main - the entry
 * Return: 0 on success
 */
int main(void)
{
	char **argv;
	char *cmd = NULL;
	size_t n = 0;

	while (1)
	{
		printf("SHELL# ");

		if (getline(&cmd, &n, stdin) == -1 || strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			exit(1);
		}

		argv = parse_sting(cmd);
		excute_line(argv);
	}
	free(argv);
	return (0);
}
