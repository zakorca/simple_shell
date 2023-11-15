#include "shell.h"


/**
 * handle_builtin_ - handle built-in cmds
 *
 *@tokens: tokens
 *@buffer: buffer
 *
 * Return: int
 */
int handle_builtin_(char **tokens, char *buffer)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		return (exit_func(tokens, buffer));
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		return (env_func());
	}
	else
	{
		return (-1);
	}
}

/**
 * env_func - get the env
 *
 * Return: Always 0
 */
 
int env_func(void)
{
	int i;

	for (i = 0; envir[i]; i++)
		_puts(envir[i]);

	return (0);
}
