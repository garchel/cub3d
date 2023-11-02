#include "cub3d.h"

int	check_arg(char **argv);

int	get_files(t_cub3D *cub3D, char **argv)
{
	int		fd;
	char	*current_line;
	char	*identifier;
	int		status;

	fd = open(ft_strjoin("maps/", argv[1]), O_RDONLY);
	if (fd < 0)
		error_message(FILE_NO_ERR);
	if (check_arg(argv) == 0)
		error_message(FILE_NAME_ERR);
	current_line = next_line(fd);
	identifier = ft_split(current_line, ' ')[0];
	status = get_elements(current_line, identifier, &cub3D->file_info, fd);
	cub3D->map = create_map(fd, current_line);
	return (status);
}


int	check_arg(char **argv)
{
	char	**split;

	split = ft_split(argv[1], '.');
	if (ft_strncmp(split[1], "cub", 4) == 0)
		return (1);
	return (0);
}