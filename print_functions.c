#include "shell.h"

/**
 * _push - prints a string
 *
 * @str: the string to print
 */
void _push(char *str)
{
	int n = 0;

	while (*(str + n) != '\0')
	{
		_putchar(*(str + n));
		n++;
	}
}

/**
 * _putchar - prints characters
 *
 * @c: The character to print to stdout
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

