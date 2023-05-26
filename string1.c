#include "shell.h"
/**
 * _strcpy - copy string
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to the new string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - duplicate string
 * @str: the string pointer to be duplicated
 *
 * Return: pointer to duplicated string
 */

char *_strdup(const char *str)
{
	int length = 0, i;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		ret[i] = str[i];

	return (ret);
}
/**
 * _puts - prints a string
 * * @str: pointer to the string
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	int i;

	if (str == NULL)
		return;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
/**
 * _putchar - prints character
 * @c: the character to be printed
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}

