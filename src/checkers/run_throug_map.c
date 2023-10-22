#include "cub3d.h"

int find_adjacent_zero(t_list_map head, int i, int j, t_scale scale);
int search_zero_right(t_list_map head, int i, int j, t_scale scale);
int search_zero_down(t_list_map head, int i, int j, t_scale scale);
int search_zero_left(t_list_map head, int i, int j, t_scale scale);
int search_zero_up(t_list_map head, int i, int j, t_scale scale);


int is_valid_position(int i, int j, t_scale scale) 
{
    return (i >= 0 && i < scale.height && j >= 0 && j < scale.width);
}

void print_map_run(int **matrix)
{
    int i = 0;
    int j = 0;

    while(i < 19)
    {
        j = 0;
        while(matrix[i][j] != -1)
        {
            // printf("%d", matrix[i][j]);
            ++j;
        }
        // printf("\n");
        ++i;
    }
}



int find_adjacent_zero(t_list_map head, int i, int j, t_scale scale)
{
	// printf("Iniciou Find_adjacent_zero na posição [%d][%d]\n", i, j);
    if (j + 1 < scale.width && head.map[i][j + 1] == '0')
        return (1);
    else if(i + 1 < scale.height && head.map[i + 1][j] == '0')
        return (1);
    else if(j - 1 > 0 && head.map[i][j - 1] == '0')
         return (1);
    else if(i - 1 > 0 && head.map[i - 1][j] == '0')
         return (1);
    else
        return 0;
}

int process_zeros(t_list_map head, int i, int j, t_scale scale)
{
	// printf("Iniciou process_zeros na posição [%d][%d]\n", i, j);
    if (!search_zero_right(head, i, j, scale))
        return (0);
    else if (!search_zero_down(head, i, j, scale))
        return (0);
    else if (!search_zero_left(head, i, j, scale))
        return (0);
    else if (!search_zero_up(head, i, j, scale))
        return (0);
    else
	{
		// printf("Finalizou process_zeros na posição [%d][%d]\n", i, j);
        return (1);
	}
}

int search_zero_right(t_list_map head, int i, int j, t_scale scale)
{
    if (j + 1 == scale.width && head.map[i][j + 1] == '0') // Se for o ultimo elemento da linha e for um 0 (significa que o mapa está aberto)
    {
	    return (0);// Retorna 0 caso encontre o final do mapa (indicando que o mapa está aberto)
	} 
	if (is_valid_position(i, j + 1, scale))
	{
		if (head.map[i][j + 1] == '0' && j + 1 < scale.width) // Se for um 0 e não for a ultima coluna
		{
			head.map[i][j + 1] = '3'; // Marca como visitado
			// printf("Marcou com 3 na posição: [%d][%d]\n", i, j + 1);
			return (process_zeros(head, i, j + 1, scale));
		}
	}
		
    return (1);
}

int search_zero_down(t_list_map head, int i, int j, t_scale scale)
{
	// printf("Iniciou o search_down \n");
    if (i + 1 == scale.height && head.map[i + 1][j] == '0') // Se for a ultima posição e nela contiver um 0 (significa que o mapa está aberto)
    {
		return 0;
	}
	if (is_valid_position(i + 1, j, scale))
	{
		if (head.map[i + 1][j] == '0' && i + 1 <  scale.height) // Se for um 0 na posição e não for a ultima linha
		{
			head.map[i + 1][j] = '3';
			// printf("Marcou com 3 na posição: [%d][%d]\n", i + 1, j);
			return (process_zeros(head, i + 1, j, scale));
		}
	}
    return (1);
}

int search_zero_left(t_list_map head, int i, int j, t_scale scale)
{
	// printf("Iniciou o search_left \n");
    if (j - 1 == '0' && head.map[i][j - 1] == '0') // Se for a primeira posição e nela contiver um 0 (significa que o mapa está aberto)
    {
		return 0;
	}    	
	if (is_valid_position(i, j - 1, scale))
	{
		if (head.map[i][j - 1] == '0' && j - 1 > '0') // Se for um 0 na posição e não for a primeira coluna
		{
			head.map[i][j - 1] = '3';
			// printf("Marcou com 3 na posição: [%d][%d]\n", i, j - 1);
			return (process_zeros(head, i, j - 1, scale));
		}
	}
    return (1);
}

int search_zero_up(t_list_map head, int i, int j, t_scale scale)
{
	// printf("Iniciou o search_up \n");
    if (i - 1 == '0' && head.map[i - 1][j] == '0') // Se for a primeira posição e nela contiver um 0 (significa que o mapa está aberto)
    {
		return 0;
	}
	if (is_valid_position(i - 1, j, scale))
	{
		if (head.map[i - 1][j] == '0' && i - 1 > '0') // Se for um 0 na posição e não for a primeira linha
		{
			head.map[i - 1][j] = '3';
			// printf("Marcou com 3 na posição: [%d][%d]\n", i - 1, j);
			return (process_zeros(head, i - 1, j, scale));
		}
	}
    return (1);
}

void normalize_matrix(char **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(matrix[i] != NULL)
	{
		j = 0;
		while(matrix[i][j])
		{
			if(matrix[i][j] == '3')
                matrix[i][j] = '0';
			if(matrix[i][j] == -1)
			{
				matrix[i][j] = '\0';
			}
			++j;
		}
		++i;
	}
}

int check_walls(t_list_map head, t_scale scale)
{
    int i;
    int j;

    i = 0;
	// printf("Iniciou Check_walls\n");
    while(head.map[i] != NULL)
	{
		j = 0;
		while(head.map[i][j] != -1)
		{
			// printf("[%c]", head.map[i][j]);
			// printf("adj_scale = %d\n", find_adjacent_zero(head, i, j, scale));
			if((head.map[i][j] == '1') && find_adjacent_zero(head, i, j, scale) != 0) // Se for uma parede e tiver um 0 ao lado
			{
				// printf("Process_Zeros Acabou, todos os zeros foram passados");
                return (process_zeros(head, i, j, scale));
			}
			++j;
		}
			// printf("\n");
			// printf("i = %d\n", i);
		++i;
	}
    return (1); // Se não tiver uma parede com um 0 ao lado
}