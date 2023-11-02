
#include <cub3d.h>

int	check_map(t_cub3D *cub3d, char **argv)
{
 	t_scale	scale;

	get_files(cub3d, argv);
	scale = get_scale(cub3d->map);
	cub3d->map_info.height = scale.height;
	cub3d->map_info.width = scale.width;
	cub3d->collors.cell = cub3d->file_info.colors.ceiling;
	cub3d->collors.floor = cub3d->file_info.colors.floor;
	return (TRUE);
}
