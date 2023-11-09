/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:02:02 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:02:03 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_images(t_cub3D *cub3D)
{
	mlx_destroy_image(cub3D->s_mlx.mlx, cub3D->sprites.no.img);
	mlx_destroy_image(cub3D->s_mlx.mlx, cub3D->sprites.so.img);
	mlx_destroy_image(cub3D->s_mlx.mlx, cub3D->sprites.we.img);
	mlx_destroy_image(cub3D->s_mlx.mlx, cub3D->sprites.ea.img);
}

void	free_mlx_all(t_cub3D *cub3D)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
		free(cub3D->textures[i++]);
	mlx_destroy_image(cub3D->s_mlx.mlx, cub3D->img.img);
	mlx_destroy_window(cub3D->s_mlx.mlx, cub3D->s_mlx.win);
	mlx_destroy_display(cub3D->s_mlx.mlx);
	ft_free_ptr(&cub3D->s_mlx.mlx);
}

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
