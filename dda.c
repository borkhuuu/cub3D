#include "cub3D.h"
#include "game.h"
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
		ray->ray_dir.y = INFINITY;
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

int	raycaster(t_game *game)
{
	t_raycast	ray;
	t_texture	t;
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
		t = select_texture(game, ray);
		calculate_wall_height(&ray, game);
		game->ray = ray;
		draw(game, t, ray.wall_height, x);
		x++;
	}
	return (1);
}

