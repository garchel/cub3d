
#include "cub3d.h"

// Cria uma lista encadeada
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

// Adiciona um nó na lista encadeada
void	add_on_tail(t_list_map *list, char *line)
{
	t_node_map	*node;

	// Cria o nó
	node = create_node(line);
	// Se a lista estiver vazia, o nó será o primeiro e o último
	if (list->begin == NULL)
	{
		list->begin = node;
		list->end = node;
	}
	// Se não, o nó será adicionado no final da lista
	else
	{
		list->end->next = node;
		list->end = list->end->next;
	}
}
