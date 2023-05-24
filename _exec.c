#include "shell.h"
/**
 * execute_command - execute commands
 * @args: the input command
 *
 *Return: Nothing on success or -1 on error
 */

void execute_command(char **args)
{
	if (execvp(args[0], args) == -1)
	{
		perror("execute_command");
		exit(EXIT_FAILURE);
	}
}
