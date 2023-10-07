#include "maps.h"

int is_valid(int block);
int **linked_to_int(t_list_map *head,int size);

void print_map_create(int **matrix)
{
    int i = 0;
    int j = 0;

    while(matrix[i][j])
    {
        j = 0;
        while(matrix[i][j] != -1)
        {
            printf("%d", matrix[i][j]);
            ++j;
        }
        printf("\n");
        ++i;
    }
}

int **create_map(int fd, char *current_line)
{
    t_list_map  *head;
    int         **map;
    int         size;

    head = create_list();
    current_line = next_line(fd);
    size = 0;
    while(current_line[0] != 0 && current_line[0] != '\n')
    {
        add_on_tail(head,current_line);
        current_line = get_next_line(fd);
        if(current_line == NULL || current_line[0] == '\n')
            break;
        ++size;
    }
    map = linked_to_int(head, size);
    if(check_walls(map, size) != 1)
        return NULL;
    normalize_matrix(map);
    // print_map_create(map);
    return map;
}

int **linked_to_int(t_list_map *head,int size)
{
    int     **map;
    int     i;
    int     j;
    
    map = malloc(sizeof(int*) * size + 1);
    i = 0;
    while(head->begin)
    {
        if(size == i)
            head->begin->size++;
        map[i] = malloc(sizeof(int) * (head->begin->size));
        j = 0;
        while(j < head->begin->size)
        {
            if(head->begin->line[j] == ' ')
                 head->begin->line[j] = '0';
            map[i][j] = (head->begin->line[j] - '0'); 
            ++j;
        }
        map[i][--j] = -1;
        head->begin = head->begin->next;
        ++i;
    }
    // print_map_create(map);
    map[size + 1] = NULL;
    return map;
}

t_scale get_scale(int **matrix)
{
    t_scale scale;
    int i;
    int j;
    int greater;

    i = 0;
    j = 0;
    greater = 1;
    while(matrix[i] != NULL)
    {
        j = 0;
        while(matrix[i][j] != -1)
            ++j;
        if(j > greater)
            greater = j;
        ++i;
    }
    scale.height = i;
    scale.width = greater;
    return scale;
}

t_coordinates return_pos(int **matrix, t_coordinates pos)
{
    pos.status = 0;
    if(matrix[pos.i][pos.j-1] == 0)
    {
        --pos.j;
        return pos;
    }
    else if(matrix[pos.i+1][pos.j] == 0)
    {
        ++pos.i;
        return pos;
    }
    else if(matrix[pos.i-1][pos.j] == 0)
    {
        --pos.i;
        return pos;
    }
    pos.status = 1;
    return pos;
}

t_coordinates first_empty_block(int **matrix, int size)
{
    t_coordinates final_pos;
    t_coordinates pos;

    pos.i = 0;
    pos.j = 0;
    while(pos.i < size)
    {
        pos.j = 0;
        while(matrix[pos.i][pos.j] != -1)
        {
            if(matrix[pos.i][pos.j] == 3)
            {
                final_pos = return_pos(matrix, pos);
                if(final_pos.status == 0)
                    return final_pos;
            }
            ++pos.j;
        }
        ++pos.i;
    }
    pos.i = 0;
    pos.j = 0;
    return pos;
}