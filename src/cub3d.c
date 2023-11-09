/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:02:16 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:11:16 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_cub3D	cub3d;

	ft_bzero(&cub3d, sizeof(t_cub3D));
	if (argc != 2)
		error_message(ARG_ERR);
	if (check_map(&cub3d, argv) == FALSE)
		return (1);
	init_game(&cub3d);
	return (0);
}
