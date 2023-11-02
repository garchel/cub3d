#include "cub3d.h"

void	check_last_char(t_texture_path **texture);
char	**get_file_path(int fd, char *current_line);
int	set_places(char **list, t_texture_path **textures);
int	validate_textures_file_path(t_texture_path **textures);

int	map_textures(int fd, t_texture_path *textures, char *first_line)
{
	char	**list;

	list = get_file_path(fd, first_line);
	if (set_places(list, &textures) == 0)
	{
		error_message(TEXTURE_ERR);
		return (0);
	}
	check_last_char(&textures);
	if (validate_textures_file_path(&textures) == 0)
	{
		error_message(FILE_NO_ERR);
		return (0);
	}
	return (1);
}

char	**get_file_path(int fd, char *current_line)
{
	char	**list;

	list = malloc(4 * sizeof(char *));
	while (current_line[0] == '\n')
		current_line = get_next_line(fd);
	list[0] = current_line;
	current_line = get_next_line(fd);
	while (current_line[0] == '\n')
		current_line = get_next_line(fd);
	list[1] = current_line;
	current_line = get_next_line(fd);
	while (current_line[0] == '\n')
		current_line = get_next_line(fd);
	list[2] = current_line;
	current_line = get_next_line(fd);
	while (current_line[0] == '\n')
		current_line = get_next_line(fd);
	list[3] = current_line;
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
			(*textures)->TEX_EA = line_splitted[1];
		else if (ft_strncmp(line_splitted[0], "NO", 2) == 0)
			(*textures)->TEX_NO = line_splitted[1];
		else if (ft_strncmp(line_splitted[0], "WE", 2) == 0)
			(*textures)->TEX_WE = line_splitted[1];
		else if (ft_strncmp(line_splitted[0], "SO", 2) == 0)
			(*textures)->TEX_SO = line_splitted[1];
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
