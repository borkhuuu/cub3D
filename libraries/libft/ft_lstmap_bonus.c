/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boenkhja <boenkhja@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:32:07 by boenkhja          #+#    #+#             */
/*   Updated: 2025/05/05 11:12:48 by boenkhja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void	*content)
{
	free(content);
}

void	*f(void	*content)
{
	int	i = 0;
	char	*str;
	str = (char*)content;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return ((void*)str);
}
*/
static t_list	*my_lstnew(void *content)
{
	t_list	*root;

	root = NULL;
	root = malloc(sizeof(t_list));
	if (root == NULL)
	{
		return (NULL);
	}
	if (!content)
		root -> content = NULL;
	root->content = content;
	root->next = NULL;
	return (root);
}

static void	my_lstadd_back(t_list **lst, t_list *new)
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

static void	my_lstclear(t_list **lst, void (*del)(void *))
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*new;
	t_list	*curr;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	curr = lst;
	root = my_lstnew(f(curr -> content));
	if (root == NULL)
		return (NULL);
	curr = curr -> next;
	while (curr != NULL)
	{
		new = my_lstnew(f(curr -> content));
		if (new == NULL)
		{
			my_lstclear(&root, del);
			return (NULL);
		}
		my_lstadd_back(&root, new);
		curr = curr -> next;
	}
	return (root);
}
/*
int	main(void)
{
	t_list	*lst;
	char	str[] = "aBc";
	char	str2[] = "QWE";
	char	str3[] = "123";
	lst = malloc(sizeof(t_list));
	lst -> content = str;
	lst -> next = malloc(sizeof(t_list));
	lst -> next -> content = str2;
	lst -> next -> next = malloc(sizeof(t_list));
	lst -> next -> next -> content = str3;
	lst -> next -> next -> next = NULL;
	while (lst != NULL)
	{
		printf("%s\n", (char*)lst -> content);
		lst = lst -> next;
	}
	t_list	*new;
	new = ft_lstmap(lst, f, del);
	if (new == lst)
		write(1, "A new list is not returned\n", 27);
	else if (new != lst)
		write(1, "A new list is returned\n", 23);
	while (new != NULL)
	{
		printf("%s\n", (char*)new -> content);
		new = new -> next;
	}
	return 0;
}*/
