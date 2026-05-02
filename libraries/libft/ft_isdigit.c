/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:00:36 by boenkhja          #+#    #+#             */
/*   Updated: 2025/04/30 00:00:37 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	digit;

	digit = '0';
	while (digit - 1 != '9')
	{
		if (c == digit)
			return (1);
		digit++;
	}
	return (0);
}
