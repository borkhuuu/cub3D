#include "color.h"
#include "map.h"
#include "game.h"
#include "cub3D.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include <X11/X.h>

void	setup_fov(t_player *player)
{
	if (player->spawn == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->camera.x = 0.66;
		player->camera.y = 0;
	}
	if (player->spawn == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->camera.x = -0.66;
		player->camera.y = 0;
	}
	if (player->spawn == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->camera.x = 0;
		player->camera.y = -0.66;
	}
	if (player->spawn == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->camera.x = 0;
		player->camera.y = 0.66;
	}
}

int	init_player(t_game *game)
{
	if (!game)
		return (0);
	game->player.pos.x = game->map->player.x + 0.5;
	game->player.pos.y = game->map->player.y + 0.5;
	game->player.spawn = game->map->player_dir;
	setup_fov(&game->player);
	return (1);	
}

void	init_color(t_game *game, t_color color_f, t_color color_c)
{
	game->color_f = (color_f.r << 16) | (color_f.g << 8) | color_f.b;
	game->color_c = (color_c.r << 16) | (color_c.g << 8) | color_c.b;
}

int	game_loop(t_game *game)
{
	movement(game);
	raycaster(game);
	mlx_put_image_to_window(game->connection, game->window, game->image.ptr_to_img, 0, 0);
	return (0);
}

int	start_game(t_game *game)
{
	mlx_hook(game->window, 17, 0, x_window, game);
	mlx_hook(game->window, 2, 1L<<0, key_press, game);
	mlx_hook(game->window, 3, 1L<<1, key_release, game);
	mlx_loop_hook(game->connection, game_loop, game);
	mlx_loop(game->connection);
	return (0);
}

int	setup_game(t_map *map)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.map = map;
	if (!init_mlx(&game))
		return (0);
	if (!init_player(&game))
		return (0);
	init_color(&game, map->color_f, map->color_c);
	start_game(&game);
	return (1);
}
