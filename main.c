#include "main.h"
/**
 * main - the entry
 * Return: 0 on success
 */
int main(void)
{
	char **argv;
	char *cmd = NULL;			/*command entered by the user*/
	size_t n = 0;			/*size of input buffer*/

	while (1)
	{
		printf("\e[1;31m SHELL# ");
		printf("\e[0m");

		if (getline(&cmd, &n, stdin) == -1 || strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			exit(1);
		}

		argv = parse_line(cmd);
		excute_command(argv);
	}
	free(argv);
	return (0);
}
