/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:46:55 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/05 16:49:14 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/map.h"
#include <math.h>

void	rotate(t_game *game, int dir)
{
	double	rot_angle;
	double	old_player_x;
	double	old_camera_x;

	if (dir == 0)
		rot_angle = -ROT_ANGLE;
	else
		rot_angle = ROT_ANGLE;
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

void	forward(t_game *game)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = game->map->map_arr;
	new_x = game->player.pos.x + game->player.dir.x * SPEED;
	new_y = game->player.pos.y + game->player.dir.y * SPEED;
	if (map[(int)game->player.pos.y][(int)(new_x - PADDING)] != '1'
			&& map[(int)game->player.pos.y][(int)(new_x + PADDING)] != '1')
		game->player.pos.x = new_x;
	if (map[(int)(new_y - PADDING)][(int)game->player.pos.x] != '1'
			&& map[(int)(new_y + PADDING)][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}

void	backward(t_game *game)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = game->map->map_arr;
	new_x = game->player.pos.x - game->player.dir.x * SPEED;
	new_y = game->player.pos.y - game->player.dir.y * SPEED;
	if (map[(int)game->player.pos.y][(int)(new_x - PADDING)] != '1'
			&& map[(int)game->player.pos.y][(int)(new_x + PADDING)] != '1')
		game->player.pos.x = new_x;
	if (map[(int)(new_y - PADDING)][(int)game->player.pos.x] != '1'
			&& map[(int)(new_y + PADDING)][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}

void	left(t_game *game)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = game->map->map_arr;
	new_x = game->player.pos.x - game->player.camera.x * SPEED;
	new_y = game->player.pos.y - game->player.camera.y * SPEED;
	if (map[(int)game->player.pos.y][(int)(new_x + PADDING)] != '1'
			&& map[(int)game->player.pos.y][(int)(new_x - PADDING)] != '1')
		game->player.pos.x = new_x;
	if (map[(int)(new_y + PADDING)][(int)game->player.pos.x] != '1'
			&& map[(int)(new_y - PADDING)][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}

void	right(t_game *game)
{
	double	new_x;
	double	new_y;
	char	**map;

	map = game->map->map_arr;
	new_x = game->player.pos.x + game->player.camera.x * SPEED;
	new_y = game->player.pos.y + game->player.camera.y * SPEED;
	if (map[(int)game->player.pos.y][(int)(new_x + PADDING)] != '1'
			&& map[(int)game->player.pos.y][(int)(new_x - PADDING)] != '1')
		game->player.pos.x = new_x;
	if (map[(int)(new_y + PADDING)][(int)game->player.pos.x] != '1'
			&& map[(int)(new_y - PADDING)][(int)game->player.pos.x] != '1')
		game->player.pos.y = new_y;
}
