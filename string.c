#include "shell.h"

/**
 * _strlen - determine the length of a string
 * @s: the input string
 *
 * Return: string length
 */
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

	return (len);
}

/**
 * _strcmp - compare strings
 * @s1: first string
 * @s2: second string
 *
 * Return: numer of different characters
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
/**
 * starts_with - finds a substring from main string
 * @haystack: the main string
 * @needle: the sub string
 *
 * Return: pointer to the first occurance of the substring
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle != *haystack)
			return (NULL);

		needle++;
		haystack++;
	}

	return ((char *)haystack);
}

/**
 * _strcat - continate strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to the new string
 */

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

	return (ret);
}

