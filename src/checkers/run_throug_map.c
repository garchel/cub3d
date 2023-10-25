
#include "cub3d.h"

int	find_adjacent_zero(t_list_map head, int i, int j, t_scale scale);
int	search_zero_right(t_list_map head, int i, int j, t_scale scale);
int	search_zero_down(t_list_map head, int i, int j, t_scale scale);
int	search_zero_left(t_list_map head, int i, int j, t_scale scale);
int	search_zero_up(t_list_map head, int i, int j, t_scale scale);

int	is_valid_position(int i, int j, t_scale scale)
{
	return (i >= 0 && i < scale.height && j >= 0 && j < scale.width);
}

void	print_map_run(int **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 19)
	{
		j = 0;
		while (matrix[i][j] != -1)
		{
			++j;
		}
		++i;
	}
}

int	find_adjacent_zero(t_list_map head, int i, int j, t_scale scale)
{
	if (j + 1 < scale.width && head.map[i][j + 1] == '0')
		return (1);
	else if (i + 1 < scale.height && head.map[i + 1][j] == '0')
		return (1);
	else if (j - 1 > 0 && head.map[i][j - 1] == '0')
		return (1);
	else if (i - 1 > 0 && head.map[i - 1][j] == '0')
		return (1);
	else
		return (0);
}

int	process_zeros(t_list_map head, int i, int j, t_scale scale)
{
	if (!search_zero_right(head, i, j, scale))
		return (0);
	else if (!search_zero_down(head, i, j, scale))
		return (0);
	else if (!search_zero_left(head, i, j, scale))
		return (0);
	else if (!search_zero_up(head, i, j, scale))
		return (0);
	else
		return (1);
}

int	search_zero_right(t_list_map head, int i, int j, t_scale scale)
{
	if (j + 1 == scale.width || head.map[i][j + 1] == 32)
	{
		printf("Mapa aberto na posição: [%d][%d]\n", i, j);
		return (0);
	}
	if (is_valid_position(i, j + 1, scale))
	{
		if (head.map[i][j + 1] == '0') // Se for um 0 e não for a ultima coluna
		{
			head.map[i][j + 1] = '3'; // Marca como visitado
			printf("Marcou com 3 na posição: [%d][%d]\n", i, j + 1);
			return (process_zeros(head, i, j + 1, scale));
		}
	}
	return (1);
}

int	search_zero_down(t_list_map head, int i, int j, t_scale scale)
{
	if (i + 1 == scale.height || head.map[i + 1][j] == 32)
	{
		printf("Mapa aberto na posição: [%d][%d]\n", i, j);
		return (0);
	}
	if (is_valid_position(i + 1, j, scale))
	{
		if (head.map[i + 1][j] == '0')
		{
			head.map[i + 1][j] = '3';
			printf("Marcou com 3 na posição: [%d][%d]\n", i + 1, j);
			return (process_zeros(head, i + 1, j, scale));
		}
	}
	return (1);
}

int	search_zero_left(t_list_map head, int i, int j, t_scale scale)
{
	if (j == 0 || head.map[i][j - 1] == 32)
	{
		printf("Mapa aberto na posição: [%d][%d]\n", i, j);
		return (0);
	}
	if (is_valid_position(i, j - 1, scale))
	{
		if (head.map[i][j - 1] == '0')
		{
			head.map[i][j - 1] = '3';
			printf("Marcou com 3 na posição: [%d][%d]\n", i, j - 1);
			return (process_zeros(head, i, j - 1, scale));
		}
	}
	return (1);
}

int	search_zero_up(t_list_map head, int i, int j, t_scale scale)
{
	if (head.map[i][j] != '1')
	{
		if (i == 0 || head.map[i - 1][j] == 32)
		{
			printf("Mapa aberto na posição: [%d][%d]\n", i, j);
			return (0);
		}
	}
	if (is_valid_position(i - 1, j, scale))
	{
		if (head.map[i - 1][j] == '0')
		{
			head.map[i - 1][j] = '3';
			printf("Marcou com 3 na posição: [%d][%d]\n", i - 1, j);
			return (process_zeros(head, i - 1, j, scale));
		}
	}
	return (1);
}

void	normalize_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '3')
				matrix[i][j] = '0';
			if (matrix[i][j] == -1)
			{
				matrix[i][j] = '\0';
			}
			++j;
		}
		++i;
	}
}

int	check_walls(t_list_map head, t_scale scale)
{
	int	i;
	int	j;

	i = 0;
	while (head.map[i] != NULL)
	{
		j = 0;
		while (head.map[i][j] != -1)
		{
			if ((head.map[i][j] == '1') && \
				find_adjacent_zero(head, i, j, scale) != 0)
			{
				return (process_zeros(head, i, j, scale));
			}
			++j;
		}
		++i;
	}
	return (1);
}
