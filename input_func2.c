#include "shell.h"

/**
 * _strspn - function definition
 * @s: the string to search
 * @accept: the prefic substring to be tested
 * Description: returns number of bytes in s
 * which only has bytes from accept
 * Return: number of bytes
 */
int _strspn(char *s, const char *accept)
{
	int i, j, flag, count;

	i = flag = count = 0;
	while (s[i] && count == i)
	{
		for (j = 0; accept[j] && !flag; j++)
		{
			if (accept[j] == s[i])
			{
				count++;
				flag = 1;
			}
		}
		flag = 0;
		i++;
	}
	return (count);
}

/**
 * _strcmp - Compare two strings, output int based on comparison
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: Int -1 if s1 shorter, +1 if s1 is longer, 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i, l1, l2;

	i = 0;
	l1 = 0;
	l2 = 0;
	while (s1[l1] != 0)
	{
		l1++;
	}
	while (s2[l2] != 0)
	{
		l2++;
	}
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (l1 > l2)
	{
		return (s1[l2]);
	}
	else if (l1 < l2)
	{
		return (s2[l1] * -1);
	}
	return (0);
}

/**
 * _strcat - function definition
 * Description: concatenates dest and src strings
 * @dest: second string
 * @src: first string
 * Return: character
 */
char *str_concat(char *s1, char *s2)
{
	char *s, *p;
	int s1length, s2length;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	s1length = _strlen(s1);
	s2length = _strlen(s2);
	s = mem_alloc(s1length + s2length + 1);
	p = s;
	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (p);
}
/**
 * _strcpy - function declaration
 * Description: copies a string
 * @dest: destination to copy to
 * @src: source to copy from
 * Return: destination
 */

char *_strcpy(char *dest, char *src)
{
	int index;

	for (index = 0; index <= _strlen(src); index++)
	{
		dest[index] = src[index];
	}
	return (dest);
}
