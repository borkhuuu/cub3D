/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_m_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:42:32 by rheidary          #+#    #+#             */
/*   Updated: 2026/08/01 18:52:58 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libraries/libft/libft.h"
#include "../../../libraries/mlx/mlx.h"
#include "../../includes/map_bonus.h"
#include "../../includes/game_bonus.h"
#include <stdlib.h>

void	free_m_paths_helper(t_map *map)
{
	if (map->path_m_five)
	{
		free(map->path_m_five);
		map->path_m_five = NULL;
	}
	if (map->path_m_six)
	{
		free(map->path_m_six);
		map->path_m_six = NULL;
	}
}

void	free_m_paths(t_map *map)
{
	if (map->path_m_one)
	{
		free(map->path_m_one);
		map->path_m_one = NULL;
	}
	if (map->path_m_two)
	{
		free(map->path_m_two);
		map->path_m_two = NULL;
	}
	if (map->path_m_three)
	{
		free(map->path_m_three);
		map->path_m_three = NULL;
	}
	if (map->path_m_four)
	{
		free(map->path_m_four);
		map->path_m_four = NULL;
	}
}
