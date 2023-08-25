#include "main.h"
#include <signal.h>

/**
*cleanup - signal handler to catch signals.
*@sig: signal to terminate the program.
*/

char *lineptr = NULL;

void cleanup(int sig)
{
	free(lineptr);
	exit(sig);
}

/**
 * main - the entry point.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	char *prompt = "(shell) $: ";
	char *copy;
	size_t n = 0;
	ssize_t n_read;
	const char *delim = " \n";
	char *token;
	int num_tokens;
	int i;


	(void) argc;

	signal(SIGINT, cleanup);
	signal(SIGTERM, cleanup);

	while (1)
	{
		printf("%s", prompt);

		n_read = getline(&lineptr, &n, stdin);
		if (n_read == -1)
			return (-1);

		copy = malloc(sizeof(char) * n_read);
		if (!copy)
		{
			perror("Memory allocation error");
			return (-1);
		}

		strcpy(copy, lineptr);

		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}

		argv[i] = NULL;

		execmd(argv);

		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}


		free(copy);
		free(argv);
	}

	free(lineptr);

	return (0);
}

