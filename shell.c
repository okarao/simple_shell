#include "shell.h"
/**
 * main - entry point
 *
 * Return: 0 always success
 */

int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		buffer[strcspn(buffer, "\n")] = '\0';

		if (fork() == 0)
		{
			execlp(buffer, buffer, NULL);
			fprintf(stderr, "%s: command not found\n", buffer);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
