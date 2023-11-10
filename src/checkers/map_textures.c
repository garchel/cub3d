/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:06 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/10 18:31:13 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_last_char(t_texture_path **texture);
char	**get_file_path(t_list_map *head);
int		set_places(char **list, t_texture_path **textures, \
	char	**line_splitted);
int		validate_textures_file_path(t_texture_path **textures);

int	map_textures(t_texture_path *textures, t_list_map *head)
{
	char	**list;
	char	**line_splitted;

	list = get_file_path(head);
	line_splitted = ft_split(list[0], ' ');
	if (set_places(list, &textures, line_splitted) == 0)
	{
		ft_free_split(line_splitted);
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

int	set_places(char **list, t_texture_path **textures, char	**line_splitted)
{
	int		i;

	i = 0;
	if (!(*textures)->TEX_EA || !(*textures)->TEX_SO || \
		!(*textures)->TEX_NO || !(*textures)->TEX_WE)
		return (0);
	while (list[i])
	{
		if (ft_strncmp(line_splitted[0], "EA", 2) == 0)
			(*textures)->TEX_EA = ft_strdup(line_splitted[1]);
		else if (ft_strncmp(line_splitted[0], "NO", 2) == 0)
			(*textures)->TEX_NO = ft_strdup(line_splitted[1]);
		else if (ft_strncmp(line_splitted[0], "WE", 2) == 0)
			(*textures)->TEX_WE = ft_strdup(line_splitted[1]);
		else if (ft_strncmp(line_splitted[0], "SO", 2) == 0)
			(*textures)->TEX_SO = ft_strdup(line_splitted[1]);
		else
			return (0);
		++i;
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
