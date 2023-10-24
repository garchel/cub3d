#include "cub3d.h"

void	get_ray_distance(t_cub3d *cub3d, t_aux_ray *horz, t_aux_ray *vert)
{
	if (horz->found_wall_hit == TRUE)
		horz->hit_distance = distance_between_points(
				cub3d->player.x, cub3d->player.y, horz->wall_hit_x,
				horz->wall_hit_y);
	else
		horz->hit_distance = 2147483648;
	if (vert->found_wall_hit == TRUE)
		vert->hit_distance = distance_between_points(
				cub3d->player.x, cub3d->player.y, vert->wall_hit_x,
				vert->wall_hit_y);
	else
		vert->hit_distance = 2147483648;
}

void	get_values_of_ray(t_ray *ray, t_utils_ray utils,
	t_aux_ray horz, t_aux_ray vert)
{
	if (vert.hit_distance < horz.hit_distance)
	{
		ray->distance = vert.hit_distance;
		ray->wall_hit_x = vert.wall_hit_x;
		ray->wall_hit_y = vert.wall_hit_y;
	}
	else
	{
		ray->distance = horz.hit_distance;
		ray->wall_hit_x = horz.wall_hit_x;
		ray->wall_hit_y = horz.wall_hit_y;
	}
	if (utils.is_ray_facing_up == TRUE) //apagar
			ray->wall_hit_cotent = NO;
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI); //2*PI equevalem a 360ª
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

