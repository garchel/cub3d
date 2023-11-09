/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:17 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:00:19 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_celling(t_cub3D *cub3D, t_projection var);
void	draw_floor(t_cub3D *cub3D, t_projection var);

void	draw_background(t_cub3D *cub3D, t_projection var)
{
	draw_celling(cub3D, var);
	draw_floor(cub3D, var);
}

void	draw_celling(t_cub3D *cub3D, t_projection var)
{
	var.y = 0;
	while (var.y < HEIGHT / 2)
		ft_mlx_pixel_put(&cub3D->img, var.x, var.y++, cub3D->collors.cell);
}

void	draw_floor(t_cub3D *cub3D, t_projection var)
{
	var.y = HEIGHT / 2;
	while (var.y < HEIGHT)
		ft_mlx_pixel_put(&cub3D->img, var.x, var.y++, cub3D->collors.floor);
}
