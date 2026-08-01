/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:42:17 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/01 18:42:30 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libraries/libft/libft.h"
#include "../../../libraries/mlx/mlx.h"
#include "../../includes/map_bonus.h"
#include "../../includes/game_bonus.h"
#include <stdlib.h>

void	free_paths(t_map *map)
{
	if (map->path_no)
	{
		free(map->path_no);
		map->path_no = NULL;
	}
	if (map->path_so)
	{
		free(map->path_so);
		map->path_so = NULL;
	}
	if (map->path_we)
	{
		free(map->path_we);
		map->path_we = NULL;
	}
	if (map->path_ea)
	{
		free(map->path_ea);
		map->path_ea = NULL;
	}
	if (map->path_m)
	{
		free(map->path_m);
		map->path_m = NULL;
	}
}

void	free_func(t_map *map, char **arr)
{
	ft_free_arr(arr);
	if (map)
	{
		if (map->strlen_arr)
		{
			free(map->strlen_arr);
			map->strlen_arr = NULL;
		}
		if (map->map_fd != -1)
		{
			close(map->map_fd);
			map->map_fd = -1;
		}
		if (map->line)
		{
			free(map->line);
			map->line = NULL;
		}
		free_paths(map);
		free_m_paths(map);
		free_m_paths_helper(map);
	}
}

void	free_textures(t_game *game, t_texture textures[4])
{
	if (textures[0].ptr_to_img)
		mlx_destroy_image(game->connection, textures[0].ptr_to_img);
	if (textures[1].ptr_to_img)
		mlx_destroy_image(game->connection, textures[1].ptr_to_img);
	if (textures[2].ptr_to_img)
		mlx_destroy_image(game->connection, textures[2].ptr_to_img);
	if (textures[3].ptr_to_img)
		mlx_destroy_image(game->connection, textures[3].ptr_to_img);
	if (textures[4].ptr_to_img)
		mlx_destroy_image(game->connection, textures[4].ptr_to_img);
}

void	mlx_cleanup(t_game *game)
{
	int	code;

	code = 0;
	free_textures(game, game->textures);
	if (game->enemy.bfs_path)
	{
		free(game->enemy.bfs_path);
		game->enemy.bfs_path = NULL;
	}
	if (game->image.ptr_to_img)
		mlx_destroy_image(game->connection, game->image.ptr_to_img);
	if (game->window)
		mlx_destroy_window(game->connection, game->window);
	if (game->connection)
	{
		mlx_destroy_display(game->connection);
		free(game->connection);
	}
	if (ft_strcmp(game->map->err_msg, "\n"))
	{
		write(2, game->map->err_msg, ft_strlen(game->map->err_msg));
		code = 1;
	}
	free_func(game->map, game->map->map_arr);
	exit (code);
}
