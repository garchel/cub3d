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

void	free_struct(t_cub3D *cub3D)
{
	ft_free_triple(cub3D->texture_path);
	ft_free_triple(cub3D->colors);
	ft_free_split(cub3D->content_map);
}


