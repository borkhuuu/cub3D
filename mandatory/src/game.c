/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:53:54 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/11 23:59:06 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/game.h"
#include "../includes/cub3D.h"
#include "../../libraries/libft/libft.h"
#include "../../libraries/mlx/mlx.h"
#include <X11/X.h>

int	game_loop(t_game *game)
{
	movement(game);
	raycaster(game);
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
	init_mlx(&game);
	if (!load_textures(&game))
		return (0);
	init_player(&game);
	init_color(&game, map->color_f, map->color_c);
	start_game(&game);
	return (1);
}
