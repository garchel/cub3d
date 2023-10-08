#include "render.h"

void	put_pixel_img(t_image *img, int x, int y, int color)
{
	char	*render;

	if (x > WIN_X || y > WIN_Y || x < 0 || y < 0)
		return ;
	render = img->addr + (y * img->l_length + x * (img->bpp / 8));
	*(unsigned int *)render = color;
}

void	draw_background(t_image *img)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y <= WIN_Y)
			put_pixel_img(img, x, y, BLACK_COLOR);
	}
}

void	draw_player(t_data *data)
{
	t_point	init;
	t_point	dest;
	
	init.x = data->player.x;
	init.y = data->player.y;
	dest.x = data->player.x + 6;
	dest.y = data->player.y;
	while (dest.y < data->player.y + 6)
	{
		bresenham(&(data->img), init, dest);
		init.y++;
		dest.y++;
	}
	init.x = data->player.x + 2;
	init.y = data->player.y + 2;
	dest.x = data->player.x + 2 - (data->player.dx * 15);
	dest.y = data->player.y + 2 - (data->player.dy * 15);
	printf("init.y: %d\n", init.y);
	printf("dest.y: %d\n", dest.y);
	bresenham(&(data->img), init, dest);
	dest.x += 1;
	init.x += 1;
	printf("ang: %f\n", data->player.ang);
	bresenham(&(data->img), init, dest);
}

void	draw_wall(t_image *img, int y, int x)
{
	int	sizeX = x + TILE_SIZE;
	int	sizeY = y + TILE_SIZE;
	int i = x;
	while (++i < sizeX)
	{
		int j = y;
		while (++j < sizeY)
			put_pixel_img(img, i, j, YELLOW_COLOR);
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
				draw_wall(&(data)->img, i, j);
			j += TILE_SIZE;
			++j_matrix;
		}
		++i_matrix;
		i += TILE_SIZE;
	}
}

void	draw(t_data *data)
{
	draw_background(&(data)->img);
	draw_map(data);
	// draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
