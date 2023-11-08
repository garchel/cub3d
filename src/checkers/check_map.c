#include <cub3d.h>

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

int	file_info(t_list_map *list, char **argv)
{
	char	*current_line;
	int		fd;
	int		n_lines;

	n_lines = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(list);
		error_message(FILE_NO_ERR);
	}
	if (check_arg(argv) == 0)
		error_message(FILE_NAME_ERR);
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

int	check_map(t_cub3D *cub3D, char **argv)
{
	t_list_map	*list;
	t_node_map	*init;
	char		**temp_ident;
	char		*identifier;
	int			n_lines;

	list = create_list();
	n_lines = file_info(list, argv);
	temp_ident = ft_split(list->begin->line, ' ');
	identifier = temp_ident[0];
	init = list->begin;
	if(get_elements(list, identifier, &cub3D->file_info) == 0)
	{
		ft_free_split(temp_ident);
		exit(127);
	}
	if(create_map(list, n_lines, &cub3D->file_info) == 0)
	{
		free_map(list->map);
		list->begin = init;
		destroy_list(&list);
		ft_free_split(temp_ident);
		exit(127);
	}
	cub3D->map = list->map;
	list->begin = init;
	store_map_info(cub3D);
	destroy_list(&list);
	ft_free_split(temp_ident);
	return (TRUE);
}
