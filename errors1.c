#include "shell.h"

/**
 *_erroratoi - converts a string to an integer
 *@text: string to be converted
 *Return: 0 if no string converted otherwise -1
 */
int _erroratoi(char *text)
{
	int i = 0;
	unsigned long int result = 0;

	if (*text == '+')
		text++;
	for (i = 0; text[i] != '\0'; i++)
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			result *= 10;
			result += (text[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}

	return (result);
}

/**
 *print_error - function to print an error message
 *@info: the parameter &return info struct
 *@errorstr: string containing specified error type
 *Return: 0 if no numbers in string, converted number otherwise
 *      -1 on error
 */
void print_error(info_t *info, char *errorstr)
{
	_customputs(info->fname);
	_customputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_customputs(": ");
	_customputs(info->argv[0]);
	_customputs(": ");
	_customputs(estr);
}

/**
 *print_d - function to print decimal
 *@input: the input
 *@fd: the filedescriptor to write to
 *
 *Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}

		current %= i;
	}

	__putchar('0' + current);
	count++;

	return (count);
}

/**
 *convert_number - converter function,mimics itoa
 *@n: number
 *@base: base
 *@flags: argument flags
 *
 *Return: string
 */
char *convert_number(long int n, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long nm = n;

	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		nm = -n;
		sign = '-';
	}

	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[nm % base];
		nm /= base;
	} while (nm != 0);

	if (sign)
		*
		--ptr = sign;
	return (ptr);
}

/**
 *remove_comments - replaces first instance of '#' with '\0'
 *@buff: address of the string to modify
 *
 *Return: Always 0;
 */
void remove_comments(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
}
