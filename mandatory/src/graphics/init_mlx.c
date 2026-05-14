/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:59:12 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/14 18:43:23 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include "../../includes/game.h"
#include "../../includes/map.h"
#include "../../../libraries/mlx/mlx.h"
#include <X11/keysym.h>

int	x_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_cleanup(game);
	return (0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_cleanup(game);
	return (0);
}

void	init_mlx(t_game *game)
{
	game->connection = NULL;//mlx_init();
	if (!game->connection)
	{
		game->map->err_msg = "Error\nmlx_init has failed\n";
		mlx_cleanup(game);
	}
	game->window = mlx_new_window(game->connection, WIDTH, HEIGHT, "cub3D");
	if (!game->window)
	{
		game->map->err_msg = "Error\nmlx_new_window has failed\n";
		mlx_cleanup(game);
	}
	game->image.ptr_to_img = mlx_new_image(game->connection, WIDTH, HEIGHT);
	if (!game->image.ptr_to_img)
	{
		game->map->err_msg = "Error\nmlx_new_image has failed\n";
		mlx_cleanup(game);
	}
	game->image.ptr_to_pixel = mlx_get_data_addr(game->image.ptr_to_img,
			&game->image.bpp, &game->image.line_len, &game->image.endian);
	if (!game->image.ptr_to_pixel)
	{
		game->map->err_msg = "Error\nmlx_get_data_addr has failed\n";
		mlx_cleanup(game);
	}
}
