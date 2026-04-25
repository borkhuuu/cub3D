#include "game.h"
#include <math.h>
#include "libft/libft.h"

void	cast_ray(t_raycast *ray, t_game *game, int x)
{
	ft_memset(ray, 0, sizeof(t_raycast));
	calculate_ray_dir(ray, &game->player, x);
	calculate_side_dist(ray, &game->player);
	calculate_delta_dist(ray);
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
	ray->wall_height = (int)(HEIGHT / ray->perp_dist);
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

double	left_up(double ppos, double ratio)
{
	double	hypotenuse;
	double	xy_dist;
	
	ppos = ppos - (int)ppos;
	xy_dist = ppos * ratio;
	hypotenuse = sqrt(pow(ppos, 2) + pow(xy_dist, 2));
	return (hypotenuse);
}

double	right_down(double ppos, double ratio)
{
	double	hypotenuse;
	double	xy_dist;
	
	ppos = ppos - (int)ppos;
	xy_dist = (1 - ppos) * ratio;
	hypotenuse = sqrt(pow(1 - ppos, 2) + pow(xy_dist, 2));
	return (hypotenuse);
}
