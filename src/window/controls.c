#include "window.h"

int	exit_button(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == ESC_KEY)
		exit_button(data);
	if (key == W_KEY)
	{
		data->player.y -= data->player.dy * 5;
		data->player.x -= data->player.dx * 5;
	}
	if (key == S_KEY)
	{
		data->player.y += data->player.dy * 5;
		data->player.x += data->player.dx * 5;
	}
	if (key == A_KEY)
		data->player.x -= 5;
	if (key == D_KEY)
		data->player.x += 5;
	
	if (key == LEFT_KEY)
	{
		data->player.ang -= 0.1;
		if (data->player.ang < 0)
			data->player.ang += 2 * PI;
		data->player.dx = cos(data->player.ang);
		printf("-> %f\n", data->player.dx);
		data->player.dy = sin(data->player.ang);
	}
	if (key == RIGHT_KEY)
	{
		data->player.ang += 0.1;
		if (data->player.ang > 2 * PI)
			data->player.ang -= 2 * PI;
		data->player.dx = cos(data->player.ang);
		data->player.dy = sin(data->player.ang);
	}
	draw(data);
	return (0);
}

void	buttons_hook(t_data *data)
{
	mlx_hook(data->win, 17, 0, exit_button, data);
	mlx_hook(data->win, 02, 1L << 0, key_press, data);
}