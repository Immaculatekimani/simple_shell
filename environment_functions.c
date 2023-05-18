#include "shell.h"

/**
 * unset_env - unsets an environment
 *
 * @name: name of variable
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env(char *name)
{
	char **ep;
	int len;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
		return (-1);
	ep = environ;
	len = _strlen(name);
	while (*ep != NULL)
	{
		if (_strcmp(*ep, name) == 0 && (*ep)[len] == '=')
			while (*ep != NULL)
			{
				*ep = *(ep + 1);
				ep++;
			}
		else
			ep++;
	}
	return (0);
}

/**
 * find_env - gets an environment variable
 *
 * @name: name used to look for environment
 *
 * Return: pointer to variable if it exists, or NULL if it doesn't
 */
char *find_env(char *name)
{
	char **envp;

	envp = environ;
	while (*envp != NULL)
	{
		if (_strcmp(*envp, name) == 0)
			return (*envp);
		envp++;
	}
	return (*envp);
}

/**
 * add_env - add or modify an environment
 *
 * @new_arr: variable and value
 * @name: name of variable to add or modify
 *
 * Return: 0 if success, -1 if failure
 */
int add_env(char *new_arr, char *name)
{
	char **nenv, **envp;
	size_t i;

	if (find_env(name) == NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
			;
		nenv = mem_alloc(sizeof(char *) * (i + 2));
		envp = nenv;
		i = 0;
		while (*environ != NULL)
		{
			*nenv = *environ;
			nenv++;
			environ++;
		}
		*nenv = new_arr;
		nenv++;
		*nenv = NULL;
		environ = envp;
		return (0);
	}
	else
		return (-1);
	return (0);
}

