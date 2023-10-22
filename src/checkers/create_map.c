#include "cub3d.h"

char **linked_to_int(t_list_map *head,int size);

void print_map_create(int **matrix) //temporário. apenas para debug
{
    int i = 0;
    int j = 0;

    while(i < 18)
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

char **linked_to_int(t_list_map *head,int size) // Recebe uma lista encadeada de strings e um tamanho, e retorna uma matriz de inteiros.
{
    char     **map;
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
            map[i][j] = (head->begin->line[j]); 
            ++j;
        }
        map[i][--j] = -1;
        head->begin = head->begin->next;
        ++i;
    }
    map[size + 1] = NULL;
    // print_map_create(map);
    return map;
}

t_scale get_scale(char **map) // Armazena a altura e largura da matriz (mapa) em uma struct.
{
    t_scale scale;
    int i;
    int j;
    int greater;

    i = 0;
    j = 0;
    greater = 1;
    while(map[i]) 
    {
        j = 0;
        while(map[i][j]) 
            ++j;
        if(j > greater)
            greater = j;
        ++i;
    }
    scale.height = i;
    scale.width = greater - 1;
    return scale;
}

t_pos return_pos(int **matrix, t_pos pos)
{
    pos.status = 0;
    if(matrix[pos.y][pos.x-1] == 0)
    {
        --pos.x;
        return pos;
    }
    else if(matrix[pos.y+1][pos.x] == 0)
    {
        ++pos.y;
        return pos;
    }
    else if(matrix[pos.y-1][pos.x] == 0)
    {
        --pos.y;
        return pos;
    }
    pos.status = 1;
    return pos;
}

t_pos first_empty_block(int **matrix, int size)
{
    t_pos final_pos;
    t_pos pos;

    pos.y = 0;
    pos.x = 0;
    while(pos.y < size)
    {
        pos.x = 0;
        while(matrix[pos.y][pos.x] != -1)
        {
            if(matrix[pos.y][pos.x] == 3)
            {
                final_pos = return_pos(matrix, pos);
                if(matrix[final_pos.y][final_pos.x+1] == -1)
                    error_message(FAIL_WALL);
                if(final_pos.status == 0)
                    return final_pos;
            }
            ++pos.x;
        }
        ++pos.y;
    }
    pos.y = 0;
    pos.x = 0;
    return pos;
}



char **create_map(int fd, char *current_line)
{
    t_list_map  *head;
    int         size;
    t_scale     scale;

    head = create_list();
    current_line = next_line(fd);
    size = 0;
	// printf("Iniciou Create_Map\n");
    while(current_line[0] != 0 && current_line[0] != '\n') //guardas todas a informações em uma lista encadeada
    {
        add_on_tail(head,current_line);
        current_line = get_next_line(fd);
        if(current_line == NULL || current_line[0] == '\n')
            break;
        ++size;
    }
    head->map = linked_to_int(head, size); //passa todas a informações para uma matriz]
    scale = get_scale(head->map);
    if(check_walls(*head, scale) != 1)  //verifica se todos os mapas estão cercados por paredes, se não existe nenhum
    {                                //numero inválido e a posição inicial do jogador
        error_message(PARSE_MAP);
    }
    normalize_matrix(head->map);//adiciona um '-1' em todas a linha para identificar o final do mapa(para os mapas irregulares)
    // print_map_create(map);
    return (head->map);
}