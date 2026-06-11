/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:16:10 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/01 16:56:42 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_bonus.h"
#include "../includes/game_bonus.h"
#include "../includes/cub3D_bonus.h"
#include "../includes/minimap_bonus.h"
#include "../../libraries/libft/libft.h"
#include "../../libraries/mlx/mlx.h"
#include <X11/X.h>
#include <stdbool.h>

bool	enemy_caught_player(t_game *game)
{
	double	dx;
	double	dy;

	dx = game->player.pos.x - game->enemy.pos.x;
	dy = game->player.pos.y - game->enemy.pos.y;
	if (dx * dx + dy * dy < KILL_DISTANCE * KILL_DISTANCE)
		return (true);
	else
		return (false);
}

int	game_loop(t_game *game)
{
	double	now;
	double	delta_time;
	
	now = get_time();
	delta_time = now - game->last_time;
	game->last_time = now;
	if (delta_time > 0.05)
		delta_time = 0.05;
	movement(game, delta_time);
	if (!enemy_move(game, delta_time))
		return (game->map->err_msg = "Error\nBFS failed\n", 0);
	if (enemy_caught_player(game))
	{
		write(1, "GAME OVER!\n", 12);
		mlx_cleanup(game);
	}
	raycaster(game);
	minimap(game);
	mlx_put_image_to_window(game->connection, game->window,
		game->image.ptr_to_img, 0, 0);
	return (0);
}

int	start_game(t_game *game)
{
	mlx_hook(game->window, 17, 0, x_window, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->connection, game_loop, game);
	mlx_loop(game->connection);
	return (0);
}

void	setup_game(t_map *map)
{
	t_game	game;
	
	ft_memset(&game, 0, sizeof(t_game));
	game.map = map;
	init_mlx(&game);
	load_textures(&game);
	init_player(&game);
	init_enemy(&game);
	init_color(&game, map->color_f, map->color_c);
	start_game(&game);
}
