/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:21 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:00:22 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_gaming(t_cub3D *cub3D)
{
	generate3d_projection(cub3D);
	mlx_put_image_to_window(cub3D->s_mlx.mlx, cub3D->s_mlx.win, \
		cub3D->img.img, 0, 0);
	mlx_destroy_image(cub3D->s_mlx.mlx, cub3D->img.img);
	build_main_img(cub3D);
}
