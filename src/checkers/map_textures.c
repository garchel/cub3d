/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:06 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/10 20:14:33 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_last_char(t_texture_path **texture);
char	**get_file_path(t_list_map *head);
int		set_places(char **list, t_texture_path **textures);
int		validate_textures_file_path(t_texture_path **textures);

int	map_textures(t_texture_path *textures, t_list_map *head)
{
	char	**list;

	list = get_file_path(head);
	if (set_places(list, &textures) == 0)
	{
		free(list);
		return (0);
	}
	check_last_char(&textures);
	if (validate_textures_file_path(&textures) == 0)
	{
		free(list);
		return (0);
	}
	free(list);
	return (1);
}

char	**get_file_path(t_list_map *head)
{
	char	**list;

	list = calloc(5, sizeof(char *));
	list[0] = head->begin->line;
		head->begin = head->begin->next;
	list[1] = head->begin->line;
		head->begin = head->begin->next;
	list[2] = head->begin->line;
		head->begin = head->begin->next;
	list[3] = head->begin->line;
		head->begin = head->begin->next;
	return (list);
}

int	set_places(char **list, t_texture_path **tex)
{
	int		i;
	char	**split;

	i = -1;
	while (list[++i])
	{
		split = ft_split(list[i], ' ');
		if (ft_strncmp(split[0], "NO", 2) == 0 && !(*tex)->TEX_NO)
			(*tex)->TEX_NO = ft_strdup(split[1]);
		else if (ft_strncmp(split[0], "EA", 2) == 0 && !(*tex)->TEX_EA)
			(*tex)->TEX_EA = ft_strdup(split[1]);
		else if (ft_strncmp(split[0], "SO", 2) == 0 && !(*tex)->TEX_SO)
			(*tex)->TEX_SO = ft_strdup(split[1]);
		else if (ft_strncmp(split[0], "WE", 2) == 0 && !(*tex)->TEX_WE)
			(*tex)->TEX_WE = ft_strdup(split[1]);
		else
		{
			ft_free_split(split);
			return (0);
		}
		ft_free_split(split);
	}
	return (1);
}

void	check_last_char(t_texture_path **texture)
{
	int	size;

	size = ft_strlen((*texture)->TEX_NO);
	if ((*texture)->TEX_NO[size -1] == '\n')
		(*texture)->TEX_NO[size -1] = '\0';
	size = ft_strlen((*texture)->TEX_SO);
	if ((*texture)->TEX_SO[size -1] == '\n')
		(*texture)->TEX_SO[size -1] = '\0';
	size = ft_strlen((*texture)->TEX_WE);
	if ((*texture)->TEX_WE[size -1] == '\n')
		(*texture)->TEX_WE[size -1] = '\0';
	size = ft_strlen((*texture)->TEX_EA);
	if ((*texture)->TEX_EA[size -1] == '\n')
		(*texture)->TEX_EA[size -1] = '\0';
}

int	validate_textures_file_path(t_texture_path **textures)
{
	int	fd;

	fd = open((*textures)->TEX_NO, O_RDONLY);
	if (fd < 0)
		return (0);
	fd = open((*textures)->TEX_SO, O_RDONLY);
	if (fd < 0)
		return (0);
	fd = open((*textures)->TEX_WE, O_RDONLY);
	if (fd < 0)
		return (0);
	fd = open((*textures)->TEX_EA, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}
