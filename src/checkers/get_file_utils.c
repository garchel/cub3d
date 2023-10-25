#include "cub3d.h"

char	*next_line(int fd) // Vai para a próxima linha do arquivo
{
	char	*current_line;

	// Pega a próxima linha
	current_line = get_next_line(fd);
	// Enquanto a linha for vazia, vai para a próxima
	while (current_line[0] == '\n')
		current_line = get_next_line(fd);
	return (current_line);
}

static int	validate_textures_file_path(t_texture_path **textures)
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

static int	have_letters(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			return (1);
		++i;
	}
	return (0);
}

static char	**get_file_path(int fd, char *current_line)
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

static void	check_last_char(t_texture_path **texture)
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
