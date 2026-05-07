/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:40:03 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/07 17:39:07 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"
#include "../../includes/game_bonus.h"
#include "../../includes/vec_bonus.h"
#include "../../includes/map_bonus.h"
#include <math.h>

void	calculate_ray_dir(t_raycast *ray, t_entity *player, size_t x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = player->dir.x + player->camera.x * camera_x;
	ray->ray_dir.y = player->dir.y + player->camera.y * camera_x;
}

void	calculate_side_dist(t_raycast *ray, t_entity *player)
{
	double	frac_x;
	double	frac_y;

	frac_x = player->pos.x - (int)player->pos.x;
	frac_y = player->pos.y - (int)player->pos.y;
	if (ray->ray_dir.x == 0)
		ray->side_dist.x = INFINITY;
	else if (ray->ray_dir.x < 0)
		ray->side_dist.x = frac_x * ray->delta_dist.x;
	else
		ray->side_dist.x = (1.0 - frac_x) * ray->delta_dist.x;
	if (ray->ray_dir.y == 0)
		ray->side_dist.y = INFINITY;
	else if (ray->ray_dir.y < 0)
		ray->side_dist.y = frac_y * ray->delta_dist.y;
	else
		ray->side_dist.y = (1.0 - frac_y) * ray->delta_dist.y;
}

void	calculate_delta_dist(t_raycast *ray)
{
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

void	move_ray(t_raycast *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

int	raycaster(t_game *game)
{
	t_raycast	ray;
	t_texture	t;
	size_t		x;

	x = 0;
	while (x < WIDTH)
	{
		cast_ray(&ray, game, x);
		while (game->map->map_arr[ray.map_y][ray.map_x] != '1')
			move_ray(&ray);
		t = select_texture(game, ray);
		calculate_wall_height(&ray, game);
		game->pdist_buffer[x] = ray.perp_dist;
		game->ray = ray;
		draw(game, t, ray.wall_height, x);
		x++;
	}
	draw_monster(game, game->textures[4]);
	return (1);
}
