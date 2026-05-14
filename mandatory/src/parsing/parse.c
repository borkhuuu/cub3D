/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:25:56 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/14 18:41:27 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include "../../includes/map.h"
#include "../../../libraries/libft/libft.h"

int	handle_id(t_map *map, char **arr)
{
	if (!arr || !arr[0] || !arr[1])
		return (map->err_msg = "Path is misconfigured\n", 0);
	if (!ft_strcmp(arr[0], "NO"))
		if (!handle_path(map, &map->path_no, arr[1], 'N'))
			return (0);
	if (!ft_strcmp(arr[0], "SO"))
		if (!handle_path(map, &map->path_so, arr[1], 'S'))
			return (0);
	if (!ft_strcmp(arr[0], "WE"))
		if (!handle_path(map, &map->path_we, arr[1], 'W'))
			return (0);
	if (!ft_strcmp(arr[0], "EA"))
		if (!handle_path(map, &map->path_ea, arr[1], 'E'))
			return (0);
	if (!ft_strcmp(arr[0], "F"))
		if (!handle_color(map, &map->color_f, arr[1], 'F'))
			return (0);
	if (!ft_strcmp(arr[0], "C"))
		if (!handle_color(map, &map->color_c, arr[1], 'C'))
			return (0);
	free_func(NULL, arr);
	return (1);
}

int	parse_paths(t_map *map)
{
	char	**arr;
	char	**tmp_ptr;

	if (!validate_line(map->line))
		return (1);
	arr = ft_custom_split(map->line, 2);
	if (!arr)
		return (1);
	tmp_ptr = arr;
	tmp_ptr = trim_ws_loop(tmp_ptr);
	if (!tmp_ptr)
		return (free_func(NULL, arr), 0);
	arr = tmp_ptr;
	if (is_path(arr[0]))
	{
		if (!handle_id(map, arr))
			return (free_func(NULL, arr), 0);
	}
	else
	{
		map->in_map = true;
		free_func(NULL, arr);
	}
	return (1);
}
