/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:26:31 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/04 16:38:36 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void *content)
{
	free(content);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst -> content);
	free (lst);
}
/*
int	main(void)
{
	t_list	*lst;
	char	*str = malloc(10);
	//char str = "abc";
	str [0] = 'a';
	str [1] = 'b';
	str [2] = 'c';
	str [3] = '\0';
//	char	str2[] = "abc";
	lst = malloc(sizeof(t_list));
	lst -> content = str;
	lst -> next = NULL;
//	printf("%s\n", (char*)lst -> content);
//	fptr(lst -> content);
	ft_lstdelone(lst, del);
//	printf("%s\n", (char*)lst -> content);
	return 0;
}*/
