#include "cub3d.h"

void	sprites(t_data *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x,
			&img->pos.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_len, &img->endian);
}

void	build_main_img(t_cub3d *cub)
{
	cub->img.img = mlx_new_image(cub->s_mlx.mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp,
			&cub->img.l_len, &cub->img.endian);
}
