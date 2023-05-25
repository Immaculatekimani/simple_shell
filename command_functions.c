#include "shell.h"

/**
 * create_arg - make a vector of commands
 *
 * @input: the input from the user
 *
 * Return: command vector
 */
char **create_arg(char *input)
{
	char **commands, *command, *position, *delims;
	int i, wc;

	position = NULL;
	delims = "\n\t \r\a";
	i = 0;
	wc = wordcount(input);
	commands = mem_alloc(sizeof(char *) * (wc + 1));
	command = tokenize(input, delims, &position);
	while (command != NULL)
	{
		commands[i] = command;
		if (commands[i][0] == '#')
			break;
		command = tokenize(NULL, delims, &position);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
/**
 * wordcount - count the number of words in a string
 *
 * @st: string
 *
 * Return: number of words in @st
 */
int wordcount(char *st)
{
	int wc, state, i;

	i = wc = 0;
	state = OUT;
	while (st[i] != '\0')
	{
		switch (st[i])
		{
		case '\0':
		case ' ':
		case '\t':
		case '\n':
			if (state == IN)
			{
				state = OUT;
				wc++;
			}
			i++;
			break;
		default:
			state = IN;
			i++;
		}
	}
	return (wc);
}
/**
 * is_arg - Compare the original first argument to
 * a possible new first argument
 *
 * @first_com: The original first argument
 * @arg0: The argument that may have changed
 *
 * Return: 0 if they're the same, 1 if they are different
 */
int is_arg(char *first_com, char *arg0)
{
	if (_strcmp(first_com, arg0) == 0)
		return (0);
	return (1);
}
/**
 * tokenize - create a token from @input
 *
 * @input: string to tokenize
 * @delim: delimitor string
 * @saveptr: save pointer
 *
 * Return: the next token found in @input string
 */
char *tokenize(char *input, const char *delim, char **saveptr)
{
	char *token;
	int i;

	i = 0;
	if (input == NULL)
		input = *saveptr;
	input += _strspn(input, delim);
	if (*input == '\0')
	{
		*saveptr = input;
		return (NULL);
	}
	token = input;
	input = _strpbrk(input, delim);
	if (input == NULL)
	{
		while (token[i] != '\0')
			i++;
		*saveptr = token + i;
	}
	else
	{
		*input = '\0';
		*saveptr = input + 1;
	}
	return (token);
}

