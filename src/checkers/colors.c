#include "cub3d.h"

unsigned int	get_colors(char ***floor, \
	char ***ceiling, t_list_map *head);
unsigned int	rgb_to_uint(char ***rgb);
int	have_letters(char *color);

int	colors(t_colors *colors, t_list_map *head)
{
    char **floor = NULL; 
    char **ceiling = NULL; 

	// floor = calloc(4, sizeof(char*));
	// ceiling = calloc(4, sizeof(char*));
	if (!get_colors(&floor, &ceiling, head))
		return (0);
	colors->ceiling = rgb_to_uint(&ceiling);
	if (colors->ceiling == 0)
		error_message(CEILING_ERR);
	colors->floor = rgb_to_uint(&floor);
	if (colors->floor == 0)
		error_message(FLOOR_ERR);
	ft_free_split(floor);
	ft_free_split(ceiling);
	return (1);
}


int	have_letters(char *color)
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

unsigned int	rgb_to_uint(char ***rgb)
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

unsigned int	get_colors(char ***floor, \
	char ***ceiling, t_list_map *head)
{
	char *info_floor;
	char *info_ceiling;
	int i = 1;
	int j = 0;

	info_floor = ft_calloc(head->begin->size, sizeof(char));
	while(head->begin->line[i])
	{
		if(head->begin->line[i] != ' ')
		{
			info_floor[j] = head->begin->line[i];
			++j;
		}
		++i;
	}
	(*floor) = ft_split(info_floor, ',');
	i = 1;
	j = 0;
	info_ceiling = ft_calloc(head->begin->size, sizeof(char));
	head->begin = head->begin->next;
	while(head->begin->line[i])
	{
		if(head->begin->line[i] != ' ')
		{
			info_ceiling[j] = head->begin->line[i];
			++j;
		}
		++i;
	}
	(*ceiling) = ft_split(info_ceiling, ',');
	head->begin = head->begin->next;
	free(info_ceiling);
	free(info_floor);
	return 1;
}

