#include "cub3d.h"

float	normalize_angle(float angle);
void	get_ray_distance(t_cub3D *cub3D, t_aux_ray *horz, t_aux_ray *vert);
void	get_values_of_ray(t_ray *ray, t_utils_ray utils,
	t_aux_ray horz, t_aux_ray vert);
float	distance_between_points(float x1, float y1, float x2, float y2);


void	cast_ray(float ray_angle, int id, t_cub3D *cub3D)
{
	t_utils_ray	utils;
	t_aux_ray	horz;
	t_aux_ray	vert;

	ft_bzero(&utils, sizeof(t_utils_ray));
	ft_bzero(&cub3D->rays[id], sizeof(t_ray));
	ray_angle = normalize_angle(ray_angle);
	rays_facing(&utils, ray_angle);
	horz = ray_horizontal(cub3D, &utils, ray_angle);
	vert = ray_vertical(cub3D, &utils, ray_angle);
	get_ray_distance(cub3D, &horz, &vert);
	get_values_of_ray(&cub3D->rays[id], utils, horz, vert);
	cub3D->rays[id].ray_angle = ray_angle;
}


float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	get_ray_distance(t_cub3D *cub3D, t_aux_ray *horz, t_aux_ray *vert)
{
	if (horz->found_wall_hit == TRUE)
		horz->hit_distance = distance_between_points(
				cub3D->player.x, cub3D->player.y, horz->wall_hit_x,
				horz->wall_hit_y);
	else
		horz->hit_distance = INT_MAX;
	if (vert->found_wall_hit == TRUE)
		vert->hit_distance = distance_between_points(
				cub3D->player.x, cub3D->player.y, vert->wall_hit_x,
				vert->wall_hit_y);
	else
		vert->hit_distance = INT_MAX;
}

void	get_values_of_ray(t_ray *ray, t_utils_ray utils,
	t_aux_ray horz, t_aux_ray vert)
{
	if (vert.hit_distance < horz.hit_distance)
	{
		ray->distance = vert.hit_distance;
		ray->wall_hit_x = vert.wall_hit_x;
		ray->wall_hit_y = vert.wall_hit_y;
		ray->wall_hit_cotent = vert.wall_content;
		if (utils.is_ray_facing_left == TRUE)
			ray->wall_hit_cotent = WE;
		else
			ray->wall_hit_cotent = EA;
		ray->was_hit_vertical = TRUE;
	}
	else
	{
		ray->distance = horz.hit_distance;
		ray->wall_hit_x = horz.wall_hit_x;
		ray->wall_hit_y = horz.wall_hit_y;
		ray->wall_hit_cotent = horz.wall_content;
		if (utils.is_ray_facing_up == TRUE)
			ray->wall_hit_cotent = NO;
		else
			ray->wall_hit_cotent = SO;
		ray->was_hit_vertical = FALSE;
	}
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
