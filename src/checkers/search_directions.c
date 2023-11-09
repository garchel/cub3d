/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:10 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:19:24 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_position(int i, int j, t_scale scale)
{
	return (i >= 0 && i < scale.height && j >= 0 && j < scale.width);
}

int	search_zero_right(t_list_map head, int i, int j, t_scale scale)
{
	if (head.map[i][j] != '1')
	{
		if (j + 1 == scale.width || head.map[i][j + 1] == 32)
			return (0);
	}
	if (is_valid_position(i, j + 1, scale))
	{
		if (head.map[i][j + 1] == '0')
		{
			head.map[i][j + 1] = '3';
			return (process_zeros(head, i, j + 1, scale));
		}
	}
	return (1);
}

int	search_zero_down(t_list_map head, int i, int j, t_scale scale)
{
	if (head.map[i][j] != '1')
	{
		if (i + 1 == scale.height || head.map[i + 1][j] == 32)
			return (0);
	}
	if (is_valid_position(i + 1, j, scale))
	{
		if (head.map[i + 1][j] == '0')
		{
			head.map[i + 1][j] = '3';
			return (process_zeros(head, i + 1, j, scale));
		}
	}
	return (1);
}

int	search_zero_left(t_list_map head, int i, int j, t_scale scale)
{
	if (head.map[i][j] != '1')
	{
		if (j == 0 || head.map[i][j - 1] == 32)
			return (0);
	}
	if (is_valid_position(i, j - 1, scale))
	{
		if (head.map[i][j - 1] == '0')
		{
			head.map[i][j - 1] = '3';
			return (process_zeros(head, i, j - 1, scale));
		}
	}
	return (1);
}

int	search_zero_up(t_list_map head, int i, int j, t_scale scale)
{
	if (head.map[i][j] != '1')
	{
		if (i == 0 || head.map[i - 1][j] == 32)
			return (0);
	}
	if (is_valid_position(i - 1, j, scale))
	{
		if (head.map[i - 1][j] == '0')
		{
			head.map[i - 1][j] = '3';
			return (process_zeros(head, i - 1, j, scale));
		}
	}
	return (1);
}
