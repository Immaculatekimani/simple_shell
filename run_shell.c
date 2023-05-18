#include "shell.h"

/**
 * display - decide what to do with @commands
 *
 * @commands: a vector of command strings
 *
 * Return: void
 */
void display(char **commands)
{
	if (commands[0][0] == '/')
		run_shell(commands);
	else
	{
		commands = is_path(commands);
		if (commands != NULL)
			run_shell(commands);
	}
}

/**
 * run_shell - run the shell program
 *
 * @commands: vector of command strings
 *
 * Return: void
 */
void run_shell(char **commands)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		_exit(99);
	}
	if (pid == 0)
	{
		execve(commands[0], commands, environ);
		perror("Error");
		free(commands);
		_exit(1);
	}
	else
		wait(&status);
}

