/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:41 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:00:42 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scale	get_scale(char **map)
{
	t_scale	scale;
	int		i;
	int		j;
	int		greater;

	i = 0;
	j = 0;
	greater = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '0';
			++j;
		}
		if (j > greater)
			greater = j;
		++i;
	}
	scale.height = i;
	scale.width = greater - 1;
	return (scale);
}

int	check_arg(char **argv)
{
	char	**split;

	split = ft_split(argv[1], '.');
	if (ft_strncmp(split[1], "cub", 4) == 0)
	{
		ft_free_split(split);
		return (1);
	}
	return (0);
}
