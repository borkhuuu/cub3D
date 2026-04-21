#ifndef MAP_H
# define MAP_H

# include "game.h"

# include <stdbool.h>

#define TEXTURE 't'

typedef	struct s_color
{
	char	**values;
	int		r;
	int		g;
	int		b;
	bool	set;
}	t_color;

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

/*              PARSE PATHS             */
int		parse_paths(t_map *map);
bool	missing_path(t_map *map);

/*              PARSE MAP               */
int		parse_map(t_map *map);

/*				VALIDATE MAP			*/
int		validate_map(t_map *map);

/*              UTILITY                 */
void	free_func(t_map *map, char **arr);
void	remove_nl(char **arr);
#endif
