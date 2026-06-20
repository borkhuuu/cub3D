/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:21:58 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 16:37:51 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libraries/libft/libft.h"
#include "../../includes/map_bonus.h"
#include "../../includes/cub3D_bonus.h"
#include <stdbool.h>

int	validate_characters(t_map *map, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_iswspace(s[i]))
		i++;
	while (s[i])
	{
		if (!is_valid(s[i]))
			return (0);
		if (s[i] == 'X')
			map->exit = s[i];
		if (is_player(s[i]))
		{
			map->player.spawn = s[i];
			map->player.count++;
		}
		else if (is_enemy(s[i]))
			map->enemy.count++;
		i++;
	}
	return (1);
}

char	*replace_tabs(char *line)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (line[i] && ft_iswspace(line[i]))
	{
		if (line[i] == '\t')
		{
			line[i] = ' ';
			line = ft_realloc(line, ft_strlen(line), ft_strlen(line) + 4);
			if (!line)
				return (NULL);
			tmp = ft_strjoin("   ", line);
			if (!tmp)
				return (line);
			free(line);
			line = tmp;
			i += 3;
		}
		i++;
	}
	return (line);
}

int	align_line(char **line)
{
	char	*res;

	if (!line || !*line)
		return (0);
	res = replace_tabs(*line);
	if (!res)
		return (0);
	*line = res;
	return (1);
}

int	parse_map(t_map *map)
{
	char	**tmp;
	char	*s;

	if (!validate_characters(map, map->line))
		return (map->err_msg
			= "Error\nInvalid character found somewhere?!\n", 0);
	tmp = ft_realloc(map->map_arr, (map->map_height)
			* sizeof(char *), (map->map_height + 2) * sizeof(char *));
	if (!tmp)
		return (map->err_msg
			= "Error\nreallocation/growing of map_arr failed\n", 0);
	map->map_arr = tmp;
	if (!align_line(&map->line))
		return (map->err_msg = "Error\nalign_line failed\n", 0);
	s = ft_strdup(map->line);
	if (!s)
		return (map->err_msg = "Error\nft_strdup in parse_map failed\n", 0);
	trim_ws_back(s);
	map->map_arr[map->map_height] = s;
	map->map_height++;
	map->map_arr[map->map_height] = NULL;
	return (1);
}
