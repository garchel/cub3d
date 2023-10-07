#include "cub3d.h"

void print_map(int **map, t_scale scales)
{
	int j;

	for(int i = 0; i < scales.height; i++)
	{
		j = 0;
		for(j = 0;j < scales.width; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
}

int	init_data(t_data *data, char** argv)
{
	t_map_info map_info;

	get_files(&map_info, &data->matrix_map, argv); //pega todas as informações vinda do arquivo

	data->player.x = 350; 
	data->player.y = 200;
	return 1;
}