#include "cub3d.h"

void	arg_error()
{
	perror("ERROR: to many args\n");
	exit(1);
}

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
	int 	err_status;

	err_status = get_files(&map_info, &data->matrix_map, argv);
	if(err_status != 1)
	{
		err_msg(err_status);
		return 0;
	}
	data->player.x = 350; 
	data->player.y = 200;
	// int	**map = data->matrix_map;
	// for (int i = 0; i < 10; i++)
	// 	for (int j = 0; j < 10; j++)
	// 		data->temp[i][j] = map[i][j];
	print_map(data->matrix_map, get_scale(data->matrix_map));
	return 1;
}