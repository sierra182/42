/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:35:49 by seblin            #+#    #+#             */
/*   Updated: 2023/09/24 14:44:09 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_l;
	
	if (!*lst)
		*lst = new;
	else 
		last_l = ft_lstlast(*lst);	
	last_l->next = new;	
}