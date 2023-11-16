#include "shell.h"
/**
 * strconst_len - counts the number of characters in a constant string
 * @str: constant string
 * Return: number of characters in the string
 */

int strconst_len(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * error_printer - prints an error message
 * @argv: name of the progrm
 * @count: numb of cmds entered
 * @cmd: cmd entered
 * @msg: error message
 */

void error_printer(char *argv, int count, char *cmd, char *msg)
{
	char *count_str = NULL;

	write(STDERR_FILENO, argv, strconst_len(argv));
	write(STDERR_FILENO, ": ", 2);
	count_str = _intstr(count);
	write(STDERR_FILENO, count_str, strconst_len(count_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, strconst_len(msg));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strconst_len(cmd));
	write(STDERR_FILENO, "\n", 1);
	free(count_str);
}
