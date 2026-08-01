/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:07:07 by rheidary          #+#    #+#             */
/*   Updated: 2026/08/01 19:11:00 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map_bonus.h"
#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../includes/minimap_bonus.h"
#include "../../../libraries/libft/libft.h"
#include "../../../libraries/mlx/mlx.h"
#include <X11/X.h>
#include <stdbool.h>
#include <math.h>

int	mouse_hook(int x, int y, t_game *game)
{
	int			delta_x;
	double		rot_speed;
	double		old_dir_x;
	double		old_camera_x;

	(void)y;
	delta_x = x - (WIDTH / 2);
	if (delta_x == 0)
		return (0);
	rot_speed = 0.002;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = old_dir_x * cos(delta_x * rot_speed)
		- game->player.dir.y * sin(delta_x * rot_speed);
	game->player.dir.y = old_dir_x * sin(delta_x * rot_speed)
		+ game->player.dir.y * cos(delta_x * rot_speed);
	old_camera_x = game->player.camera.x;
	game->player.camera.x = old_camera_x * cos(delta_x * rot_speed)
		- game->player.camera.y * sin(delta_x * rot_speed);
	game->player.camera.y = old_camera_x * sin(delta_x * rot_speed)
		+ game->player.camera.y * cos(delta_x * rot_speed);
	mlx_mouse_move(game->connection, game->window, WIDTH / 2, HEIGHT / 2);
	return (0);
}

void	init_mouse(t_game *game)
{
	mlx_mouse_hide(game->connection, game->window);
	mlx_mouse_move(game->connection, game->window, WIDTH / 2, HEIGHT / 2);
}
