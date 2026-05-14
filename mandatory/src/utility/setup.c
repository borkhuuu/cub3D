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

#include "../../includes/game.h"
#include "../../includes/cub3D.h"
#include "../../includes/map.h"

void	setup_player_vectors(t_player *player)
{
	if (player->spawn == 'N')
	{
		vector_setter(&player->dir, 0, -1);
		vector_setter(&player->camera, 0.66, 0);
	}
	if (player->spawn == 'S')
	{
		vector_setter(&player->dir, 0, 1);
		vector_setter(&player->camera, -0.66, 0);
	}
	if (player->spawn == 'W')
	{
		vector_setter(&player->dir, -1, 0);
		vector_setter(&player->camera, 0, -0.66);
	}
	if (player->spawn == 'E')
	{
		vector_setter(&player->dir, 1, 0);
		vector_setter(&player->camera, 0, 0.66);
	}
}

void	vector_setter(t_vec *v, double x, double y)
{
	v->x = x;
	v->y = y;
}

void	init_player(t_game *game)
{
	game->player.pos.x = game->map->player.x + 0.5;
	game->player.pos.y = game->map->player.y + 0.5;
	game->player.spawn = game->map->player_dir;
	setup_player_vectors(&game->player);
}

void	init_color(t_game *game, t_color color_f, t_color color_c)
{
	game->color_f = (color_f.r << 16) | (color_f.g << 8) | color_f.b;
	game->color_c = (color_c.r << 16) | (color_c.g << 8) | color_c.b;
}
