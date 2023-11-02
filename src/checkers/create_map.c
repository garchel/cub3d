#include "cub3d.h"

int	check_map_chars(t_list_map head,  t_scale scale);

char	**create_map(int fd, char *current_line)
{
	t_list_map	*head;
	int			size;
	t_scale		scale;

	head = create_list();
	current_line = next_line(fd);
	size = 0;
	while (current_line[0] != 0 && current_line[0] != '\n')
	{
		add_on_tail(head, current_line);
		current_line = get_next_line(fd);
		if (current_line == NULL || current_line[0] == '\n')
			break ;
		++size;
	}
	head->map = linked_to_int(head, size);
	scale = get_scale(head->map);
	if ((check_map_chars(*head, scale) != 1) || (check_walls(*head, scale) != 1))
		error_message(PARSE_MAP);
	normalize_matrix(head->map);
	return (head->map);
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


int	check_map_chars(t_list_map head,  t_scale scale)
{
	int	i;
	int	j;

	i = 0;
	while (i <= scale.height - 1 && head.map[i] != NULL)
	{
		j = 0;
		while (j <= scale.width - 2 && head.map[i][j] != -1)
		{
			if (head.map[i][j] == '1' ||
				head.map[i][j] == '0' ||
				head.map[i][j] == 'N' ||
				head.map[i][j] == 'S' ||
				head.map[i][j] == 'E' ||
				head.map[i][j] == 'W')
				{
					++j;
				}
			else
				return (0); // Caractere inválido encontrado
		}
		++i;
	}
	return (1);
}

t_pos	return_pos(int **matrix, t_pos pos)
{
	pos.status = 0;
	if (matrix[pos.y][pos.x - 1] == 0)
	{
		--pos.x;
		return (pos);
	}
	else if (matrix[pos.y + 1][pos.x] == 0)
	{
		++pos.y;
		return (pos);
	}
	else if (matrix[pos.y - 1][pos.x] == 0)
	{
		--pos.y;
		return (pos);
	}
	pos.status = 1;
	return (pos);
}

t_pos	first_empty_block(int **matrix, int size)
{
	t_pos	final_pos;
	t_pos	pos;

	pos.y = 0;
	pos.x = 0;
	while (pos.y < size)
	{
		pos.x = 0;
		while (matrix[pos.y][pos.x] != -1)
		{
			if (matrix[pos.y][pos.x] == 3)
			{
				final_pos = return_pos(matrix, pos);
				if (matrix[final_pos.y][final_pos.x + 1] == -1)
					error_message(FAIL_WALL);
				if (final_pos.status == 0)
					return (final_pos);
			}
			++pos.x;
		}
		++pos.y;
	}
	pos.y = 0;
	pos.x = 0;
	return (pos);
}