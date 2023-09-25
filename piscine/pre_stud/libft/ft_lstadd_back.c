/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:35:49 by seblin            #+#    #+#             */
/*   Updated: 2023/09/25 15:06:48 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_l;

	last_l = NULL;
	if (!*lst)
		*lst = new;
	else
		last_l = ft_lstlast(*lst);
	//if (last_l)
		last_l->next = new;
}

int	main(void)
{
	
	return (0);
}
