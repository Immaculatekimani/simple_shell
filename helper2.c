#include "shell.h"

/**
 * push_unsetenv - describes unsetenv
 */
void push_unsetenv(void)
{
	_push("unsetenv: unsetenv [variable]\n");
	_push("    Remove a variable from the environment.\n\n");
	_push("    Arguments:\n");
	_push("       variable   The name of the variable to remove.\n\n");
	_push("    Exit status:\n");
	_push("    Return success unless cannot remove variable or variable");
	_push(" does not exist.\n");
}
/**
 * push_help - describes the help builtin
 */
void push_help(void)
{
	_push("Help: help [name ...]\n");
	_push("    Display info about builtins\n\n");
	_push("    Gives brief descriptions of builtins.");
	_push(" If \'name\' is specified gives more details about all");
	_push(" commands matching \'name\'\n\n");
	_push("    Arguments:\n");
	_push("       name    The name of builtin to get help with\n\n");
	_push("    Exit status:\n");
	_push("    Returns success unless invalide \'name\' is given.\n");
}
/**
 * display_help - describes basic information
 */
void display_help(void)
{
	_push("These commands are defined internally.");
	_push(" Type \'help\' to see this list.\n");
	_push("Type \'help name\' to find out more about");
	_push(" function \'name\'\n");
	_push("   exit [status]\n");
	_push("   env\n");
	_push("   setenv [variable] [value]\n");
	_push("   unsetenv [variable]\n");
	_push("   help [name ...]\n");
}
