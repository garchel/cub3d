#include "maps.h"

t_list_map *create_list()
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

void add_on_tail(t_list_map *list, char *line)
{
    t_node_map *node;

    node =  create_node(line);
    if(list->begin == NULL)
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


