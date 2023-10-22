#include "cub3d.h"

void	draw_gaming(t_cub3d *cub3d)
{
	generate3d_projection(cub3d); //3d_projection
	mlx_put_image_to_window(cub3d->s_mlx.mlx, cub3d->s_mlx.win, cub3d->img.img, 0, 0); //mlx
	mlx_destroy_image(cub3d->s_mlx.mlx, cub3d->img.img); //mlx
	build_main_img(cub3d); //mlx
}
