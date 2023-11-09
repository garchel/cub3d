/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:58 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:00:59 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_elements(t_list_map *list, t_file_info *file_info, \
	char *err_msg, t_node_map *init);

int	get_elements(t_list_map *list, char *ident, \
	t_file_info *file_info)
{
	t_node_map	*init;
	int			i;

	init = list->begin;
	i = 0;
	while (i < 2)
	{
		if (!ft_strncmp(ident, "NO", 2) || !ft_strncmp(ident, "SO", 2) || \
			!ft_strncmp(ident, "EA", 2) || !ft_strncmp(ident, "WE", 2))
		{
			if (map_textures(&file_info->texture_path, list) == 0)
				return (free_elements(list, file_info, TEXTURE_ERR, init));
			ident = "F";
		}
		else if (!ft_strncmp(ident, "F", 1) || !ft_strncmp(ident, "C", 1))
		{
			if (colors(&file_info->colors, list) == 0)
				return (free_elements(list, file_info, COLOR_ERR, init));
			ident = "NO";
		}
		else
			error_message(ID_FAIL);
		++i;
	}
	return (1);
}

int	free_elements(t_list_map *list, t_file_info *file_info, \
	char *err_msg, t_node_map *init)
{
	list->begin = init;
	free_tex(file_info);
	destroy_list(&list);
	error_message(err_msg);
	return (0);
}
