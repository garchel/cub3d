#include "cub3d.h"

void	cast_all_rays(t_cub3D *cub3D)
{
	float	ray_angle;
	int		i;
	double	rad_increment;

	rad_increment = FOV_ANGLE / NUM_RAYS;
	ray_angle = cub3D->player.rotation_angle - \
		(FOV_ANGLE / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		cast_ray(ray_angle, i, cub3D);
		ray_angle += rad_increment;
		++i;
	}
}


