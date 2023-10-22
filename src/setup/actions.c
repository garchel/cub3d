#include "cub3d.h"

int	action_loop(t_cub3d *cub3d)
{
	move_player(cub3d);
	cast_all_rays(cub3d);
	draw_gaming(cub3d);
	return (1);
}
