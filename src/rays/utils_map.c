
#include "cub3d.h"

int	is_inside_map(float x, float y, t_cub3d *cub3d)
{
	if (x >= 0 && x <= get_lenght(cub3d, y) * TILE && y >= 0
		&& y <= cub3d->map_info.height * TILE)
		return (TRUE);
	else
		return (FALSE);
}

int	get_lenght(t_cub3d *cub3d, float line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE)
		> cub3d->map_info.height)
		return (0);
	else
		return ((int)ft_strlen(cub3d->map[(int)floor(line / TILE)]));
}
