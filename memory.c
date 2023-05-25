#include "shell.h"

/**
 * smart_alloc - allocate space if there is any, and add memory
 * to list of space to free
 *
 * @size: size of space to allocate
 *
 * Return: pointer to space in memory
 */
void *smart_alloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		_puts("We used up all the memory!!! Holy shit\n");
		exit(20);
	}
	return (ptr);
}

/**
 * free_array - frees a pointer array of strings
 *
 * @array: 2d array
 *
 * Return: void
 */
void free_array(char **array)
{
	free(array[0]);
	free(array);
}
