/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:32:08 by boenkhja          #+#    #+#             */
/*   Updated: 2025/04/29 23:32:09 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *buffer)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_calloc(sizeof(char), ft_strlen(buffer) + 1);
	if (new == NULL)
		return (NULL);
	while (buffer[i] != '\0')
	{
		new[i] = buffer[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main(void)
{
	char	*str;
	str = malloc(10);
	str[0] = 'a';
	str[1] = 'b';
	str[3] = 'c';
	str[4] = '\0';
	printf("%p\n", &str);
	printf("str is: %s\n", str);
	char	*test = ft_strdup(str);
	printf("%p\n", &test);
	printf("test is: %s\n", test);
	return 0;
}*/
