#include "render.h"

void	draw_background(t_image *img);
void	draw_map(t_data *data);
void	put_pixel_img(t_image *img, int x, int y, int color);

void	draw(t_data *data)
{
	draw_background(&(data)->img);
	draw_map(data);
	handle_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}


void	put_pixel_img(t_image *img, int x, int y, int color)
{
	char	*render;

	if (x > WIN_HEIGHT || y > WIN_WIDTH || x < 0 || y < 0)
		return ;
	render = img->addr + (y * img->l_length + x * (img->bpp / 8));
	*(unsigned int *)render = color;
}

void	draw_background(t_image *img)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_HEIGHT)
	{
		y = -1;
		while (++y <= WIN_WIDTH)
			put_pixel_img(img, x, y, BLACK_COLOR);
	}
}

void	draw_square(t_image *img, int y, int x, int size, int color)
{
	int	sizeX = x + size;
	int	sizeY = y + size;
	int i = x;
	while (++i < sizeX)
	{
		int j = y;
		while (++j < sizeY)
			put_pixel_img(img, i, j, color);
	}
}

void	draw_map(t_data *data)
{
	int i;
	int j;
	int i_matrix;
	int	j_matrix;
	

	i = 0;
	j = 0;
	i_matrix = 0;
	j_matrix = 0;
	while(i < data->win_height * TILE_SIZE)
	{
		j = 0;
		j_matrix = 0;
		while(j < data->win_width * TILE_SIZE)
		{
			if(data->matrix_map[i_matrix][j_matrix] == 1)
				draw_square(&(data)->img, i, j, TILE_SIZE ,YELLOW_COLOR);
			j += TILE_SIZE;
			++j_matrix;
		}
		++i_matrix;
		i += TILE_SIZE;
	}
}

