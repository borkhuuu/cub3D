/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:25:56 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 22:38:37 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"

int	handle_id_helper(t_map *map, char **arr)
{
	if (!arr || !arr[0] || !arr[1])
		return (map->err_msg = "Path is misconfigured\n", 0);
	if (!ft_strcmp(arr[0], "1"))
		if (!handle_path(map, &map->path_M_one, arr[1], '1'))
			return (0);
	if (!ft_strcmp(arr[0], "2"))
		if (!handle_path(map, &map->path_M_two, arr[1], '2'))
			return (0);
	if (!ft_strcmp(arr[0], "3"))
		if (!handle_path(map, &map->path_M_three, arr[1], '3'))
			return (0);
	if (!ft_strcmp(arr[0], "4"))
		if (!handle_path(map, &map->path_M_four, arr[1], '4'))
			return (0);
	if (!ft_strcmp(arr[0], "5"))
		if (!handle_path(map, &map->path_M_five, arr[1], '5'))
			return (0);
	if (!ft_strcmp(arr[0], "6"))
		if (!handle_path(map, &map->path_M_six, arr[1], '6'))
			return (0);
	free_func(NULL, arr);
	return (1);
}

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
	if (!ft_strcmp(arr[0], "M"))
		if (!handle_path(map, &map->path_m, arr[1], 'M'))
			return (0);
	if (!ft_strcmp(arr[0], "F"))
		if (!handle_color(map, &map->color_f, arr[1], 'F'))
			return (0);
	if (!ft_strcmp(arr[0], "C"))
		if (!handle_color(map, &map->color_c, arr[1], 'C'))
			return (0);
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
		if (!handle_id(map, arr) || !handle_id_helper(map, arr))
			return (free_func(NULL, arr), 0);
	}
	else
	{
		map->in_map = true;
		free_func(NULL, arr);
	}
	return (1);
}
