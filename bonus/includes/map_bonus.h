/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:22:18 by boenkhja          #+#    #+#             */
/*   Updated: 2026/06/01 14:36:11 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "game_bonus.h"
# include "vec_bonus.h"
# include "color_bonus.h"
# include <stdbool.h>

# define TEXTURE 't'

typedef struct s_entity	t_entity;

typedef struct s_map
{
	t_entity	player;
	bool		player_hit;
	t_entity	enemy;
	char		**map_arr;
	char		**copy;
	char		*line;
	char		*err_msg;
	int			map_fd;
	size_t		*strlen_arr;
	size_t		map_height;
	size_t		map_max_width;
	bool		in_map;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*path_m;
	t_color		color_f;
	t_color		color_c;
}	t_map;

/*				parsing/parse_bonus.c				*/
int		parse_paths(t_map *map);
int		handle_id(t_map *map, char **arr);

/*              parsing/paths_bonus.c             */
int		handle_path(t_map *map, char **map_path, char *path, char type);
int		validate_path(t_map *map, char *path, char *ext);
int		validate_line(const char *s);

/*				parsing/color_bonus.c				*/
int		handle_color(t_map *map, t_color *color, char *line, char type);
int		validate_color(t_map *map, t_color *color, char *rgb);
void	save_rgb(t_color *color);

/*				parsing/map_bonus.c				*/
int		parse_map(t_map *map);
char	*replace_tabs(char *line);
int		align_line(char **line);
int		validateCharacters(t_map *map, const char *s);

/*				parsing/floodFill_bonus.c			*/
int		validate_map(t_map *map);
int		flood_fill(t_map *m, char **map, int x, int y);
int		check_rem_rooms(t_map *map, char **copy);
void	get_pos(t_map *m);

#endif
