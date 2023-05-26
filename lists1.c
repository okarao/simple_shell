#include "shell.h"

/**
 * list_len - Determines the length of a linked list
 * @h: Pointer to the first node
 *
 * Return: Size of the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * list_to_strings - Converts a linked list to an array of strings
 * @head: Pointer to the first node
 *
 * Return: Array of strings
 */
char **list_to_strings(list_t *head)
{
	size_t len = list_len(head);
	char **strs;
	char *str;
	size_t i = 0;
	list_t *node;

	if (!head || len == 0)
		return (NULL);

	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);

	node = head;
	while (node)
	{
		str = _strdup(node->str);
		if (!str)
		{
			for (i = 0; i < len; i++)
				free(strs[i]);
			free(strs);
			return (NULL);
		}
		strs[i] = str;
		node = node->next;
		i++;
	}
	strs[i] = NULL;

	return (strs);
}

/**
 * print_list - Prints all elements of a list_t linked list
 * @h: Pointer to the first node
 *
 * Return: Size of the list
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * node_starts_with - Returns a node whose string starts with the prefix
 * @node: Pointer to the list head
 * @prefix: String to match
 * @c: The next character after the prefix to match
 *
 * Return: Matching node or NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && (c == -1 || *p == c))
			return (node);
		node = node->next;
	}

	return (NULL);
}

/**
 * get_node_index - Gets the index of a node
 * @head: Pointer to the list head
 * @node: Pointer to the node
 *
 * Return: Index of the node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (index);
		head = head->next;
		index++;
	}

	return (-1);
}
