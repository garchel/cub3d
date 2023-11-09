/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:45 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:00:47 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_adjacent_zero(t_list_map head, int i, int j, t_scale scale);
int	process_zeros(t_list_map head, int i, int j, t_scale scale);

int	check_walls(t_list_map head, t_scale scale)
{
	int	i;
	int	j;

	i = 0;
	while (head.map[i] != NULL)
	{
		j = 0;
		while (head.map[i][j] != -1)
		{
			if ((head.map[i][j] == '1') && \
				find_adjacent_zero(head, i, j, scale) != 0)
			{
				return (process_zeros(head, i, j, scale));
			}
			++j;
		}
		++i;
	}
	return (1);
}

int	process_zeros(t_list_map head, int i, int j, t_scale scale)
{
	if (!search_zero_right(head, i, j, scale))
		return (0);
	else if (!search_zero_down(head, i, j, scale))
		return (0);
	else if (!search_zero_left(head, i, j, scale))
		return (0);
	else if (!search_zero_up(head, i, j, scale))
		return (0);
	else
		return (1);
}

int	find_adjacent_zero(t_list_map head, int i, int j, t_scale scale)
{
	if (j + 1 < scale.width && head.map[i][j + 1] == '0')
		return (1);
	else if (i + 1 < scale.height && head.map[i + 1][j] == '0')
		return (1);
	else if (j - 1 > 0 && head.map[i][j - 1] == '0')
		return (1);
	else if (i - 1 > 0 && head.map[i - 1][j] == '0')
		return (1);
	else
		return (0);
}
