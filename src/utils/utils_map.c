#include "cub3d.h"

int	get_lenght(t_cub3D *cub3d, float line);

int	map_has_wall_at(t_cub3D *cub3d, float x, float y)
{
	int	map_grid_indexx;
	int	map_grid_indexy;

	map_grid_indexx = floor(x / TILE);
	map_grid_indexy = floor(y / TILE);
	return (cub3d->map[map_grid_indexy][map_grid_indexx] != '0');
}

int	get_lenght(t_cub3D *cub3d, float line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE)
		> cub3d->map_info.height)
		return (0);
	else
		return ((int)ft_strlen(cub3d->map[(int)floor(line / TILE)]));
}
