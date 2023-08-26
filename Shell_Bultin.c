#include "main.h"
/**
 * print_environment - Print the current environment variables.
 */
void print_environment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * Shell_Builtin - Execute built-in shell commands.
 * @command: The command and its arguments.
 *
 * Return: Always 0.
 */
int Shell_Builtin(char **command)
{
	char *cwd;
	int i;

	if (strcmp(command[0], "exit") == 0)
	{
		for (i = 0; command[i] != NULL; i++)
			free(command[i]);
		free(command);
		exit(0);
	}
	else if (strcmp(command[0], "env") == 0)
		print_environment();
	else if (strcmp(command[0], "cd") == 0)
	{
		if (command[1] == NULL || !strcmp(command[1], "~"))
			cwd = "/home";
		else
			cwd = command[1];
		chdir(cwd);
	}
	return (0);
}
