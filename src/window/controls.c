#include "window.h"

int	key_press(int key, t_data *data);
int	exit_button(t_data *data);


void	buttons_hook(t_data *data)
{
	mlx_hook(data->win, 17, 0, exit_button, data);
	mlx_hook(data->win, 02, 1L << 0, key_press, data);
}

int	key_press(int key, t_data *data)
{
    data->player.rotation_speed = 2 * (PI / 180);

	if (key == ESC_KEY)
		exit_button(data);
	if (key == W_KEY)
		data->player.walk_direction = +1;
	if (key == S_KEY)
		data->player.walk_direction = -1;
	if (key == RIGHT_KEY)
	 	data->player.turn_direction = +1;
	if (key == LEFT_KEY)
		data->player.turn_direction = -1;
	data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
	draw(data);
	return (0);
}

int	exit_button(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}
