/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:54:40 by seblin            #+#    #+#             */
/*   Updated: 2023/09/21 09:03:06 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_uc;
	unsigned char	c_uc;

	s_uc = (unsigned char *) s;
	c_uc = (unsigned char) c;
	while (*s_uc && n--)
		if (*s_uc++ == c_uc)
			return ((void *)--s_uc);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s;
	char	*r;
	
	s = "brav mn ddo!";
	r = ft_memchr(s, 'a', 3); // tester param s
	printf("ret:%s, ptr:%s",r, s);
	return (0);
}
*/ 