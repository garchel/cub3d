/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:54 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 17:35:54 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_chars(t_list_map head, t_scale scale);

int	create_map(t_list_map *list, int n_lines, t_file_info *file_info)
{
	t_scale		scale;
	t_node_map	*init;

	init = list->begin;
	list->map = linked_to_int(list, n_lines - 6);
	list->begin = init;
	scale = get_scale(list->map);
	if ((check_map_chars(*list, scale) != 1) || \
		(check_walls(*list, scale) != 1))
	{
		free_tex(file_info);
		error_message(PARSE_MAP);
		return (0);
	}
	normalize_matrix(list->map);
	list->map[scale.height - 1][scale.width - 1] = '1';
	return (1);
}

void	normalize_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '3' || matrix[i][j] == '4')
				matrix[i][j] = '0';
			if (matrix[i][j] == -1)
			{
				matrix[i][j] = '\0';
			}
			++j;
		}
		++i;
	}
}

int	check_map_chars(t_list_map head, t_scale scale)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (++i <= scale.height - 1 && head.map[i] != NULL)
	{
		j = 0;
		while (j <= scale.width - 2 && head.map[i][j] != -1)
		{
			if (is_map_position(head.map[i][j]))
				j++;
			else if (is_player_position(head.map[i][j]))
			{
				found++;
				j++;
			}
			else
				found = -1;
		}
	}
	if (found == 1)
		return (1);
	return (0);
}

t_pos	return_pos(int **matrix, t_pos pos)
{
	pos.status = 0;
	if (matrix[pos.y][pos.x - 1] == 0)
	{
		--pos.x;
		return (pos);
	}
	else if (matrix[pos.y + 1][pos.x] == 0)
	{
		++pos.y;
		return (pos);
	}
	else if (matrix[pos.y - 1][pos.x] == 0)
	{
		--pos.y;
		return (pos);
	}
	pos.status = 1;
	return (pos);
}

t_pos	first_empty_block(int **matrix, int size)
{
	t_pos	final_pos;
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	while (pos.y < size)
	{
		pos.x = 0;
		while (matrix[pos.y][pos.x] != -1)
		{
			if (matrix[pos.y][pos.x] == 3)
			{
				final_pos = return_pos(matrix, pos);
				if (matrix[final_pos.y][final_pos.x + 1] == -1)
					error_message(FAIL_WALL);
				if (final_pos.status == 0)
					return (final_pos);
			}
			++pos.x;
		}
		++pos.y;
	}
	pos.y = 0;
	pos.x = 0;
	return (pos);
}
