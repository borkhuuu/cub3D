/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:23:59 by boenkhja          #+#    #+#             */
/*   Updated: 2026/05/16 16:23:59 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# define WIDTH 1600 
# define HEIGHT 900
# define SPEED 0.1
# define ROT_ANGLE 0.03
# define PADDING 0.1
# include "vec_bonus.h"
# include "cub3D_bonus.h"
# include <stdbool.h>
# include <stddef.h>

typedef struct s_map	t_map;

typedef struct s_entity
{
	t_vec	pos;
	t_vec	dir;
	t_vec	camera;
	size_t	count;
	char	spawn;
	bool	set;
}	t_entity;

typedef struct s_image
{
	void	*ptr_to_img;
	char	*ptr_to_pixel;
	int		line_len;
	int		bpp;
	int		endian;
}	t_image;

typedef struct s_movement
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_movement;

typedef struct s_raycast
{
	t_vec	ray_dir;
	t_vec	side_dist;
	t_vec	delta_dist;
	double	perp_dist;
	double	wall_hit;
	int		step_x;
	int		step_y;
	int		side;
	int		map_x;
	int		map_y;
	int		wall_height;
}	t_raycast;

typedef struct s_game
{
	t_map		*map;
	t_texture	textures[5];
	t_raycast	ray;
	t_image		image;
	void		*connection;
	void		*window;
	t_entity	player;
	t_entity	enemy;
	double		pdist_buffer[WIDTH];
	t_movement	movement;
	int			color_f;
	int			color_c;
}	t_game;

/*					game_bonus.c					*/
int		start_game(t_game *game);
int		setup_game(t_map *map);

/*					dda_bonus.c					*/
int		raycaster(t_game *game);
void	calculate_delta_dist(t_raycast *ray);
void	calculate_side_dist(t_raycast *ray, t_entity *player);
void	calculate_ray_dir(t_raycast *ray, t_entity *player, size_t x);

/*					dda_helper_bonus.c			*/
void	cast_ray(t_raycast *ray, t_game *game, size_t x);
void	calculate_wall_height(t_raycast *ray, t_game *game);
void	init_step_dir(t_raycast *ray, t_vec	ray_dir);

/*					movement_bonus.c					*/
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	movement(t_game *game);

/*					movement_helper_bonus.c			*/
void	rotate(t_game *game, int dir);
void	forward(t_game *game);
void	backward(t_game *game);
void	left(t_game *game);
void	right(t_game *game);

#endif
