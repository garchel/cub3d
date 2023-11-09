/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_projection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:31 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:00:32 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_values_projection(t_cub3D *cub3D, t_projection *var)
{
	cub3D->dist_proj_plane = ((WIDTH / 2) / tan(FOV_ANGLE / 2));
	var->correct_wall_distance = cub3D->rays[var->x].distance
		* cos(cub3D->rays[var->x].ray_angle - cub3D->player.rotation_angle);
	var->proj_wall_height = (TILE / var->correct_wall_distance)
		* cub3D->dist_proj_plane;
	var->wall_strip_height = (int)var->proj_wall_height;
	var->wall_top_pixel = (HEIGHT / 2) - (var->wall_strip_height / 2);
	if (var->wall_top_pixel < 0)
		var->wall_top_pixel = 0;
	if (var->wall_top_pixel >= HEIGHT)
		var->wall_top_pixel = HEIGHT;
	var->wall_bottom_pixel = (HEIGHT / 2) + (var->wall_strip_height / 2);
	if (var->wall_bottom_pixel >= HEIGHT)
		var->wall_bottom_pixel = HEIGHT;
	if (var->wall_bottom_pixel < 0)
		var->wall_bottom_pixel = 0;
}
