#include "../map.h"
#include "../libft/libft.h"

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
	if (!map->path_no || !map->path_so || !map->path_we
		|| !map->path_ea || !map->color_f.set || !map->color_c.set)
		return (map->err_msg = "Error\nA path or color is missing/misconfigured or map is not last\n", true);
	return (false);
}
