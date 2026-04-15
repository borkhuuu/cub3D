/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:22:42 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/04 19:47:11 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (root == NULL)
		return (root);
	root->content = content;
	root->next = NULL;
	return (root);
}
/*
int	main(void)
{
	t_list*	test;
	t_list*	test2;
	int	*i;
	int	k;
	char	str[20] = "abc";
	test = ft_lstnew(str);
	printf("%s\n", (char*)test->content);
	*i = 20;
	printf("%i\n", *i);
	test2 = ft_lstnew(i);
	k = test2->content;
	printf("%i\n", k);
	//return 0;
}*/
