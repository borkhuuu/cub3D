/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:02:27 by boenkhja          #+#    #+#             */
/*   Updated: 2025/04/30 03:10:22 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;
	int	counter;

	i = 0;
	res = 0;
	sign = 0;
	counter = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		counter++;
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	if (counter > 1)
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + (nptr[i++] - '0');
	if (sign == 1)
		res = res * -1;
	return (res);
}
/*
int	main(int argc, const char **argv)
{
	printf("%i\n", ft_atoi(argv[1]));
	printf("%i\n", atoi(argv[1]));
	return 0;
}*/
