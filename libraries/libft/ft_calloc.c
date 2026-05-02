/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:26:03 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/07 04:25:51 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = NULL;
	if (nmemb == 0 || size == 0)
	{
		res = (void *)malloc(0);
		if (res == NULL)
			return (NULL);
		return (res);
	}
	if (nmemb > (i - 1) / size)
		return (NULL);
	res = (void *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
/*
int	main(void)
{
	int *ptr = ft_calloc(0, 4);
	printf("%i\n", *ptr);
	return 0;
}*/
