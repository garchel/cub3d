/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:37 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 17:32:14 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	open_file(t_list_map *list, char **argv)
{
	int		fd;
	char	*path;

	path = ft_strjoin("maps/", argv[1]);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(list);
		free(path);
		error_message(FILE_NO_ERR);
		return (-1);
	}
	if (check_arg(argv) == 0)
	{
		error_message(FILE_NAME_ERR);
		return (-1);
	}
	free(path);
	return (fd);
}

int	process_lines(t_list_map *list, int fd)
{
	char	*current_line;
	int		n_lines;

	n_lines = 0;
	current_line = get_next_line(fd);
	while (current_line != NULL)
	{
		if (current_line[0] != '\n')
			add_on_tail(list, current_line);
		else
			free(current_line);
		current_line = get_next_line(fd);
		++n_lines;
	}
	close(fd);
	return (n_lines);
}

void	store_map_info(t_cub3D *cub3D)
{
	t_scale	scale;

	scale = get_scale(cub3D->map);
	cub3D->map_info.height = scale.height;
	cub3D->map_info.width = scale.width;
	cub3D->collors.cell = cub3D->file_info.colors.ceiling;
	cub3D->collors.floor = cub3D->file_info.colors.floor;
}

void	map_handler(t_cub3D *cub3D, t_list_map *list, \
	t_node_map *init, int n_lines)
{
	char		**temp_ident;
	char		*identifier;

	temp_ident = ft_split(list->begin->line, ' ');
	identifier = temp_ident[0];
	if (get_elements(list, identifier, &cub3D->file_info) == 0)
	{
		ft_free_split(temp_ident);
		exit(127);
	}
	if (create_map(list, n_lines, &cub3D->file_info) == 0)
	{
		free_map(list->map);
		list->begin = init;
		destroy_list(&list);
		ft_free_split(temp_ident);
		exit(127);
	}
	ft_free_split(temp_ident);
}

int	check_map(t_cub3D *cub3D, char **argv)
{
	t_list_map	*list;
	t_node_map	*init;
	int			fd;
	int			n_lines;

	list = create_list();
	fd = open_file(list, argv);
	if (fd < 0)
		return (FALSE);
	n_lines = process_lines(list, fd);
	if(n_lines <= 7)
	{
		error_message(INCOMPLETE_FILE);
		destroy_list(&list);
		exit(127);
	}
	init = list->begin;
	map_handler(cub3D, list, init, n_lines);
	cub3D->map = list->map;
	list->begin = init;
	store_map_info(cub3D);
	destroy_list(&list);
	return (TRUE);
}
