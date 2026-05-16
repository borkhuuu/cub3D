/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:05:58 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/13 15:10:34 by boenkhja         ###   ########.fr       */
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

void	vector_setter(t_vec *v, double x, double y)
{
	v->x = x;
	v->y = y;
}

void	init_player(t_game *game)
{
	vector_setter(&game->player.pos,
		game->map->player.pos.x + 0.5, game->map->player.pos.y + 0.5);
	game->player.spawn = game->map->player.spawn;
	setup_vectors(&game->player);
}

void	init_enemy(t_game *game)
{
	vector_setter(&game->enemy.pos,
		game->map->enemy.pos.x + 0.5, game->map->enemy.pos.y + 0.5);
	game->enemy.spawn = 'N';
	setup_vectors(&game->enemy);
}

void	init_color(t_game *game, t_color color_f, t_color color_c)
{
	game->color_f = (color_f.r << 16) | (color_f.g << 8) | color_f.b;
	game->color_c = (color_c.r << 16) | (color_c.g << 8) | color_c.b;
}
