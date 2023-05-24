#include "shell.h"

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return dest;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return dest;
}

char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return NULL;

	while (str[length])
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return NULL;

	for (int i = 0; i <= length; i++)
		ret[i] = str[i];

	return ret;
}

void _puts(char *str)
{
	if (str == NULL)
		return;

	for (int i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

int _putchar(char c)
{
	static int i = 0;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buf[i++] = c;

	return 1;
}

