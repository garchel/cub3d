#include "cub3d.h"

t_scale	get_scale(char **map)
{
	t_scale	scale;
	int		i;
	int		j;
	int		greater;

	i = 0;
	j = 0;
	greater = 1;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] == ' ')
				map[i][j] = '0';
			++j;
		}
		if (j > greater)
			greater = j;
		++i;
	}
	scale.height = i;
	scale.width = greater - 1;
	return (scale);
}


char	*next_line(int fd)
{
	char	*current_line;

	current_line = get_next_line(fd);
	while (current_line[0] == '\n')
	{
		// free(current_line);
		current_line = get_next_line(fd);
	}
	return (current_line);
}
