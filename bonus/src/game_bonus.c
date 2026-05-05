#include "../includes/color_bonus.h"
#include "../includes/map_bonus.h"
#include "../includes/game_bonus.h"
#include "../includes/cub3D_bonus.h"
#include "../../libraries/libft/libft.h"
#include "../../libraries/mlx/mlx.h"
#include <X11/X.h>

void	setup_vectors(t_entity *e)
{
	if (e->spawn == 'N')
	{
		vector_setter(&e->dir, 0, -1);
		vector_setter(&e->camera, 0.66, 0);
	}
	if (e->spawn == 'S')
	{
		vector_setter(&e->dir, 0, 1);
		vector_setter(&e->camera, -0.66, 0);
	}
	if (e->spawn == 'W')
	{
		vector_setter(&e->dir, -1, 0);
		vector_setter(&e->camera, 0, -0.66);
	}
	if (e->spawn == 'E')
	{
		vector_setter(&e->dir, 1, 0);
		vector_setter(&e->camera, 0, 0.66);
	}
}

void	init_player(t_game *game)
{
	game->player.pos.x = game->map->player.x + 0.5;
	game->player.pos.y = game->map->player.y + 0.5;
	game->player.spawn = game->map->player_dir;
	setup_vectors(&game->player);
}

void	init_enemy(t_game *game)
{
	game->enemy.pos.x = game->map->enemy.x + 0.5;
	game->enemy.pos.y = game->map->enemy.y + 0.5;
	setup_vectors(&game->enemy);
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
	if (!load_textures(&game))
		return (0);
	init_player(&game);
	init_enemy(&game);
	init_color(&game, map->color_f, map->color_c);
	start_game(&game);
	return (1);
}
