#ifndef WINDOW_H
# define WINDOW_H

# include "cub3d.h"

typedef struct s_image	t_image;
typedef struct s_data	t_data;

//window.c
void	init_window(t_data *data);

//controls.c
void	buttons_hook(t_data *data);

#endif //WINDOW_H
