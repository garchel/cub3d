#include "cub3d.h"

#define TEMP_LINE_SIZE 10
#define MOVE_SPEED 4

void draw_direction_line(t_data *data, t_point init);
void move_player(t_data *data);

void	handle_player(t_data *data)
{
	t_point	init;

	init.x = data->player.x;
	init.y = data->player.y / 2;
	int	sizeX = init.x + TEMP_LINE_SIZE;
	int	sizeY = init.y + TEMP_LINE_SIZE;
	int i = init.x;
	while (++i < sizeX)
	{
		int j = init.y;
		while (++j < sizeY)
			put_pixel_img(&(data)->img, i, j, RED_COLOR);
	}
    //...
    init.x -= (init.x - sizeX ) / 2; //posição da linha de visualização em relação ao player
    init.y -= (init.y - sizeY ) / 2; //posição da linha de visualização em relação ao player
    //
	data->player.rotation_angle += data->player.turn_direction * data->player.rotation_speed;
    move_player(data);
    draw_direction_line(data, init);
}

void init_player(t_data *data)
{
    data->player.x = WIN_WIDTH / 2;
    data->player.y = WIN_HEIGHT / 2;
    data->player.turn_direction = 0;          // +1 ou -1 dependendo da direção
    data->player.walk_direction = 0;          // +1 ou -1 dependendo se para frente ou para trás
    data->player.rotation_angle = PI / 2;     
    data->player.move_speed = 2;
    data->player.rotation_speed = 4 * (PI / 180);
    data->player.size = 5;
}

void draw_direction_line(t_data *data, t_point init)
{
    t_point dest;

    dest.x = init.x + cos(data->player.rotation_angle) * 40;
    dest.y = init.y + sin(data->player.rotation_angle) * 40;
    bresenham(&(data)->img, init, dest);
}

void move_player(t_data *data)
{
    int move_step;

    move_step = data->player.walk_direction * MOVE_SPEED;
    data->player.x += cos(data->player.rotation_angle) * move_step;
    data->player.y += sin(data->player.rotation_angle) * move_step;   
}