
#include "cub3d.h"

// cub3d->player.rotation_angle = posição da rotação do player no mapa, depende se a posição inicial no mapa será W,E,S ou N
// cub3d->player.turn_direction = +1 para a direita -1 para a esquerda
// cub3d->player.turn_speed = irá incrementara posição do angulo da camera em radianos
// cub3d->player.side_direction; = +1 para a esquerda(a) -1 para a direita(d)
// cub3d->player.walk_speed = incremento da poisão do player
// cub3d->player.walk_direction = +1 para cima(w) -1 para baixo(s)
// cub3d->player.x = posição inicial do player. 64 (tamanho das paredes) * coluna N + 64/2 (posição dentro do quadrado atual)
// cub3d->player.y = posição inicial do player. 64 (tamanho das paredes) * linha N + 64/2 (posição dentro do quadrado atual)

void	move_player(t_cub3d *cub3d) //video 4 cap 3
{
	float	move_step;
	float	side_step;
	float	new_player_x;
	float	new_player_y;

	cub3d->player.rotation_angle += cub3d->player.turn_direction
		* cub3d->player.turn_speed;
	side_step = cub3d->player.side_direction * cub3d->player.walk_speed;
	move_step = cub3d->player.walk_direction * cub3d->player.walk_speed;
	if (move_step && side_step) //quando andando da diagoal
	{
		move_step /= 2;
		side_step /= 2;
	}
	new_player_x = cub3d->player.x + cos(cub3d->player.rotation_angle) \
		* move_step;
	new_player_y = cub3d->player.y + sin(cub3d->player.rotation_angle) \
		* move_step;
	new_player_x = new_player_x - sin(-cub3d->player.rotation_angle) \
		* side_step; //quando anda de lado
	new_player_y = new_player_y - cos(-cub3d->player.rotation_angle) \
		* side_step; //quando anda de lado
	if (!map_has_wall_at(cub3d, new_player_x, new_player_y)) //Evita colisões
	{
		cub3d->player.x = new_player_x;
		cub3d->player.y = new_player_y;
	}
}

int	map_has_wall_at(t_cub3d *cub3d, float x, float y)
{
	int	map_position_x;
	int	map_position_y;

	map_position_x = floor(x / TILE);
	map_position_y = floor(y / TILE);
	return (cub3d->map[map_position_y][map_position_x] != '0');
}
