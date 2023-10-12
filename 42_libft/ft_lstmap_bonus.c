/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:36:21 by svidot            #+#    #+#             */
/*   Updated: 2023/10/12 20:03:23 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new_l;
	t_list	*link;

	new_l = NULL;
	link = NULL;
	while (lst)
	{
		link = ft_lstnew(f(lst->content));
		if (!link)
			return (NULL);
		ft_lstadd_back(&new_l, link);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (new_l);
}
