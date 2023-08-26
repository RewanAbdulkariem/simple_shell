#include "main.h"
/**
 * excute_command - function to fork a process and execute a command
 * @command: the command to be executed
 * @argv: arguments to pass to the command
 */
void excute_command(char *command, char **argv)
{
	pid_t child;
	int status;

	child = fork();

	if (child == -1)
	{
		perror("Error");
		exit(1);
	}
	if (child == 0)
	{
		execve(command, argv, environ);
		perror("Execve failed");
	}
	else
	{
		wait(&status);
	}
}
/**
 * command_path - find the path of a command
 * @command: the command to search for
 * Return: the path of the command, or NULL if not found
 */
char *command_path(char *command)
{
	char *path, *cpy_path, *file_path, *token;
	int file_len = 0;
	struct stat buffer;

	if (stat(command, &buffer) == 0)
	{
		file_path = strdup(command);
		return (file_path);
	}
	path = getenv("PATH");
	cpy_path = strdup(path);

	token = strtok(cpy_path, ":");
	while (token != NULL)
	{
		file_len = strlen(command) + strlen(token) + 2;
		file_path = malloc(file_len * sizeof(char *));
		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");

		if (stat(file_path, &buffer) == 0)
		{
			free(cpy_path);
			return (file_path);
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	free(cpy_path);
	return (NULL);
}
