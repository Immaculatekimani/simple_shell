#include "shell.h"

/**
 * mem_alloc - allocate space to size
 * @size: size of space to allocate
 *
 * Return: pointer to space in memory
 */
void *mem_alloc(size_t size)
{
	void *pointer;

	pointer = malloc(size);
	if (pointer == NULL)
	{
		_push("Memory allocation failed!");
		exit(20);
	}
	return (pointer);
}

/**
 * clear_arr - clear a vector of strings
 *
 * @vector: the vector of strings to be cleared
 *
 * Return: void
 */
void clear_arr(char **vector)
{
	free(vector[0]);
	free(vector);
}
