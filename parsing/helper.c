#include "../map.h"
#include "../libft/libft.h"
#include <stdlib.h>

void    free_func(t_map *map, char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
	if (map)
	{
		if (map->line)
		{
			free(map->line);
			map->line = NULL;
		}
		if (map->path_no)
		{
			free(map->path_no);
			map->path_no = NULL;
		}
		if (map->path_so)
		{
			free(map->path_so);
			map->path_so = NULL;
		}
		if (map->path_we)
		{
			free(map->path_we);
			map->path_we = NULL;
		}
		if (map->path_ea)
		{
			free(map->path_ea);
			map->path_ea = NULL;
		}
	}
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
