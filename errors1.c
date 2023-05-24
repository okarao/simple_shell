#include "shell.h"

/**
 * _erratoi - Converts a string to an integer
 * @s: The string to be converted
 * Return: Converted number if successful, -1 on error
 */
int _erratoi(char *s)
{
	int result = 0;

	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);
		result = (result * 10) + (*s - '0');
		s++;
	}

	return (result);
}

/**
 * print_error - Prints an error message
 * @info: Parameter and return info struct
 * @estr: String containing specified error type
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - Prints a decimal (integer) number (base 10)
 * @input: The input number
 * @fd: The file descriptor to write to
 * Return: Number of characters printed
 */
int print_d(int input, int fd)
{
	int count = 0;
	int abs = (input < 0) ? -input : input;
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;

	if (input < 0)
	{
		__putchar('-');
		count++;
	}

	if (abs >= 10)
		count += print_d(abs / 10, fd);

	__putchar('0' + (abs % 10));
	count++;

	return (count);
}

/**
 * convert_number - Converts a number to a string
 * @num: The number to convert
 * @base: The base to convert to
 * @flags: Argument flags
 * Return: The converted string
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	char *ptr = &buffer[49];
	char *array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	unsigned long n = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? -num : num;

	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (num < 0 && !(flags & CONVERT_UNSIGNED))
		*--ptr = '-';

	return (ptr);
}

/**
 * remove_comments - Replaces the first instance of '#' with '\0'
 * @buf: The string to modify
 */
void remove_comments(char *buf)
{
	while (*buf)
	{
		if (*buf == '#' && (buf == buf || *(buf - 1) == ' '))
		{
			*buf = '\0';
			break;
		}
		buf++;
	}
}

