#include "main.h"
/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on successful completion
 */
int main(int argc, char **argv)
{
	char *command, *prompt = "$ ";
	size_t n = 0;
	ssize_t num_read;
	int i;
	(void)argc;

	while (1)
	{
		char *cmd = NULL, **split_string = NULL;

		if (isatty(STDIN_FILENO) == 1)
			printf("%s", prompt);

		num_read = getline(&cmd, &n, stdin);
		if (num_read == -1 || feof(stdin))
		{
			free(cmd);
			break;
		}
		split_string = parse_string(cmd, num_read);
		if (strcmp(split_string[0], "exit") == 0)
		{
			for (i = 0; split_string[i] != NULL; i++)
				free(split_string[i]);
			free(split_string), free(cmd);
			break;
		}
		command = command_path(split_string[0]);
		if (command == NULL)
		{
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		excute_command(command, split_string);
		for (i = 0; split_string[i] != NULL; i++)
			free(split_string[i]);
		free(split_string), free(cmd), free(command);
	}
	return (0);
}
