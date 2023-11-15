#include "shell.h"


/**
 * free_tok - free the tokens
 *
 * @tok: tokens
 */
void free_tok(char **tok)
{
	int i = 0;

	while (tok[i])
	{
		free(tok[i]);
		i++;
	}
}

/**
 * execute_cmd - executes Cmds
 * @tok: tokens
 * @buff: buffer
 * Return: exitt
 */
int execute_cmd(char **tok, char *buff)
{
	pid_t pid;
	char *cmd = NULL;
	int exitt = builtin_hundler(tok, buff);

	if (exitt == -1)
	{
		cmd = get_cmd(tok[0]);
		if (!cmd)
		{
			_puts("Command not found");
			return (2);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(cmd, tok, environ) == -1)
			{
				perror("execve");
				free_tok(tok);
				free(buff);
				exit(2);
			}
		}
		else
		{
			waitpid(pid, &exitt, 0);
			if (exitt != 0)
				exitt = 2;
		}
		if (_strcmp(cmd, tok[0]) != 0)
		{
			free(cmd);
		}
	}
	return (exitt);
}


/**
 * _getenv - get the environ
 *
 * @name: name of the environ
 *
 * Return: ptr
 */
char *_getenv(char *name)
{
	int i = 0;
	ssize_t len = _strlen(name);

	for (; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
	}
	return (NULL);
}

/**
 * get_cmd - function that look for cmd
 * @command: cmd
 * Return: pointer
 */
char *get_cmd(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_lenght, directory_length;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		cmd_lenght = _strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(cmd_lenght + directory_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}

	return (NULL);
}

/**
 * tokenize - parsing tokens
 *
 * @buffer: buffers
 * @tokens: token
 *
 */
void tokenize(char *buffer, char **tokens)
{
	size_t token_len;
	const char *delim = " \t\n";
	char *token = NULL;
	int count = 0;
	char *buffer_copy = NULL;

	buffer_copy = _strdup(buffer);
	token = strtok(buffer_copy, delim);
	for (count = 0; token; count++)
	{
		token_len = _strlen(token);
		tokens[count] = malloc(sizeof(char *) * token_len);
		_strncpy(tokens[count], token, token_len + 1);
		token = strtok(NULL, delim);
	}
	free(buffer_copy);
}
