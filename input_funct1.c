#include "shell.h"

/**
 * _strdup - function definition
 * @str: a string pointer
 * Description: duplicates a string
 * Return: a string value
 */

char *_strdup(char *str)
{
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}

	new_str = mem_alloc(strlen(str) + 1);

	if (new_str == NULL)
	{
		return (NULL);
	}
	_strcpy(new_str, str);
	return (new_str);
}


/**
 * _strlen - function definition
 * Description: checks string length
 * @s: the string pointer
 * Return: index
 */

int _strlen(char *s)
{
	int index;

	for (index = 0; s[index] != '\0'; index++)
	{}
	return (index);
}

/**
 * *_strchr - function definition
 * @s: the string to be searched
 * @c: the character to find
 * Description: finds a character in a string
 * Return: a character value
 */

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index] != '\0'; index++)
	{
		if (s[index] == c)
		{
			return (s + index);
		}
	}
	if (s[index] == c)
	{
		return (s + index);
	}
	return (NULL);
}

/**
 * *_strpbrk - function definition
 * @s: the string to be searched
 * @accept: bytes to search for
 * Description: searches for a string of a set of bytes
 * Return: pointer to matched byte or NULL if no match
 */

char *_strpbrk(char *s, char *accept)
{
	int str_index;
	int sub_str_index;

	for (str_index = 0; s[str_index] != '\0'; str_index++)
	{
		for (sub_str_index = 0; accept[sub_str_index] != '\0'; sub_str_index++)
		{
			if (s[str_index] == accept[sub_str_index])
			{
				return (s + str_index);
			}
		}
	}
	return (0);
}
