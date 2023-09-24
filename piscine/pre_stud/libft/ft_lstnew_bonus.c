/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:10:03 by seblin            #+#    #+#             */
/*   Updated: 2023/09/23 19:19:20 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_l;

	new_l = (t_list *) malloc (sizeof(t_list));
	new_l->content = content;
	new_l->next = NULL;
	return (new_l);
}
/*
int	main(void)
{
	void	*content;
	t_list	*list = ft_lstnew(content);
	return (0);
}
*/