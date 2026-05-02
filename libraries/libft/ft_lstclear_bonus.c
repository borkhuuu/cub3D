/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:39:25 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/05 11:24:01 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void *content)
{
	free(content);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*onebehind;

	curr = *lst;
	while (curr != NULL)
	{
		onebehind = curr;
		curr = curr -> next;
		del(onebehind -> content);
		free(onebehind);
	}
	*lst = NULL;
}
/*
int	main(void)
{
	t_list	*lst;
	lst = malloc(sizeof(t_list));
	lst -> next = malloc(sizeof(t_list));
	lst -> next -> next = malloc(sizeof(t_list));
	ft_lstclear(&lst, del);
	return 0;
}*/
