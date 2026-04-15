/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:19:57 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/05 11:25:27 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	f(void	*content)
{
	int	i;
	char	*content1;

	content1 = (char *)content;
	i = 0;
	while (content1[i] != '\0')
	{
		if (content1[i] >= 'a' && content1[i] <= 'z')
			content1[i] = content1[i] - 32;
		i++;
	}
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	curr = lst;
	while (curr != NULL)
	{
		f(curr -> content);
		curr = curr -> next;
	}
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*curr;
	char	str[] = "abc";
	char	str2[] = "qwe";
	lst = malloc(sizeof(t_list));
	curr = lst;
	lst -> content = str;
	lst -> next = malloc(sizeof(t_list));
	lst -> next -> content = str2;
	lst -> next -> next = NULL;
	ft_lstiter(lst, f);
	while (curr != NULL)
	{
		printf("%s\n", (char*)curr -> content);
		curr = curr -> next;
	}
	return 0;
}*/
