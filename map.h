#ifndef MAP_H
# define MAP_H

# include "vec.h"
# include "color.h"
# include <stdbool.h>

#define TEXTURE 't'

typedef struct s_map
{
	t_vec 	player;
	char	player_dir;
	int		player_count;
	char	**map_arr;
	char	*line;
	char	*err_msg;
	int 	map_fd;
	int 	map_height;
	bool	in_map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	t_color	color_f;
	t_color	color_c;
}	t_map;

/*				parsing/parse.c				*/
int		parse_paths(t_map *map);
int		handle_id(t_map *map, char **arr);
bool    missing_path(t_map *map);

/*              parsing/paths.c             */
int		handle_path(t_map *map, char **map_path, char *path, char type);
int		validate_path(t_map *map, char *path);
int		validate_line(const char *s);

/*				parsing/color.c				*/
int		handle_color(t_map *map, t_color *color, char *rgb, char type);
int		validate_color(t_map *map, t_color *color, char *rgb);
void	save_rgb(t_color *color);

/*				parsing/map.c				*/
int		parse_map(t_map *map);
void	align_line(char **str);
int		validateCharacters(t_map *map, const char *s);

/*				parsing/floodFill.c			*/
int		validate_map(t_map *map);
int		flood_fill(char **map, int x, int y, int height);
void	get_player_pos(t_map *m);
char	**copy_map(t_map *map);

/*				parsing/helper.c			*/
void	remove_nl(char **arr);
char	first_char(const char *s);
void	free_func(t_map *map, char **arr);

#endif
