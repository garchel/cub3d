#include <cub3d.h>

void	ft_free_ptr(void **ptr);

void	free_mlx_all(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->s_mlx.mlx, cub3d->img.img);
	mlx_destroy_window(cub3d->s_mlx.mlx, cub3d->s_mlx.win);
	mlx_destroy_display(cub3d->s_mlx.mlx);
	ft_free_ptr(&cub3d->s_mlx.mlx);
}

int	close_win(t_cub3d *cub3d)
{
	free_mlx_all(cub3d);
	exit(0);
}

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}


