/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:10:03 by seblin            #+#    #+#             */
/*   Updated: 2023/09/25 16:09:01 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_l;
	
	new_l = NULL;
	new_l = (t_list *) malloc (sizeof(t_list));
	if (!new_l)
		return (NULL);
	new_l->content = content;
	new_l->next = NULL;
	return (new_l);
}
/*
#include <stdio.h>
int	main(void)
{
	int a = 42;
	void	*content = &a;
	t_list	*list = ft_lstnew(content);
	printf("%d", *((int *) list->content));
	return (0);
}
*/
