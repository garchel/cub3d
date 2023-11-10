#ifndef CUB3D_H

# define CUB3D_H

# include	"libft.h"
# include	"get_next_line.h"
# include	<ft_errors.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<mlx.h>
# include	<math.h>
# include	<structs.h>
# include	<limits.h>

#include <string.h>

//3d_projection
void			generate3d_projection(t_cub3D *cub3D);
void			get_values_projection(t_cub3D *cub3D, t_projection *var);
void			draw_background(t_cub3D *cub3D3d, t_projection var);
void			get_texture_offset(t_cub3D *cub3D, t_projection *var);

//checkers
int				search_zero_right(t_list_map head, int i, int j, t_scale scale);
int				search_zero_down(t_list_map head, int i, int j, t_scale scale);
int				search_zero_left(t_list_map head, int i, int j, t_scale scale);
int				search_zero_up(t_list_map head, int i, int j, t_scale scale);
t_list_map		*create_list(void);
int				get_elements(t_list_map *list, char *ident, \
t_file_info 	*file_info);
t_list_map		*create_list(void);
t_scale			get_scale(char **map);
void			add_on_tail(t_list_map *list, char *line);
char			**linked_to_int(t_list_map *head, int size);
int				check_walls(t_list_map head, t_scale scale);
void			normalize_matrix(char **matrix);
int				map_textures(t_texture_path *textures, t_list_map *head);
int				colors(t_colors *colors, t_list_map *head);
int             create_map(t_list_map *list, int n_lines, t_file_info *file_info);
int				process_zeros(t_list_map head, int i, int j, t_scale scale);
int				check_arg(char **argv);

//keys
int				key_release(int key, t_cub3D *cub3D3d);
int				action(int keycode, t_cub3D *cub3D);

//mlx_utils
void			build_main_img(t_cub3D *cub3D);
void			sprites(t_data *img, void *mlx, char *path);
void			ft_mlx_pixel_put(t_data *img_data, int x, int y, int color);
unsigned int	get_color(t_data *data, int x, int y);

//move_player
void			move_player(t_cub3D *cub3D);

//rays
void			cast_all_rays(t_cub3D *cub3D);
void			cast_ray(float ray_angle, int id, t_cub3D *cub3D);
void			rays_facing(t_utils_ray *utils, float ray_angle);
t_aux_ray		ray_horizontal(t_cub3D *cub3D, t_utils_ray *utils, float angle);
t_aux_ray		ray_vertical(t_cub3D *cub3D, t_utils_ray *utils, float angle);
int				is_ray_facing_down(float angle);
int				is_ray_racing_up(float angle);
int				is_ray_facing_right(float angle);
int				is_ray_facing_left(float angle);

//setup
int			setup(t_cub3D *cub3D);
int			start_player(t_cub3D *cub3D);
void			start_textures(t_cub3D *cub3D);

//action
int				action_loop(t_cub3D *cub3D);
void			move_player(t_cub3D *cub3D);
void			cast_all_rays(t_cub3D *cub3D);
void			draw_gaming(t_cub3D *cub3D);

//cub3D3D
int				check_map(t_cub3D *cub3D3d, char **argv);
int			init_game(t_cub3D *cub3D); //init_game

//utils
int				map_has_wall_at(t_cub3D *cub3D, float x, float y);
int				get_lenght(t_cub3D *cub3D, float line);
void			error_message(char *msg);
int             have_letters(char *color);


//free
int				close_win(t_cub3D *cub3D);
void			free_images(t_cub3D *cub3D);
void			ft_free_ptr(void **ptr);
char			*ft_free_triple(char ***str);
char			*ft_free_split(char **str);
void			free_mlx_all(t_cub3D *cub3D);
void	        destroy_list(t_list_map **List);
void            free_tex(t_file_info *info);
void            free_map(char **map);

#endif
