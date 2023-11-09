/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:29 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:01:30 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_wall_at(t_cub3D *cub3D, float x, float y);
int	get_lenght(t_cub3D *cub3D, float line);

void	move_player(t_cub3D *cub3D)
{
	float	move_step;
	float	side_step;
	float	new_p_x;
	float	new_p_y;

	cub3D->player.rotation_angle += cub3D->player.turn_direction
		* cub3D->player.turn_speed;
	side_step = cub3D->player.side_direction * cub3D->player.walk_speed;
	move_step = cub3D->player.walk_direction * cub3D->player.walk_speed;
	if (move_step && side_step)
	{
		move_step /= 2;
		side_step /= 2;
	}
	new_p_x = cub3D->player.x + cos(cub3D->player.rotation_angle) * move_step;
	new_p_y = cub3D->player.y + sin(cub3D->player.rotation_angle) * move_step;
	new_p_x = new_p_x - sin(-cub3D->player.rotation_angle) * side_step;
	new_p_y = new_p_y - cos(-cub3D->player.rotation_angle) * side_step;
	if (!map_has_wall_at(cub3D, new_p_x, new_p_y))
	{
		cub3D->player.x = new_p_x;
		cub3D->player.y = new_p_y;
	}
}
