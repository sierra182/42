/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:14:36 by seblin            #+#    #+#             */
/*   Updated: 2023/09/25 12:16:38 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *)) //** ?
{
	t_list	temp;
	
	while (*lst)
	{	
		temp = *lts->next;	
		del(*lst->content);
		free(*lst);
		*lst = temp; // null ?
	}
}

static void	ft_del(void *ptr)
{
	free(ptr);
}