#include "cub3d.h"


void rays_facing(t_utils_ray *utils, float ray_angle)
{
	utils->is_ray_facing_down = is_ray_facing_down(ray_angle);
	utils->is_ray_facing_up = is_ray_racing_up(ray_angle);
	utils->is_ray_facing_right = is_ray_facing_right(ray_angle);
	utils->is_ray_facing_left = is_ray_facing_left(ray_angle);
}

int	is_ray_facing_down(float angle)
{
	if (angle > 0 && angle < PI)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ray_racing_up(float angle)
{
	if (is_ray_facing_down(angle) == TRUE)
		return (FALSE);
	else
		return (TRUE);
}

int	is_ray_facing_right(float angle)
{
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ray_facing_left(float angle)
{
	if (is_ray_facing_right(angle) == TRUE)
		return (FALSE);
	else
		return (TRUE);
}