/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_helper2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:59:48 by rheidary          #+#    #+#             */
/*   Updated: 2026/08/01 19:47:20 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include <X11/keysym.h>
#include <stdbool.h>

void	movement2(t_game *game, double delta_time)
{
	if (game->movement.left)
		rotate(game, 0, delta_time);
	if (game->movement.right)
		rotate(game, 1, delta_time);
}

void	set_target_pos(t_game *game)
{
	size_t	i;

	i = game->enemy.path_index;
	if (!game->enemy.bfs_path || i >= game->enemy.bfs_path_len)
		return ;
	game->enemy.pos = (t_vec)
	{(int)game->enemy.pos.x + 0.5, (int)game->enemy.pos.y + 0.5};
	if (game->enemy.bfs_path[i] == 'N')
	{
		game->enemy.target_pos = (t_vec)
		{(int)game->enemy.pos.x + 0.5, (int)game->enemy.pos.y - 1 + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	else if (game->enemy.bfs_path[i] == 'S')
	{
		game->enemy.target_pos = (t_vec)
		{(int)game->enemy.pos.x + 0.5, (int)game->enemy.pos.y + 1 + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	set_target_pos2(game, i);
}

void	set_target_pos2(t_game *game, size_t i)
{
	if (game->enemy.bfs_path[i] == 'W')
	{
		game->enemy.target_pos = (t_vec)
		{(int)game->enemy.pos.x - 1 + 0.5, (int)game->enemy.pos.y + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	else if (game->enemy.bfs_path[i] == 'E')
	{
		game->enemy.target_pos = (t_vec)
		{(int)game->enemy.pos.x + 1 + 0.5, (int)game->enemy.pos.y + 0.5};
		game->enemy.has_target = true;
		i++;
	}
	game->enemy.path_index = i;
}
