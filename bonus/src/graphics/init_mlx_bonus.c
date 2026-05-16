/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:32:45 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 16:32:45 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include "../../includes/game_bonus.h"
#include "../../includes/map_bonus.h"
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

int	init_mlx(t_game *game)
{
	game->connection = mlx_init();
	if (!game->connection)
		return (game->map->err_msg = "Error\nmlx_init has failed\n",
			mlx_cleanup(game), 0);
	game->window = mlx_new_window(game->connection, WIDTH, HEIGHT, "cub3D");
	if (!game->window)
		return (game->map->err_msg = "Error\nmlx_new_window has failed\n",
			mlx_cleanup(game), 0);
	game->image.ptr_to_img = mlx_new_image(game->connection, WIDTH, HEIGHT);
	if (!game->image.ptr_to_img)
		return (game->map->err_msg = "Error\nmlx_new_image has failed\n",
			mlx_cleanup(game), 0);
	game->image.ptr_to_pixel = mlx_get_data_addr(game->image.ptr_to_img,
			&game->image.bpp, &game->image.line_len, &game->image.endian);
	if (!game->image.ptr_to_pixel)
		return (game->map->err_msg = "Error\nmlx_get_data_addr has failed\n",
			mlx_cleanup(game), 0);
	return (1);
}
