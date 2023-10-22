#include "cub3d.h"

t_list_map *create_list()  // Cria uma lista encadeada
{
    t_list_map *list;

    list = malloc(1 * sizeof(list));
    list->begin = NULL;
    list->end = NULL;

    return (list);
}

t_node_map * create_node(char *line)
{
    t_node_map *node;

    node = malloc(1 * sizeof(node));
    node->line = line;
    node->size = ft_strlen(line);
    node->next = NULL;

    return node;
}

void add_on_tail(t_list_map *list, char *line)  // Adiciona um nó na lista encadeada
{
    t_node_map *node;

    node =  create_node(line);  // Cria o nó
    if(list->begin == NULL)  // Se a lista estiver vazia, o nó será o primeiro e o último
    {
        list->begin = node;
        list->end = node;
    }
    else // Se não, o nó será adicionado no final da lista
    {
        list->end->next = node;
        list->end = list->end->next;
    }
}