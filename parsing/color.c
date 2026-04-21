#include "../map.h"
#include "../libft/libft.h"
#include "../cub3D.h"

void	save_rgb(t_color *color)
{
	color->r = ft_atoi(color->values[0]);
	color->g = ft_atoi(color->values[1]);
	color->b = ft_atoi(color->values[2]);
	color->set = true;
	free_func(NULL, color->values);
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
			return (map->err_msg = "Color value not between 0-255\n", free_func(NULL, tmp), 0);
		size++;
	}
	color->values = tmp;
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
