/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:57:32 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/05 11:23:48 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (lst == NULL)
		return (NULL);
	curr = lst;
	while (curr -> next != NULL)
	{
		curr = curr -> next;
	}
	return (curr);
}
/*
int	main(void)
{
	t_list	*lst;
	char	str[] = "abc";
	char	str2[] = "123";
	t_list	*res;
	lst = malloc(sizeof(t_list));
	lst -> content = str;
	lst -> next = malloc(sizeof(t_list));
	lst -> next -> next = malloc(sizeof(t_list));
	lst -> next -> next -> content = str2;
	lst -> next -> next -> next = NULL;
	res = ft_lstlast(lst);
//	printf("%i\n", ft_lstsize(lst));
	printf("%s\n", (char *)res -> content);
	printf("%s\n", (char *)res -> next);
	return 0;
}*/
