#include "libft.h"

char	**ft_copy_arr(const char **arr)
{
	char	**copy;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!arr)
		return (NULL);
	while (arr[n])
		n++;
	copy = ft_calloc(n + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	while (arr[i])
	{
		copy[i] = ft_strdup((char*)arr[i]);
		if (!copy[i])
			return (ft_free_arr(copy), NULL);
		i++;
	}
	return (copy);
}
