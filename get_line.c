#include "main.h"

#define BUFFER_SIZE 1024

/**
 * get_line - read the user input.
 * Return: pointer to the input.
 */

char *get_line(void)
{
	char *input = malloc(sizeof(char) * BUFFER_SIZE);
	int ch, size = BUFFER_SIZE, i = 0;

	if (input == NULL)
	{
		fprintf(stderr, "allocation error");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		ch = getchar();

		if (ch == EOF)
		{
			free(input);
			exit(EXIT_FAILURE);
		}
		else if (ch == '\n')
		{
			input[i] = '\0';
			return (input);
		}
		else
		{
			input[i] = ch;
		}

		i++;

		if (i >= size)
		{
			size = size * 2;
			input = realloc(input, size); /* i will change it to malloc later */
			if (input == NULL)
			{
				fprintf(stderr, "error in reallocatin");
				exit(EXIT_FAILURE);
			}
		}
	}
}

