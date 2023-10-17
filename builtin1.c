#include "shell.h"

/**
 * _myhistory - shows the history list, one command
 * by line
 * @info: containing potential arguments for constant
 * function prototype.
 * Return: 0 always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: the parameter structure
 * @str: the string
 *
 * Return: return 1 if success and 0 if failure
 */
int unset_alias(info_t *info, char *str)
{
	char *m, c;
	int len;

	m = _strchr(str, '=');
	if (!m)
		return (1);
	c = *m;
	*m = 0;
	len = delete_node_at_index(&(info->alias),
	    get_node_index(info->alias,
node_starts_with(info->alias, str, -1)));
	*m = c;
	return (len);
}

/**
 * set_alias - sets alias to string
 * @info: parameter structure
 * @str: string
 *
 * Return: 0 on success and 1 failure
 */
int set_alias(info_t *info, char *str)
{
	char *m;

	m = _strchr(str, '=');
	if (!m)
		return (1);
	if (!*++m)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints alias
 * @node: alias node
 *
 * Return: On success 0, 1 on failure
 */
int print_alias(list_t *node)
{
	char *m = NULL, *a = NULL;

	if (node)
	{
		m = _strchr(node->str, '=');
		for (a = node->str; a <= m; a++)
			_putchar(*a);
			_putchar('\");
			_puts(m + 1);
			_puts('''\n");
			return (0);
	}
	return (1);
}

/**
 * _myalias -mimics the alias builtin
 * @info: contains potential arguments.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *m = NULL;
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
	for (j = 1; info->argv[j]; j++)
	{
		m = _strchr(info->argv[j], '=');
		if (m)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info-alias,
			info->argv[j], '='));
	}
	return (0);
}
