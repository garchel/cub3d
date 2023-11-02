#include <cub3d.h>

int	action_loop(t_cub3D *cub3D)
{
	move_player(cub3D);
	cast_all_rays(cub3D);
	draw_gaming(cub3D);
	return (1);
}
