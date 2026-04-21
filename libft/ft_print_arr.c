#include "libft.h"

void	ft_print_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		write(1, arr[i], ft_strlen(arr[i]));
		write(1, "\n", 1);
		i++;
	}
}
