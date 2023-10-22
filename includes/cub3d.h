#ifndef CUB3D_H

# define CUB3D_H

# include	"libft.h"
# include	"get_next_line.h"
# include	"error_message.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<mlx.h>
# include	<math.h>
# include	<structs.h>
# include	<limits.h>

//setup
void			init_game(t_cub3d *cub);
t_scale			get_scale(char  **map);

//validation
int				check_map(t_cub3d *cub, char **argv);
int				get_files(t_cub3d *cub, char** argv);
char			*next_line(int fd);
int 			check_walls(t_list_map head, t_scale scale);
void			normalize_matrix(char **matrix);
void			error_message(char *msg);
void			add_on_tail(t_list_map *list, char *line);
t_list_map		*create_list();

//free
void			free_mlx_all(t_cub3d *cub);

// draw
void			ft_mlx_pixel_put(t_data *img_data, int x, int y, int color);
unsigned int	get_color(t_data *data, int x, int y);

//actions
void			move_player(t_cub3d *cub);
int				action_loop(t_cub3d *cub);
int				action(int keycode, t_cub3d *cub);

//render game
void			draw_gaming(t_cub3d *cub);
void			cast_ray(float ray_angle, int id, t_cub3d *cub);
void			cast_all_rays(t_cub3d *cub);
void			generate3d_projection(t_cub3d *cub);
void			find_horz_intersection(t_aux_ray *aux, t_utils_ray *utils,
					t_cub3d *cub);
t_aux_ray		ray_horizontal(t_cub3d *cub, t_utils_ray *utils, float angle);
void			find_vert_intersection(t_aux_ray *aux, t_utils_ray *utils,
					t_cub3d *cub);
t_aux_ray		ray_vertical(t_cub3d *cub, t_utils_ray *utils, float angle);

//utils
int				map_has_wall_at(t_cub3d *cub, float x, float y);
int				close_win(t_cub3d *cub);
void			start_player(t_cub3d *cub);
float			normalize_angle(float angle);
float			distance_between_points(float x1, float y1, float x2, float y2);
int				get_lenght(t_cub3d *cub, float line);
int				is_inside_map(float x, float y, t_cub3d *cub);
void			change_color_intesity(uint32_t *color, float factor);
int				is_ray_facing_down(float angle);
int				is_ray_racing_up(float angle);
int				is_ray_facing_right(float angle);
int				is_ray_facing_left(float angle);
void			check_inverse_offset_x(t_ray ray, int *texture_offset_x);
void			build_main_img(t_cub3d *cub);
void			start_textures(t_cub3d *cub);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_free_ptr(void **ptr);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				key_release(int key, t_cub3d *cub);
void			move_player(t_cub3d *cub);
void			get_ray_distance(t_cub3d *cub, t_aux_ray *horz, t_aux_ray *vert);
void			get_values_of_ray(t_ray *ray, t_utils_ray utils, t_aux_ray horz, t_aux_ray vert);
void			draw_background(t_cub3d *cub, t_projection var);

#endif