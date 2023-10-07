#include "window.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "cub3D");
	data->img.img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->img.addr = mlx_get_data_addr(data->img.img, &(data->img.bpp),
			&(data->img.l_length), &(data->img.endian));
}
