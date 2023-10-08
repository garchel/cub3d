#include "window.h"

void	init_window(t_data *data)
{
	int win_height;
	int win_width;

	win_height = data->win_height * TILE_SIZE * 2;
	win_width = data->win_width * TILE_SIZE;
	// if(win_width > 700)
	// 	win_width = 700;
	printf("height = %d\n", win_height);
	printf("width = %d\n", win_width);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, win_width, win_height, "cub3D");
	data->img.img = mlx_new_image(data->mlx, win_width, win_height);
	data->img.addr = mlx_get_data_addr(data->img.img, &(data->img.bpp),
			&(data->img.l_length), &(data->img.endian));
}