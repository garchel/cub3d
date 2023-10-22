#include <cub3d.h>

void temp_print_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

int	check_map(t_cub3d *cub3d, char **argv)
{
	t_scale scale;
	get_files(cub3d, argv);
	scale = get_scale(cub3d->map);
	cub3d->map_info.height = scale.height;
	cub3d->map_info.width = scale.width;
	cub3d->collors.cell = cub3d->file_info.colors.ceiling;
	cub3d->collors.floor = cub3d->file_info.colors.floor;
	return (TRUE);
}
