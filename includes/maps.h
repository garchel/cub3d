#ifndef MAPS_H
# define MAPS_H

# include "cub3d.h"

#define UP 1
#define DOWN 2

typedef struct s_textures
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
} t_textures;

typedef struct s_colors
{
	unsigned int ceiling;
	unsigned int floor;
} t_colors;

typedef struct s_map_info
{
	t_textures	*textures;
	t_colors	*colors;
} t_map_info;

//liked list
typedef struct s_node_map
{
    char* line;
	int	  size;
    struct s_node_map *next;
} t_node_map;

typedef struct s_list_map
{
    t_node_map *begin;
    t_node_map *end;
} t_list_map;

typedef struct s_coordinates
{
	int i;
	int j;
	int status;
} t_coordinates;

typedef struct s_scale
{
	int width;
	int height;
} t_scale;


# include "cub3d.h"

// maps
int    get_files(t_map_info *map, int*** matrix_map, char** argv);


int     	map_textures(int fd, t_textures *textures,char *first_line);
int			colors(int fd, t_colors *colors, char *current_line);
char    	*next_line(int fd);
t_list_map	*create_list();
void		add_on_tail(t_list_map *list, char *line);
int			**create_map(int fd, char *current_line);
int			check_walls(int **map, int size);
int			is_valid(int block);
t_scale		get_scale(int **matrix);
t_coordinates first_empty_block(int **matrix, int size);
void		normalize_matrix(int **matrix);




#endif // !MAPS_H