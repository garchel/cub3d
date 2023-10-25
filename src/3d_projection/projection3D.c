#include "cub3d.h"

void	get_values_projection(t_cub3d *cub3d, t_projection *var);

void	generate3d_projection(t_cub3d *cub3d)
{
	t_projection	var;

	ft_bzero(&var, sizeof(t_projection));
	while (var.x < NUM_RAYS)
	{
		get_values_projection(cub3d, &var); //videos 4 e 5 do capitulo 5
		draw_background(cub3d, var);
		var.y = var.wall_top_pixel;
		while (var.y < var.wall_bottom_pixel)
		{
			ft_mlx_pixel_put(&cub3d->img, var.x, var.y, 0xFFA07A);
			var.y++;
		}
		var.x++;
	}
}

void	get_values_projection(t_cub3d *cub3d, t_projection *var)
{
	cub3d->dist_proj_plane = ((WIDTH / 2) / tan(FOV_ANGLE / 2));
	var->correct_wall_distance = cub3d->rays[var->x].distance
		* cos(cub3d->rays[var->x].ray_angle - cub3d->player.rotation_angle);
	var->proj_wall_height = (TILE / var->correct_wall_distance)
		* cub3d->dist_proj_plane;
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
