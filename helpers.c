#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the resulting string
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr)
		ptr++;

	while (*src)
		*ptr++ = *src++;

	*ptr = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are equal, positive if s1 > s2, negative if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the resulting string
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src)
		*ptr++ = *src++;

	*ptr = '\0';

	return (dest);
}

/**
 * _strlen - calculates the length of a string
 * @s: input string
 * Return: length of the string
 */
size_t _strlen(const char *s)
{
	size_t length = 0;

	while (*s++)
		length++;

	return (length);
}

/**
 * _strdup - duplicates a string
 * @str: input string
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	size_t length = _strlen(str) + 1;
	char *dup = malloc(length);

	if (dup)
		_strcpy(dup, str);

	return (dup);
}

