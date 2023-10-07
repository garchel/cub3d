#include "maps.h"

static int     alloc_structs(t_map_info **map);
static int     check_arg(char** argv);
static int     get_elements(char *current_line, char *identifier, t_map_info **map, int fd);


void print_map_maps(int **matrix)
{
    int j = 0;
    for(int i = 0; matrix[i][j]; i++)
    {
        for(j = 0; matrix[i][j] != -1; ++j)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

int    get_files(t_map_info *map, int ***map_matrix, char** argv)
{
    int         fd;
    char        *current_line;
    char        *identifier;
    int         status;

    fd = open(ft_strjoin("maps/",argv[1]), O_RDONLY);
    if(fd < 0 )
        error_message(FILE_NO_ERR);
    if(check_arg(argv) == 0)
        error_message(FILE_NAME_ERR);
    if(alloc_structs(&map) == 0)
        error_message(ALLOC_ERR);
    current_line = next_line(fd);
    identifier = ft_split(current_line,' ')[0];
    status = get_elements(current_line, identifier, &map, fd);
    (*map_matrix) = create_map(fd, current_line); //vai pegar todas as informações vinda do mapa
    return status;
}

static int alloc_structs(t_map_info **map)
{
    (**map).textures = malloc(4 * sizeof(char*));
    (**map).colors = malloc(2 * sizeof(int));
    if(!(**map).colors || !(**map).textures)
        return 0;
    return 1;
}

static int check_arg(char** argv)
{
    char **split;

    split = ft_split(argv[1], '.');
    if(ft_strncmp(split[1],"cub",4) == 0)
        return 1;
    return 0;
}

char *next_line(int fd)
{
    char *current_line;

    current_line = get_next_line(fd);
    while(current_line[0] == '\n')
        current_line = get_next_line(fd);
    return current_line;
}

// guarda as informações das cores e texturas independete da ordem em que elas aparecem no arquivo
static int get_elements(char *current_line, char *ident, t_map_info **map, int fd)
{
    int i;

    i = 0;
    while(i < 2)
    {
        if(!ft_strncmp(ident,"NO",2) || !ft_strncmp(ident,"SO",2) || //vai verificar se é o momento de pegar as
         !ft_strncmp(ident,"EA",2) || !ft_strncmp(ident,"WE",2))     //informações de texturas
        {
            if(map_textures(fd, (**map).textures, current_line) == 0)
                error_message(TEXTURE_ERR);
            ident = "F";
            current_line = get_next_line(fd);
        }
        else if(!ft_strncmp(ident,"F",1) || !ft_strncmp(ident,"C",1)) //vai ver se é o momento de pegar as informações
        {                                                             //das cores
            if(colors(fd, (**map).colors, current_line) == 0)
                error_message(COLOR_ERR);
            ident = "NO";
            current_line = get_next_line(fd);
        }
        else
            error_message(ID_FAIL);
        ++i;
    }
    return 1;
}