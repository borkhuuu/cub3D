/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:03:58 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/04 20:14:13 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = NULL;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr -> next != NULL)
	{
		curr = curr -> next;
	}
	curr -> next = new;
	new -> next = NULL;
}
/*
int	main(void)
{
	char	lststr[] = "hi";
	char	midstr[] = "its";
	char	newstr[] = "me";
	t_list	*curr;
	t_list	*new;
	t_list	*lst;
	lst = malloc(sizeof(t_list));
	lst -> content = lststr;
	lst -> next = malloc(sizeof(t_list));
	lst -> next -> content = midstr;
	lst -> next -> next = NULL;
	curr = lst;
	while (curr != NULL)
	{
		printf("%s\n", (char*)curr -> content);
		curr = curr -> next;
	}
	printf("\n");
	curr = lst;
	new = malloc(sizeof(t_list));
	new -> content = newstr;
	ft_lstadd_back(&lst, new);
	while (curr != NULL)
	{
		printf("%s\n", (char*)curr -> content);
		curr = curr -> next;
	}
	return 0;
}*/
