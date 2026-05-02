#include "libft.h"

int	get_len(char **arr)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			j++;
		len += j;
		i++;
	}
	return (len);
}

char	*ft_catcat(char **arr)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = get_len(arr);
	s = ft_calloc(j + 1, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			s[k++] = arr[i][j++];
		i++;
	}
	return (s);
}
