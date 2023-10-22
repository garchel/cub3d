/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:09:31 by hbernard          #+#    #+#             */
/*   Updated: 2022/05/25 23:34:48 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX 2147483647

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*ptr;
	size_t	total;

	total = nmemb * size;
	if (total > INT_MAX)
		return (NULL);
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return ((void *)ptr);
}
