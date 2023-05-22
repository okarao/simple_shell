#include "shell.h"

/**
 *_customhistory - displays the history list, one command by line, preceded
 *            with line numbers, starting at 0.
 *@info: Structure containing potential arguments. Used to maintain
 *constant function prototype.
 *Return: Always 0
 */
int _customhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 *unset_alias - sets alias to string
 *@info: parameter struct
 *@al: the string alias
 *
 *Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *al)
{
	char *i, j;
	int output;

	i = _strchr(al, '=');
	if (!i)
		return (1);
	j = *i;
	*i = 0;
	output = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, al, -1)));
	*i = j;
	return (output);
}

/**
 *set_alias - sets alias to string
 *@info: parameter struct
 *@al: the string alias
 *
 *Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *al)
{
	char *i;

	i = _strchr(al, '=');
	if (!i)
		return (1);
	if (!*++i)
		return (unset_alias(info, al));

	unset_alias(info, al);
	return (add_node_end(&(info->alias), al, 0) == NULL);
}

/**
 *print_alias - prints an alias string
 *@node: the alias node
 *
 *Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *i = NULL, *j = NULL;

	if (node)
	{
		i = _strchr(node->str, '=');
		for (j = node->str; j <= i; j++)
			_putchar(*j);
		_putchar('\'');
		_puts(i + 1);
		_puts("'\n");
		return (0);
	}

	return (1);
}

/**
 *_customalias - emulates the alias builtin (man alias)
 *@info: Structure containing arguments.
 *Return: Always 0
 */
int _customalias(info_t *info)
{
	int i = 0;
	char *j = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}

		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		j = _strchr(info->argv[i], '=');
		if (j)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
