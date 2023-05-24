#include "shell.h"
/**
 * read_line - reads input line from the standard input
 *
 * Return: the line read
 */

char *read_line()
{
	char *line = NULL;
	size_t buffer_size = 0;
	ssize_t line_size = getline(&line, &buffer_size, stdin);

	if (line_size == -1)
	{
		if (feof(stdin))
		{
			/* Handle end of file condition (Ctrl+D)*/
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_line");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
