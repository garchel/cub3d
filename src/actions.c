/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:02:13 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:02:14 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	action_loop(t_cub3D *cub3D)
{
	move_player(cub3D);
	cast_all_rays(cub3D);
	draw_gaming(cub3D);
	return (1);
}
