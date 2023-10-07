#include "maps.h"

static char     **get_file_path(int fd,char *current_line);
static int      validate_textures_file_path(t_textures **textures);
static void     check_last_char(t_textures **texture);
static int      set_places( char **list, t_textures **textures);

int     map_textures(int fd, t_textures *textures,char *first_line)
{
    char **list;

    list = get_file_path(fd, first_line);
    if(set_places(list, &textures) == 0)
    {
        printf("There is an error with a coordinate\n");
        return 0;
    }
    check_last_char(&textures);
    if(validate_textures_file_path(&textures) == 0)
    {
        printf(".xpm : some file did not exist in this context\n");
        return 0;
    }
    return 1;
}

static int     validate_textures_file_path(t_textures **textures)
{
    int fd;

    fd = open((*textures)->NO, O_RDONLY);
    if(fd < 0)
        return 0;
    fd = open((*textures)->SO, O_RDONLY);
    if(fd < 0)
        return 0;
    fd = open((*textures)->WE, O_RDONLY);
    if(fd < 0)
        return 0;
    fd = open((*textures)->EA, O_RDONLY);
    if(fd < 0)
        return 0;
    return 1;
}

static void    check_last_char(t_textures **texture)
{
    int size;

    size = ft_strlen((*texture)->NO);
    if((*texture)->NO[size -1] == '\n')
        (*texture)->NO[size -1] = '\0';
    size = ft_strlen((*texture)->SO);
    if((*texture)->SO[size -1] == '\n')
        (*texture)->SO[size -1] = '\0';
    size = ft_strlen((*texture)->WE);
    if((*texture)->WE[size -1] == '\n')
        (*texture)->WE[size -1] = '\0';
    size = ft_strlen((*texture)->EA);
    if((*texture)->EA[size -1] == '\n')
        (*texture)->EA[size -1] = '\0';
}

static char **get_file_path(int fd,char *current_line)
{
    char **list;

    list = malloc(4 * sizeof(char*));
    while(current_line[0] == '\n')
        current_line = get_next_line(fd);
    list[0] = current_line;
    current_line = get_next_line(fd);
    while(current_line[0] == '\n')
        current_line = get_next_line(fd);
    list[1] = current_line;
    current_line = get_next_line(fd);
    while(current_line[0] == '\n')
        current_line = get_next_line(fd);
    list[2] = current_line;
    current_line = get_next_line(fd);
    while(current_line[0] == '\n')
        current_line = get_next_line(fd);
    list[3] = current_line;
    return list;
}

static int set_places(char **list, t_textures **textures)
{
    int i;
    char **line_splitted;

    i = 0;
    while(list[i])
    {
        line_splitted = ft_split(list[i], ' ');
        if(ft_strncmp(line_splitted[0],"EA", 2) == 0)
            (*textures)->EA = line_splitted[1];
        else if(ft_strncmp(line_splitted[0],"NO", 2) == 0)
            (*textures)->NO = line_splitted[1];
        else if(ft_strncmp(line_splitted[0],"WE", 2) == 0)
            (*textures)->WE = line_splitted[1];
        else if(ft_strncmp(line_splitted[0],"SO", 2) == 0)
            (*textures)->SO = line_splitted[1];
        else
        {
            printf("[%s]?: ", line_splitted[0]);
            return 0;
        }
        ++i;
    }
    return 1;
}