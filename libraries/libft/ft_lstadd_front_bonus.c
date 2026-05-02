/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:59:08 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/04 20:01:58 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*curr;
	t_list	*lst;
	t_list	*new;
	lst = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	char	str1[20] = "abc";
	char	str2[20] = "qwe";
	curr = lst;
	lst->content = str1;
	lst->next = new;
	new->content = str2;
	new->next = NULL;
	while (curr != NULL)
	{
		printf("%s\n", (char*)curr->content);
		curr = curr->next;
	}
	ft_lstadd_front(&lst, new);
	t_list	*new_curr;
	new_curr = new;
	lst->next = NULL;
	while (new_curr != NULL)
	{
		printf("%s\n", (char*)new_curr->content);
		new_curr = new_curr->next;
	}
	return 0;
}*/
