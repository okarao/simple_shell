#include "shell.h"

/**
 * shell_loop - main shell loop
 *
 * Return: Nothing
 */

void shell_loop(void)
{

	char *line, **args;
	int status;

	while (1)
	{
		printf("$ ");
		line = read_line();
		line[strcspn(line, "\n")] = '\0';
		args = split_line(line);

		if (args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}
		if (handle_builtin(args) == 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
				execute_command(args);
			else
			{
				if (waitpid(pid, &status, 0) == -1)
				{
					perror("waitpid");
					exit(EXIT_FAILURE);
				}
			}
		}
		free(line);
		free(args);
	}
}
