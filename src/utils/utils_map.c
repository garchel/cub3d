/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:02:09 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:02:11 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_lenght(t_cub3D *cub3d, float line);

int	map_has_wall_at(t_cub3D *cub3d, float x, float y)
{
	int	map_grid_indexx;
	int	map_grid_indexy;

	map_grid_indexx = floor(x / TILE);
	map_grid_indexy = floor(y / TILE);
	return (cub3d->map[map_grid_indexy][map_grid_indexx] != '0');
}

int	get_lenght(t_cub3D *cub3d, float line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE)
		> cub3d->map_info.height)
		return (0);
	else
		return ((int)ft_strlen(cub3d->map[(int)floor(line / TILE)]));
}

int	have_letters(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (1);
		++i;
	}
	return (0);
}
