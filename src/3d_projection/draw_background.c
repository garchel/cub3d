#include "cub3d.h"

void	draw_celling(t_cub3d *cub3d, t_projection var);
void	draw_floor(t_cub3d *cub3d, t_projection var);

void	draw_background(t_cub3d *cub3d, t_projection var)
{
	draw_celling(cub3d, var);
	draw_floor(cub3d, var);
}

void	draw_celling(t_cub3d *cub3d, t_projection var)
{
	var.y = 0;
	while (var.y < HEIGHT / 2)
		ft_mlx_pixel_put(&cub3d->img, var.x, var.y++, cub3d->collors.cell);
}

void	draw_floor(t_cub3d *cub3d, t_projection var)
{
	var.y = HEIGHT / 2;
	while (var.y < HEIGHT)
		ft_mlx_pixel_put(&cub3d->img, var.x, var.y++, cub3d->collors.floor);
}
