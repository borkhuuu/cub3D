/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:19:32 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 16:35:39 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include "../../includes/cub3D_bonus.h"

void	save_rgb(t_color *color)
{
	color->r = ft_atoi(color->values[0]);
	color->g = ft_atoi(color->values[1]);
	color->b = ft_atoi(color->values[2]);
	color->set = true;
	free_func(NULL, color->values);
}

int	process_color(char *color)
{
	size_t	i;
	int		num;

	i = 0;
	if (!color)
		return (0);
	while ((color[i] && ft_iswspace(color[i]))
		|| (color[i] && ft_isdigit(color[i])))
		i++;
	while (color[i] && ft_isdigit(color[i]))
		i++;
	if (color[i])
		return (0);
	num = ft_atoi(color);
	if (num > 255 || num < 0)
		return (0);
	return (1);
}

int	validate_color(t_map *map, t_color *color, char *rgb)
{
	char	**tmp;
	size_t	size;

	tmp = ft_split(rgb, ',');
	if (!tmp)
		return (map->err_msg
			= "Error\nft_split returned NULL in validate_color\n", 0);
	size = ft_arr_size((const char **)tmp);
	if (size != 3)
		return (map->err_msg = "Error\nColor values are not exactly 3\n",
			free_func(NULL, tmp), 0);
	size = 0;
	while (tmp[size])
	{
		if (!check_format(tmp[size]))
			return (map->err_msg = "Error\nColor has wrong format\n",
				free_func(NULL, tmp), 0);
		if (!process_color(tmp[size]))
			return (map->err_msg = "Error\nColor value not between 0-255\n",
				free_func(NULL, tmp), 0);
		size++;
	}
	color->values = tmp;
	return (1);
}

int	handle_color(t_map *map, t_color *color, char *line, char type)
{
	if (check_comma(line) != 2)
		return (map->err_msg = "Error\nComma count not 2\n", 0);
	if (!validate_color(map, color, line))
		return (0);
	if (color->set)
	{
		if (type == 'F')
			map->err_msg = "Error\nDuplicate Floor colors\n";
		else if (type == 'C')
			map->err_msg = "Error\nDuplicate Ceiling colors\n";
		return (0);
	}
	save_rgb(color);
	return (1);
}
