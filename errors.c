i#include "shell.h"

/**
 *_customputs - prints an input string
 *@x: the string to be printed
 *
 *Return: Nothing
 */
void _customputs(char *x)
{
	int i = 0;

	if (!x)
		return;
	while (x[i] != '\0')
	{
		_customputchar(x[i]);
		i++;
	}
}

/**
 *_customputchar - writes the character c to stderr
 *@x: The character to print
 *
 *Return: On success 1.
 *On error, -1 is returned, and errno is set appropriately.
 */
int _customputchar(char x)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}

	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 *_putfd - writes the character c to given fd
 *@x: The character to print
 *@fd: The filedescriptor to write to
 *
 *Return: On success 1.
 *On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char x, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (x == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}

	if (x != BUF_FLUSH)
		buf[i++] = x;
	return (1);
}

/**
 *_putsfd - prints an input string
 *@text: the string to be printed
 *@fd: the filedescriptor to write to
 *
 *Return: the number of chars put
 */
int _putsfd(char *text, int fd)
{
	int i = 0;

	if (!text)
		return (0);
	while (*text)
	{
		i += _putfd(*text++, fd);
	}

	return (i);
}
