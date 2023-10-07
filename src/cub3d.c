# include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	if (argc != 2)
		error_message("ERROR: invalid number of arguments");
	if(init_data(&data, argv) == 0)
		return (0);
	init_window(&data);
	buttons_hook(&data);
	draw(&data);
	mlx_loop(data.mlx);
	return (0);
}
