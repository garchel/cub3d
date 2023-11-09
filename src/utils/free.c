/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:02:06 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:02:07 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_cub3D *cub3D)
{
	free_mlx_all(cub3D);
	free_tex(&cub3D->file_info);
	free_map(cub3D->map);
	exit(127);
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

void	free_tex(t_file_info *info)
{
	free(info->texture_path.TEX_EA);
	free(info->texture_path.TEX_NO);
	free(info->texture_path.TEX_SO);
	free(info->texture_path.TEX_WE);
}
