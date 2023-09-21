/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:14:28 by seblin            #+#    #+#             */
/*   Updated: 2023/09/21 09:35:54 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	if (!n)
		return (0);
	s1_uc = (unsigned char *) s1;
	s2_uc = (unsigned char *) s2;
	while (n--)
		if (*s1_uc++ != *s2_uc++)
			break ;
	return (*--s1_uc - *--s2_uc);
}
