#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		error_message(ARG_ERR);
	ft_bzero(&cub3d, sizeof(t_cub3d));
	if (check_map(&cub3d, argv) == FALSE)
		return (1);
	init_game(&cub3d);
	// free
	return (0);
}
