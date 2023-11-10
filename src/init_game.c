/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:02:19 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 17:49:19 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_cub3D *cub3D)
{
	t_data	img_p;

	ft_bzero(&img_p, sizeof(t_data));
	cub3D->s_mlx.mlx = mlx_init();
	cub3D->s_mlx.win = mlx_new_window(cub3D->s_mlx.mlx, WIDTH, HEIGHT, "cub3D");
	build_main_img(cub3D);
	if (!setup(cub3D))
		return (0);
	mlx_hook(cub3D->s_mlx.win, 17, 0, close_win, (void *)cub3D);
	mlx_hook(cub3D->s_mlx.win, 2, 1L << 0, action, (void *)cub3D);
	mlx_hook(cub3D->s_mlx.win, 3, 1L << 1, key_release, (void *)cub3D);
	mlx_loop_hook(cub3D->s_mlx.mlx, action_loop, (void *)cub3D);
	mlx_loop(cub3D->s_mlx.mlx);
	return (1);
}
