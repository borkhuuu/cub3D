#include "cub3D.h"
#include "game.h"
#include "libft/libft.h"
#include "vec.h"
#include "map.h"
#include <math.h>

void	calculate_ray_dir(t_raycast *ray, t_player *player, int x)
{
	double	camera_x;
	
	camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = player->dir.x + player->camera.x * camera_x;
	ray->ray_dir.y = player->dir.y + player->camera.y * camera_x;
}

void	calculate_side_dist(t_raycast *ray, t_player *player)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = left_up(player->pos.x,(ray->ray_dir.y / ray->ray_dir.x));
	else if (ray->ray_dir.x > 0)
		ray->side_dist.x = right_down(player->pos.x, (ray->ray_dir.y / ray->ray_dir.x));
	else if (ray->ray_dir.x == 0)
		ray->side_dist.x = INFINITY;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = left_up(player->pos.y, (ray->ray_dir.x / ray->ray_dir.y));
	else if (ray->ray_dir.y > 0)
		ray->side_dist.y = right_down(player->pos.y, (ray->ray_dir.x / ray->ray_dir.y));
	else if (ray->ray_dir.y == 0)
		ray->side_dist.y = INFINITY;
}

void	calculate_delta_dist(t_raycast *ray)
{
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

int	raycaster(t_game *game)
{
	t_raycast	ray;
	int			x;
	
	x = 0;
	while (x < WIDTH)
	{
		cast_ray(&ray, game, x);
		while (game->map->map_arr[ray.map_y][ray.map_x] != '1')
		{
			if (ray.side_dist.x < ray.side_dist.y)
			{
				ray.side_dist.x += ray.delta_dist.x;
				ray.map_x += ray.step_x;
				ray.side = 0;
			}
			else
			{
				ray.side_dist.y += ray.delta_dist.y;
				ray.map_y += ray.step_y;
				ray.side = 1;
			}
		}
		calculate_wall_height(&ray, game);
		draw(game, ray.wall_height, x);
		x++;
	}
	return (1);
}

