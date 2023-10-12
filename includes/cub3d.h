#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"	//minilibx
# include <math.h>	//sin, cos and abs
# include <fcntl.h>	//open and close
# include <errno.h>	//errno
# include <stdio.h>	//perror
# include <stdlib.h>//malloc, free

# include "libft.h"
# include "get_next_line.h"
# include "keycode.h"
# include "maps.h"
# include "window.h"
# include "render.h"
# include "error_message.h"

#define TILE_SIZE   42
#define PI			3.14159265

typedef struct s_map	t_map;

typedef struct s_player
{
	float		x;
	float		y;
	int 	turn_direction;
	int 	walk_direction;
	int 	side_direction;
	float   rotation_angle;
	int 	move_speed;
	float 	rotation_speed;
	int		size;
	float	dx;
	float	dy;
	float	ang;
}	t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}	t_image;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_player	player;
	int         **matrix_map;
	int         temp[11][25]; //apagar
	int			win_height;
	int			win_width;
}	t_data;

//cub3d.c
void	arg_error();
void	handle_player(t_data *data);
int 	init_data(t_data *data,  char** argv);
void	err_msg(int err_status);
void	error_message(char *msg);

#endif //CUB3D_H
