/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_helper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:49:20 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/14 13:21:33 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/map_bonus.h"
#include <math.h>
#include "../../../libraries/libft/libft.h"

void	cast_ray(t_raycast *ray, t_game *game, size_t x)
{
	ft_memset(ray, 0, sizeof(t_raycast));
	calculate_ray_dir(ray, &game->player, x);
	calculate_delta_dist(ray);
	calculate_side_dist(ray, &game->player);
	ray->map_x = (int)game->player.pos.x;
	ray->map_y = (int)game->player.pos.y;
	init_step_dir(ray, ray->ray_dir);
}

void	calculate_wall_height(t_raycast *ray, t_game *game)
{
	if (ray->side == 0)
		ray->perp_dist = (ray->map_x - game->player.pos.x
				+ (1 - ray->step_x) / 2.0) / ray->ray_dir.x;
	else
		ray->perp_dist = (ray->map_y - game->player.pos.y
				+ (1 - ray->step_y) / 2.0) / ray->ray_dir.y;
	if (ray->perp_dist < 0.0001)
		ray->perp_dist = 0.0001;
	ray->wall_height = (HEIGHT / ray->perp_dist);
	if (ray->side == 0)
		ray->wall_hit = game->player.pos.y + ray->perp_dist * ray->ray_dir.y;
	else
		ray->wall_hit = game->player.pos.x + ray->perp_dist * ray->ray_dir.x;
	ray->wall_hit -= floor(ray->wall_hit);
}

void	init_step_dir(t_raycast *ray, t_vec	ray_dir)
{
	if (ray_dir.x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray_dir.y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

bool	is_entity_near_door(t_game *game, int door_x, int door_y)
{
	float	dist_player;
	float	dist_enemy;
	
	dist_player = sqrt(pow(game->player.pos.x - (door_x + 0.5), 2) +
				pow(game->player.pos.y - (door_y + 0.5), 2));
	if (dist_player < 1.5)
		return (true);
	dist_enemy = sqrt(pow(game->enemy.pos.x - (door_x + 0.5), 2) +
				pow(game->enemy.pos.y - (door_y + 0.5), 2));
	if (dist_enemy < 1.5)
		return (true);
	return (false);
}

void	run_dda(t_raycast *ray, t_game *game)
{
	char	cell;

	while (1)
	{
		cell = game->map->map_arr[ray->map_y][ray->map_x];
		if (cell == '1')
			break;
		if (cell == 'D' && !is_entity_near_door(game, ray->map_x, ray->map_y))
			break;
		move_ray(ray);
	}
}