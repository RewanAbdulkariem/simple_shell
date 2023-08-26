#include "main.h"

#define BUFFER_SIZE 1024

/**
* get_line - get command from user.
* Return: characters from stdin.
*/

char get_line(void)
{
	static char read_buffer[BUFFER_SIZE];
	static size_t read_index, bytes_in_buffer;
	size_t bufsize = BUFFER_SIZE, index = 0;
	char *buffer = malloc(bufsize);

	if (!buffer)
	{
		return (NULL);
	}

	while (1)
	{
		if (bytes_in_buffer == 0)
		{
			bytes_in_buffer = read(STDIN_FILENO, read_buffer, BUFFER_SIZE);
			read_index = 0;
		}

		if (bytes_in_buffer <= 0)
			break;

		buffer[index++] = read_buffer[read_index++];
		bytes_in_buffer--;

		if (index >= bufsize)
		{
			bufsize *= 2;
			char *new_buffer = malloc(bufsize);

			if (!new_buffer)
			{
				free(buffer);
				return (NULL);
			}

			for (size_t i = 0; i < index; i++)
			{
				new_buffer[i] = buffer[i];
			}

			free(buffer);
			buffer = new_buffer;
		}

		if (buffer[index - 1] == '\n')
			break;
	}

	buffer[index] = '\0';
	return (buffer);
}

