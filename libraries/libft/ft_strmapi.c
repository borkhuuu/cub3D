/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:20:40 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/09 20:47:07 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	f(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	else if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return c;
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = 0;
	new = NULL;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[len] != 0)
		len++;
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main(void)
{
	char	*str = malloc(15);
	str = "LoReM iPsUm";
	printf("%s\n", str = ft_strmapi(str, f));
	return 0;
}*/
