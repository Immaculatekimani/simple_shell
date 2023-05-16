#include "shell.h"

/**
 * is_path - Check the path for the given file and if found
 * replaces command argument with new full file name
 *
 * @commands: Pointer array holding command & all command commands
 *
 * Return: Pointer array to commands w/ first command replaced
 * if the file was found, or the orginal commands, if not found
 */
char **is_path(char **commands)
{
	char *filename, *delim, *pos, *path, *dir;
	struct stat st;

	pos = NULL;
	delim = ":";
	path = path_copy("PATH");
	if (path == NULL)
	{
		_push("Path not found!");
		_exit(22);
	}
	dir = tokenize(path, delim, &pos);
	while (dir != NULL)
	{
		filename = concat_path(dir, commands[0]);
		if (stat(filename, &st) == 0)
		{
			commands[0] = filename;
			free(path);
			return (commands);
		}
		dir = tokenize(NULL, delim, &pos);
		free(filename);
	}
	free(path);
	return (commands);
}

/**
 * concat_path - join strings together with a '/' 
 *
 * @s1: starting string
 * @s2: completing string
 *
 * Return: points to the new string
 */
char *concat_path(char *s1, char *s2)
{
	char *s, *p;
	int s1len, s2len;

	s1len = s2len = 0;
	s1len = _strlen(s1);
	s2len = _strlen(s2);
	s = mem_alloc((s1len + s2len + 2) * sizeof(char));
	p = s;
	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = '/';
	s++;
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
 * path_copy - Duplicates a path
 *
 * @name: the name of the Path
 *
 * Return: the Path or null if not found
 */
char *path_copy(char *name)
{
	char **envp, *path;
	int len, i;

	i = 0;
	envp = environ;
	len = _strlen(name);
	while (envp[i] != NULL)
	{
		if (_strncmp(envp[i], name, len) == 0)
		{
			path = _strdup(&envp[i][len + 1]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

