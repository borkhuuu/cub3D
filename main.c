#include "game.h"
#include "libft/libft.h"
#include "map.h"
#include "mlx/mlx.h"
#include "cub3D.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	strerror_wrapper(const int errnum)
{
	char	*err;

	err = strerror(errnum);
	write(2, err, ft_strlen(err));
}

void init_map(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->color_f.r = -1;
	map->color_f.g = -1;
	map->color_f.b = -1;
	map->color_c.r = -1;
	map->color_c.g = -1;
	map->color_c.b = -1;
	map->err_msg = "\n";
}

void	finish_gnl(t_map *map)
{
	while (map->line)
	{
		free(map->line);
		map->line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
	map->map_fd = -1;
}

int main(int ac, char **av)
{
	t_map map;

	if (ac != 2)
		return (write(2, "Arguments not exactly 1\n", 24), 1);
	init_map(&map);
	if ((map.map_fd = open(av[1], O_RDONLY)) == -1)
		return (strerror_wrapper(errno), write(2, map.err_msg, 1), 1);
	map.line = get_next_line(map.map_fd);
	while (map.line && !map.in_map)
	{
		if (!parse_paths(&map))
			return (finish_gnl(&map), write(2, map.err_msg, ft_strlen(map.err_msg)), free_func(&map, NULL), 1);
		else if (map.in_map)
			break;
		free(map.line);
		map.line = get_next_line(map.map_fd);
	}
	if (missing_path(&map))
		return (finish_gnl(&map), write(2, map.err_msg, ft_strlen(map.err_msg)), free_func(&map, NULL), 1);
	while (map.line)
	{
		if (!parse_map(&map))
			return (finish_gnl(&map), write(2, map.err_msg, ft_strlen(map.err_msg)), free_func(&map, map.map_arr), 1); // DONT FORGET error message
		free(map.line);
		map.line = get_next_line(map.map_fd);
	}
	if (!validate_map(&map))
		return (finish_gnl(&map), write(2, map.err_msg, ft_strlen(map.err_msg)), free_func(&map, map.map_arr), 1);
	close(map.map_fd);
	free_func(&map, map.map_arr);
	return (0);
}

// int main(int ac, char **av)
// {
//     void    *mlx;
//     void    *mlx_win;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World\n");
//     mlx_loop(mlx);
// }

// int main(void)
// {
//     int fd = open("test.cub", O_RDONLY);
//     for (char*   line = get_next_line(fd); line; line = get_next_line(fd))
//     free(line);
//     close(fd);
// }
