#include "shell.h"

int _strlen(char *s)
{
	int len = 0;

	if (s)
	{
		while (*s)
		{
			len++;
			s++;
		}
	}

	return len;
}

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle != *haystack)
			return NULL;

		needle++;
		haystack++;
	}

	return (char *)haystack;
}

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = *src;

	return ret;
}

