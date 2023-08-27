#include "main.h"
/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on successful completion
 */
int main(int argc, char **argv)
{
	char *command, *Bultin[3] = {"exit", "env", "cd"};
	int i, exitshell = 0, Internalcmd = 0;
	(void)argc;

	while (!exitshell)
	{
		char *cmd = NULL, **split_string = NULL;

		Internalcmd = 0;
		print_prompt();
		cmd = read_command();
		if (cmd == NULL)
			break;
		split_string = parse_string(cmd, strlen(cmd));
		free(cmd);
		if (split_string[0] == NULL)
		{
			free(split_string);
			break;
		}
		for (i = 0; i < 3; i++)
		{
			if (strcmp(split_string[0], Bultin[i]) == 0)
				Internalcmd = 1;
		}
		if (Internalcmd)
			Shell_Builtin(split_string);
		else
		{
			command = command_path(split_string[0]);
			if (command == NULL)
				fprintf(stderr,"%s: No such file or directory\n", argv[0]);
			else
				excute_command(command, split_string);
			free(command);
		}
		for (i = 0; split_string[i] != NULL; i++)
			free(split_string[i]);
		free(split_string);
	}
	return (0);
}
/**
 * read_command - Read a command from the user.
 * Return: The user's entered command string.
 */
char *read_command(void)
{
	char *cmd = NULL;
	ssize_t num_read;
	size_t n = 0;

	num_read = getline(&cmd, &n, stdin);
	if (num_read == -1 || feof(stdin))
	{
		free(cmd);
		return (NULL);
	}
	return (cmd);
}
/**
 * print_prompt - Print the shell prompt.
 */
void print_prompt(void)
{
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO) == 1)
		printf("%s", prompt);
}
