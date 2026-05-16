/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:34:10 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 16:34:11 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include <X11/keysym.h>

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->movement.w = true;
	if (keycode == XK_a)
		game->movement.a = true;
	if (keycode == XK_s)
		game->movement.s = true;
	if (keycode == XK_d)
		game->movement.d = true;
	if (keycode == XK_Left)
		game->movement.left = true;
	if (keycode == XK_Right)
		game->movement.right = true;
	if (keycode == XK_Escape)
		mlx_cleanup(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->movement.w = false;
	if (keycode == XK_a)
		game->movement.a = false;
	if (keycode == XK_s)
		game->movement.s = false;
	if (keycode == XK_d)
		game->movement.d = false;
	if (keycode == XK_Left)
		game->movement.left = false;
	if (keycode == XK_Right)
		game->movement.right = false;
	return (0);
}

void	movement(t_game *game)
{
	if (game->movement.w)
		forward(game);
	if (game->movement.a)
		left(game);
	if (game->movement.s)
		backward(game);
	if (game->movement.d)
		right(game);
	if (game->movement.left)
		rotate(game, 0);
	if (game->movement.right)
		rotate(game, 1);
}
