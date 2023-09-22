/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:14:44 by seblin            #+#    #+#             */
/*   Updated: 2023/09/22 22:53:54 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	if (*--s == c)
		return ((char *) s);
	while (i-- > 0)
		if (*--s == c)
			return ((char *) s);
	return (NULL);
}
