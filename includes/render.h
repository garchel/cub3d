#ifndef REDER_H
# define REDER_H

# include "cub3d.h"
# include "colors.h"

typedef struct s_image	t_image;
typedef struct s_data	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bres
{
	int	x;
	int	y;
	int	sign_x;
	int	sign_y;
	int	dx;
	int	dy;
	int	color;
	int	p;
}	t_bres;

//draw.c
void	put_pixel_img(t_image *img, int x, int y, int color);
void	draw_background(t_image *img);
void	draw(t_data *data);

// bresenham.c
void	bresenham(t_image *img, t_point init, t_point dest);

#endif //REDER_H
