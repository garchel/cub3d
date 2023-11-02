#include "cub3d.h"

int	close_win(t_cub3D *cub3D)
{
	free_mlx_all(cub3D);
	exit(0);
}

void free_tex(t_texture_path *tex)
{
	free(tex->TEX_NO);
	free(tex->TEX_SO);
	free(tex->TEX_WE);
	free(tex->TEX_EA);
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
