#include "cub3d.h"

void	generate3d_projection(t_cub3D *cub3D)
{
	t_projection	var;

	ft_bzero(&var, sizeof(t_projection));
	while (var.x < NUM_RAYS)
	{
		get_values_projection(cub3D, &var);
		draw_background(cub3D, var);
		get_texture_offset(cub3D, &var);
		var.y = var.wall_top_pixel;
		while (var.y < var.wall_bottom_pixel)
		{
			var.distance_from_top = var.y + (var.wall_strip_height / 2)
				- (HEIGHT / 2);
			var.texture_off_sety = var.distance_from_top
				* ((float)TEXTURE_HEIGHT / var.wall_strip_height);
			var.texel_color = cub3D->textures[var.tex_num][(TEXTURE_WIDTH
					* var.texture_off_sety) + var.texture_offset_x];
			ft_mlx_pixel_put(&cub3D->img, var.x, var.y, var.texel_color);
			var.y++;
		}
		var.x++;
	}
}
