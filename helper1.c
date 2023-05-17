#include "shell.h"

/**
 * push_exit - Describes the exit builtin
 */
void push_exit(void)
{
	_push("exit: exit [status]");
	_push("    Kill the current running process.\n\n");
	_push("    Kills the current running process. If \'status\' is ");
	_push("given then return status to parent process.\n\n");
	_push("    Arguments:\n");
	_push("       status   The status to exit with\n\n");
	_push("    Exit Status:\n");
	_push("    Returns failure if invalid \'status\' is given otherwise");
	_push(" returns exit status\n");
}
/**
 * push_env - Print out the description of env builtin
 */
void push_env(void)
{
	_push("env:\n");
	_push("    Prints out all environment variables. One");
	_push(" variable per line.\n\n");
	_push("    Exit Status:\n");
	_push("    Return success unless arguments are attempted to be");
	_push(" passed\n");
}
/**
 * push_setenv - describes setenv
 */
void push_setenv(void)
{
	_push("setenv: setenv [variable] [value]\n");
	_push("    Change the value of an environment variable.");
	_push(" If the environment variable does not exist create");
	_push(" a new variable with the given value.\n\n");
	_push("    Arguments:\n");
	_push("       variable   The name of the variable to change or create\n");
	_push("       value      The value to assign to the variable\n\n");
	_push("    Exit Status:\n");
	_push("    Return success unless variable can't be changed or created\n");
}

