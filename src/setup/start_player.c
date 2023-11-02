#include "cub3d.h"

static void	find_player_position(t_cub3D *cub3D);
static void	save_initial_angle(t_cub3D *cub3D);
static void	save_orientation(t_cub3D *cub3D, char c);

void	start_player(t_cub3D *cub3D)
{
	ft_bzero(&cub3D->player, sizeof(t_player));
	find_player_position(cub3D);
	save_initial_angle(cub3D);
	cub3D->player.turn_direction = 0;
	cub3D->player.walk_direction = 0;
	cub3D->player.walk_speed = 10;
	cub3D->player.turn_speed = 2 * (PI / 180);
}

static void	find_player_position(t_cub3D *cub3D)
{
	int		x;
	size_t	y;

	x = 0;
	while (x < cub3D->map_info.height)
	{
		y = 0;
		while (y < ft_strlen(cub3D->map[x]))
		{
			if (cub3D->map[x][y] == 'N' || cub3D->map[x][y] == 'S' ||
				cub3D->map[x][y] == 'W' || cub3D->map[x][y] == 'E')
			{
				cub3D->player.x = (y * TILE) + (TILE / 2);
				cub3D->player.y = (x * TILE) + (TILE / 2);
				save_orientation(cub3D, cub3D->map[x][y]);
				cub3D->map[x][y] = '0';
				break ;
			}
			y++;
		}
		x++;
	}
}

static void	save_initial_angle(t_cub3D *cub3D)
{
	if (cub3D->player.orientation == WE)
		cub3D->player.rotation_angle = TWO_PI / 2;
	else if (cub3D->player.orientation == EA)
		cub3D->player.rotation_angle = (TWO_PI * 2) / 2;
	else if (cub3D->player.orientation == SO)
		cub3D->player.rotation_angle = PI / 2;
	else if (cub3D->player.orientation == NO)
		cub3D->player.rotation_angle = (PI * 3) / 2;
}

static void	save_orientation(t_cub3D *cub3D, char c)
{
	if (c == 'N')
		cub3D->player.orientation = NO;
	else if (c == 'S')
		cub3D->player.orientation = SO;
	else if (c == 'W')
		cub3D->player.orientation = WE;
	else if (c == 'E')
		cub3D->player.orientation = EA;
}
