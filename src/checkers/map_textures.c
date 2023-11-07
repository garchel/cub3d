#include "cub3d.h"

void	check_last_char(t_texture_path **texture);
char	**get_file_path(t_list_map *head);
int		set_places(char **list, t_texture_path **textures);
int		validate_textures_file_path(t_texture_path **textures);

int	map_textures(t_texture_path *textures, t_list_map *head)
{
	char	**list;

	// printf("tex = %s\n", head->begin->line);
	list = get_file_path(head);
	if (set_places(list, &textures) == 0)
	{
		error_message(TEXTURE_ERR);
		return (0);
	}
	check_last_char(&textures);
	// printf("-> %s\n", textures->TEX_EA);
	// printf("-> %s\n", textures->TEX_SO);
	// printf("-> %s\n", textures->TEX_NO);
	// printf("-> %s\n", textures->TEX_WE);
	if (validate_textures_file_path(&textures) == 0)
	{
		error_message(FILE_NO_ERR);
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

int	set_places(char **list, t_texture_path **textures)
{
	int		i;
	char	**line_splitted;

	i = 0;
	while (list[i])
	{
		line_splitted = ft_split(list[i], ' ');
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
		ft_free_split(line_splitted);
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
