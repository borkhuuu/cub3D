#include "game.h"
#include "map.h"
#include "mlx/mlx.h"

#include <stdlib.h>
#include <X11/keysym.h>

void	mlx_cleanup(t_game *game)
{
	if (game->image.ptr_to_img)
		mlx_destroy_image(game->connection, game->image.ptr_to_img);
	if (game->window)
		mlx_destroy_window(game->connection, game->window);
	if (game->connection)
	{
		mlx_destroy_display(game->connection);
		free(game->connection);
	}
	free_func(game->map, game->map->map_arr);
	exit(0);
}

int	x_window(void *param)
{
	t_game	*game;

	game = (t_game*)param;
	mlx_cleanup(game);
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_cleanup(game);
	return (0);
}

int	init_mlx(t_game *game)
{
	game->connection = mlx_init();
	if (!game->connection)
		return (mlx_cleanup(game), 0); //cleanup
	game->window = mlx_new_window(game->connection, HEIGHT, WIDTH, "cub3D");
	if (!game->window)
		return (mlx_cleanup(game), 0); //cleanup
	game->image.ptr_to_img = mlx_new_image(game->connection, HEIGHT, WIDTH);
	if (!game->image.ptr_to_img)
		return (mlx_cleanup(game), 0); //cleanup
	game->image.ptr_to_pixel = mlx_get_data_addr(game->image.ptr_to_img, &game->image.bpp, &game->image.line_len, &game->image.endian);
	if (!game->image.ptr_to_pixel)
		return (mlx_cleanup(game), 0); //cleanup
	mlx_hook(game->window, 17, 0, x_window, game);
	mlx_key_hook(game->window, key_handler, game);
	mlx_loop(game->connection);
	return (1);
}
