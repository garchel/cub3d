
#include "cub3d.h"

static char	**get_file_path(int fd, char *current_line);
static int	set_places(char **list, t_texture_path **textures);
static void	check_last_char(t_texture_path **texture);
static int	validate_textures_file_path(t_texture_path **textures);
int			colors(int fd, t_colors *colors, char *current_line);
static int	set_info(char letter, char *colors, \
	char ****ceiling, char ****floor);
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

static unsigned int	get_colors(int fd, char ***floor, \
	char ***ceiling, char *current_line)
{
	char	**line_splitted_space;
	char	*colors;
	int		i;
	int		j;
	char	letter;

	j = 0;
	while (j < 2)
	{
		colors = "\0";
		while (current_line[0] == '\n')
			current_line = get_next_line(fd);
		line_splitted_space = ft_split(current_line, ' ');
		letter = line_splitted_space[0][0];
		i = 0;
		while (line_splitted_space[++i])
			colors = ft_strjoin(colors, line_splitted_space[i]);
		set_info(letter, colors, &floor, &ceiling);
		current_line = get_next_line(fd);
		free(colors);
		++j;
	}
	return (1);
}

static unsigned int	rgb_to_uint(char ***rgb)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi((*rgb)[0]);
	if (red < 0 || red > 255 || have_letters((*rgb)[0]))
		return (0);
	green = ft_atoi((*rgb)[1]);
	if (green < 0 || green > 255 || have_letters((*rgb)[1]))
		return (0);
	blue = ft_atoi((*rgb)[2]);
	if ((*rgb)[2][ft_strlen((*rgb)[2]) - 1] == '\n')
		(*rgb)[2][ft_strlen((*rgb)[2]) - 1] = '\0';
	if (blue < 0 || blue > 255 || have_letters((*rgb)[2]))
		return (0);
	return ((red << 16) + (green << 8) + blue);
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

static int	set_info(char letter, char *colors, \
	char ****ceiling, char ****floor)
{
	if (letter == 'f' || letter == 'F')
		(**floor) = ft_split(colors, ',');
	else if (letter == 'c' || letter == 'C')
		(**ceiling) = ft_split(colors, ',');
	else
		return (0);
	return (1);
}

int	colors(int fd, t_colors *colors, char *current_line)
{
	char	**floor;
	char	**ceiling;

	if (!get_colors(fd, &floor, &ceiling, current_line))
		return (0);
	colors->ceiling = rgb_to_uint(&ceiling);
	if (colors->ceiling == 0)
	{
		error_message(CEILING_ERR);
		return (0);
	}
	colors->floor = rgb_to_uint(&floor);
	if (colors->floor == 0)
	{
		error_message(FLOOR_ERR);
		return (0);
	}
	return (1);
}
