#include "cub3d.h"

void	check_inverse_offset_x(t_ray ray, int *texture_offset_x);

void	get_texture_offset(t_cub3D *cub3D, t_projection *var)
{
	if (cub3D->rays[var->x].was_hit_vertical == TRUE)
		var->texture_offset_x = (int)cub3D->rays[var->x].wall_hit_y % TILE;
	else
		var->texture_offset_x = (int)cub3D->rays[var->x].wall_hit_x % TILE;
	check_inverse_offset_x(cub3D->rays[var->x], &var->texture_offset_x);
	var->tex_num = cub3D->rays[var->x].wall_hit_cotent;
}

void	check_inverse_offset_x(t_ray ray, int *texture_offset_x)
{
	if (ray.was_hit_vertical == FALSE
		&& is_ray_facing_down(ray.ray_angle) == TRUE)
		*texture_offset_x = TILE - *texture_offset_x;
	if (ray.was_hit_vertical == TRUE
		&& is_ray_facing_left(ray.ray_angle) == TRUE)
		*texture_offset_x = TILE - *texture_offset_x;
}
