#include "shell.h"

/**
 * _atoi - function definition
 * Description: convert string to integer
 * @st: the string pointer
 * Return: integer value of string
 */
int _atoi(char *st)
{
	int num_sign = 1;
	unsigned int digit = 0;

	do {
		if (*st == '-')
		{
			num_sign *= -1;
		}
		else if (*st >= '0' && *st <= '9')
		{
			digit = (digit * 10) + (*st - '0');
		}
		else if (digit > 0)
		{
			break;
		}
	} while (*st++);
	return (digit * num_sign);
}
