#include "main.h"
/**
 * parse_string - Split a string into an array of tokens.
 * @cmd: The input string to be parsed.
 * @num_chars: The number of characters in the input string.
 * Return: An array of strings containing the parsed tokens, with a NULL
 *         pointer at the end.
 */
char **parse_string(char *cmd, int num_chars)
{
	const char *delim = " \n";
	char **split_string, *token, *cpycmd = NULL;
	int num_tokens = 0, i;

	cpycmd = malloc(sizeof(char *) * num_chars);
	if (cpycmd == NULL)
	{
		perror("memory allocation error");
		exit(1);
	}
	strcpy(cpycmd, cmd);
	token = strtok(cpycmd, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;
	split_string = malloc(sizeof(char *) * num_tokens);
	token = strtok(cmd, delim);
	for (i = 0; token != NULL; i++)
	{
		split_string[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	split_string[i] = NULL;
	free(cpycmd);
	return (split_string);
}
