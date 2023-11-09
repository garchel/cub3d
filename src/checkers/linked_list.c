/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:03 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 02:27:44 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list_map	*create_list(void)
{
	t_list_map	*list;

	list = ft_calloc(2, sizeof(t_list_map));
	list->begin = NULL;
	list->end = NULL;
	return (list);
}

t_node_map	*create_node(char *line)
{
	t_node_map	*node;

	node = ft_calloc(2, sizeof(t_node_map));
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
	char		**map;
	int			i;
	int			j;
	t_node_map	*init;

	init = head->begin;
	map = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	while (head->begin)
	{
		map[i] = ft_calloc(strlen(head->begin->line) + 2, sizeof(char));
		j = 0;
		while (j < head->begin->size)
		{
			if (head->begin->line[j] == ' ')
				head->begin->line[j] = '4';
			map[i][j] = (head->begin->line[j]);
			++j;
		}
		map[i][--j] = -1;
		head->begin = head->begin->next;
		++i;
	}
	head->begin = init;
	return (map);
}

void	destroy_list(t_list_map **List)
{
	t_list_map	*l;
	t_node_map	*p;
	t_node_map	*aux;

	l = *List;
	p = l->begin;
	aux = NULL;
	while (p != NULL)
	{
		aux = p;
		p = p->next;
		free(aux->line);
		free(aux);
	}
	free(l);
	List = NULL;
}
