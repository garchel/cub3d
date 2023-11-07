#include "cub3d.h"

int	get_elements(t_list_map *list, char *ident, \
	t_file_info *file_info)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!ft_strncmp(ident, "NO", 2) || !ft_strncmp(ident, "SO", 2) || \
			!ft_strncmp(ident, "EA", 2) || !ft_strncmp(ident, "WE", 2))
		{
			if (map_textures(&file_info->texture_path, list) == 0)
				error_message(TEXTURE_ERR);
			ident = "F";
			// list->begin = list->begin->next;
		}
		else if (!ft_strncmp(ident, "F", 1) || !ft_strncmp(ident, "C", 1))
		{
			if (colors(&file_info->colors, list) == 0)
				error_message(COLOR_ERR);
			ident = "NO";
			// list->begin = list->begin->next;
		}
		else
			error_message(ID_FAIL);
		++i;
	}
	return (1);
}
