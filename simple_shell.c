#include "shell.h"

/**
 * main - initialization of shell
 *
 * @argc: number of commands
 * @argv: vector of commands
 * @env: environment
 *
 * Return: 0 if success, -1 if failure
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	shell_loop();
	return (0);
}

/**
 * shell_loop - shell prompt shell_loop
 *
 * Return: void
 */
void shell_loop(void)
{
	char *input, **commands, *prog_name;
	int looped;
	size_t size;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);

	size = 0;
	looped = 0;
	input = NULL;
	while (1)
	{
		forked = 0;
		_push("Shell$ ");
		if (getline(&input, &size, stdin) != -1)
		{
			if (input[0] != '\n' && input[0] != '#')
			{
				commands = create_arg(input);
				prog_name = commands[0];
				if (is_builtins(commands, input) == -1)
				{
					forked = 1;
					display(commands);
				}
				if (is_arg(prog_name, commands[0]) == 0)
					free(commands);
				else
					clear_arr(commands);
				looped++;
			}
		}
		else
		{
			free(input);
			_putchar('\n');
			_exit(0);
		}
	}
}

/**
 * sighandler - Print out the prompt if ctrl-C is hit
 * @sig_digit: Unused variable 
 */
void sighandler(int sig_digit)
{
	(void)sig_digit;
	if (forked == 0)
		_push("\nShell$ ");
	signal(SIGINT, sighandler);
}

