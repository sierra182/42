/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:19:37 by seblin            #+#    #+#             */
/*   Updated: 2023/09/20 20:35:03 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*src_c;
	char	*dest_c;	

	src_c = (char *) src;
	dest_c = (char *) dest;
	while (n--)
		*dest_c++ = *src_c++;
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char 	*src = "zyxwvutsrqponmjjjjjjjjjjjjjjjj";
	char	dest*;
	char	*res;
	
	res = ft_memcpy(dest, src, 3);
	printf("%s\n", dest);
	return (0);
}
*/