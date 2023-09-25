/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:01:15 by seblin            #+#    #+#             */
/*   Updated: 2023/09/25 14:39:52 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list **lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*link;
	t_list	*new_l;

	while (*lst)
	{
		link = ft_lstnew(f((*lst)->content));
		if (!link)
			return (NULL);
		ft_lstadd_back(&new_l, link);
		del((*lst)->content);
		*lst = (*lst)->next;
	}
	return (new_l);
}
/*
static void	ft_del(void *ptr) // ?
{
	free(ptr);
}
*/