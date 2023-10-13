/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:42:43 by hbernard          #+#    #+#             */
/*   Updated: 2022/06/24 00:43:54 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *str, char *buffer)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	new_str = malloc(sizeof(char) * ((gnl_strlen(str) + gnl_strlen(buffer)) + 1));
	if (new_str == NULL)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			new_str[i] = str[i];
	while (buffer[j] != '\0')
		new_str[i++] = buffer[j++];
	new_str[gnl_strlen(str) + gnl_strlen(buffer)] = '\0';
	free(str);
	return (new_str);
}
