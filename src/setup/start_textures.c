#include <cub3d.h>

static uint32_t	*get_texture_buffer(t_data *img);

void	start_textures(t_cub3D *cub3D)
{
	sprites(&cub3D->sprites.no, cub3D->s_mlx.mlx, \
		cub3D->file_info.texture_path.TEX_NO);
	sprites(&cub3D->sprites.so, cub3D->s_mlx.mlx, \
		cub3D->file_info.texture_path.TEX_SO);
	sprites(&cub3D->sprites.we, cub3D->s_mlx.mlx, \
		cub3D->file_info.texture_path.TEX_WE);
	sprites(&cub3D->sprites.ea, cub3D->s_mlx.mlx, \
		cub3D->file_info.texture_path.TEX_EA);
	cub3D->textures[0] = get_texture_buffer(&cub3D->sprites.no);
	cub3D->textures[1] = get_texture_buffer(&cub3D->sprites.so);
	cub3D->textures[2] = get_texture_buffer(&cub3D->sprites.we);
	cub3D->textures[3] = get_texture_buffer(&cub3D->sprites.ea);
	free_images(cub3D);
}

static uint32_t	*get_texture_buffer(t_data *img)
{
	int			x;
	int			y;
	uint32_t	*buffer;

	buffer = ft_calloc(TEXTURE_WIDTH * TEXTURE_HEIGHT, sizeof(uint32_t *));
	x = -1;
	while (++x < TEXTURE_HEIGHT)
	{
		y = -1;
		while (++y < TEXTURE_WIDTH)
			buffer[(TEXTURE_WIDTH * y) + x] = (uint32_t)get_color(img, x, y);
	}
	return (buffer);
}
