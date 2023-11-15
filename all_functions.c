#include "shell.h"


/**
 * free_avv - free the tokens
 *
 * @avv: tokens
 */
void free_avv(char **avv)
{
	int i = 0;

	while (avv[i])
	{
		free(avv[i]);
		i++;
	}
}


/**
 * execute_cmd - executes Commands
 * @avv: tokens
 * @buf: buffer
 * Return: exitt
 */
int execute_cmd(char **avv, char *buf)
{
	pid_t pid;
	char *cmd = NULL;
	int exitt = handle_builtin_(avv, buf);

	if (exitt == -1)
	{
		cmd = get_cmd(avv[0]);
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
			if (execve(cmd, avv, envir) == -1)
			{
				perror("execve");
				free_avv(avv);
				free(buf);
				exit(2);
			}
		}
		else
		{
			waitpid(pid, &exitt, 0);
			if (exitt != 0)
			{
				exitt = 2;
			}
		}
		if (_strcmp(cmd, avv[0]) != 0)
			free(cmd);
	}
	return (exitt);
}


/**
 * _getenv - get envirment
 * @name: name of envirement
 *
 * Return: ptr
 */
char *_getenv(char *name)
{
	int i = 0;
	ssize_t len = _strlen(name);

	for (; envir[i]; i++)
	{
		if (strncmp(envir[i], name, len) == 0 && envir[i][len] == '=')
		{
			return (&envir[i][len + 1]);
		}
	}
	return (NULL);
}


/**
 * get_cmd - func that looks for commd
 * @command: commandd
 *
 * Return: ptr
 */
char *get_cmd(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
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
 * tokenize - parsing
 * @buffer: buffer
 * @tokens: tokens
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
