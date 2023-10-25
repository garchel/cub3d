
#include "cub3d.h"

static char	**get_file_path(int fd, char *current_line);
static int	set_places(char **list, t_texture_path **textures);
static void	check_last_char(t_texture_path **texture);
static int	validate_textures_file_path(t_texture_path **textures);
int			colors(int fd, t_colors *colors, char *current_line);
static int	set_info(char letter, char *colors, \
char 		****ceiling, char ****floor);
static int	have_letters(char *color);
char		**create_map(int fd, char *current_line);

static int	check_arg(char **argv) // Verifica extensão .cub
{
	char	**split;

	split = ft_split(argv[1], '.');
	if (ft_strncmp(split[1], "cub", 4) == 0)
		return (1);
	return (0);
}

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

static int	set_places(char **list, t_texture_path **textures)
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
		{
			printf("[%s]?: ", line_splitted[0]);
			return (0);
		}
		++i;
	}
	return (1);
}

static int	get_elements(char *current_line, char *ident, \
	t_file_info *file_info, int fd)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		//vai verificar se é o momento de pegar as informações de texturas
		if (!ft_strncmp(ident, "NO", 2) || !ft_strncmp(ident, "SO", 2) || \
			!ft_strncmp(ident, "EA", 2) || !ft_strncmp(ident, "WE", 2))
		{
			if (map_textures(fd, &file_info->texture_path, current_line) == 0)
				error_message(TEXTURE_ERR);
			ident = "F";
			current_line = get_next_line(fd);
		}
		//vai ver se é o momento de pegar as informações das cores
		else if (!ft_strncmp(ident, "F", 1) || !ft_strncmp(ident, "C", 1))
		{
			if (colors(fd, &file_info->colors, current_line) == 0)
				error_message(COLOR_ERR);
			ident = "NO";
			current_line = get_next_line(fd);
		}
		else
			error_message(ID_FAIL);
		++i;
	}
	return (1);
}

int	get_files(t_cub3d *cub, char **argv)
{
	int		fd;
	char	*current_line;
	char	*identifier;
	int		status;

	// printf("argv = %s\n", argv[1]);
	fd = open(ft_strjoin("maps/", argv[1]), O_RDONLY);
	if (fd < 0)
		error_message(FILE_NO_ERR);
	if (check_arg(argv) == 0)
		error_message(FILE_NAME_ERR);
	current_line = next_line(fd);
	identifier = ft_split(current_line, ' ')[0];
	status = get_elements(current_line, identifier, &cub->file_info, fd);
	//vai pegar todas as informações vinda do mapa
	cub->map = create_map(fd, current_line);
	return (status);
}
