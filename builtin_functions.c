#include "shell.h"

/**
 * is_builtins - Check to see if given command is a builtin
 * @commands: Array holding command and all its arguments
 * @input: The user input received 
 *
 * Return: the return value of the builtin called on success,
 * or -1 if it failed
 */
int is_builtins(char **commands, char *input)
{
	builtins_t built_ins[] = {
		{"exit", shell_exit},
		{"env", print_env},
		{"unsetenv", unset_environ},
		{"setenv", set_environ},
		{"help", shell_help},
		{NULL, NULL}
	};
	int i;

	for (i = 0; built_ins[i].name != NULL; i++)
	{
		if (_strcmp(commands[0], "exit") == 0)
			return (built_ins[0].func(commands, input));
		if (_strcmp(commands[0], built_ins[i].name) == 0)
			return (built_ins[i].func(commands));
	}
	return (-1);
}
/**
 * shell_exit - exit a child process
 * @commands: Double pointer to the entered commands
 * @input: The original input from the user
 *
 * Return: 0 if success, 1 if failure
 */
int shell_exit(char **commands, char *input)
{
	int status;

	if (commands[1] == NULL)
	{
		free(input);
		free(commands);
		_exit(0);
	}
	else
	{
		status = _atoi(commands[1]);
		if (status == -1)
		{
			_push("Illegal number\n");
			return (1);
		}
		free(input);
		free(commands);
		_exit(status);
	}
	return (1);
}
/**
 * shell_help - Acts as the man help page
 * @commands: arguments passed to shell_help
 *
 * Return: 0 on success, 1 on failure
 */
int shell_help(char **commands)
{
	help_t built_ins[] = {
		{"exit", push_exit},
		{"setenv", push_setenv},
		{"unsetenv", push_unsetenv},
		{"env", push_env},
		{"help", push_help},
		{NULL, NULL}
	};
	int i, j, helped;

	helped = 0;
	i = 1;
	if (commands[1] == NULL)
	{
		print_help();
		return (0);
	}
	while (commands[i] != NULL)
	{
		j = 0;
		while (built_ins[j].name != NULL)
		{
			if (_strcmp(built_ins[j].name, commands[i]) == 0)
			{
				helped++;
				built_ins[j].func();
				break;
			}
			j++;
		}
		i++;
	}
	if (helped > 0)
		return (0);
	_push("Command not available in help\n");
	return (1);
}

