#include "maps.h"

int             run_through_up(int **matrix, t_coordinates pos, t_coordinates init_pos);
int             run_through_down(int **matrix, t_coordinates pos, t_coordinates init_pos);
t_coordinates get_initial_position(t_coordinates pos, int **matrix, int size);

void print_map_run(int **matrix)
{
    int i = 0;
    int j = 0;

    while(i < 19)
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

int check_walls(int **matrix, int size)
{
    t_coordinates   pos;
    
    pos = get_initial_position(pos, matrix, size);
    if(pos.status == 1)
        return 0;
    --pos.i;
    --pos.j;
    while(pos.i != 0 && pos.j != 0)
    {
        run_through_up(matrix, pos, pos);
        pos = first_empty_block(matrix, size);
    }
    return 1;
}

int run_through_up(int **matrix, t_coordinates pos, t_coordinates init_pos)
{
    while(matrix[pos.i][pos.j] != 1)
    {
        while(matrix[pos.i][pos.j] == 0)
        {
            matrix[pos.i][pos.j] = 3;
            ++pos.j;
        }
        pos = init_pos;
        --pos.j;
        while(matrix[pos.i][pos.j] == 0)
        {
            matrix[pos.i][pos.j] = 3;
            --pos.j;
        }
        pos = init_pos;
        --pos.i;
        init_pos = pos;
    }
    return 1;
}

t_coordinates get_initial_position(t_coordinates pos, int **matrix, int size)
{
    int i;
    int j;
    int block;

    pos.status = 2;
    i = -1;
    while(++i <= size)
    {
        j = 0;
        block = matrix[i][j];
        while(block != -1)
        {
            block = matrix[i][j];
            if(block == 30 || block == 21 || block == 35 || block == 39)
            {
                pos.i = i + 1;
                pos.j = j + 1;
            }
            else if(block != 1 && block != 0 && block != -1)
                pos.status = 1;
            ++j;
        }
    }
    return pos;
}

void normalize_matrix(int **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(matrix[i] != NULL)
	{
		j = 0;
		while(matrix[i][j] != -1)
		{
			if(matrix[i][j] == 3)
                matrix[i][j] = 0;
			++j;
		}
		++i;
	}
}
