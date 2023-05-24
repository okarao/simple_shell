#include "shell.h"

/**
 * handle_builtin -  Function to handle built-in commands
 * @args: input string (command)
 *
 * Return: 0 on success or 1
 */

int handle_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1);
	}
	return (0);
}
