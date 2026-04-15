/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:51:29 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/05 11:25:00 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	i = 0;
	while (curr != NULL)
	{
		i++;
		curr = curr -> next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*test;
	test = malloc(sizeof(t_list));
	lst = malloc(sizeof(t_list));
	lst -> next = malloc(sizeof(t_list));
	lst -> next -> next = malloc(sizeof(t_list));
	lst -> next -> next -> next = NULL;
	printf("%i\n", ft_lstsize(lst));
	printf("%i\n", ft_lstsize(test));
	return 0;
}*/
