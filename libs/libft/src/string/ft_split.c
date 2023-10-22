/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 04:53:22 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/25 23:20:08 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_c(char const *s, char c)
{
	int	i;
	int	count;
	int	w;

	w = 0;
	i = 0;
	count = 0;
	while (s[i])
	{	
		if (s[i] == c)
			w = 0;
		else if (s[i] != c && w == 0)
		{
			w = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		f;
	int		w;

	if (!s)
		return (NULL);
	array = (char **)malloc((count_c(s, c) + 1) * sizeof(char *));
	i = -1;
	f = -1;
	w = 0;
	while (s[++i])
	{
		if (s[i] == c)
			w = 0;
		else if (s[i] != c && w == 0)
		{
			w = 1;
			array[++f] = word(s + i, c);
			if (array[f] == NULL)
				return (NULL);
		}
	}
	array[count_c(s, c)] = 0;
	return (array);
}