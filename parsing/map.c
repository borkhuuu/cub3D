#include "../libft/libft.h"
#include "../map.h"

int	validateCharacters(t_map *map, const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if ((s[i] != '0' && s[i] != '1' && s[i] != 'N' && s[i] != '\n' &&
			s[i] != 'S' && s[i] != 'E' && s[i] != 'W' && s[i] != ' '))
		{
			return (0);
		}
		if (s[i] == 'N' || s[i] == 'W' || s[i] == 'E' || s[i] == 'S')
		{
			map->player_dir = s[i];
			map->player_count++;
		}
		i++;
	}
	return (1);
}

void	align_line(char **str)
{
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	if (!str || !*str)
		return ;
	s = *str;
	while (s[i] && s[i] == '\t')
	{
		if (s[i] == '\t')
		{
			ft_memset(ft_memchr(s, '\t', ft_strlen(s)), ' ', 1);
			s = ft_realloc(s, ft_strlen(s), ft_strlen(s) + 4);
			tmp = ft_strjoin("   ", s);
			free(s);
			s = tmp;
			i += 3;
		}
		i++;
	}
	*str = s;
}

int	parse_map(t_map *map)
{
	char	**tmp;
	char	*s;

	if (!validateCharacters(map, map->line))
		return (map->err_msg = "Invalid character found somewhere?!\n", 0);
	tmp = ft_realloc(map->map_arr, (map->map_height) * sizeof(char *),(map->map_height + 2) * sizeof(char *));
	if (!tmp)
		return (map->err_msg = "reallocation/growing of map_arr failed\n", 0);
	map->map_arr = tmp;
	align_line(&map->line);
	s = ft_strdup(map->line);
	if (!s)
		return (map->err_msg = "ft_strdup in parse_map failed\n", 0);
	map->map_arr[map->map_height] = s;
	map->map_height++;
	map->map_arr[map->map_height] = NULL;
	remove_nl(map->map_arr);
	return (1);
}
