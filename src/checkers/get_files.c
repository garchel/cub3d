#include "cub3d.h"

// int	check_arg(char **argv);

// int	get_files(t_cub3D *cub3D, char **argv)
// {
// 	int		fd;
// 	char	*current_line = NULL;
// 	char	*identifier;
// 	int		status = 1;
// 	char 	**temp;
// 	t_list_map *head;

// 	identifier = temp[0];
// 	status = get_elements(current_line, identifier, &cub3D->file_info);
// 	head = create_list();
// 	cub3D->map = create_map(fd, current_line, head);
// 	// destroy_list(&head);
// 	// ft_free_split(temp);
// 	// close(fd);
// 	return (status);
// }

// int	check_arg(char **argv)
// {
// 	char	**split;

// 	split = ft_split(argv[1], '.');
// 	if (ft_strncmp(split[1], "cub", 4) == 0)
// 	{
// 		ft_free_split(split);
// 		return (1);
// 	}
// 	return (0);
// }