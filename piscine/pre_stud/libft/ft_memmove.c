/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:45:02 by seblin            #+#    #+#             */
/*   Updated: 2023/09/20 22:44:58 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_c;
	char	*dest_c;	

	src_c = (char *) src;
	dest_c = (char *) dest;
	while (n--)
		if (src - dest > 0)
			*dest_c++ = *src_c++;
	else
		dest_c[n] = src_c[n];
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char 	src[] = "lorem ipum dolor sit a";
	char	*dest = src + 8;
	char	*res;
	
	res = ft_memmove(dest, src, 22);
	printf("%s\n", dest);
	return (0);
}
*/