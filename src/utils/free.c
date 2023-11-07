#include "cub3d.h"

int	close_win(t_cub3D *cub3D)
{
	free_mlx_all(cub3D);
	free(cub3D->file_info.texture_path.TEX_EA);
	free(cub3D->file_info.texture_path.TEX_SO);
	free(cub3D->file_info.texture_path.TEX_WE);
	free(cub3D->file_info.texture_path.TEX_NO);
	free(cub3D->map[0]);
	free(cub3D->map[1]);
	free(cub3D->map[2]);
	free(cub3D->map[3]);
	free(cub3D->map[4]);
	free(cub3D->map[5]);
	free(cub3D->map[6]);
	free(cub3D->map[7]);
	free(cub3D->map[8]);
	free(cub3D->map[9]);
	free(cub3D->map[10]);
	free(cub3D->map[11]);
	free(cub3D->map[12]);
	free(cub3D->map[13]);
	free(cub3D->map[14]);
	free(cub3D->map[15]);
	free(cub3D->map[16]);
	free(cub3D->map);
	exit(0);
}

char	*ft_free_triple(char ***str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		ft_free_split(str[i++]);
	free(str);
	return (NULL);
}

char	*ft_free_split(char **str)
{
	int	count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count])
		free(str[count++]);
	free(str);
	return (NULL);
}

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
