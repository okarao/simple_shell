#include "shell.h"

/**
 **_strncpy - function to copy a string
 *@location: the location string to be copied to
 *@str: the source string
 *@num: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *location, char *str, int num)
{
	int i, j;
	char *s = location;

	i = 0;
	while (location[i] != '\0' && i < num - 1)
	{
		location[i] = str[i];
		i++;
	}

	if (i < num)
	{
		j = i;
		while (j < num)
		{
			location[j] = '\0';
			j++;
		}
	}

	return (s);
}

/**
 **_strncat - concatenates two strings
 *@location: the first string
 *@str: the second string
 *@num: maximum amount of bytes to be used
 *Return: the concatenated string
 */
char *_strncat(char *location, char *str, int num)
{
	int i, j;
	char *s = location;

	i = 0;
	j = 0;
	while (location[i] != '\0')
		i++;
	while (str[j] != '\0' && j < num)
	{
		location[i] = str[j];
		i++;
		j++;
	}

	if (j < num)
		location[i] = '\0';
	return (s);
}

/**
 **_strchr - function to locate a character in a string
 *@str: the string to be parsed
 *@c: the character to look for
 *Return: a pointer to the memory area s
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
