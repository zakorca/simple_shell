#include "shell.h"


/**
 * builtin_hundler - handle builtin comds
 *
 * @tokens: tokens
 * @buffer: buffer
 *
 * Return: int
 */
int builtin_hundler(char **tokens, char *buffer)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		return (exit_function(tokens, buffer));
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		return (envir_function());
	}
	else
	{
		return (-1);
	}
}


/**
 * envir_function - get the env
 *
 * Return: Always 0
 */
int envir_function(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
	}

	return (0);
}


/**
 * exit_function - does the exiting
 * @tokens: tokens
 * @buffer: buffer
 * Return: int
 */
int exit_function(char **tokens, char *buffer)
{
	int i = 0;
	int existatus = 0;

	while (tokens[i])
		i++;
	if (i == 1)
	{
		free_tok(tokens);
		free(buffer);
		exit(0);
	}
	if (_atoi(tokens[1]) == -1)
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", tokens[1]);
		return (2);
	}
	existatus = atoi(tokens[1]);
	free_tok(tokens);
	free(buffer);
	exit(existatus);
}


/**
 * _atoi - converts str to an int
 * @conv_ptr: str to be converted
 * Return: converted int value or -1
 */
int _atoi(char *conv_ptr)
{
	int i = 0, n = 0;

	if (conv_ptr[i] == '+')
	{
		i++;
	}
	while (conv_ptr[i])
	{
		if (conv_ptr[i] < '0' || conv_ptr[i] > '9')
		{
			return (-1);
		}
		n = (n * 10) + (conv_ptr[i] - '0');
		i++;
	}
	return (n);
}
