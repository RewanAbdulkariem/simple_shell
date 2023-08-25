#include "main.h"
/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: 0 on successful completion, -1 on error or when the shell exits.
 */
int main(int argc, char **argv)
{
	char *prompt = "(MyShell)$ ", *command;
	size_t n = 0;
	ssize_t num_read;
	int i;
	(void)argc;

	while (1)
	{
		char *cmd = NULL;
		char **split_string = NULL;

		printf("%s", prompt);
		num_read = getline(&cmd, &n, stdin);

		if (num_read == -1 || feof(stdin))
		{
			printf("Exit shell....\n");
			free(cmd);
			break;
		}
		split_string = parse_string(cmd, num_read);
		command = command_path(split_string[0]);
		if (command == NULL)
		{
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		excute_command(command, split_string);
		free(command);
		free(cmd);
		for (i = 0; split_string[i] != NULL; i++)
			free(split_string[i]);
		free(split_string);
	}
	return (0);
}
