#include "cub3d.h"

void	cast_ray(float ray_angle, int id, t_cub3d *cub3d);

// cub->player.rotation_angle = posição da rotação do player no mapa
void	cast_all_rays(t_cub3d *cub3d)
{
	float	ray_angle;
	int		i;
	double  rad_increment;

	rad_increment = FOV_ANGLE / NUM_RAYS;
	ray_angle = cub3d->player.rotation_angle - (FOV_ANGLE / 2); //primeiro raio da esquerda para a direita
	i = 0;
	while (i < NUM_RAYS) //incrementa até chegar ao ultimo raio a direita
	{
		cast_ray(ray_angle, i, cub3d);
		ray_angle += rad_increment;
		++i;
	}
}

void	cast_ray(float ray_angle, int id, t_cub3d *cub3d)
{
	t_utils_ray	utils;
	t_aux_ray	horz;
	t_aux_ray	vert;

	ft_bzero(&utils, sizeof(t_utils_ray));
	ft_bzero(&cub3d->rays[id], sizeof(t_ray));
	ray_angle = normalize_angle(ray_angle);
	utils.is_ray_facing_down = is_ray_facing_down(ray_angle);
	utils.is_ray_facing_up = is_ray_racing_up(ray_angle);
	utils.is_ray_facing_right = is_ray_facing_right(ray_angle);
	utils.is_ray_facing_left = is_ray_facing_left(ray_angle);
	horz = ray_horizontal(cub3d, &utils, ray_angle); //video 7 da cap 4
	vert = ray_vertical(cub3d, &utils, ray_angle);//video 9 da cap 4
	get_ray_distance(cub3d, &horz, &vert); //video 10 da cap 4
	get_values_of_ray(&cub3d->rays[id], utils, horz, vert);
	cub3d->rays[id].ray_angle = ray_angle;
}
