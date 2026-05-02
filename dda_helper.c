#include "game.h"
#include <math.h>
#include "libft/libft.h"

void	cast_ray(t_raycast *ray, t_game *game, int x)
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
    	ray->perp_dist = (ray->map_x - game->player.pos.x + (1 - ray->step_x) / 2.0) / ray->ray_dir.x;
	else
    	ray->perp_dist = (ray->map_y - game->player.pos.y + (1 - ray->step_y) / 2.0) / ray->ray_dir.y;
	if (ray->perp_dist < 0.0001)
		ray->perp_dist = 0.0001;
	ray->wall_height = (HEIGHT / ray->perp_dist);
	if (ray->side == 0)
		ray->wall_hit = game->player.pos.y + ray->perp_dist * ray->ray_dir.y;
	else
	 	ray->wall_hit = game->player.pos.x + ray->perp_dist * ray->ray_dir.x;
	ray->wall_hit -= floor(ray->wall_hit);
	//printf("perp dist: %f wall_height: %d\n", ray->perp_dist, ray->wall_height);
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
