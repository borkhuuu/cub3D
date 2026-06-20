/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:23:59 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/14 13:19:39 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# define WIDTH 1600 
# define HEIGHT 900
# define SPEED 4.5
# define MONSTER_SPEED 3.0
# define ROT_ANGLE 2.7
# define PADDING 0.12
# define BFS_THRESHOLD 0.5
# define MOVE_INTERVAL 1.0
# define KILL_DISTANCE 0.7
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
	t_vec	target_pos;
	t_vec	last_bfs_player_pos;
	bool	has_target;
	char	*bfs_path;
	size_t	bfs_path_len;
	size_t	path_index;
	double	move_accumulation;
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

typedef struct s_bfs
{
	t_map		*map;
	t_vec_int	*queue;
	char		*came_from;
}	t_bfs;

typedef struct s_game
{
	void		*connection;
	void		*window;
	t_map		*map;
	t_texture	textures[5];
	t_texture	monster_textures[6];
	t_raycast	ray;
	t_image		image;
	t_entity	player;
	t_entity	enemy;
	t_movement	movement;
	double		pdist_buffer[WIDTH];
	double		anim_timer;
	int			anim_frame;
	double		last_time;
	int			color_f;
	int			color_c;
}	t_game;

/*					game_bonus.c				*/
int		start_game(t_game *game);
void	setup_game(t_map *map);

/*					dda_bonus.c					*/
int		raycaster(t_game *game);
void	calculate_delta_dist(t_raycast *ray);
void	calculate_side_dist(t_raycast *ray, t_entity *player);
void	calculate_ray_dir(t_raycast *ray, t_entity *player, size_t x);
void	move_ray(t_raycast *ray);

/*					dda_helper_bonus.c			*/
void	cast_ray(t_raycast *ray, t_game *game, size_t x);
void	calculate_wall_height(t_raycast *ray, t_game *game);
void	init_step_dir(t_raycast *ray, t_vec	ray_dir);
bool	is_entity_near_door(t_game *game, int door_x, int door_y);
void	run_dda(t_raycast *ray, t_game *game);

/*					bfs.c						*/
char	*bfs(t_game *game);
int		rerun_bfs(t_game *game);
int		setup_bfs(t_bfs *bfs, t_game *game);
char	*reconstruct_path(t_game *game, t_bfs *bfs);

/*					movement_bonus.c			*/
void	rotate(t_game *game, int dir, double delta_time);
void	player_move(t_game *game,
			double move_x,
			double move_y,
			double delta_time);
int		enemy_move(t_game *game, double delta_time);
void	move_one_step(t_game *game);

/*					movement_helper_bonus.c		*/
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	movement(t_game *game, double delta_time);
bool	boundary_check_x(t_map *map, double new_x, double pos_y);
bool	boundary_check_y(t_map *map, double new_y, double pos_x);

#endif