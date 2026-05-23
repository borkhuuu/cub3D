/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:16:10 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/18 13:59:27 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_bonus.h"
#include "../includes/game_bonus.h"
#include "../includes/cub3D_bonus.h"
#include "../../libraries/libft/libft.h"
#include "../../libraries/mlx/mlx.h"
#include <X11/X.h>
#include "../includes/minimap_bonus.h"

int	game_loop(t_game *game)
{
	movement(game);
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
