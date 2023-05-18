#include "shell.h"

/**
 * print_environ - print the list of environment variables
 * @commands: commands passed
 *
 * Return: 0 on success, 1 on failure
 */
int print_environ(char **commands)
{
	char c;
	int i, j;

	if (commands[1] == NULL)
	{
		for (i = 0; environ[i]; i++)
		{
			for (j = 0; environ[i][j]; j++)
			{
				c = environ[i][j];
				_putchar(c);
			}
			_putchar('\n');
		}
		return (0);
	}
	return (1);
}

/**
 * unset_environ - unset an environment variable
 *
 * @commands: command array
 *
 * Return: 0 if success, -1 if failure
 */
int unset_environ(char **commands)
{
	if (commands[1] == NULL)
		return (-1);
	return (unset_env(commands[1]));
}

/**
 * set_environ - set an environment variable
 *
 * @commands: argument array
 *
 * Return: 0 on success, -1 on failure
 */
int set_environ(char **commands)
{
	char *envp;
	int i, j, len;

	if (commands[1] == NULL || commands[2] == NULL || commands[1][0] == '\0')
	{
		_push("setenv syntax: setenv VARIABLE VALUE\n");
		return (-1);
	}
	unset_env(commands[1]);
	len = 0;
	for (i = 2; commands[i] != NULL; i++)
		for (j = 0; commands[i][j] != '\0'; j++, len++)
			;
	envp = mem_alloc(sizeof(char) * (len + i - 1));
	envp = _strcpy(envp, commands[1]);
	envp = str_concat(envp, "=");
	for (i = 2; commands[i] != NULL; i++)
	{
		envp = str_concat(envp, commands[i]);
		if (commands[i + 1] != NULL)
			envp = str_concat(envp, " ");
	}
	if (add_env(envp, commands[1]) != 0)
		return (-1);
	return (0);
}

