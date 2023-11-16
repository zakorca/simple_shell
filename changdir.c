#include "shell.h"

/**
 * changedir_pwd - change the current directory
 *
 * @args: arguments
 */

void changedir_pwd(char **args)
{
	char **dir = NULL, *oldpwd = NULL, *home = NULL;

	if (args[1] == NULL)
	{
		home = _getenv("HOME");
		if (home == NULL)
		{
			write(STDERR_FILENO, "cd: HOME not set\n", 17);
			return;
		}
		dir = malloc(sizeof(char *) * 2);
		if (dir == NULL)
			return;
		dir[0] = home;
		dir[1] = NULL;
	}
	else if (_strncmp(args[1], "-", 1) == 0)
	{
		oldpwd = _getenv("OLDPWD");
		if (oldpwd == NULL)
		{
			write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
			return;
		}
		dir = malloc(sizeof(char *) * 2);
		if (dir == NULL)
			return;
		dir[0] = oldpwd;
		dir[1] = NULL;
	}
	else
	{
		dir = malloc(sizeof(char *) * 2);
		if (dir == NULL)
			return;
		dir[0] = args[1];
		dir[1] = NULL;
	}
	chang_dir(dir, args[0]);
	free(dir);
}


/**
 * chang_dir - changes the current working directory
 * @dir: dir to change to
 * @cmd: name of the command
 */
void chang_dir(char **dir, char *cmd)
{
	char *pwd = getcwd(NULL, 0);

	if (chdir(dir[0]) == -1)
	{
		printf(cmd, 0, dir[0], "can't cd to ");
		return;
	}
	else
	{
		free(pwd);
	}
}
