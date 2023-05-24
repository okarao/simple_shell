#include "shell.h"

/**
 * _printenv - Prints environment variables like printenv
 *
 * Return: Always 0
 */
int _printenv(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * _str_n_cmp - Lexicographically compares n characters from two strings
 * @s1: First string
 * @s2: Second string to compare with the first string
 * @n: Number of characters to compare
 *
 * Return: Negative, 0 , Positive
 */
int _str_n_cmp(char *s1, char *s2, int n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _getenv - Retrieves an environment variable
 * @var: Environment variable to retrieve
 *
 * Return: Pointer to the environment variable, or NULL if not found
 */
char *_getenv(char *var)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_str_n_cmp(environ[i], var, _strlen(var)) == 0 && environ[i][_strlen(var)] == '=')
			return (&(environ[i][_strlen(var) + 1]));
	}
	return (NULL);
}
