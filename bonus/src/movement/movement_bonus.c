/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:35:28 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/01 20:00:53 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/map_bonus.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

void	rotate(t_game *game, int dir, double delta_time)
{
	double	rot_angle;
	double	old_player_x;
	double	old_camera_x;

	if (dir == 0)
		rot_angle = -ROT_ANGLE * delta_time;
	else
		rot_angle = ROT_ANGLE * delta_time;
	old_player_x = game->player.dir.x;
	old_camera_x = game->player.camera.x;
	game->player.dir.x = game->player.dir.x * cos(rot_angle)
		- game->player.dir.y * sin(rot_angle);
	game->player.dir.y = old_player_x * sin(rot_angle)
		+ game->player.dir.y * cos(rot_angle);
	game->player.camera.x = game->player.camera.x * cos(rot_angle)
		- game->player.camera.y * sin(rot_angle);
	game->player.camera.y = old_camera_x * sin(rot_angle)
		+ game->player.camera.y * cos(rot_angle);
}

void	player_move(t_game *game,
		double move_x,
		double move_y,
		double delta_time)
{
	double	len;
	double	new_x;
	double	new_y;

	len = sqrt(move_x * move_x + move_y * move_y);
	if (len > 0)
	{
		move_x = (move_x / len) * SPEED * delta_time;
		move_y = (move_y / len) * SPEED * delta_time;
	}
	new_x = game->player.pos.x + move_x;
	new_y = game->player.pos.y + move_y;
	if (boundary_check_x(game->map, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (boundary_check_y(game->map, new_y, game->player.pos.x))
		game->player.pos.y = new_y;
}

int	enemy_move(t_game *game, double delta_time)
{
	t_doubles	d;

	if (!rerun_bfs(game))
		return (game->map->err_msg = "Error\nBFS failed\n", 0);
	if (!game->enemy.has_target)
		set_target_pos(game);
	if (!game->enemy.has_target)
		return (1);
	d.dx = game->enemy.target_pos.x - game->enemy.pos.x;
	d.dy = game->enemy.target_pos.y - game->enemy.pos.y;
	d.dist_sq = d.dx * d.dx + d.dy * d.dy;
	d.step = MONSTER_SPEED * delta_time;
	if (d.dist_sq < d.step * d.step)
	{
		game->enemy.pos = game->enemy.target_pos;
		game->enemy.has_target = false;
	}
	else
	{
		d.dist = sqrt(d.dist_sq);
		game->enemy.pos.x += (d.dx / d.dist) * d.step;
		game->enemy.pos.y += (d.dy / d.dist) * d.step;
	}
	return (1);
}
