
#include "cub3d.h"

t_list_map	*create_list(void)
{
	t_list_map	*list;

	list = malloc(1 * sizeof(list));
	list->begin = NULL;
	list->end = NULL;
	return (list);
}

t_node_map	*create_node(char *line)
{
	t_node_map	*node;

	node = malloc(1 * sizeof(node));
	node->line = line;
	node->size = ft_strlen(line);
	node->next = NULL;
	return (node);
}

void	add_on_tail(t_list_map *list, char *line)
{
	t_node_map	*node;

	node = create_node(line);
	if (list->begin == NULL)
	{
		list->begin = node;
		list->end = node;
	}
	else
	{
		list->end->next = node;
		list->end = list->end->next;
	}
}

char	**linked_to_int(t_list_map *head, int size)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(int *) * size + 1);
	i = 0;
	while (head->begin)
	{
		if (size == i)
			head->begin->size++;
		map[i] = malloc(sizeof(int) * (head->begin->size));
		j = 0;
		while (j < head->begin->size)
		{
			if (head->begin->line[j] == ' ')
				head->begin->line[j] = '0';
			map[i][j] = (head->begin->line[j]);
			++j;
		}
		map[i][--j] = -1;
		head->begin = head->begin->next;
		++i;
	}
	map[size + 1] = NULL;
	return (map);
}