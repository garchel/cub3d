#include "cub3d.h"

void print_map(int **map)
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 25; j++)
            printf("->%d", map[i][j]);
        printf("\n");
    }
}

void alloc_matrix_temp(int ***matrix, int temp[11][25])
{
	int i = 0;
	int j = 0;

	*matrix = malloc(11 * sizeof(int*));
	while(i < 11)
	{
		(*matrix)[i] = malloc(25 * sizeof(int));
		j = 0;
		while(j < 25)
		{
			(*matrix)[i][j] = temp[i][j];
			++j;
		}
		++i;
	}
}

int	init_data(t_data *data, char** argv)
{
	t_map_info map_info;
	int        **matrix_temp;//apagar

	get_files(&map_info, &matrix_temp, argv); //pega todas as informações vinda do arquivo
	int temp[11][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
		{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	data->win_height = 11;
	data->win_width = 25;
	alloc_matrix_temp(&data->matrix_map, temp);
	init_player(data);
	return 1;
}