/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:38:53 by rheidary          #+#    #+#             */
/*   Updated: 2026/08/01 19:42:50 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include "../../includes/game_bonus.h"
#include "../../../libraries/libft/libft.h"
#include "../../../libraries/mlx/mlx.h"
#include "../../includes/map_bonus.h"

void	load_monster_textures(t_game *game)
{
	game->monster_textures[0]
		= texture_loader(game->connection, game->map->path_m_one);
	if (!game->monster_textures[0].valid)
		return (game->map->err_msg = "Error\nLoading texture '1' failed\n",
			mlx_cleanup(game));
	game->monster_textures[1]
		= texture_loader(game->connection, game->map->path_m_two);
	if (!game->monster_textures[1].valid)
		return (game->map->err_msg = "Error\nLoading texture '2' failed\n",
			mlx_cleanup(game));
	game->monster_textures[2]
		= texture_loader(game->connection, game->map->path_m_three);
	if (!game->monster_textures[2].valid)
		return (game->map->err_msg = "Error\nLoading texture '3' failed\n",
			mlx_cleanup(game));
	load_monster_textures2(game);
}

void	load_monster_textures2(t_game *game)
{
	game->monster_textures[3]
		= texture_loader(game->connection, game->map->path_m_four);
	if (!game->monster_textures[3].valid)
		return (game->map->err_msg = "Error\nLoading texture '4' failed\n",
			mlx_cleanup(game));
	game->monster_textures[4]
		= texture_loader(game->connection, game->map->path_m_five);
	if (!game->monster_textures[4].valid)
		return (game->map->err_msg = "Error\nLoading texture '5' failed\n",
			mlx_cleanup(game));
	game->monster_textures[5]
		= texture_loader(game->connection, game->map->path_m_six);
	if (!game->monster_textures[5].valid)
		return (game->map->err_msg = "Error\nLoading texture '6' failed\n",
			mlx_cleanup(game));
}
