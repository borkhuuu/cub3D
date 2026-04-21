#include "cub3D.h"
#include "map.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int	validate_path(t_map *map, char *path)
{
	int	i;
	int	fd;

	i = 0;
	if (!path)
		return (map->err_msg = "Path is non existent\n", 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (strerror_wrapper(errno), 0);
	close(fd);
	while (path[i])
	{
		if (path[i] == '/' && path[i + 1] == '.')
			return (map->err_msg = "Path is hidden file, nice try BOZO\n", 0);
		i++;
	}
	return (1);
}

int	validate_color(t_map *map, t_color *color, char *rgb)
{
	char	**tmp;
	int		size;
	int		i;
	int		num;

	tmp = ft_split(rgb, ',');
	if (!tmp)
		return (map->err_msg = "ft_split returned NULL in validate_color\n", 0);
	size = get_arr_size(tmp);
	if (size != 3)
		return (map->err_msg = "Color values are not exactly 3\n", free_func(NULL, tmp), 0);
	size = 0;
	while (tmp[size])
	{
		i = 0;
		while (tmp[size][i] == ' ' || (tmp[size][i] >= 9 && tmp[size][i] <= 13))
			i++;
		while (ft_isdigit(tmp[size][i]))
			i++;
		num = ft_atoi(tmp[size]);
		if (tmp[size][i] || num > 255 || num < 0)
			return (map->err_msg = "Color value not between 0-255", free_func(NULL, tmp), 0);
		size++;
	}
	color->values = tmp;
	return (1);
}

void	save_rgb(t_color *color)
{
	color->r = ft_atoi(color->values[0]);
	color->g = ft_atoi(color->values[1]);
	color->b = ft_atoi(color->values[2]);
	color->set = true;
	free_func(NULL, color->values);
}

char	first_char(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ((char)0);
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
	{
		i++;
	}
	return (s[i]);
}

int	validate_line(const char *s)
{
	char	first;

	if (!s)
		return (0);
	first = first_char(s);
	if (!first || first == '\n')
		return (0); //skip if line is empty or only has newline
	return (1);
}

void	remove_nl(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] && arr[i + 1])
		i++;
	ft_memset(ft_memchr(arr[i], '\n', ft_strlen(arr[i])), 0, 1);
}

int	handle_path(t_map *map, char **map_path, char *path, char type)
{
	if (!validate_path(map, path))
		return (0);
	if (*map_path)
	{
		if (type == 'N')
			map->err_msg = "Duplicate NO texture path\n";
		else if (type == 'S')
			map->err_msg = "Duplicate SO texture path\n";
		else if (type == 'W')
			map->err_msg = "Duplicate WE texture path\n";
		else if (type == 'E')
			map->err_msg = "Duplicate EA texture path\n";
		return (0);
	}
	*map_path = ft_strdup(path);
	if (!(*map_path))
		return (map->err_msg = "ft_strdup failed in handle_path\n", 0);
	return (1);
}

int	handle_color(t_map *map, t_color *color, char *rgb, char type)
{
	if (!validate_color(map, color, rgb))
		return (0);
	if (color->set)
	{
		if (type == 'F')
			map->err_msg = "Duplicate Floor colors\n";
		else if (type == 'C')
			map->err_msg = "Duplicate Ceiling colors\n";
		return (0);
	}
	save_rgb(color);
	return (1);
}

int	handle_id(t_map *map, char **arr)
{
	if (!ft_strcmp(arr[0], "NO"))
		if (!handle_path(map, &map->path_no, arr[1], 'N'))
			return (0);
	if (!ft_strcmp(arr[0], "SO"))
		if (!handle_path(map, &map->path_so, arr[1], 'S'))
			return (0);
	if (!ft_strcmp(arr[0], "WE"))
		if (!handle_path(map, &map->path_we, arr[1], 'W'))
			return (0);
	if (!ft_strcmp(arr[0], "EA"))
		if (!handle_path(map, &map->path_ea, arr[1], 'E'))
			return (0);
	if (!ft_strcmp(arr[0], "F"))
		if (!handle_color(map, &map->color_f, arr[1], 'F'))
			return (0);
	if (!ft_strcmp(arr[0], "C"))
		if (!handle_color(map, &map->color_c, arr[1], 'C'))
			return (0);
	free_func(NULL, arr);
	return (1);
}

int	parse_paths(t_map *map)
{
	char	**arr;

	if (!validate_line(map->line))
		return (1);
	arr = ft_split(map->line, ' ');
	if (!arr)
		return (1);
	remove_nl(arr);
	if (!ft_strcmp(arr[0], "NO") || !ft_strcmp(arr[0], "SO")
			|| !ft_strcmp(arr[0], "WE") || !ft_strcmp(arr[0], "EA")
			|| !ft_strcmp(arr[0], "F") || !ft_strcmp(arr[0], "C"))
	{
		if (!handle_id(map, arr))
			return (free_func(NULL, arr), 0);
	}
	else
	{
		map->in_map = true;
		free_func(NULL, arr);
	}
	return (1);
}

bool    missing_path(t_map *map)
{
	printf("%s\n%s\n%s\n%s\n%d\n%d\n", map->path_no, map->path_so, map->path_we, map->path_ea, map->color_f.set, map->color_c.set);
	if (!map->path_no || !map->path_so || !map->path_we
		|| !map->path_ea || !map->color_f.set || !map->color_c.set)
		return (map->err_msg = "A path or color is missing/misconfigured\n", true);
	return (false);
}
