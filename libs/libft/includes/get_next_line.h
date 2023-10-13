/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:21:24 by hbernard          #+#    #+#             */
/*   Updated: 2022/06/24 01:48:35 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>

#define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *str, char *buffer);

#endif
