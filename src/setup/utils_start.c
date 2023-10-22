#include "cub3d.h"

static void	find_player_position(t_cub3d *cub3d);
static void	save_orientation(t_cub3d *cub3d, char c);


void	start_player(t_cub3d *cub3d)
{
	ft_bzero(&cub3d->player, sizeof(t_player));
	find_player_position(cub3d);
	cub3d->player.width = 5;
	cub3d->player.height = 5;
	cub3d->player.turn_direction = 0;
	cub3d->player.walk_direction = 0;
	cub3d->player.walk_speed = 10;
	cub3d->player.turn_speed = 2 * (PI / 180); // PI/180 serve para converter angulos para radianos
}

static void	find_player_position(t_cub3d *cub3d)
{
	int x;
	int	y;

	x = 0;
	while (x < cub3d->map_info.height)
	{
		y = 0;
		while (y < cub3d->map_info.width)
		{
			if (cub3d->map[x][y] == 'N' || cub3d->map[x][y] == 'S' ||
				cub3d->map[x][y] == 'W' || cub3d->map[x][y] == 'E')
			{
				cub3d->player.x = (y * TILE) + (TILE / 2);
				cub3d->player.y = (x * TILE) + (TILE / 2);
				save_orientation(cub3d, cub3d->map[x][y]);
				cub3d->map[x][y] = '0'; //retira a letra indicando o posicionamento
				break ;
			}
			y++;
		}
		x++;
	}
}

static void	save_orientation(t_cub3d *cub3d, char c)
{
	if (c == 'N')
		cub3d->player.rotation_angle = (PI * 3) / 2;
	else if (c == 'S')
		cub3d->player.rotation_angle = PI / 2;
	else if (c == 'W')
		cub3d->player.rotation_angle = TWO_PI / 2;
	else if (c == 'E')
		cub3d->player.rotation_angle = (TWO_PI * 2) / 2;
}
