/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:35:28 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/06 11:57:31 by boenkhja         ###   ########.fr       */
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

void	set_target_pos(t_game *game)
{
	size_t	i;
	
	i = game->enemy.path_index;
	if (!game->enemy.bfs_path || i >= game->enemy.bfs_path_len)
		return ;
	game->enemy.pos = (t_vec){(int)game->enemy.pos.x + 0.5, (int)game->enemy.pos.y + 0.5};
	if (game->enemy.bfs_path[i] == 'N')
	{
		game->enemy.target_pos = (t_vec){(int)game->enemy.pos.x + 0.5, (int)game->enemy.pos.y - 1 + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	else if (game->enemy.bfs_path[i] == 'S')
	{
		game->enemy.target_pos = (t_vec){(int)game->enemy.pos.x + 0.5, (int)game->enemy.pos.y + 1 + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	else if (game->enemy.bfs_path[i] == 'W')
	{
		game->enemy.target_pos = (t_vec){(int)game->enemy.pos.x - 1 + 0.5, (int)game->enemy.pos.y + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	else if (game->enemy.bfs_path[i] == 'E')
	{
		game->enemy.target_pos = (t_vec){(int)game->enemy.pos.x + 1 + 0.5, (int)game->enemy.pos.y + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	game->enemy.path_index = i;
}

int	enemy_move(t_game *game, double delta_time)
{
	double	dx;
	double	dy;
	double	step;
	double	dist;
	double	dist_sq;
	
	if (!rerun_bfs(game))
		return (game->map->err_msg = "Error\nBFS failed\n", 0);
	if (!game->enemy.has_target)
		set_target_pos(game);
	if (!game->enemy.has_target)
		return (1);
	dx = game->enemy.target_pos.x - game->enemy.pos.x;
	dy = game->enemy.target_pos.y - game->enemy.pos.y;
	dist_sq = dx * dx + dy * dy;
	step = MONSTER_SPEED * delta_time;
	if (dist_sq < step * step)
	{
		game->enemy.pos = game->enemy.target_pos;
		game->enemy.has_target = false;
	}
	else
	{
		dist = sqrt(dist_sq);
		game->enemy.pos.x += (dx / dist) * step;
		game->enemy.pos.y += (dy / dist) * step;
	}
	return (1);
}