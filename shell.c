#include "shell.h"

/**
 * print_not_found - prints an error message for a command not found
 * @cmd: command name
 */
void print_not_found(char *cmd)
{
	fprintf(stderr, "%s: command not found: %s\n", shell_name, cmd);
}

/**
 * execute_command - executes the given command
 * @cmd: command to execute
 * @args: arguments for the command
 * Return: 0 on success, 1 if command not found, -1 on error
 */
int execute_command(char *cmd, char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		execvp(cmd, args);
		perror("execvp");
		exit(1);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}

/**
 * main - entry point of the shell program
 * @argc: argument count
 * @argv: array of argument strings
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *line = NULL, *token, *args[100];
	size_t buffer_size = 0;
	ssize_t line_length;
	int result, arg_count;

	shell_name = argv[0];
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		line_length = getline(&line, &buffer_size, stdin);
		if (line_length == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		if (line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';
		if (line[0] == '\0')
			continue;
		if (strcmp(line, "exit") == 0)
			break;
		arg_count = 0;

		token = strtok(line, " ");
		while (token)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		result = execute_command(args[0], args);

		if (result == 1)
			print_not_found(args[0]);
	}
	free(line);
	return (0);
}
