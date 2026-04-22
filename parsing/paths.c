#include "../map.h"
#include "../libft/libft.h"
#include "../cub3D.h"
#include <errno.h>
#include <fcntl.h>

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

int	validate_path(t_map *map, char *path)
{
	int	i;
	int	fd;

	i = 0;
	if (!path)
		return (map->err_msg = "Error\nPath is non existent\n", 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\n", 6), strerror_wrapper(errno), 0);
	close(fd);
	while (path[i])
	{
		if (path[i] == '/' && path[i + 1] == '.')
			return (map->err_msg = "Error\nPath is hidden file, nice try BOZO\n", 0);
		i++;
	}
	return (1);
}

int	handle_path(t_map *map, char **map_path, char *path, char type)
{
	if (!validate_path(map, path))
		return (0);
	if (*map_path)
	{
		if (type == 'N')
			map->err_msg = "Error\nDuplicate NO texture path\n";
		else if (type == 'S')
			map->err_msg = "Error\nDuplicate SO texture path\n";
		else if (type == 'W')
			map->err_msg = "Error\nDuplicate WE texture path\n";
		else if (type == 'E')
			map->err_msg = "Error\nDuplicate EA texture path\n";
		return (0);
	}
	*map_path = ft_strdup(path);
	if (!(*map_path))
		return (map->err_msg = "Error\nft_strdup failed in handle_path\n", 0);
	return (1);
}
