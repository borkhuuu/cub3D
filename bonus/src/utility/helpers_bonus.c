/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:49:47 by boenkhja          #+#    #+#             */
/*   Updated: 2026/08/01 19:34:21 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include "../../includes/game_bonus.h"
#include "../../includes/map_bonus.h"
#include "../../../libraries/libft/libft.h"
#include <stddef.h>
#include <sys/time.h>

int	get_texture_pixel_color(t_texture t, int x, int y)
{
	return (*(int *)(t.ptr_to_pixel + (y * t.line_len + x * (t.bpp / 8))));
}

void	ft_pixel_put(t_game *game, int x, int y, int colour)
{
	char	*pixel_to_manipulate;

	pixel_to_manipulate = game->image.ptr_to_pixel
		+ (y * game->image.line_len + x * (game->image.bpp / 8));
	*(unsigned int *)pixel_to_manipulate = colour;
}

int	init_strlen_arr(t_map *map)
{
	size_t	i;

	i = 0;
	if (!map)
		return (0);
	map->strlen_arr = ft_calloc(map->map_height, sizeof(size_t));
	if (!map->strlen_arr)
		return (0);
	while (map->map_arr[i])
	{
		map->strlen_arr[i] = ft_strlen(map->map_arr[i]);
		i++;
	}
	return (1);
}

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + (tv.tv_usec / 1000000.0));
}

void	end_game(t_game *game, bool flag)
{
	if (flag)
	{
		write(1, "Congratulations, you won!\n", 27);
		mlx_cleanup(game);
	}
	else
	{
		write(1, "GAME OVER!\n", 12);
		mlx_cleanup(game);
	}
}
