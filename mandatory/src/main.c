/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:44:16 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/05 19:44:17 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../../libraries/libft/libft.h"
#include "../includes/map.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->color_f.r = -1;
	map->color_f.g = -1;
	map->color_f.b = -1;
	map->color_c.r = -1;
	map->color_c.g = -1;
	map->color_c.b = -1;
	map->err_msg = "\n";
}

int	parse_until_map(t_map *map)
{
	if (!map)
		return (0);
	map->line = get_next_line(map->map_fd);
	while (map->line && !map->in_map)
	{
		if (!parse_paths(map))
			return (0);
		else if (map->in_map)
			break ;
		free(map->line);
		map->line = get_next_line(map->map_fd);
	}
	if (missing_path(map))
		return (0);
	return (1);
}

int	parse_remainder(t_map *map)
{
	while (map->line)
	{
		if (!parse_map(map))
			return (0);
		free(map->line);
		map->line = get_next_line(map->map_fd);
	}
	if (!validate_map(map))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (write(2, "Error\nArguments not exactly 1\n", 30), 1);
	init_map(&map);
	if (!validate_path(&map, av[1], ".cub"))
		return (write(2, map.err_msg, ft_strlen(map.err_msg)), 1);
	map.map_fd = open(av[1], O_RDONLY);
	if (!parse_until_map(&map))
		return (get_next_line(-1), write(2, map.err_msg,
				ft_strlen(map.err_msg)), free_func(&map, NULL), 1);
	if (!parse_remainder(&map))
		return (get_next_line(-1), write(2, map.err_msg,
				ft_strlen(map.err_msg)), free_func(&map, map.map_arr), 1);
	close(map.map_fd);
	if (!setup_game(&map))
		return (free_func(&map, map.map_arr), 1);
	free_func(&map, map.map_arr);
	return (0);
}
