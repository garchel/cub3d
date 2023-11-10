/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:00:51 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/10 20:31:20 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				get_colors(char ***floor, char ***ceiling, t_list_map *head);
unsigned int	rgb_to_uint(char ***rgb);
void			remove_space(char *list, char **color);

int	colors(t_colors *colors, t_list_map *head)
{
	char	**floor;
	char	**ceiling;

	floor = NULL;
	ceiling = NULL;
	if (!get_colors(&floor, &ceiling, head))
		return (0);
	colors->ceiling = rgb_to_uint(&ceiling);
	if (colors->ceiling == 0)
	{
		ft_free_split(floor);
		ft_free_split(ceiling);
		return (0);
	}
	colors->floor = rgb_to_uint(&floor);
	if (colors->floor == 0)
		return (0);
	ft_free_split(floor);
	ft_free_split(ceiling);
	return (1);
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

int	get_colors(char ***floor, char ***ceiling, t_list_map *head)
{
	char	*info;
	int		i;

	i = 0;
	if (head->begin->line[0] == head->begin->next->line[0])
		return (0);
	while (i < 2)
	{
		info = ft_calloc(head->begin->size, sizeof(char));
		remove_space(head->begin->line, &info);
		if (head->begin->line[0] == 'F')
			(*floor) = ft_split(info, ',');
		else if (head->begin->line[0] == 'C')
			(*ceiling) = ft_split(info, ',');
		else
		{
			free(info);
			return (0);
		}
		free(info);
		head->begin = head->begin->next;
		++i;
	}
	return (1);
}

void	remove_space(char *list, char **color)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (list[i])
	{
		if (list[i] != ' ')
		{
			(*color)[j] = list[i];
			++j;
		}
		++i;
	}
}
