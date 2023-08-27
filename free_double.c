#include "main.h"

/**
 * free_double - free double pointer.
 * @array: pointer to a pointer.
 * @size_t: the size of the pointer.
 */

void free_double(void **array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		free(array[i]);
	}

	free(array);
}

