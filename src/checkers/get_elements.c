#include "cub3d.h"

int	get_elements(char *current_line, char *ident, \
	t_file_info *file_info, int fd)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!ft_strncmp(ident, "NO", 2) || !ft_strncmp(ident, "SO", 2) || \
			!ft_strncmp(ident, "EA", 2) || !ft_strncmp(ident, "WE", 2))
		{
			if (map_textures(fd, &file_info->texture_path, current_line) == 0)
				error_message(TEXTURE_ERR);
			ident = "F";
			current_line = get_next_line(fd);
		}
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


