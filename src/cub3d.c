#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_cub3D	cub3D;

	ft_bzero(&cub3D, sizeof(t_cub3D));
	if (argc != 2)
		error_message(ARG_ERR);
	if (check_map(&cub3D, argv) == FALSE)
		return (1);
	init_game(&cub3D);
	return (0);
}
