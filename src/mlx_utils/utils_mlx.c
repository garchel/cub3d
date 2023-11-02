#include "cub3d.h"

void	build_main_img(t_cub3D *cub3D)
{
	cub3D->img.img = mlx_new_image(cub3D->s_mlx.mlx, WIDTH, HEIGHT);
	cub3D->img.addr = mlx_get_data_addr(cub3D->img.img, &cub3D->img.bpp,
			&cub3D->img.l_len, &cub3D->img.endian);
}

void	sprites(t_data *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x,
			&img->pos.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_len, &img->endian);
}

void	ft_mlx_pixel_put(t_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->l_len + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*color;

	color = data->addr + (y * data->l_len + x * (data->bpp / 8));
	return (*(unsigned int *)color);
}
