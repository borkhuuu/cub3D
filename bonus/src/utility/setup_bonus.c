/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:15:31 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/07 14:15:54 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include "../../includes/map_bonus.h"

void	setup_vectors(t_entity *e)
{
	if (e->spawn == 'N')
	{
		vector_setter(&e->dir, 0, -1);
		vector_setter(&e->camera, 0.66, 0);
	}
	if (e->spawn == 'S')
	{
		vector_setter(&e->dir, 0, 1);
		vector_setter(&e->camera, -0.66, 0);
	}
	if (e->spawn == 'W')
	{
		vector_setter(&e->dir, -1, 0);
		vector_setter(&e->camera, 0, -0.66);
	}
	if (e->spawn == 'E')
	{
		vector_setter(&e->dir, 1, 0);
		vector_setter(&e->camera, 0, 0.66);
	}
}

void	init_player(t_game *game)
{
	vector_setter(&game->player.pos,
		game->map->player.x + 0.5, game->map->player.y + 0.5);
	game->player.spawn = game->map->player_dir;
	setup_vectors(&game->player);
}

void	init_enemy(t_game *game)
{
	vector_setter(&game->enemy.pos,
		game->map->enemy.x + 0.5, game->map->enemy.y + 0.5);
	game->enemy.spawn = 'N';
	setup_vectors(&game->enemy);
}

void	init_color(t_game *game, t_color color_f, t_color color_c)
{
	game->color_f = (color_f.r << 16) | (color_f.g << 8) | color_f.b;
	game->color_c = (color_c.r << 16) | (color_c.g << 8) | color_c.b;
}
