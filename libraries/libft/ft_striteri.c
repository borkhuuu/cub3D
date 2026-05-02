/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:47:21 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/08 14:41:38 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	f(unsigned int n, char *s)
{
	unsigned int i;
	i = 0;
	if (s[i] == 'b')
		s[i] = 'a';
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "abc";
	ft_striteri(str, f);
	return 0;
}*/
